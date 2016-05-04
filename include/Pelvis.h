#ifndef PELVIS_INC
#define PELVIS_INC

#define PELVIS_NB_EDGE 16
#define PELVIS_RADIUS 2.5

#include <stdint.h>
#include <math.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Thigh.h"
#include <stdio.h>

typedef struct Pelvis
{
	Element base;
	int list;
	Thigh* leftThigh;
	Thigh* rightThigh;
}Pelvis;

Pelvis* Pelvis_create(GLUquadricObj* qobj);
void Pelvis_onUpdate(Element* self);

#endif
