#ifndef HAIR_INC
#define HAIR_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include <stdio.h>
#include "math.h"

typedef struct Hair
{
	Element base;
	int hair;
	int frange;
}Hair;

Hair* Hair_create(GLUquadricObj* qobj);
void Hair_onUpdate(Element* self);

#endif
