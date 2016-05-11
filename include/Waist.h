#ifndef  WAIST_INC
#define  WAIST_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Breast.h"
#include "Hip.h"
#include <stdio.h>

typedef struct Waist
{
	Element base;
	Breast* breast;
	Hip* hip;
	float defposWalk;
	float endposWalk;
	int list;
}Waist;

Waist* Waist_create(GLUquadricObj* qobj);
void  Waist_onUpdate(Element* elem);

#endif
