#ifndef WRIST_INC
#define WRIST_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Wrist
{
	Element base;
	Position pos;
	int list;
}Wrist;

Wrist* Wrist_create(GLUquadricObj* qobj, Position pos);
void Wrist_onUpdate(Element* self);

#endif

