#include <GL\freeglut.h>
#include "PlayGround.h"

#define X_MATRIX_SIZE 20
#define Y_MATRIX_SIZE 20
#define SCALE 15
#define DELAY 100

PlayGround PG(X_MATRIX_SIZE, Y_MATRIX_SIZE);

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//draw grid of playground
	glColor3f(0.0, 0.3, 1.0);
	for (int i = 0; i < PG.itsSizeX; i++)
	{
		glBegin(GL_LINES);
		glVertex2f(i, 0);
		glVertex2f(i, PG.itsSizeY);
		glEnd();
	}
	for (int i = 0; i < PG.itsSizeY; i++)
	{
		glBegin(GL_LINES);
		glVertex2f(0, i);
		glVertex2f(PG.itsSizeX, i);
		glEnd();
	}


	PG.update();
	//draw matrix
	glBegin(GL_QUADS);
	for (int x = 0; x < PG.itsSizeX; x++)
		for (int y = 0; y < PG.itsSizeY; y++)
		{
			switch (PG.matrix[x][y])
			{
			case ' ':
				continue;
				break;
			case 'h':
				glColor3f(1.0, 0.0, 0.0);
				break;
			case 's':
				glColor3f(0.0, 0.0, 1.0);
				break;
			case 'f':
				glColor3f(0.0, 1.0, 0.0);
				break;
			default:
				continue;
				break;
			}
			glVertex2f(x, y);
			glVertex2f(x + 1, y);
			glVertex2f(x + 1, y + 1);
			glVertex2f(x, y + 1);
		}
	glEnd();

	glFlush();
}

void timer(int t)
{
	PG.step();
	PG.player.setTurn(false);
	glutPostRedisplay();
	glutTimerFunc(DELAY, timer, 0);
}

void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if ((PG.player.getTurn() == false) && (PG.player.getDirection() != 2))
		{
			PG.player.setDirection(0);
			PG.player.setTurn(true);
		}
		break;
	case GLUT_KEY_RIGHT:
		if ((PG.player.getTurn() == false) && (PG.player.getDirection() != 3))
		{
			PG.player.setDirection(1);
			PG.player.setTurn(true);
		}
		break;
	case GLUT_KEY_DOWN:
		if ((PG.player.getTurn() == false) && (PG.player.getDirection() != 0))
		{
			PG.player.setDirection(2);
			PG.player.setTurn(true);
		}
		break;
	case GLUT_KEY_LEFT:
		if ((PG.player.getTurn() == false) && (PG.player.getDirection() != 1))
		{
			PG.player.setDirection(3);
			PG.player.setTurn(true);
		}
		break;
	default:
		break;
	}
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(X_MATRIX_SIZE*SCALE, Y_MATRIX_SIZE*SCALE);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Snake");

	glMatrixMode(GL_PROJECTION);
	glutDisplayFunc(display);
	glutTimerFunc(DELAY, timer, 0);
	glutSpecialFunc(keyboard);
	glLoadIdentity();
	gluOrtho2D(0, X_MATRIX_SIZE, 0, Y_MATRIX_SIZE);
	glutMainLoop();
	return 0;
}