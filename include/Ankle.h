#ifndef ANKLE_INC
#define ANKLE_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Ankle
{
	Element base;
	Position pos;
	int list;
}Ankle;

Ankle* Ankle_create(GLUquadricObj* qobj, Position pos);
void Ankle_onUpdate(Element* self);

#endif

