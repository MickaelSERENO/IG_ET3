#ifndef CALF_INC
#define CALF_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Ankle.h"
#include <stdio.h>

typedef struct Calf
{
	Element base;
	Position pos;
	Ankle* ankle;
	int list;
	
}Calf;

Calf* Calf_create(GLUquadricObj* qobj, Position pos);
void Calf_onUpdate(Element* self);

#endif
