#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}


float _angle = 0.0;
float _cameraAngle = 0.0;
float _cameraAngleX = 0.0;
float _cameraAnglex = -2;
float _cameraAngleY = 3;
float _ang_tri = 0.0;
float _angle_2 = 90;
float i = 0.0f;
float move_=-140;
float move_1=0;
float mov2=-160;
float mov3;
double eyeX=20;
float fireX;
float fireY=-5;
bool night=0;
int n=0;
int m=0;
float colorNx=100;
float colorNy=100;
float colorNz=100;
bool flag=0;
int run=0;
double eyeY=20;

double eyeZ=0;

int xp=2;
    int zp=0;
    float fire=-5;
//Called when the window is resized
void side4(){
     glPushMatrix();
    glScalef(1,1,15);
    glPushMatrix();
    glScalef(0.05,0.05,0.05);
    for(int j=0;j<5;j++){
        for (int i=0;i<10;i++){
            for(int k=-1.5;k<1.5;k++){
        glPushMatrix();
        glTranslatef(i,j,k);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
            }
        }
        }

    glPopMatrix();
    glPopMatrix();
}



void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 97: //Escape key

			eyeX-=0.5;
			eyeZ+=0.2;
			glutPostRedisplay();
			break;
        case 100: //Escape key
			eyeX+=0.5;
			eyeZ-=0.2;
			glutPostRedisplay();
			break;
        case 119: //Escape key
			eyeY-=1;
			eyeZ-=0.2;
			glutPostRedisplay();
			break;
        case 115: //Escape key
			eyeY+=1;
           eyeZ+=0.2;
			glutPostRedisplay();
			break;
        case 120: //Escape key
			eyeZ-=1;
			glutPostRedisplay();
			break;

        case 122: //Escape key
            eyeZ+=1;

			glutPostRedisplay();
			break;

			case 98: //Escape key
            run=0;
			glutPostRedisplay();
			break;

			case 110: //Escape key
            run=1;
			glutPostRedisplay();
			break;

			case 102: //F

            n=1;
			glutPostRedisplay();
			break;

			case 112: //p

            m=1;
			glutPostRedisplay();
			break;

			case 99: //p

            night=1;
			glutPostRedisplay();
			break;

			case 118: //p

            night=0;
			glutPostRedisplay();
			break;
	}

}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//if(run==1){
	gluPerspective(18, (double)w / (double)h, 1.0, 200.0);
	//}else if(run==0){
        //gluPerspective(3, (double)w / (double)h, 1.0, 200.0);
	//}
}


void drawgrid(){

    float j,k;
    for(k=-20;k<170;k+=0.5){
    for(j=0;j<50;j++){
    glPushMatrix();
    glTranslatef(0,0,j);
    glPushMatrix();
    /*glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(1);
    glVertex3f(k,-0.5,zp);
    glVertex3f(k+.5,-0.5,zp);
    glVertex3f(k+.5,-0.5,zp+1);
    glVertex3f(k,-0.5,zp+1);
    zp+=0.5;
    glEnd();*/

    //1.1
    glBegin(GL_POLYGON);
    glColor3f(0, 0.80, 0);
    glVertex3f(k,-0.5,zp);
    glVertex3f(k+.1,-0.5,zp);
    glVertex3f(k+.1,-0.5,zp+0.2);
    glVertex3f(k,-0.5,zp+0.2);
    glEnd();
    //1.2
    glBegin(GL_POLYGON);
    glColor3f(0, 0.75, 0);
    glVertex3f(k+.1,-0.5,zp);
    glVertex3f(k+.2,-0.5,zp);
    glVertex3f(k+.2,-0.5,zp+0.2);
    glVertex3f(k+.1,-0.5,zp+0.2);
    glEnd();
    //1.3
    glBegin(GL_POLYGON);
    glColor3f(0, 0.70, 0);
    glVertex3f(k+.2,-0.5,zp);
    glVertex3f(k+.3,-0.5,zp);
    glVertex3f(k+.3,-0.5,zp+0.2);
    glVertex3f(k+.2,-0.5,zp+0.2);
    glEnd();
    //1.4
    glBegin(GL_POLYGON);
    glColor3f(0, 0.65, 0);
    glVertex3f(k+.3,-0.5,zp);
    glVertex3f(k+.4,-0.5,zp);
    glVertex3f(k+.4,-0.5,zp+0.2);
    glVertex3f(k+.3,-0.5,zp+0.2);
    glEnd();
    //1.5
    glBegin(GL_POLYGON);
    glColor3f(0, 0.60, 0);
    glVertex3f(k+.4,-0.5,zp);
    glVertex3f(k+.5,-0.5,zp);
    glVertex3f(k+.5,-0.5,zp+0.2);
    glVertex3f(k+.4,-0.5,zp+0.2);
    glEnd();



    //2.1
    glBegin(GL_POLYGON);
    glColor3f(0, 0.55, 0);
    glVertex3f(k,-0.5,zp+.2);
    glVertex3f(k+.1,-0.5,zp+.2);
    glVertex3f(k+.1,-0.5,zp+0.4);
    glVertex3f(k,-0.5,zp+0.4);
    glEnd();
    //2.2
    glBegin(GL_POLYGON);
    glColor3f(0, 0.50, 0);
    glVertex3f(k+.1,-0.5,zp+.2);
    glVertex3f(k+.2,-0.5,zp+.2);
    glVertex3f(k+.2,-0.5,zp+0.4);
    glVertex3f(k+.1,-0.5,zp+0.4);
    glEnd();
    //2.3
    glBegin(GL_POLYGON);
    glColor3f(0, 0.45, 0);
    glVertex3f(k+.2,-0.5,zp+.2);
    glVertex3f(k+.3,-0.5,zp+.2);
    glVertex3f(k+.3,-0.5,zp+0.4);
    glVertex3f(k+.2,-0.5,zp+0.4);
    glEnd();
    //2.4
    glBegin(GL_POLYGON);
    glColor3f(0, 0.40, 0);
    glVertex3f(k+.3,-0.5,zp+.2);
    glVertex3f(k+.4,-0.5,zp+.2);
    glVertex3f(k+.4,-0.5,zp+0.4);
    glVertex3f(k+.3,-0.5,zp+0.4);
    glEnd();
    //2.5
    glBegin(GL_POLYGON);
    glColor3f(0, 0.45, 0);
    glVertex3f(k+.4,-0.5,zp+.2);
    glVertex3f(k+.5,-0.5,zp+.2);
    glVertex3f(k+.5,-0.5,zp+0.4);
    glVertex3f(k+.4,-0.5,zp+0.4);
    glEnd();


    //3.1
    glBegin(GL_POLYGON);
    glColor3f(0, 0.50, 0);
    glVertex3f(k,-0.5,zp+.4);
    glVertex3f(k+.1,-0.5,zp+.4);
    glVertex3f(k+.1,-0.5,zp+0.6);
    glVertex3f(k,-0.5,zp+0.6);
    glEnd();
    //3.2
    glBegin(GL_POLYGON);
    glColor3f(0, 0.55, 0);
    glVertex3f(k+.1,-0.5,zp+.4);
    glVertex3f(k+.2,-0.5,zp+.4);
    glVertex3f(k+.2,-0.5,zp+0.6);
    glVertex3f(k+.1,-0.5,zp+0.6);
    glEnd();
    //3.3
    glBegin(GL_POLYGON);
    glColor3f(0, 0.60, 0);
    glVertex3f(k+.2,-0.5,zp+.4);
    glVertex3f(k+.3,-0.5,zp+.4);
    glVertex3f(k+.3,-0.5,zp+0.6);
    glVertex3f(k+.2,-0.5,zp+0.6);
    glEnd();
    //3.4
    glBegin(GL_POLYGON);
    glColor3f(0, 0.65, 0);
    glVertex3f(k+.3,-0.5,zp+.4);
    glVertex3f(k+.4,-0.5,zp+.4);
    glVertex3f(k+.4,-0.5,zp+0.6);
    glVertex3f(k+.3,-0.5,zp+0.6);
    glEnd();
    //3.5
    glBegin(GL_POLYGON);
    glColor3f(0, 0.70, 0);
    glVertex3f(k+.4,-0.5,zp+.4);
    glVertex3f(k+.5,-0.5,zp+.4);
    glVertex3f(k+.5,-0.5,zp+0.6);
    glVertex3f(k+.4,-0.5,zp+0.6);
    glEnd();

     //4.1
    glBegin(GL_POLYGON);
    glColor3f(0, .75, 0);
    glVertex3f(k,-0.5,zp+.6);
    glVertex3f(k+.1,-0.5,zp+.6);
    glVertex3f(k+.1,-0.5,zp+0.8);
    glVertex3f(k,-0.5,zp+0.8);
    glEnd();
    //4.2
    glBegin(GL_POLYGON);
    glColor3f(0, .80, 0);
    glVertex3f(k+.1,-0.5,zp+.6);
    glVertex3f(k+.2,-0.5,zp+.6);
    glVertex3f(k+.2,-0.5,zp+0.8);
    glVertex3f(k+.1,-0.5,zp+0.8);
    glEnd();
    //4.3
    glBegin(GL_POLYGON);
    glColor3f(0, .85, 0);
    glVertex3f(k+.2,-0.5,zp+.6);
    glVertex3f(k+.3,-0.5,zp+.6);
    glVertex3f(k+.3,-0.5,zp+0.8);
    glVertex3f(k+.2,-0.5,zp+0.8);
    glEnd();
    //4.4
    glBegin(GL_POLYGON);
    glColor3f(0, .90, 0);
    glVertex3f(k+.3,-0.5,zp+.6);
    glVertex3f(k+.4,-0.5,zp+.6);
    glVertex3f(k+.4,-0.5,zp+0.8);
    glVertex3f(k+.3,-0.5,zp+0.8);
    glEnd();
    //4.5
    glBegin(GL_POLYGON);
    glColor3f(0, .85, 0);
    glVertex3f(k+.4,-0.5,zp+.6);
    glVertex3f(k+.5,-0.5,zp+.6);
    glVertex3f(k+.5,-0.5,zp+0.8);
    glVertex3f(k+.4,-0.5,zp+0.8);
    glEnd();

    //1
    glBegin(GL_POLYGON);
    glColor3f(0, .80, 0);
    glVertex3f(k,-0.5,zp+.8);
    glVertex3f(k+.1,-0.5,zp+.8);
    glVertex3f(k+.1,-0.5,zp+1);
    glVertex3f(k,-0.5,zp+1);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0, .75, 0);
    glVertex3f(k+.1,-0.5,zp+.8);
    glVertex3f(k+.2,-0.5,zp+.8);
    glVertex3f(k+.2,-0.5,zp+1);
    glVertex3f(k+.1,-0.5,zp+1);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(0, .70, 0);
    glVertex3f(k+.2,-0.5,zp+.8);
    glVertex3f(k+.3,-0.5,zp+.8);
    glVertex3f(k+.3,-0.5,zp+1);
    glVertex3f(k+.2,-0.5,zp+1);
    glEnd();
    //4
    glBegin(GL_POLYGON);
     glColor3f(0, 0.65, 0);
    glVertex3f(k+.3,-0.5,zp+.8);
    glVertex3f(k+.4,-0.5,zp+.8);
    glVertex3f(k+.4,-0.5,zp+1);
    glVertex3f(k+.3,-0.5,zp+1);
    glEnd();
    //5
    glBegin(GL_POLYGON);
     glColor3f(0, 0.60, 0);
    glVertex3f(k+.4,-0.5,zp+.8);
    glVertex3f(k+.5,-0.5,zp+.8);
    glVertex3f(k+.5,-0.5,zp+1);
    glVertex3f(k+.4,-0.5,zp+1);
    glEnd();

    glPopMatrix();
    glPopMatrix();
    }
    }

}

void roater(){

        ///////////////////////////////////////////
    glPushMatrix();
    glColor3f(.255,.255,.255);
    glScalef(0.2,0.2,0.2);
    if(run==1){
    glRotatef(_angle,0.0,1.0,0.0);
    }else{
        glRotatef(0,0.0,0.0,0.0);
    }
    glPushMatrix();

    glPushMatrix();

    glTranslatef(0,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(1,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(2,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(3,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(4,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(5,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(6,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(7,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

/////////////////////////////////////////
    glPopMatrix();

    glRotatef(180,0,0,1);
    glPushMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(0,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(1,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(2,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(3,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(4,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(5,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(6,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(1,0,0);
    //glColor3f(2.0,0.50,.50);
    glTranslatef(7,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    //one single
    //////////////////////////////////////

    glPushMatrix();
    glRotatef(90,0.0,1.0,0.0);
     glPushMatrix();
    glScalef(0.2,0.2,0.2);
    if(run==1){
    glRotatef(_angle,0.0,1.0,0.0);
    }else{
        glRotatef(0,0.0,0.0,0.0);
    }
    glPushMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(0,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(1,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(2,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(3,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(4,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(5,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(6,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(7,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();
    glPopMatrix();


    ////down
    //////////////////////////////////////

    glPushMatrix();
    glRotatef(90,0.0,0.0,1);
     glPushMatrix();
    glScalef(0.2,0.2,0.2);
    if(run==1){
    glRotatef(_angle,0.0,1.0,0.0);
    }else{
        glRotatef(0,0.0,0.0,0.0);
    }
    glPushMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(0,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(1,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(2,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(3,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(4,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(5,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(6,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(7,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();
    glPopMatrix();

     //one single
    //////////////////////////////////////

    glPushMatrix();
    glRotatef(-90,0.0,1.0,0.0);
     glPushMatrix();
    glScalef(0.2,0.2,0.2);
    if(run==1){
    glRotatef(_angle,0.0,1.0,0.0);
    }else{
        glRotatef(0,0.0,0.0,0.0);
    }
    glPushMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(0,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(1,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(2,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(3,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(4,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(5,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(6,0.0,0.0);

    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    //glColor3f(2.0,0.50,.50);
    glTranslatef(7,0.0,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(1); //(GLdouble size)
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}
void side1(){
    glPushMatrix();
    glColor3f(0,1,0);
    glScalef(1,1,7);
    glPushMatrix();
    glScalef(0.05,0.05,0.05);
    for(int j=0;j<4;j++){
        for (int i=0;i<42;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.05,0.05);
    for(int j=4;j<8;j++){
        for (int i=5;i<30;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

    glPopMatrix();
    glPopMatrix();

}
void side2(){
   glPushMatrix();
    glScalef(1,1,15);
    glPushMatrix();
    glScalef(0.05,0.05,0.05);
    for(int j=0;j<10;j++){
        for (int i=0;i<10;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

    glPopMatrix();
    glPopMatrix();
}
void side3(){
     glPushMatrix();
    glScalef(1,1,15);
    glPushMatrix();
    glScalef(0.05,0.05,0.05);
    for(int j=0;j<5;j++){
        for (int i=0;i<10;i++){
            for(int k=0;k<5;k++){
        glPushMatrix();
        glTranslatef(i,j,k);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
            }
        }
        }

    glPopMatrix();
    glPopMatrix();

}
void mainbody1(){
    glPushMatrix();
    glColor3f(0.105,0.105,.105);
    glPushMatrix();
        glScalef(0.05,0.05,0.05);
        for (int i=5;i<94;i++){

        glPushMatrix();
        glTranslatef(i,0.0,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        /////////
        for(int j=-3;j<0;j++){
        for (int i=5;i<86;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

        /////////
        for(int j=-5;j<=-3;j++){
        for (int i=5;i<52;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

        /////////
        for(int j=-8;j<=-5;j++){
        for (int i=11;i<=47;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
        //////////////
        for(int j=-11;j<=-8;j++){
        for (int i=12;i<=47;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

        for(int j=-7;j<=-3;j++){
        for (int i=72;i<=85;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
        for(int j=0;j<=2;j++){
        for (int i=10;i<=94;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
        ///////////
        for(int j=2;j<=3;j++){
        for (int i=12;i<=94;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
        ///////////
        for(int j=3;j<=4;j++){
        for (int i=12;i<=64;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
         ///////////
        for(int j=4;j<=6;j++){
        for (int i=14;i<=64;i++){

        glPushMatrix();
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

         ///////////
        for(int j=3;j<=6;j++){
        for (int i=73;i<=94;i++){

        glPushMatrix();

        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
        /////////////
        for(int j=6;j<=8;j++){
        for (int i=16;i<=52;i++){

        glPushMatrix();
        //glColor3f(2.0,0.50,.50);
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
         /////////////
        for(int j=8;j<=10;j++){
        for (int i=26;i<=47;i++){

        glPushMatrix();
        //glColor3f(2.0,0.50,.50);
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

        for(int j=10;j<=17;j++){
        for (int i=30;i<=44;i++){

        glPushMatrix();
        //glColor3f(2.0,0.50,.50);
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
        //////////////
        for(int j=6;j<=12;j++){
        for (int i=78;i<=97;i++){

        glPushMatrix();
        //glColor3f(2.0,0.50,.50);
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }

        for(int j=12;j<=16;j++){
        for (int i=83;i<=97;i++){

        glPushMatrix();
        //glColor3f(2.0,0.50,.50);
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }
        ////////////
         for(int j=16;j<=21;j++){
        for (int i=87;i<=101;i++){

        glPushMatrix();
        //glColor3f(2.0,0.50,.50);
        glTranslatef(i,j,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
        }
        }



        glPopMatrix();
        glPopMatrix();
}
void helicupter(){
    glPushMatrix();
    //glColor3f(255,0,0);
    if(run==0){
    glRotatef(move_1,0,1,0);
    }else{
        glRotatef(0,0,0,0);
    }
    glPushMatrix();
    glTranslatef(-2,0,0);
    for(float i=-0.25;i<0;i+=0.05){
    glPushMatrix();
    glTranslatef(0,0,i);
    mainbody1();
    glPopMatrix();
    }
    for(float i=0;i<0.25;i+=0.05){
    glPushMatrix();
    glTranslatef(0,0,i);
    mainbody1();
    glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2,1,1);
    glTranslatef(-.15,1.3,0);
    roater();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,0.3,0.5);
    glTranslatef(25,2.5,1);
    glRotatef(90,1,0,0);
    glPushMatrix();
    glScalef(4,1.5,1.5);
    if(run==1){
    glRotatef(_angle,0.0,1.0,0.0);
    }else{
        glRotatef(0,0.0,0.0,0.0);
    }
    side4();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1,0.3,0.5);
    glTranslatef(25,2.5,1);
    glRotatef(90,1,0,0);
    glPushMatrix();
    glScalef(4,1.5,1.5);
    if(run==1){
    glRotatef(_angle,0.0,1.0,0.0);
    }else{
        glRotatef(0,0.0,0.0,0.0);
    }
    side4();
    glPopMatrix();
    glPopMatrix();




    //left
    glPushMatrix();
    glTranslatef(-1.55,-0.25,-0.4);
    side1();
    glPopMatrix();

    //right
    glPushMatrix();
    glTranslatef(-1.55,-0.25,0.35);
    side1();
    glPopMatrix();

    //left
    glPushMatrix();
    glTranslatef(-0.05,-0.05,-0.4);
    side2();
    glPopMatrix();

    //left
    glPushMatrix();
    glTranslatef(-0.05,-0.05,0.35);
    side2();
    glPopMatrix();

    //center
    glPushMatrix();
    glTranslatef(-0.5,-0.3,-1.55);
    side3();
    glPopMatrix();

    //center
    glPushMatrix();
    glTranslatef(1.7,-0.2,-0.01);
    side4();
    glPopMatrix();
    glPopMatrix();

    //glTranslatef(2,0,-0.4);

}

void tree(){
    glPushMatrix();
    glTranslatef(10,-3,20);
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    GLUquadricObj *obj = gluNewQuadric();
    gluCylinder(obj, 0.8, 0.8, 4, 10, 10);

    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    //cout<<eyeZ<<endl;
    glColor3f(0.0,0.20,.0);
    glTranslatef(10,-20,1);
    //cout<<eyeZ<<endl;
    glutSolidCone(2.7,4,15,15);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    //cout<<eyeZ<<endl;
    glColor3f(0.0,0.50,.0);
    glTranslatef(10,-20,2.5);
    //cout<<eyeZ<<endl;
    glutSolidCone(2.5,4,15,15);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    //cout<<eyeZ<<endl;
    glColor3f(0.0,0.70,.0);
    glTranslatef(10,-20,4);
    //cout<<eyeZ<<endl;
    glutSolidCone(2.30,4,15,15);
    glPopMatrix();
}



void mountain(){
    //Mountain1
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    //cout<<eyeZ<<endl;
    glColor3f(0.0,0.80,.0);
    glTranslatef(5,-1,-1);
    //cout<<eyeZ<<endl;
    glutSolidCone(5,3,15,15);

    glPopMatrix();

    //Mountain2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(10,-2,-1);
    glutSolidCone(5,5,15,15);
    glPopMatrix();

    //Mountain3
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(20,-2,-1);
    glutSolidCone(8,3,15,15);
    glPopMatrix();

     //Mountain-2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(-2,-2,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();

    //Mountain4
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(25,-1,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();


    //Mountain5
    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(30,-2,3);
    glutSolidSphere(4,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(40,-2,-2);
    glutSolidCone(10,5,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.77,0.75,.0);
    glTranslatef(50,1,-1);
    glutSolidCone(6,8,10,10);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(10,-3.5,15);
    glutSolidSphere(4,30,30);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(30,-3.5,35);
    glutSolidSphere(4,30,30);
    glPopMatrix();

    //Mountain1
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    //cout<<eyeZ<<endl;
    glColor3f(0.0,0.80,.0);
    glTranslatef(55,-1,-1);
    //cout<<eyeZ<<endl;
    glutSolidCone(5,3,15,15);

    glPopMatrix();

    //Mountain2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(60,-2,-1);
    glutSolidCone(5,5,15,15);
    glPopMatrix();

    //Mountain3
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(70,-2,-1);
    glutSolidCone(8,3,15,15);
    glPopMatrix();

     //Mountain-2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(48,-2,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();

    //Mountain4
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(75,-1,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();


    //Mountain5
    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(80,-2,3);
    glutSolidSphere(4,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
     glColor3f(0.77,0.75,.0);
    glTranslatef(90,-2,-2);
    glutSolidCone(10,5,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.29,0.75,.66);
    glTranslatef(100,-1,-1);
    glutSolidCone(6,6,10,10);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(60,-3.5,15);
    glutSolidSphere(4,30,30);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(90,-3.5,35);
    glutSolidSphere(4,30,30);
    glPopMatrix();



    //Mountain1
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    //cout<<eyeZ<<endl;
    glColor3f(0.0,0.80,.0);
    glTranslatef(105,-1,-1);
    //cout<<eyeZ<<endl;
    glutSolidCone(5,3,15,15);

    glPopMatrix();
    //Mountain2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(110,-2,-1);
    glutSolidCone(5,5,15,15);
    glPopMatrix();

    //Mountain3
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(120,-2,-1);
    glutSolidCone(8,3,15,15);
    glPopMatrix();

     //Mountain-2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(98,-2,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();

    //Mountain4
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(125,-1,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();


    //Mountain5
    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(130,-2,3);
    glutSolidSphere(4,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(140,-2,-2);
    glutSolidCone(10,5,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.75,.25);
    glTranslatef(150,1,-1);
    glutSolidCone(6,8,10,10);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(110,-3.5,15);
    glutSolidSphere(4,30,30);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(130,-3.5,35);
    glutSolidSphere(4,30,30);
    glPopMatrix();

     //Mountain1
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    //cout<<eyeZ<<endl;
    glColor3f(0.0,0.80,.0);
    glTranslatef(155,-1,-1);
    //cout<<eyeZ<<endl;
    glutSolidCone(5,3,15,15);

    glPopMatrix();
    //Mountain2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(160,-2,-1);
    glutSolidCone(5,5,15,15);
    glPopMatrix();

    //Mountain3
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(170,-2,-1);
    glutSolidCone(8,3,15,15);
    glPopMatrix();

     //Mountain-2
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(158,-2,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();

    //Mountain4
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(175,-1,-1);
    glutSolidCone(4,2,15,15);
    glPopMatrix();


    //Mountain5
    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(180,-2,3);
    glutSolidSphere(4,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.50,.0);
    glTranslatef(190,-2,-2);
    glutSolidCone(10,5,10,10);
    glPopMatrix();

    //Mountain6
    glPushMatrix();
    glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.75,.25);
    glTranslatef(200,1,-1);
    glutSolidCone(6,8,10,10);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(160,-3.5,15);
    glutSolidSphere(4,30,30);
    glPopMatrix();


    glPushMatrix();
    //glRotatef(-90,0.1,0.0,0.0);
    glColor3f(0.0,0.70,.0);
    glTranslatef(180,-3.5,35);
    glutSolidSphere(4,30,30);
    glPopMatrix();


}

void tree2(){
    //tree1
    glPushMatrix();

    glTranslatef(0,-0.2,0);
    //glRotatef(90,0.0,0.0,1.0);
    //glRotatef(- 90,1.0,0.0,0.0);
    //cout<<eyeZ<<endl;
    //glScalef(.15,.15,.15);
    glScalef(.15,.15,.15);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,-0.2,4 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.5,-0.2,4 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-0.2,5 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-0.2,15 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.5,-0.2,15 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,-0.2,1 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6.5,-0.2,1 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(15,-0.2,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14.5,-0.2,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(20,0.5,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.5,0.5,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(25.5,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(23,-0.2,8 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22.5,-0.2,8 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(29.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(26,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(29,1.8,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(31,1.6,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.5,1.6,2.5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(34.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,0.35,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40.5,-0.25,6 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(41,-0.25,6 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(47,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46.5,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(51,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    //tree1
    glPushMatrix();

    glTranslatef(50,-0.2,0);
    //glRotatef(90,0.0,0.0,1.0);
    //glRotatef(- 90,1.0,0.0,0.0);
    //cout<<eyeZ<<endl;
    //glScalef(.15,.15,.15);
    glScalef(.15,.15,.15);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55,-0.2,4 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(54.5,-0.2,4 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,-0.2,5 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,-0.2,15 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(59.5,-0.2,15 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(45,-0.2,1 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(46.5,-0.2,1 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(65,-0.2,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(64.5,-0.2,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(70,0.5,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(69.5,0.5,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(75.5,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(73,-0.2,8 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(72.5,-0.2,8 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(79.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(76,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(79,1.8,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(81,1.6,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80.5,1.6,2.5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(85,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(84.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(90,0.35,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(90.5,-0.25,6 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(91,-0.25,6 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(97,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(96.5,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(101,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    //tree
    glTranslatef(100,-0.2,0);
    //glRotatef(90,0.0,0.0,1.0);
    //glRotatef(- 90,1.0,0.0,0.0);
    //cout<<eyeZ<<endl;
    //glScalef(.15,.15,.15);
    glScalef(.15,.15,.15);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,-0.2,4 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(104.5,-0.2,4 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,-0.2,5 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,-0.2,15 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(109.5,-0.2,15 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,-0.2,1 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6.5,-0.2,1 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(115,-0.2,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(114.5,-0.2,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(120,0.5,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(119.5,0.5,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(125.5,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(123,-0.2,8 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(122.5,-0.2,8 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(129.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(126,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(129,1.8,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(131,1.6,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130.5,1.6,2.5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(134.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(140,0.35,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(140.5,-0.25,6 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(141,-0.25,6 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(147,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(146.5,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(151,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

     //tree1
    glPushMatrix();

    glTranslatef(150,-0.2,0);
    //glRotatef(90,0.0,0.0,1.0);
    //glRotatef(- 90,1.0,0.0,0.0);
    //cout<<eyeZ<<endl;
    //glScalef(.15,.15,.15);
    glScalef(.15,.15,.15);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(155,-0.2,4 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(154.5,-0.2,4 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(160,-0.2,5 );
    glScalef(.13,.13,.13);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(160,-0.2,15 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(159.5,-0.2,15 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(145,-0.2,1 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(146.5,-0.2,1 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(165,-0.2,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(164.5,-0.2,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(170,0.5,5 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(169.5,0.5,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(175,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(175.5,0.5,5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(173,-0.2,8 );
    glScalef(.10,.10,.10);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(172.5,-0.2,8 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(179.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(176,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(175.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(179,1.8,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(181,1.6,2.5 );
    glScalef(.07,.07,.07);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180.5,1.6,2.5 );
    glScalef(.05,.05,.05);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(185,-0.25,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(184.5,-0.25,5 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(190,0.35,5 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(190.5,-0.25,6 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(191,-0.25,6 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(197,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(196.5,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(200,-0.25,3 );
    glScalef(.08,.08,.08);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.5,-0.25,3 );
    glScalef(.1,.1,.1);
    tree();
    glPopMatrix();


}

void cloud(){

glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(10,3,1);
    glutSolidSphere(2,50,50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(13,3.5,-0.9);
    glutSolidSphere(3,50,50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(16.5,3,-0.89);
    glutSolidSphere(2,50,50);
    glPopMatrix();

}

void grass(){
    glPushMatrix();
    glColor3f(0,255,0);
    glBegin(GL_POLYGON);

    glVertex3f(0,-0.5,0);
    glVertex3f(1,-0.5,0);
    glVertex3f(1,2,0);
    glVertex3f(0,2,0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(1,2,0);
    glVertex3f(2,2,0);
    glVertex3f(2,5,0);
    glVertex3f(1,5,0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(2,5,0);
    glVertex3f(3,5,0);
    glVertex3f(3,6,0);
    glVertex3f(2,6,0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(3,6,0);
    glVertex3f(5,6,0);
    glVertex3f(5,7,0);
    glVertex3f(3,7,0);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex3f(5,6,0);
    glVertex3f(5,5,0);
    glVertex3f(6,5,0);
    glVertex3f(6,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(6,5,0);
    glVertex3f(6,3,0);
    glVertex3f(7,3,0);
    glVertex3f(7,5,0);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glRotated(90.0,0,1,0);
    glColor3f(0,255,0);
    glBegin(GL_POLYGON);

    glVertex3f(0,-0.5,0);
    glVertex3f(1,-0.5,0);
    glVertex3f(1,2,0);
    glVertex3f(0,2,0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(1,2,0);
    glVertex3f(2,2,0);
    glVertex3f(2,5,0);
    glVertex3f(1,5,0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(2,5,0);
    glVertex3f(3,5,0);
    glVertex3f(3,6,0);
    glVertex3f(2,6,0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(3,6,0);
    glVertex3f(5,6,0);
    glVertex3f(5,7,0);
    glVertex3f(3,7,0);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex3f(5,6,0);
    glVertex3f(5,5,0);
    glVertex3f(6,5,0);
    glVertex3f(6,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(6,5,0);
    glVertex3f(6,3,0);
    glVertex3f(7,3,0);
    glVertex3f(7,5,0);
    glEnd();

    glPopMatrix();
}

void grass2(){
    glScalef(0.1,0.1,0.1);
    glTranslatef(0,-5,0);
    glPushMatrix();
    glRotated(0.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.10,0);
    glTranslatef(1,0,0);
    glRotated(45.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.30,0);
    glRotated(90.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.30,0);
    glTranslatef(1,0,0);
    glRotated(135.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.40,0);
    glRotated(180.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.50,0);
    glTranslatef(1,0,0);
    glRotated(225.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.60,0);
    glRotated(270.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.70,0);
    glTranslatef(1,0,0);
    glRotated(315.0,0,1,0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0.80,0);
    glRotated(360.0,0,1,0);
    grass();
    glPopMatrix();


}

void grass3(){
    glPushMatrix();
    glTranslatef(-8,0,1);
    glScalef(0.5,0.5,0.5);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,0,1);
    glScalef(0.5,0.5,0.5);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.5,0,1);
    glScalef(0.5,0.5,0.5);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.5,0,5);
    glScalef(0.2,0.2,0.2);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.1,0.25,5);
    glScalef(0.2,0.2,0.2);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,0,5);
    glScalef(0.2,0.2,0.2);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,0,5);
    glScalef(0.2,0.2,0.2);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,0,5);
    glScalef(0.2,0.2,0.2);
    grass2();
    glPopMatrix();


}
void house2(){

    glPushMatrix();
    glColor3f(0.60,0,0);
    glScalef(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glColor3f(0.60,0,0);
    glVertex3f(-25,0,-20);
    glVertex3f(25,0,-20);
    glVertex3f(25,20,-20);
    glVertex3f(-25,20,-20);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.60,0,0);
    glVertex3f(-25,0,20);
    glVertex3f(25,0,20);
    glVertex3f(25,20,20);
    glVertex3f(-25,20,20);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.60,0,0);
    glVertex3f(-25,0,-20);
    glVertex3f(-25,20,-20);
    glVertex3f(-25,20,30);
    glVertex3f(-25,0,30);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.60,0,0);
    glVertex3f(-25,0,30);
    glVertex3f(-6,0,30);
    glVertex3f(-6,20,30);
    glVertex3f(-25,20,30);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-6,20,30);
    glVertex3f(-6,0,30);
    glVertex3f(-5,0,-0);
    glVertex3f(-5,20,-0);
glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(25,0,-20);
    glVertex3f(25,20,-20);
    glVertex3f(25,20,20);
    glVertex3f(25,0,20);
glEnd();

    glBegin(GL_POLYGON);
   glColor3f(0,0.10,0);
      glVertex3f(-27,20,-22);
       glVertex3f(27,20,-22);
        glVertex3f(27,20,22);
         glVertex3f(-27,20,22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,20,32);
       glVertex3f(27,20,32);
        glVertex3f(27,20,0);
         glVertex3f(-27,20,0);
    glEnd();
////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,20,32);
       glVertex3f(27,20,32);
        glVertex3f(27,22,32);
         glVertex3f(-27,22,32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,20,-22);
       glVertex3f(27,20,-22);
        glVertex3f(27,22,-22);
         glVertex3f(-27,22,-22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,20,-22);
       glVertex3f(-27,22,-22);
        glVertex3f(-27,22,32);
         glVertex3f(-27,20,32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(27,20,-22);
       glVertex3f(27,22,-22);
        glVertex3f(27,22,32);
         glVertex3f(27,20,32);
    glEnd();

    ///////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,35,12);
       glVertex3f(2,35,12);
        glVertex3f(2,37,12);
         glVertex3f(-27,37,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,35,-22);
       glVertex3f(2,35,-22);
        glVertex3f(2,37,-22);
         glVertex3f(-27,37,-22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,35,-22);
       glVertex3f(-27,37,-22);
        glVertex3f(-27,37,12);
         glVertex3f(-27,35,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(2,35,-22);
       glVertex3f(2,37,-22);
        glVertex3f(2,37,12);
         glVertex3f(2,35,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.10,0);
      glVertex3f(-27,37,-22);
       glVertex3f(2,37,-22);
        glVertex3f(2,37,12);
         glVertex3f(-27,35,12);
    glEnd();



    ///////////////////////////////////////////////////////////////


    glBegin(GL_POLYGON);
    glColor3f(0.60,0,0);
    glVertex3f(-25,20,-20);
    glVertex3f(0,20,-20);
    glVertex3f(0,35,-20);
    glVertex3f(-25,35,-20);
glEnd();

    //front
    glBegin(GL_POLYGON);
    glColor3f(0.60,0,0);
    glVertex3f(-25,20,10);
    glVertex3f(0,20,10);
    glVertex3f(0,35,10);
    glVertex3f(-25,35,10);

glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.60,0,0);
    glVertex3f(-25,20,-20);
    glVertex3f(-25,35,-20);
    glVertex3f(-25,35,10);
    glVertex3f(-25,20,10);
glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0,20,10);
    glVertex3f(0,35,10);
    glVertex3f(0,35,-20);
    glVertex3f(0,20,-20);
     glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0.10,0);
    glVertex3f(-27,35,-22);
    glVertex3f(-27,35,12);
    glVertex3f(2,35,12);
    glVertex3f(2,35,-22);


    glEnd();


    ////////////
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(-20,25,10.1);
    glVertex3f(-5,25,10.1);
    glVertex3f(-5,30,10.1);
    glVertex3f(-20,30,10.1);
    glEnd();
    ///////////

    ////////////
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(-20,8,30.1);
    glVertex3f(-10,8,30.1);
    glVertex3f(-10,13,30.1);
    glVertex3f(-20,13,30.1);
    glEnd();
    ///////////

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(5,0,20.1);
    glVertex3f(13,0,20.1);
    glVertex3f(13,12,20.1);
    glVertex3f(5,12,20.1);
    glEnd();
    ///////////




    glPopMatrix();

    /*glPushMatrix();
    glScalef(0.1,0.1,0.1);
    for(int j=0;j<20;j++){
        for (int i=-25;i<-5;i++){
            for(int k=-20;k<30;k++){
        glPushMatrix();
        glTranslatef(i,j,k);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(1); //(GLdouble size)
        glPopMatrix();
        glEnd();
            }
        }
        }

    glPopMatrix();
    glPopMatrix();*/

    glPushMatrix();
      glColor3f(0.60,0,0);
    glScalef(0.2,0.2,0.2);
    glBegin(GL_POLYGON);

    glEnd();
    glPopMatrix();

}

void house(){
    glPushMatrix();
    glTranslatef(2,0,-7);
    house2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4,0.5,0);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0.5,1);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4,0.5,2);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2,0.5,5);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0.5,4);
    grass2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(3,0.5,4);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(2,0.5,6);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,0.5,6);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.5,0.5,4);
    grass2();
    glPopMatrix();

     glPushMatrix();
    glTranslated(4,0.5,2);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.5,0.5,0);
    grass2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,0.5,-1);
    grass2();
    glPopMatrix();
}

void cloud2(){
       //cloud1
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(mov2,3,9);
    cloud();
    glPopMatrix();

    //cloud2
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2+10,7,6);
    cloud();
    glPopMatrix();

    //cloud3
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-10,8,12);
    cloud();
    glPopMatrix();


    //cloud4
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-50,8,9);
    cloud();
    glPopMatrix();


    //cloud5
    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslatef(mov2-100,8,4);
    cloud();
    glPopMatrix();


    //cloud6
    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslatef(mov2-150,8,4);
    cloud();
    glPopMatrix();

    //cloud6
    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslatef(mov2-200,8,4);
    cloud();
    glPopMatrix();

    //cloud6
    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslatef(mov2-250,8,4);
    cloud();
    glPopMatrix();

    //cloud6
    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslatef(mov2-300,8,4);
    cloud();
    glPopMatrix();

    //cloud6
    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslatef(mov2-350,8,4);
    cloud();
    glPopMatrix();


    //cloud2
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-70,7,6);
    cloud();
    glPopMatrix();

    //cloud3
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-90,8,12);
    cloud();
    glPopMatrix();


    //cloud4
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-100,8,9);
    cloud();
    glPopMatrix();



    //cloud2
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-120,7,6);
    cloud();
    glPopMatrix();

    //cloud3
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-150,8,12);
    cloud();
    glPopMatrix();


    //cloud4
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-200,8,7);
    cloud();
    glPopMatrix();


    //cloud1
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(mov2-220,3,9);
    cloud();
    glPopMatrix();

    //cloud2
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-250,7,6);
    cloud();
    glPopMatrix();

    //cloud3
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-300,8,12);
    cloud();
    glPopMatrix();


    //cloud4
    glPushMatrix();
    glScalef(0.6,0.6,0.6);
    glTranslatef(mov2-350,8,8);
    cloud();
    glPopMatrix();
}

void bomb(){
    glPushMatrix();


     glScalef(.8,.8,.8);
     glRotatef(40,1,0,0);
    glColor3f(0,0,0 );
    glTranslatef(-14,10,-5);


    glutSolidSphere(3,50,50);
    glPopMatrix();

}
void star(){
        glPushMatrix();


    glScalef(0.1,0.1,0.1);
    glRotatef(40,1,0,0);
    glColor3f(255,255,255 );
    glTranslatef(0,9,5);
    glutSolidSphere(2,50,50);

    glPopMatrix();

     glPushMatrix();


    glScalef(0.02,0.02,0.02);
    glRotatef(40,1,0,0);
    glColor3f(255,255,255 );
    glTranslatef(20,10,-5);
    glutSolidSphere(2,50,50);

    glPopMatrix();

}
void day_(){
    glPushMatrix();


    glScalef(1,1,1);
    glRotatef(40,1,0,0);
    glColor3f(255,255,0 );
    glTranslatef(-10,8,-5);
    glutSolidSphere(2,50,50);

    glPopMatrix();
    colorNx=100;
    colorNy=100;
    colorNz=100;

    glPushMatrix();
    //glColor3f(0.0,0.0,100);
    //glColor3f(colorNx,colorNy,colorNz);
    glBegin(GL_POLYGON);
    glColor3f(255.0f, 255.0f, 255.0f);
    //glColor3f(0.40f, .40f, .40f);
    glVertex3f(-100,-1,0);
    glVertex3f(600,-1,0);
    glColor3f(0.0f, 0.0f, 255.0f);
    //glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(600,14,0);
    glVertex3f(-100,14,0);
    glEnd();
    glPopMatrix();
}
void night_(){
    glPushMatrix();
    glScalef(1,1,1);
    glRotatef(40,1,0,0);
    glColor3f(255,255,255 );
    glTranslatef(-8,8,-5);
    glutSolidSphere(2,50,50);
    glPopMatrix();

    colorNx=0.30;
    colorNy=0.30;
    colorNz=0.30;

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, .40f, .40f);
    glVertex3f(-100,-1,0);
    glVertex3f(600,-1,0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(600,14,0);
    glVertex3f(-100,14,0);
    glEnd();
    glPopMatrix();
}


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
    glRotatef(45.0f, 0.0f, 0.0f, 0.0f);
	glTranslatef(-5, 0.0, -45); //Move forward 5 units
    //gluLookAt(11,10.0,10.0,eyeX,eyeY,eyeZ,0.0,1.0,0.0);
    if(run==1){
    gluLookAt(_cameraAngleX,_cameraAngle,_cameraAngleY,_cameraAnglex,0.0,0.0,0.0,5.0,0.0);
    }
    else if(run==0){
        gluLookAt(0,0,3,-2.0,0.0,0.0,0.0,5.0,0.0);
    }



    glPushMatrix();

    if(night==0){
        day_();
    }
    else if(night==1){
        night_();
        //star();
    }



    glPopMatrix();

    glPushMatrix();

    glPushMatrix();

    if(run==1){
            glRotatef(20,1,0,1);
    glTranslatef(eyeX,eyeZ,eyeY);
    glScalef(0.5,0.5,0.5);
    helicupter();
    //bomb
    glPushMatrix();
    if(n==1){
            glScalef(0.2,0.2,.2);

    glTranslatef(eyeX,fire,eyeZ);
    bomb();

    } else if(m==1){
    glScalef(0.1,0.1,.1);
     glPushMatrix();
    glTranslatef(fireX-20,fireY,eyeZ);
    bomb();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(fireX-10,fireY,eyeZ);
    bomb();
    glPopMatrix();
    }

    else if(n==0){
       glTranslatef(2,-2,-0.5);
    glScalef(0.2,0.2,.2);
    bomb();
    }

    glPopMatrix();
    }else if(run==0){
        glPushMatrix();
        glTranslatef(0,0,0);
        glPushMatrix();

        glTranslatef(eyeX,0,eyeY+5);
        glScalef(0.5,0.5,0.5);
        helicupter();
    glPopMatrix();
      glPopMatrix();
    }


    glPopMatrix();


    cloud2();









    //glColor3f(0,1,0);
    if(run==1){
    glTranslatef(move_, 0.0, 0);
    }else if(run==0){
        glTranslatef(-140, 0.0, 0);
        move_=-140;
    }
    drawgrid();
    glTranslatef(10,-0.1,0.0);




    glPushMatrix();
    glTranslatef(0,4,0);
    glScalef(0.5,0.5,0.5);

    glPopMatrix();
    glPushMatrix();
    grass3();
    mountain();
    tree2();

    glPushMatrix();
    glTranslatef(100,0,10);
    for(int h=-200; h<200;h+=100){

        glPushMatrix();
        glScalef(0.2,0.2,0.2);
        glTranslatef(h,-2,10);
        house();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,0,10);
    for(int h=-200; h<200;h+=150){

        glPushMatrix();
        glScalef(0.4,0.4,0.4);
        glTranslatef(h,-2,40);
        house();
        glPopMatrix();

    }
    glPopMatrix();







      cout<<fireX<<endl;
      cout<<fireY<<endl;









	glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    if(n==1){
    if(fire>-60){
        fire-=3;
    }
    if(fire<-59){
        n=0;
        fire=-5;
    }
    }else{
        fire-=0.0;
    }

    if(m==1){
    if(fireY>-106 && fireX>-100){
        fireY-=30;
        fireX-=30;
    }
    if(fireY<-105 || fireX<-99){
        m=0;
        fireX=30;
        fireY=-5;

    }
    }else{
        fireX-=0.0;
        fireY-=0;
    }
    mov2 +=1.5f;
	_angle += 50.0f;
	if(_angle>1000){
        _angle=0;
	}
	if(n==1){
        if(fire>0){
            fire -=1;
        }
	}
	move_1 +=.7f;
	if (move_1 > 360) {
		move_1 -= 360;
	}
    if(run==1){
	if (move_>5) {
        move_-=0.3;
    }
    if (move_<160) {
        move_+=0.3;
    }


    if(eyeZ<0){
        eyeZ+=0.5;

    }
    if(eyeZ>8.5){
        eyeZ-=0.5;

    }
    if(eyeZ<5){
        eyeZ+=0.07;
    }
    if(_cameraAngle<3){
        _cameraAngle+=0.1;
    }
    if(_cameraAngleX<9.5){
        _cameraAngleX+=0.5;
    }

    if(_cameraAnglex<1){
        _cameraAnglex+=0.05;
    }
    if(_cameraAngleY<30){
        _cameraAngleY+=0.5;
    }
    }


	//if(mov2>)

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(20, update, 0);
}
void myInit()
{
    /* set up depth-buffering */
    glEnable(GL_DEPTH_TEST);

    /* turn on default lighting */
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40,1,4,20);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10.0,10.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);

}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1300, 800);

	//Create the window
	glutCreateWindow("");
	initRendering();
	myInit();
    glutTimerFunc(25, update, 0);
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);

	glutReshapeFunc(handleResize);





	//Add a timer

	glutMainLoop();
	return 0;
}
