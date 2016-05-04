#ifndef ELBOW_INC
#define ELBOW_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Forearm.h"
#include <stdio.h>


typedef struct Elbow
{
	Element base;
	Position pos;
	Forearm* forearm;
	int list;
}Elbow;

Elbow* Elbow_create(GLUquadricObj* qobj, Position pos);
void Elbow_onUpdate(Element* self);

#endif
