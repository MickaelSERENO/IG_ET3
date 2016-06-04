#ifndef FINGER5_INC
#define FINGER5_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Finger5
{
	Element base;
	Position pos;
	int list;
}Finger5;

Finger5* Finger5_create(GLUquadricObj* qobj, Position pos);
void Finger5_onUpdate(Element* self);

#endif
