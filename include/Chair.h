#ifndef CHAIR_INC
#define CHAIR_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Chair
{
	Element base;
	int cube;
	int cylinder;
}Chair;

Chair* Chair_create(GLUquadricObj* qobj);
void Chair_onUpdate(Element* self);

#endif
