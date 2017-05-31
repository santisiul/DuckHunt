#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <Ogre.h>
#include "Component.h"

class Graphic: public Component
{
public:
	Graphic(const std::string& mesh, const std::string& material);
	Graphic(const std::string& mesh, const std::string& material, Ogre::SceneNode* parent);
	~Graphic();

	Ogre::SceneNode* node;
	
};
#endif