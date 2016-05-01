#ifndef  ELEMENT_INC
#define  ELEMENT_INC

#include <stdint.h>
#include <GL/gl.h>           
#include <GL/glu.h>         
#include <GL/glut.h>    

typedef struct Element
{
	//Pointeur sur la fonction update a appeler
	void (*update)(struct Element* this);
	//Pointeur sur la fonction onUpdate a appeler
	void (*onUpdate)(struct Element* this);
	//Pointeur sur la fonction delete a appeler
	void (*delete)(struct Element* this);
	//Tableau des enfants de cet élement
	struct Element** child;
	uint32_t nbChild;
	float defPos[3];
}Element;

void Element_init(Element* this, float* defPos);
//Met à jour l'element
void Element_update(Element* this);
//Dessinera le contenu à l'écran en modifiant la matrice courante
void Element_onUpdate(Element* this);
//Ajoute un enfant à l'élement
void Element_addChild(Element* this, Element* child);
//Supprime l'élement de la mémoire;
void Element_delete(Element* this);

#endif
