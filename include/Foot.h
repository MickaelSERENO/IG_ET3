#ifndef FOOT_INC
#define FOOT_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Foot
{
	Element base;
	Position pos;
	int list;
}Foot;

Foot* Foot_create(GLUquadricObj* qobj, Position pos);
void Foot_onUpdate(Element* self);

#endif
