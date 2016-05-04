#ifndef ARM_INC
#define ARM_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Elbow.h"
#include <stdio.h>

typedef struct Arm
{
	Element base;
	Position pos;
	Elbow* elbow;
	int list;
}Arm;

Arm* Arm_create(GLUquadricObj* qobj, Position pos);
void Arm_onUpdate(Element* self);

#endif
