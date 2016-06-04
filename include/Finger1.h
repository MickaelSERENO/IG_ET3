#ifndef FINGER1_INC
#define FINGER1_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Finger1
{
	Element base;
	Position pos;
	int list;
}Finger1;

Finger1* Finger1_create(GLUquadricObj* qobj, Position pos);
void Finger1_onUpdate(Element* self);

#endif
