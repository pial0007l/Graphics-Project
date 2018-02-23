#ifndef GeneticAlgorithm_H
#define GeneticAlgorithm_H

#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define MATE_VARIANCE_CONSTANT 0.3
#define MUTATATIONS_PER_BASE_PAIR_CONSTANT 0.1

//Binary data used for storing dna
typedef struct {

	void *dataPointer;
	int length;
} binary_data;

//This is for sorting the organisms from most fit, to least
struct sorting_element {

	unsigned int fitness;
	int state;
	struct sorting_element *nextElement;
};

typedef struct {

	binary_data dna;
} organism;

typedef struct {

	//Initial Organisms
	//This must be malloc'ed
	organism *organisms;
	//This value should stay constant throughout multiple generations
	int organismsCount;
	//Tests organism's fitness
	int (*fitnessTest)(organism org);
	//Organism's dna length
	int orgDnaLength;
	//Desired Fitness
	unsigned int desiredFitness;
	//Progress Function
	//This function is called every iteration to give the current max fitness level
	void (*progress)(unsigned int fitness);
} evolutionary_algorithm;

//This evolves the group of organisms until they reach a satisfactory fitness level
organism evolve(evolutionary_algorithm ea);
//Reproduction using 2 organisms - crossing, then mutation
organism reproduce(organism org1, organism org2, evolutionary_algorithm alg);

#endif

//GeneticAlgorithm.c


organism evolve(evolutionary_algorithm ea)
{
	if (ea.organismsCount % 2) {

		printf("Error in evolve: Cannot have odd number of organisms!");
		organism nullOrg;
		nullOrg.dna.dataPointer = NULL;
		nullOrg.dna.length = 0;
		return nullOrg;
	}
	//Seed random number generator
	srand(time(NULL));
	//The organism with a satisfactory fitness
	organism orgToReturn;
	orgToReturn.dna.length = 0;
	orgToReturn.dna.dataPointer = NULL;

	unsigned long long totalFitness = 0;
	//Current generation organisms buffer
	organism *currentGeneration = malloc(ea.organismsCount * sizeof(organism));
	memcpy(currentGeneration, ea.organisms, ea.organismsCount * sizeof(organism));
	free(ea.organisms);
	//Next generation organisms buffer
	organism *newGeneration = malloc(ea.organismsCount * sizeof(organism));

	int totalChildren = ea.organismsCount;

	//Counters
	int i,j;

	//This is used to sort the organisms from most fit to least
	//The first element is just for placeholding
	struct sorting_element *elements = (struct sorting_element *)malloc(sizeof(struct sorting_element) * (ea.organismsCount + 1));
	elements[0].fitness = 0.0;
	elements[0].nextElement = NULL;
	elements[0].state = 0;

	//Main loop — will exit once organisms found with satisfactory fitness
	while (1) {

		/***************************
		 **********TESTING**********
		 ***************************/

		//GP var
		unsigned int orgFitness = 0;

		//Loops through organisms and tests fitness
		//Also sorts them

		ea.organisms = currentGeneration;

		for (i = 0; i < totalChildren; i++)
		{
			orgFitness = ea.fitnessTest(ea.organisms[i]);

			//If org found with satisfactory fitness
			if (orgFitness >= ea.desiredFitness) {

				orgToReturn = ea.organisms[i];
				orgToReturn.dna.dataPointer = (void *)malloc(sizeof(ea.orgDnaLength));
				memcpy(orgToReturn.dna.dataPointer, ea.organisms[i].dna.dataPointer, sizeof(ea.orgDnaLength));
			}

			elements[i + 1].fitness = orgFitness;
			elements[i + 1].nextElement = NULL;
			elements[i + 1].state = 1;
			totalFitness += orgFitness;

			//Sorts orgs using relative values
			if (!i) {

				elements[0].nextElement = &elements[1];
				continue;
			}

			//Used to iterate through array of organism fitnesses
			struct sorting_element *next = &elements[0];

			for (j = 0; j < i + 1; j++) {

				if (next->nextElement == NULL) {

					next->nextElement = &elements[i + 1];
					break;
				}
				if (next->nextElement->fitness <= orgFitness) {

					elements[i + 1].nextElement = next->nextElement;
					next->nextElement = &elements[i + 1];
					break;
				}
				next = next->nextElement;
			}
		}

		ea.progress(elements[0].nextElement->fitness);

		if (orgToReturn.dna.dataPointer != NULL) {

			break;
		}

		 /***************************
		 ********REPRODUCING********
		 ***************************/

		//Mate finder pointers
		struct sorting_element *nextMate;
		struct sorting_element *previousMate;
		//Mate pointer
		organism *mate;
		//Org buffer in reproduction
		struct sorting_element *elementToReplicate;
		//Next generation array last index
		int newGenerationIndex = 0;
		//Decides number of children to have
		int children = 0;
		int randomNumber = 0;
		totalChildren = 0;

		elementToReplicate = elements[0].nextElement;

		//Loops through orgs and finds mate, then reproduce function
		while (elementToReplicate != NULL)
		{
			organism *orgToReplicate = &ea.organisms[(int)(elementToReplicate - elements) - 1];
			previousMate = NULL;
			if (!elementToReplicate->state) {

				elementToReplicate = elementToReplicate->nextElement;
				continue;
			}

			//State makes sure an organism doesn't reproduce more than once
			elementToReplicate->state = 0;
			randomNumber = rand() % (int)((double)ea.organismsCount * MATE_VARIANCE_CONSTANT);
			nextMate = elementToReplicate->nextElement;
			//Moves down the hierarchy a maximum of MATE_VARIANCE_CONSTANT percent
			for (j = 0; j < randomNumber; j++) {

				if (nextMate->state) {

					previousMate = nextMate;
				}

				nextMate = nextMate->nextElement;
				if (nextMate == NULL) {

					nextMate = previousMate;
					break;
				}
			}

			if (!nextMate->state) {

				if (previousMate == NULL) {

					while (!nextMate->state) {

						nextMate = nextMate->nextElement;
					}
				}
				else {

					nextMate = previousMate;
				}
			}

			mate = &ea.organisms[(int)(nextMate - elements) - 1];
			nextMate->state = 0;
			//Calculates number of children based on both parents' fitness
			children = (int)(ea.organismsCount * (double)(elementToReplicate->fitness +
														  nextMate->fitness) / totalFitness);
			totalChildren += children;
			for (j = 0; j < children; j++) {

				newGeneration[newGenerationIndex] = reproduce(*orgToReplicate, *mate, ea);
				newGenerationIndex++;
			}
			free(orgToReplicate->dna.dataPointer);
			free(mate->dna.dataPointer);
			elementToReplicate = elementToReplicate->nextElement;
		}

		if ((totalChildren % 2)) {

			organism dummyOrg;
			dummyOrg.dna.length = ea.orgDnaLength;
			dummyOrg.dna.dataPointer = malloc(ea.orgDnaLength);
			memset(dummyOrg.dna.dataPointer, 0, sizeof(ea.orgDnaLength));
			newGeneration[newGenerationIndex] = dummyOrg;
			totalChildren++;
		}
		organism *buffer = newGeneration;
		newGeneration = memset(currentGeneration, 0, sizeof(currentGeneration));
		currentGeneration = buffer;
		memset(elements, 0, sizeof(currentGeneration));
		totalFitness = 0;
	}

	struct sorting_element *elementFreeingPointer = elements[0].nextElement;
	struct sorting_element *elementFreeingBuffer;

	while (elementFreeingPointer != NULL) {

		elementFreeingBuffer = elementFreeingPointer;
		free(ea.organisms[(int)(elementFreeingPointer - elements) - 1].dna.dataPointer);
		elementFreeingPointer = elementFreeingBuffer->nextElement;
	}

	free(currentGeneration);
	free(newGeneration);
	free(elements);

	return orgToReturn;
}

organism reproduce(organism org1, organism org2, evolutionary_algorithm alg)
{
	organism child;
	//Decides at which index to start crossing with other parent
	int crossingIndex;
	//Number of mutations (in base pairs) in child
	int mutationCount;
	//Base pair to mutate
	int mutatedBasePair;
	//Mutation base pair buffer
	unsigned char basePairBuffer;
	//Counter
	int i;

	//Child starts with first parent's dna then crosses with the other
	child.dna.length = org1.dna.length;
	child.dna.dataPointer = (void *)malloc(org1.dna.length);
	memcpy(child.dna.dataPointer, org1.dna.dataPointer, org1.dna.length);

	//Crossing over

	//Last index ≥ a random index ≥ 0
	crossingIndex = rand() % (alg.orgDnaLength + 1);

	//Copying from somewhere in middle of dna to end, or half of the dna length
	memcpy(child.dna.dataPointer + crossingIndex, org2.dna.dataPointer + crossingIndex,
					alg.orgDnaLength - crossingIndex >= (int)round((double)alg.orgDnaLength / 2.0) ?
					(int)round((double)alg.orgDnaLength / 2.0) : alg.orgDnaLength - crossingIndex);
	//If half of the dna length isn't copied already, the remaining amount is copied from the beginning (wraps around)
	memcpy(child.dna.dataPointer, org2.dna.dataPointer,
		   alg.orgDnaLength - crossingIndex >= (int)round((double)alg.orgDnaLength / 2.0) ? 0 :
		   (int)round((double)alg.orgDnaLength / 2.0) - (alg.orgDnaLength - crossingIndex));
	//Mutating

	mutationCount = rand() % (2 * (int)round(MUTATATIONS_PER_BASE_PAIR_CONSTANT * (double)alg.orgDnaLength * 8.0));

	for (i = 0; i < mutationCount; i++) {

		//Chooses a random byte and copies contents into basePairBuffer
		//Only the first bit will be used
		mutatedBasePair = (rand() % (8 * alg.orgDnaLength));
		memcpy(&basePairBuffer, child.dna.dataPointer + ((int)(mutatedBasePair / 8)), 1);
		//If the bit is 0, make it 1, and vice versa
		if ((basePairBuffer & (unsigned char)pow(2.0, (double)(mutatedBasePair % 8)))) {

			memset(child.dna.dataPointer + (int)(mutatedBasePair / 8),
				   basePairBuffer ^ (unsigned char)pow(2.0, (double)(mutatedBasePair % 8)), 1);
		}
		else {

			memset(child.dna.dataPointer + (int)(mutatedBasePair / 8),
				   basePairBuffer | (unsigned char)pow(2.0, (double)(mutatedBasePair % 8)), 1);
		}
	}

	return child;
}

#define MATE_VARIANCE_CONSTANT 0.3
#define MUTATATIONS_PER_BASE_PAIR_CONSTANT 0.1

//Binary data used for storing dna
typedef struct {

	void *dataPointer;
	int length;
} binary_data;

//This is for sorting the organisms from most fit, to least
struct sorting_element {

	unsigned int fitness;
	int state;
	struct sorting_element *nextElement;
};

typedef struct {

	binary_data dna;
} organism;

typedef struct {

	//Initial Organisms
	//This must be malloc'ed
	organism *organisms;
	//This value should stay constant throughout multiple generations
	int organismsCount;
	//Tests organism's fitness
	unsigned int (*fitnessTest)(organism org);
	//Organism's dna length
	int orgDnaLength;
	//Desired Fitness
	unsigned int desiredFitness;
	//Progress Function
	//This function is called every iteration to give the current max fitness level
	void (*progress)(unsigned int fitness);
} evolutionary_algorithm;

//This evolves the group of organisms until they reach a satisfactory fitness level
organism evolve(evolutionary_algorithm ea);
//Reproduction using 2 organisms - crossing, then mutation
organism reproduce(organism org1, organism org2, evolutionary_algorithm alg);
unsigned int testOrg(organism orgToTest)
{
	float dnaValue = *(float *)orgToTest.dna.dataPointer;
	return (unsigned int)(1.0 / fabs(pow((double)dnaValue, 2.0) + 3.0 * dnaValue - 1.56) * 1000);
}
unsigned int testOrg(organism orgToTest)
{
	return *(unsigned int *)orgToTest.dna.dataPointer;
}
organism evolve(evolutionary_algorithm ea)
{
	if (ea.organismsCount % 2) {

		printf("Error in evolve: Cannot have odd number of organisms!");
		organism nullOrg;
		nullOrg.dna.dataPointer = NULL;
		nullOrg.dna.length = 0;
		return nullOrg;
	}
	//Seed random number generator
	srand(time(NULL));
	//The organism with a satisfactory fitness
	organism orgToReturn;
	orgToReturn.dna.length = 0;
	orgToReturn.dna.dataPointer = NULL;

	unsigned long long totalFitness = 0;
	//Current generation organisms buffer
	organism *currentGeneration = malloc(ea.organismsCount * sizeof(organism));
	memcpy(currentGeneration, ea.organisms, ea.organismsCount * sizeof(organism));
	free(ea.organisms);
	//Next generation organisms buffer
	organism *newGeneration = malloc(ea.organismsCount * sizeof(organism));

	int totalChildren = ea.organismsCount;

	//Counters
	int i,j;

	//This is used to sort the organisms from most fit to least
	//The first element is just for placeholding
	struct sorting_element *elements = (struct sorting_element *)malloc(sizeof(struct sorting_element) * (ea.organismsCount + 1));
	elements[0].fitness = 0.0;
	elements[0].nextElement = NULL;
	elements[0].state = 0;

    //Main loop — will exit once organisms found with satisfactory fitness
	while (1) {

		/***************************
		 **********TESTING**********
		 ***************************/

		//GP var
		unsigned int orgFitness = 0;

		//Loops through organisms and tests fitness
		//Also sorts them

		ea.organisms = currentGeneration;

		for (i = 0; i < totalChildren; i++)
		{
			orgFitness = ea.fitnessTest(ea.organisms[i]);

			//If org found with satisfactory fitness
			if (orgFitness >= ea.desiredFitness) {

				orgToReturn = ea.organisms[i];
				orgToReturn.dna.dataPointer = (void *)malloc(sizeof(ea.orgDnaLength));
				memcpy(orgToReturn.dna.dataPointer, ea.organisms[i].dna.dataPointer, sizeof(ea.orgDnaLength));
			}

			elements[i + 1].fitness = orgFitness;
			elements[i + 1].nextElement = NULL;
			elements[i + 1].state = 1;
			totalFitness += orgFitness;

	//Sorts orgs using relative values
	if (!i) {

		elements[0].nextElement = &elements[1];
		continue;
	}

	//Used to iterate through array of organism fitnesses
	struct sorting_element *next = &elements[0];

	for (j = 0; j < i + 1; j++) {

		if (next->nextElement == NULL) {

			next->nextElement = &elements[i + 1];
			break;
		}
		if (next->nextElement->fitness <= orgFitness) {

			elements[i + 1].nextElement = next->nextElement;
			next->nextElement = &elements[i + 1];
			break;
		}
		next = next->nextElement;
	}
}

ea.progress(elements[0].nextElement->fitness);

if (orgToReturn.dna.dataPointer != NULL) {

	break;
}
 /***************************
 ********REPRODUCING********
 ***************************/

//Mate finder pointers
struct sorting_element *nextMate;
struct sorting_element *previousMate;
//Mate pointer
organism *mate;
//Org buffer in reproduction
struct sorting_element *elementToReplicate;
//Next generation array last index
int newGenerationIndex = 0;
//Decides number of children to have
int children = 0;
int randomNumber = 0;
totalChildren = 0;

elementToReplicate = elements[0].nextElement;

//Loops through orgs and finds mate, then reproduce function
while (elementToReplicate != NULL)
{
	organism *orgToReplicate = &ea.organisms[(int)(elementToReplicate - elements) - 1];
	previousMate = NULL;
	if (!elementToReplicate->state) {

		elementToReplicate = elementToReplicate->nextElement;
		continue;
	}

	//State makes sure an organism doesn't reproduce more than once
	elementToReplicate->state = 0;
	randomNumber = rand() % (int)((double)ea.organismsCount * MATE_VARIANCE_CONSTANT);
	nextMate = elementToReplicate->nextElement;
	//Moves down the hierarchy a maximum of MATE_VARIANCE_CONSTANT percent
	for (j = 0; j < randomNumber; j++) {

		if (nextMate->state) {

			previousMate = nextMate;
		}

		nextMate = nextMate->nextElement;
		if (nextMate == NULL) {

			nextMate = previousMate;
			break;
		}
	}

	if (!nextMate->state) {

		if (previousMate == NULL) {

			while (!nextMate->state) {

				nextMate = nextMate->nextElement;
			}
		}
		else {

			nextMate = previousMate;
		}
	}

	mate = &ea.organisms[(int)(nextMate - elements) - 1];
	nextMate->state = 0;

	//Calculates number of children based on both parents' fitness
	children = (int)(ea.organismsCount * (double)(elementToReplicate->fitness +
												  nextMate->fitness) / totalFitness);
	totalChildren += children;
	for (j = 0; j < children; j++) {

		newGeneration[newGenerationIndex] = reproduce(*orgToReplicate, *mate, ea);
		newGenerationIndex++;
	}
	free(orgToReplicate->dna.dataPointer);
	free(mate->dna.dataPointer);
	elementToReplicate = elementToReplicate->nextElement;
}
		if ((totalChildren % 2)) {

			organism dummyOrg;
			dummyOrg.dna.length = ea.orgDnaLength;
			dummyOrg.dna.dataPointer = malloc(ea.orgDnaLength);
			memset(dummyOrg.dna.dataPointer, 0, sizeof(ea.orgDnaLength));
			newGeneration[newGenerationIndex] = dummyOrg;
			totalChildren++;
		}
		organism *buffer = newGeneration;
		newGeneration = memset(currentGeneration, 0, sizeof(currentGeneration));
		currentGeneration = buffer;
		memset(elements, 0, sizeof(currentGeneration));
		totalFitness = 0;
	}

	struct sorting_element *elementFreeingPointer = elements[0].nextElement;
	struct sorting_element *elementFreeingBuffer;

	while (elementFreeingPointer != NULL) {

		elementFreeingBuffer = elementFreeingPointer;
		free(ea.organisms[(int)(elementFreeingPointer - elements) - 1].dna.dataPointer);
		elementFreeingPointer = elementFreeingBuffer->nextElement;
	}

	free(currentGeneration);
	free(newGeneration);
	free(elements);

	return orgToReturn;
}

organism reproduce(organism org1, organism org2, evolutionary_algorithm alg)
{
	organism child;
	//Decides at which index to start crossing with other parent
	int crossingIndex;
	//Number of mutations (in base pairs) in child
	int mutationCount;
	//Base pair to mutate
	int mutatedBasePair;
	//Mutation base pair buffer
	unsigned char basePairBuffer;
	//Counter
	int i;

	//Child starts with first parent's dna then crosses with the other
	child.dna.length = org1.dna.length;
	child.dna.dataPointer = (void *)malloc(org1.dna.length);
	memcpy(child.dna.dataPointer, org1.dna.dataPointer, org1.dna.length);

	//Crossing over

	//Last index ≥ a random index ≥ 0
	crossingIndex = rand() % (alg.orgDnaLength + 1);

	//Copying from somewhere in middle of dna to end, or half of the dna length
	memcpy(child.dna.dataPointer + crossingIndex, org2.dna.dataPointer + crossingIndex,
					alg.orgDnaLength - crossingIndex >= (int)round((double)alg.orgDnaLength / 2.0) ?
					(int)round((double)alg.orgDnaLength / 2.0) : alg.orgDnaLength - crossingIndex);
	//If half of the dna length isn't copied already, the remaining amount is copied from the beginning (wraps around)
	memcpy(child.dna.dataPointer, org2.dna.dataPointer,
		   alg.orgDnaLength - crossingIndex >= (int)round((double)alg.orgDnaLength / 2.0) ? 0 :
		   (int)round((double)alg.orgDnaLength / 2.0) - (alg.orgDnaLength - crossingIndex));
	//Mutating

	mutationCount = rand() % (2 * (int)round(MUTATATIONS_PER_BASE_PAIR_CONSTANT * (double)alg.orgDnaLength * 8.0));

	for (i = 0; i < mutationCount; i++) {

		//Chooses a random byte and copies contents into basePairBuffer
		//Only the first bit will be used
		mutatedBasePair = (rand() % (8 * alg.orgDnaLength));
		memcpy(&basePairBuffer, child.dna.dataPointer + ((int)(mutatedBasePair / 8)), 1);
		//If the bit is 0, make it 1, and vice versa
		if ((basePairBuffer & (unsigned char)pow(2.0, (double)(mutatedBasePair % 8)))) {

			memset(child.dna.dataPointer + (int)(mutatedBasePair / 8),
				   basePairBuffer ^ (unsigned char)pow(2.0, (double)(mutatedBasePair % 8)), 1);
		}
		else {

			memset(child.dna.dataPointer + (int)(mutatedBasePair / 8),
				   basePairBuffer | (unsigned char)pow(2.0, (double)(mutatedBasePair % 8)), 1);
		}
	}

	return child;
}



unsigned int testOrg(organism orgToTest)
{
	return *(unsigned int *)orgToTest.dna.dataPointer;
}

void progressDisplayer(unsigned int currentFitness)
{
	printf("fitness: %u\n", currentFitness);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int i;
	evolutionary_algorithm ea;
	ea.fitnessTest = testOrg;
	ea.progress = progressDisplayer;
	ea.organismsCount = 50;
	ea.orgDnaLength = sizeof(unsigned int);
	ea.desiredFitness = 4290000000;

	organism *orgs = malloc(sizeof(organism) * ea.organismsCount);

	for (i = 0; i < 50; i++)
	{
		organism newOrg;
		binary_data newOrgDna;
		newOrgDna.dataPointer = malloc(sizeof(unsigned int));
		memset(newOrgDna.dataPointer, i, 1);
		newOrgDna.length = sizeof(unsigned int);
		newOrg.dna = newOrgDna;
		orgs[i] = newOrg;
	}

	ea.organisms = orgs;

	organism finishedOrg = evolve(ea);
	printf("final: %u", ea.fitnessTest(finishedOrg));
	free(finishedOrg.dna.dataPointer);
}

