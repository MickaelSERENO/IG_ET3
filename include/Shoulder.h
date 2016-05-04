#ifndef SHOULDER_INC
#define SHOULDER_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>
#include "Arm.h"

typedef struct Shoulder
{
	Element base;
	Position pos;
	Arm* arm;
	int list;
}Shoulder;

Shoulder* Shoulder_create(GLUquadricObj* qobj, Position pos);
void Shoulder_onUpdate(Element* self);

#endif

