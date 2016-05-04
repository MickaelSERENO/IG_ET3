#include "Element.h"

void Element_init(Element* this, float* defPos)
{
	this->update   = Element_update;
	this->onUpdate = NULL; //De base on a rien à afficher
	this->delete   = Element_delete;
	this->child    = NULL;
	this->nbChild  = 0;
	uint32_t i;
	for(i=0; i < 3; i++)
		this->defPos[i] = defPos[i];
}

void Element_update(Element* this)
{
	glPushMatrix();
	{
		//On dessiner le contenu de l'objet à l'écran
		if(this->onUpdate != NULL)
			this->onUpdate(this);

		//On appel la fonction update de tout les enfants
		//Cette fonction servira à leur tour de se mettre à jour et de dessiner leur contenue tout en gardant la matrice parente active (glPushMatrix)
		uint32_t i;
		for(i=0; i < this->nbChild; i++)
			if(this->child[i]->update != NULL)
				this->child[i]->update(this->child[i]);
	}
	glPopMatrix();
}

void Element_addChild(Element* this, Element* child)
{
	this->child = realloc(this->child, (this->nbChild+1) * sizeof(Element*));
	this->child[this->nbChild] = child;
	this->nbChild++;
}

void Element_delete(Element* this)
{
	uint32_t i=0;
	for(i=0; i < this->nbChild; i++)
		this->child[i]->delete(this->child[i]);
	free(this->child);
	free(this);
}
