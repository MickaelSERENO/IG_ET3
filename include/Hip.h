#ifndef  HIP_INC
#define  HIP_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Pelvis.h"
#include <stdio.h>

typedef struct Hip
{
	Element base;
	Pelvis* pelvis;
	int list;
}Hip;

Hip* Hip_create(GLUquadricObj* qobj);
void  Hip_onUpdate(Element* elem);

#endif
