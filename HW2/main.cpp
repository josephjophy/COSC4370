/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
//#include <GL/freeglut.h>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; 

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1(){
 
  // Creates a new teapot while angle is less than 360
   // 360/36 = 10 if we increment angle by 36 we should have 10 teapots by the time we complete one cycle
  for (float angle = 0; angle  < 360; angle += 36) { 
    //
    glPushMatrix();
    // Moves object to the center of the screen
    glTranslatef(0, -0.5, -2);
    // Rotate the object around the z-axis by the given radius angle
    glRotatef(angle, 0, 0, 1);
    // Translate the object along the x-axis by 2 units

    // Draws a teapot of size .3f
    glutSolidTeapot(.3f);
    
    glPopMatrix();
  }
}

void problem2(){
  //x-direction
  float x = -10; 
  //y-direction
  float y = -7;
  // z-direction
  float z = -7; 
  //stair size
  float stair_size = .8; 
  float incr = .26f; 
  int counter = 20;

  glPushMatrix();
   // rotate the scene by 180 degrees along the y-axis
  glRotatef(180, 0, 1, 0);

  
  for (int stair = 1; stair <=20; stair++){
    glPushMatrix();
    //move along x, y and z direction
    glTranslatef(x, y, z); 
    glScalef(1, stair*.5, 1); 
    glutSolidCube(stair_size); 
    glPopMatrix();
    counter--;
    // decrease the y-position and z-position for the next stair
    y += incr; 
    z += stair_size; 
    stair++;
  }
  // restore the original transformation matrix
  glPopMatrix(); 
}

void problem3() {

  
  for (int level = 0; level < 6; ++level) {
    // Calculate the horizontal offset for this row
    // (6-level) gives you the difference between the max_level and our current level
    float offset = (6 - level) * 0.6f;
    // Calculate the starting position for the first teapot in this row
    float first_teapot_offset = -offset / 2;
    // Calculate the number of teapots on this row
    int num_teapots = 6 - level;
    // Calculates the spacing between teapots on this row
    float spacing = 0.6f;
    if (num_teapots > 1) {
      spacing = offset / (num_teapots - 1);
    }

    for (int teapot = 0; teapot < num_teapots; ++teapot) {
      glPushMatrix();
      // Calculates the horizontal position of this teapot
      float teapot_offset = first_teapot_offset + teapot * spacing;
      // Calculates the vertical position of this teapot
      float y = (6 - level) * 0.6f - 6 * 0.3f;
      glTranslatef(teapot_offset, y, 0);
      //creates a teapot of size .25
      glutSolidTeapot(.25);
      glPopMatrix();
    }
  }
}

void problem4(){
  float thumb_up = 30, point_up = 15, middle_up = 0, ring_up = 35, tiny_up = 35;
  float hand_body = 90, thumb_fngr = 35, point_fngr = 10, middle_fngr = 0, ring_fngr = 60, tiny_fngr = 35;
  glClear (GL_DEPTH_BUFFER_BIT);
  glDisable(GL_LIGHTING);
  float r = 1.0f, g = 1.0f, b = 1.0f;
  glColor3f(r, g, b);
   
  // Palm of hand
  glTranslatef(0.0, 0.0, 0.0);
  glRotatef((GLfloat)hand_body, 0.0, 0.0, 5.0);
  glTranslatef(0.20, 0.5, 0.5);
  // push the current matrix
  glPushMatrix();
  glColor3f(0.8f, 0.5f, 0.2f);
  glScalef(0.75, 0.2, 1.1);
  glutSolidCube(1.0);

  // add nested matrix transformation
  glPushMatrix();
  // Add matrix transformations for equilateral triangle
  glTranslatef(-1.0, 0.0, 0.0);
  glRotatef(60.0, -1.0, -1.0, 1.0);
  glRotatef(-60.0, 1.0, -4.0, -1.0); 
  glColor3f(1.0f, 1.0f, 1.0f); 
  glBegin(GL_TRIANGLES);
  glVertex3f(0.0, 0.5, 0.0);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, -0.5, 0.0);
  glEnd();
  glPopMatrix();
  glPopMatrix();  

  
  // creates Thumb finger
  glPushMatrix();
  glTranslatef(0.0, 0.125, -0.1);
  glRotatef((GLfloat)thumb_fngr, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.8);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef(0.3, 0.2, 0.2);
  glutSolidCube(0.7);
  glPopMatrix();
  glTranslatef(0.15, 0.0, -0.8);
  glRotatef((GLfloat)thumb_up, 0.0, 0.0, 1.0); 
  glTranslatef(0.25, 0.0, 0.8);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef(0.3, 0.2, 0.2);
  glutSolidCube(0.7);
  glPopMatrix();
  glPopMatrix();

  
  //creates Index Finger
  glPushMatrix();
  glTranslatef (0.5, 0.1, 0.0);
  glRotatef ((GLfloat) point_fngr, 0.0, 0.0, 0);
  glTranslatef (0.0, 0.0, 0.4);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.3, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();
  glTranslatef (0.5, 0.0, 0.0);
  glRotatef ((GLfloat) point_up, 0.0, 0.0, 0);
  glTranslatef (0.0, 0.0, 0.0);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.3, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();       
  glPopMatrix();

  //creates Ring Finger
  glTranslatef (0.5, 0.1, 0.0);
  glRotatef ((GLfloat) ring_up, 0.0, 0.0, 8.0);
  glTranslatef (0.0, -0.1,  0.0);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.9, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  glTranslatef (0.5, 0.1, 0.1);
  glRotatef ((GLfloat) ring_fngr, 0.0, 0.0, 4.0);
  glTranslatef (0.0, 0.0, -0.4);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.7, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();

  
  //creates Middle Finger
  glPushMatrix();
  glTranslatef (0.5, 0.10, 0.0);
  glRotatef ((GLfloat) middle_fngr, 0.0, 0.0, 1.0);
  glTranslatef (0.0, 0.0, 0.0);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.3, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();
  glTranslatef (0.5, 0.0, 0.0);
  glRotatef ((GLfloat) middle_up, 0.0, 0.0, 0.5); 
  glTranslatef (0.0, 0.0, 0.0);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.5, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();
  glPopMatrix();

  
  //creates pinky finger
  glTranslatef (0.4, 0.1, 0.0);
  glRotatef ((GLfloat) tiny_up, 0.0, 0.0, 4.0);
  glTranslatef (0.0, -0.1, 0.0);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.3, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  glTranslatef (0.2, 0.1, 0.0);
  glRotatef ((GLfloat) tiny_fngr, 0.0, 0.0, 4.0);
  glTranslatef (0.0, 0.0, -0.6);
  glPushMatrix();
  glColor3f(r, g, b);
  glScalef (0.2, 0.2, 0.2);
  glutSolidCube (0.8);
  glPopMatrix();


  
  glPopMatrix();
  glutSwapBuffers();
}


void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
