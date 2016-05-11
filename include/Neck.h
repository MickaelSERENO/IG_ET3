#ifndef NECK_INC
#define NECK_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Head.h"
#include <stdio.h>

typedef struct Neck
{
	Element base;
	Head* head;
	int list;
}Neck;

Neck* Neck_create(GLUquadricObj* qobj);
void Neck_onUpdate(Element* self);

#endif
