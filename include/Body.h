#ifndef  BODY_INC
#define  BODY_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Shoulder.h"
#include "Pelvis.h"
#include "Neck.h"
#include <stdio.h>

typedef struct Body
{
	Element base;
	Shoulder* leftShoulder;
	Shoulder* rightShoulder;
	Pelvis* pelvis;
	Neck* neck;
	int list;
}Body;

Body* Body_create(GLUquadricObj* qobj);
void  Body_onUpdate(Element* elem);

#endif
