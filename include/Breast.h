#ifndef  BREAST_INC
#define  BREAST_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Shoulder.h"
#include "Neck.h"
#include <stdio.h>

typedef struct Breast
{
	Element base;
	Shoulder* leftShoulder;
	Shoulder* rightShoulder;
	Neck* neck;
	float defAngleWalk;
	float endAngleWalk;
	int list;
}Breast;

Breast* Breast_create(GLUquadricObj* qobj);
void  Breast_onUpdate(Element* elem);

#endif
