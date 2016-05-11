#ifndef THIGH_INC
#define THIGH_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Knee.h"
#include <stdio.h>

typedef struct Thigh
{
	Element base;
	Position pos;
	Knee* knee;
	int list;
	
}Thigh;

Thigh* Thigh_create(GLUquadricObj* qobj, Position pos);
void Thigh_onUpdate(Element* self);

#endif
