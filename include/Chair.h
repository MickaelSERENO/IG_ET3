#ifndef CHAIR_INC
#define CHAIR_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>

#define CHAIR_POSX -9.5
#define CHAIR_POSY -2.5
#define CHAIR_SIZEX 5
#define CHAIR_SIZEY 5

typedef struct Chair
{
	Element base;
	int cube;
	int cylinder;
}Chair;

Chair* Chair_create(GLUquadricObj* qobj);
void Chair_onUpdate(Element* self);

#endif
