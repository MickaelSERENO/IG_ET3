#ifndef FOREARM_INC
#define FOREARM_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Wrist.h"
#include <stdio.h>

typedef struct Forearm
{
	Element base;
	Position pos;
	Wrist* wrist;
	float defAngleWalk;
	float endAngleWalk;
	float defAngleRun;
	float endAngleRun;
	uint8_t hasStartRun;
	int list;
}Forearm;

Forearm* Forearm_create(GLUquadricObj* qobj, Position pos);
void Forearm_onUpdate(Element* self);

#endif
