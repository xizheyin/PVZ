#include "AbstractPlant.h"




AbstractPlant::AbstractPlant(int hp,int r,int c)
	:
	Object(0,hp,r,c) 
{
	mytype = Object::Plant_t;
}
AbstractPlant::~AbstractPlant() {

}