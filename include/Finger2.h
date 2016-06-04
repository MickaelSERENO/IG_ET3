#ifndef FINGER2_INC
#define FINGER2_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Finger2
{
	Element base;
	Position pos;
	int list;
}Finger2;

Finger2* Finger2_create(GLUquadricObj* qobj, Position pos);
void Finger2_onUpdate(Element* self);

#endif
