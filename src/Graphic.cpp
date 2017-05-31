#include "Graphic.h"

Graphic::Graphic(const std::string& mesh, const std::string& material)
	: Graphic(mesh, material, Ogre::Root::getSingletonPtr()->getSceneManager("SceneManager")->getRootSceneNode()){}

Graphic::Graphic(const std::string& mesh, const std::string& material, Ogre::SceneNode* parent){
	Ogre::SceneManager* _sceneMgr = Ogre::Root::getSingletonPtr()->getSceneManager("SceneManager");
	Ogre::Entity* entTmp = _sceneMgr->createEntity(mesh);
	Ogre::SceneNode* nodeTmp = _sceneMgr->createSceneNode();
	entTmp->setMaterialName(material);
	nodeTmp->attachObject(entTmp);
	nodeTmp->setPosition(Ogre::Vector3(0,0,0));

	parent->addChild(nodeTmp);
	node = nodeTmp;
}

Graphic::~Graphic(){}