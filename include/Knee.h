#ifndef KNEE_INC
#define KNEE_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Calf.h"
#include <stdio.h>

typedef struct Knee
{
	Element base;
	Position pos;
	Calf* calf;
	int list;
}Knee;

Knee* Knee_create(GLUquadricObj* qobj, Position pos);
void Knee_onUpdate(Element* self);

#endif
