#include <Accelerateur.h>
#include <vector>

Accelerateur::Accelerateur() 
	: TabElement(0), TabParticule(0) {}
	
vector Accelerateur::getTabElement() const {return TabElement;}
