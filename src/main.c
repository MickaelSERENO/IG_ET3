#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Waist.h"

#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include "global.h"

#define KEY_ESC 27
#define position_Ini 60.0
#define windowWidth 300
#define windowHeight 300

#define RED   0
#define GREEN 0
#define BLUE  0
#define ALPHA 1

#define true  1
#define false 0

Waist* waist=NULL;

//On initialise le Material
static GLfloat mat_specular[]          = { 1.0 , 1.0 , 1.0 , 1.0 };
static GLfloat mat_ambientanddiffuse[] = { 0.4, 0.4 , 0.0 , 1.0 };
static GLfloat mat_shininess[]         = { 20.0};

//On initialise la lumière (la lumière restera fixe)
static GLfloat light_position0[] = { 15.0 , 15.0 , 15.0 , 0.0 };
static GLfloat light_position1[] = { 15.0 , 15.0 , -15.0 , 0.0 };
static GLfloat ambient_light0[]  = { 0.0 , 0.0 , 0.0 , 0.0 };
static GLfloat diffuse_light0[]  = { 0.7 , 0.7 , 0.7 , 1.0 };
static GLfloat specular_light0[] = { 0.1 , 0.1 , 0.1 , 0.1 };
static GLfloat ambient_light1[]  = { 0.50 , 0.50 , 0.50 , 1.0 };
static GLfloat diffuse_light1[]  = { 0.5 , 1.0 , 1.0 , 1.0 };
static GLfloat specular_light1[] = { 0.5 , 1.0 , 1.0 , 1.0 };

float t                 = 0.f;
Anim anim               = WALK;

float delta             = 10.f;
float k                 = 0.001f;
float K                 = 0.002f;
int IdleRunning         = true;
int TraceEcran          = false;
int RangFichierStockage = 0;
float position          = position_Ini;

int Step                = 0;
int latence             = 4;

void init_scene();
void render_scene();
GLvoid initGL();
GLvoid initScene();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height); 
GLvoid window_key(unsigned char key, int x, int y); 
GLvoid window_timer(); 

int main(int argc, char **argv) 
{  
	// initialisation  des paramètres de GLUT en fonction
	// des arguments sur la ligne de commande
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	// définition et création de la fenêtre graphique
	glutInitWindowSize(windowWidth,windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Avatar animé");

	// initialisation de OpenGL et de la scène
	initGL();  
	//init_scene();
	initScene();
	
	// choix des procédures de callback pour 
	// le tracé graphique
	glutDisplayFunc(&window_display);
	// le redimensionnement de la fenêtre
	glutReshapeFunc(&window_reshape);
	// la gestion des événements clavier
	glutKeyboardFunc(&window_key);
	// fonction appelée régulièrement entre deux gestions d´événements
	glutTimerFunc(latence,&window_timer,Step);

	// la boucle prinicipale de gestion des événements utilisateur
	glutMainLoop();  

	return 1;
}

// initialisation du fond de la fenêtre graphique : noir opaque

GLvoid initGL() 
{
	// initialisation de l´éclairement

	// définition de deux source lumineuses
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light0);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light1);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	// activation de l´éclairement
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	// propriétés matérielles des objets
	// glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambientanddiffuse);
	// glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	// glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glShadeModel( GL_SMOOTH );
	glEnable(GL_COLOR_MATERIAL);

	// initialisation du fond
	glClearColor(RED, GREEN, BLUE, ALPHA);        
	// z-buffer
	glEnable(GL_DEPTH_TEST);
	
	
}

GLvoid initScene()
{
	GLUquadricObj* GLAPIENTRY qobj;
	// allocation d´une description de quadrique
	qobj = gluNewQuadric();
	// la quadrique est pleine 
	gluQuadricDrawStyle(qobj, GLU_FILL); 
	// les ombrages, s´il y en a, sont doux
	gluQuadricNormals(qobj, GLU_SMOOTH);
	
	waist = Waist_create(qobj);
}

GLvoid window_display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	render_scene();

	// trace la scène grapnique qui vient juste d'être définie
	glFlush();
}

GLvoid window_reshape(GLsizei width, GLsizei height)
{  
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -1000, 1000);
	// glFrustum(-20, 20, -20, 20, 10, 1000);
	// glScalef(10, 10, 10);

	// toutes les transformations suivantes s´appliquent au modèle de vue 
	glMatrixMode(GL_MODELVIEW);
}

// fonction de call-back pour la gestion des événements clavier

GLvoid window_key(unsigned char key, int x, int y) 
{  
	switch (key) {    
		case KEY_ESC:  
			exit(1);                    
			break; 
		case ' ':  
			if (IdleRunning) {
				glutTimerFunc(latence,NULL,Step);
				IdleRunning = false;
			} 
			else {
				glutTimerFunc(latence,&window_timer,Step);
				IdleRunning = true;
			}
			break; 
		case '+':  
			delta += 5;
			break; 
		case '-':  
			delta -= 5;
			break; 
		case 'r':
			anim = RUN;
			break;
		case 'w':
			anim = WALK;
			break;
		default:
			printf ("La touche %d n´est pas active.\n", key);
			break;
	}     
}

// fonction de call-back appelée régulièrement

GLvoid window_timer() 
{
	// On effecture une variation des angles de chaque membre
	// de l'amplitude associée et de la position médiane
	// ********* A FAIRE **************

	// On déplace la position de l'avatar pour qu'il avance
	// ********* A FAIRE **************
	switch(anim)
	{
		case WALK:
			t += 0.004;
			break;
		case RUN:
			t+= 0.020;
			break;
	}
	if(t > 1)
	{
		//anim = NOTHING;
		t=0;
	}
	glutTimerFunc(latence,&window_timer,++Step);

	glutPostRedisplay();
}

void render_scene()
{
	glLoadIdentity();
	// rotation de 90 degres autour de Ox pour mettre l'axe Oz 
	// vertical comme sur la figure
	glRotatef(-90, 1, 0, 0);

	// rotation de 160 degres autour de l'axe Oz pour faire
	// avancer l'avatar vers le spectateur
	glRotatef(-160, 0, 0, 1);
	
	glRotatef(delta, 0, 0, 1);
	if(waist != NULL)
		Element_update((Element*)waist);
	//permutation des buffers lorsque le tracé est achevé
	glutSwapBuffers();
}
