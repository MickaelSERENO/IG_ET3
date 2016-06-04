#ifndef FINGER3_INC
#define FINGER3_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Finger3
{
	Element base;
	Position pos;
	int list;
}Finger3;

Finger3* Finger3_create(GLUquadricObj* qobj, Position pos);
void Finger3_onUpdate(Element* self);

#endif
