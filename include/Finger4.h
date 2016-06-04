#ifndef FINGER4_INC
#define FINGER4_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Finger4
{
	Element base;
	Position pos;
	int list;
}Finger4;

Finger4* Finger4_create(GLUquadricObj* qobj, Position pos);
void Finger4_onUpdate(Element* self);

#endif
