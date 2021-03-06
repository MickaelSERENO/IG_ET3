#ifndef HEAD_INC
#define HEAD_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Face.h"
#include "Hair.h"
#include <stdio.h>

typedef struct Head
{
	Element base;
	Face* face;
	Hair* hair;
	int list;
}Head;

Head* Head_create(GLUquadricObj* qobj);
void Head_onUpdate(Element* self);

#endif
