#ifndef FACE_INC
#define FACE_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

typedef struct Face
{
	Element base;
	Position pos;
	int eye;
	int pupil;
	int nose;
	int mouth;
}Face;

Face* Face_create(GLUquadricObj* qobj);
void Face_onUpdate(Element* self);

#endif
