#ifndef HAND_INC
#define HAND_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    
#include "Element.h"
#include "Finger1.h"
#include "Finger2.h"
#include "Finger3.h"
#include "Finger4.h"
#include "Finger5.h"
#include <stdio.h>

typedef struct Hand
{
	Element base;
	Position pos;
	Finger1* finger1;
	Finger2* finger2;
	Finger3* finger3;
	Finger4* finger4;
	Finger5* finger5;
	int list;
}Hand;

Hand* Hand_create(GLUquadricObj* qobj, Position pos);
void Hand_onUpdate(Element* self);

#endif
