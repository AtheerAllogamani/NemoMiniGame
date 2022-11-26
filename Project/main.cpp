#include <GL\glew.h>  // A cross-platform open-source C/C++ extension loading library
#include <stdlib.h>
#include <GL\freeglut.h>   // handle the window-managing operations
#include <iostream>
#include <conio.h>
#include<math.h>
#include <sstream>
#include <windows.h>
#include <MMSystem.h>

using namespace std;
//////////////////////
// Global variables //
//////////////////////
GLint win_width = 500, win_hight = 500;
GLint obj; GLuint witchTexture; 
float playerPosX, playerPosY;
float camX = -0.5;
int times;
//////////////////////

//////////////////////////
//  Background(texture) //
//////////////////////////
void background()
{
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex2f(-1.0, -1.0);
	glTexCoord2f(1, 0); glVertex2f(-1.0, 1.0);
	glTexCoord2f(1, 1); glVertex2f(1.0, 1.0);
	glTexCoord2f(0, 1); glVertex2f(1.0, -1.0);
	glEnd();
}
//////////////////////

////////////////
//   player   //
////////////////
void drawPlayer()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glTexCoord2f(0, 0); glVertex2f(-1.0, -1.0);
	glTexCoord2f(1, 0); glVertex2f(-1.0, 1.0);
	glColor3f(0.6, 0.0, 0.0);
	glTexCoord2f(1, 1); glVertex2f(1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glTexCoord2f(0, 1); glVertex2f(1.0, -1.0);
	glEnd();
}
void player() {
	glPushMatrix();
	glTranslatef(-0.8, 0.0, 0);
	glScalef(0.025, 0.08, 0.0);
	glRotated(180, 0.0, 1.0, 0.0);
	drawPlayer();
	glPopMatrix();
}
////////////////

//////////////////////

////////////////
//   Trawl    //
////////////////
void rectangleGates() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glTexCoord2f(0, 0); glVertex2f(-1.0, -1.0);
	glTexCoord2f(0, 0); glVertex2f(-1.0, 1.0);
	glTexCoord2f(1, 1); glVertex2f(1.0, 1.0);
	glColor3f(0.5, 0.6, 0.5);
	glTexCoord2f(0, 1); glVertex2f(1.0, -1.0);
	glEnd();
}
void drawGates()
{
	glPushMatrix();
	glScalef(0.2, 0.3, 0.0);
	rectangleGates();
	glPopMatrix();
}
void gates(void)
{
	////////////////////////
	//  First trawl | Up  //
	glPushMatrix();
	glScaled(0.35, 1.5, 1);
	glTranslated(-1.5, 0.5, 0);
	drawGates();
	if ((playerPosX >= 0.2 && playerPosX < 0.34) && (playerPosY >= 0.4 && playerPosY < 1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	// First trawl | Down //
	glPushMatrix();
	glScaled(0.35, 1.9, 1);
	glTranslated(-1.5, -0.3, 0);
	drawGates();
	if ((playerPosX >= 0.2 && playerPosX < 0.34) && (playerPosY >= -1 && playerPosY < 0.1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	///////////////////////

	///////////////////////
	//   2nd trawl | Up  //
	glPushMatrix();
	glScaled(0.35, 1.5, 1);
	glTranslated(-0.7, 0.4, 0);
	drawGates();
	if ((playerPosX >= 0.5 && playerPosX < 0.64) && (playerPosY >= 0.2 && playerPosY < 1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	//  2nd trawl | Down //
	glPushMatrix();
	glScaled(0.35, 1.9, 1);
	glTranslated(-0.7, -0.4, 0);
	drawGates();
	if ((playerPosX >= 0.5 && playerPosX < 0.64) && (playerPosY >= -1 && playerPosY < -0.15))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	///////////////////////
	
	///////////////////////
	//   3rd trawl | Up  //
	glPushMatrix();
	glScaled(0.35, 1.5, 1);
	glTranslated(0.1, 0.5, 0);
	drawGates();
	glPopMatrix();
	if ((playerPosX >= 0.74 && playerPosX < 0.8) && (playerPosY >= 0.4 && playerPosY < 1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	// 3rd trawl | Down  //
	glPushMatrix();
	glScaled(0.35, 1.9, 1);
	glTranslated(0.1, -0.3, 0);
	drawGates();
	if ((playerPosX >= 0.74 && playerPosX < 0.8) && (playerPosY >= -1 && playerPosY < 0.1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	///////////////////////
	
	///////////////////////
	//   4th trawl | Up  //
	glPushMatrix();
	glScaled(0.35, 1.5, 1);
	glTranslated(1.0, 0.4, 0);
	drawGates();
	if ((playerPosX >= 1.07 && playerPosX < 1.205) && (playerPosY >= 0.2 && playerPosY < 1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	//  4th trawl | Down  //
	glPushMatrix();
	glScaled(0.35, 1.9, 1);
	glTranslated(1.0, -0.4, 0);
	drawGates();
	if ((playerPosX >= 1.07 && playerPosX < 1.205) && (playerPosY >= -1 && playerPosY < -0.15))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	///////////////////////
	
	///////////////////////
	//  Last trawl | Up  //
	glPushMatrix();
	glScaled(0.35, 1.5, 1);
	glTranslated(1.8, 0.5, 0);
	drawGates();
	if ((playerPosX >= 1.35 && playerPosX < 1.4) && (playerPosY >= 0.4 && playerPosY < 1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}	
	glPopMatrix();
	//  Last trawl | Down //
	glPushMatrix();
	glScaled(0.35, 1.9, 1);
	glTranslated(1.8, -0.3, 0);
	drawGates();
	if ((playerPosX >= 1.35 && playerPosX < 1.4) && (playerPosY >= -1 && playerPosY < 0.1))
	{
		MessageBox(NULL, L"[ Looks like you're someone's dinner tonight ]", L"!!!GameOver!!!", NULL);
		exit(0);
	}
	glPopMatrix();
	///////////////////////
}
//////////////////////

///////////////////
//    Camera     //
///////////////////
void reshapeFunc(GLint new_width, GLint new_hight)
{
	/* Save the new width and height */
	win_width = 1500;
	win_hight = 500;
}
//////////////////////

///////////////////
//    Movement   //
///////////////////
void upNdown(int obj) //represent each face with a number as type
{
	if (obj == 1) 
	{
	glPushMatrix();
	glTranslatef(playerPosX, playerPosY, 0.0); 	/// auto movement
	player();
	glPopMatrix();
	}
}
void TimerFunc(int n) //works like an infinte loop
{
	playerPosX += 0.005;
	if (camX <= -0.5 && camX > -999.5) {
		camX -= 3.0;
    }
	glutTimerFunc(50, TimerFunc, n++); //glutTimerFunc: a timer callback per milliseconds (1)
	glutPostRedisplay(); //redisplay current window
}
static void keyboard(unsigned char key, int x, int y)
{
	switch (key) 
	{
	case 32: //space
		obj = 1;
		glutTimerFunc(50, TimerFunc, times);
		break;
	case 'W': case 'w':
		playerPosY += 0.1;
		break;
	case 'S': case 's':
		playerPosY -= 0.1;
		break;
	case 'Q': case 'q': case 27: //esc
		exit(0);
		break;
	}
	glutPostRedisplay();
}
//////////////////////

///////////////////
//  Print Text   //
///////////////////
void print(int x, int y, int z,const char* string)
{
	//set the position of the text in the window using the x, y and z coordinates
	glRasterPos3f(x, y, z);
	//get the length of the string to display
	int len = (int)strlen(string);
	//loop to display character by character
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
}
void textPrint()
{
	glColor3f(0.0, 0.0, 0.0);
	glScalef(1, 0.1, 1);
	glTranslatef(-0.99, 0.0, 0.0);
	glPushMatrix();
	print(0, 7, 0, "To start the game press (Space bar)");
	glPopMatrix();
	glPushMatrix();
	print(0, 6, 0, "For movement: W for Up, S for Down");
	glPopMatrix();
	glPushMatrix();
	print(0, 5, 0, "Press Esc or Q to  Quit");
	glPopMatrix();
}
//////////////////////

////////////////
//  Display   //
////////////////
void display(void)
{
	/*  Clear the image */
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* Reset the viewport... */
	glViewport(camX, 0, win_width, win_hight);
	glPushMatrix();
	background();
	//glPopMatrix();
	//witch();
	glPopMatrix();
	gates();
	glPopMatrix();
	//pipe();
	glPopMatrix();
	upNdown(obj);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
	gates();
	glPopMatrix();
	glDisable(GL_DEPTH_TEST);
	textPrint();
	glPopMatrix();
	/* Winning case */
	if ((playerPosX >= 1.7 ) && (playerPosY >= -1 && playerPosY < 1))
	{
		MessageBox(NULL, L"[ Welcome home, Nemo ]", L"!!!Congrats!!!", NULL);
		exit(0);
	}
	/////////////////
	glFlush();
	glutSwapBuffers();
}
//////////////////////

////////////////
//    Main    //
////////////////
int main(int argc, char** argv)
{
	glutInit(&argc, argv);   // Initialize GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);  //Specify the display Mode (RGBA)    
	glutInitWindowSize(win_width, win_hight);       // Set the window's initial width & height
	glutInitWindowPosition(100, 100); 	// Position the window's initial top-left corner
	glutCreateWindow("simple legancy opengl game");     // Create a window with the given title
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshapeFunc);
	//////// Audio ////////
	//PlaySound(TEXT("Sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//////////////////////
	glutPostRedisplay();
	glutMainLoop();  // Enter the infinitely event-processing loop
	return 0;
}
