#include "PlayState.h"
#include "PauseState.h"

template<> PlayState* Ogre::Singleton<PlayState>::msSingleton = 0;

void
PlayState::enter ()
{
  _root = Ogre::Root::getSingletonPtr();

  // Se recupera el gestor de escena y la cámara.
  _sceneMgr = _root->getSceneManager("SceneManager");
  _camera = _sceneMgr->getCamera("IntroCamera");
  _viewport = _root->getAutoCreatedWindow()->addViewport(_camera);
  // Nuevo background colour.
 // _viewport->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 1.0));

  _exitGame = false;

  std::cout<<std::endl<<"PlayState Enter"<<std::endl;
  //Se crea la GUI
  // if (GameManager::getSingletonPtr()->gui != nullptr)
  // {
  //   std::cout<<std::endl<<"Ptr gui null"<<std::endl;
  //   gui = GameManager::getSingletonPtr()->gui;
  // }
    // gui = std::make_shared<GUI>(GameManager::getSingletonPtr()->gui);

  createGUI();

    std::cout<<std::endl<<"PlayState Enter fin"<<std::endl;

}

void
PlayState::exit ()
{
  _sceneMgr->clearScene();
  _root->getAutoCreatedWindow()->removeAllViewports();

  destroyGUI();
}

void
PlayState::pause()
{
}

void
PlayState::resume()
{
  // Se restaura el background colour.
  _viewport->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 1.0));
}

bool
PlayState::frameStarted
(const Ogre::FrameEvent& evt)
{
  return true;
}

bool
PlayState::frameEnded
(const Ogre::FrameEvent& evt)
{
  if (_exitGame)
    return false;
  
  return true;
}

void
PlayState::keyPressed
(const OIS::KeyEvent &e)
{
  // Tecla p --> PauseState.
  if (e.key == OIS::KC_P) {
    pushState(PauseState::getSingletonPtr());
  }
}

void
PlayState::keyReleased
(const OIS::KeyEvent &e)
{
  if (e.key == OIS::KC_ESCAPE) {
    _exitGame = true;
  }
}

void
PlayState::mouseMoved
(const OIS::MouseEvent &e)
{
}

void
PlayState::mousePressed
(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
}

void
PlayState::mouseReleased
(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
}

PlayState*
PlayState::getSingletonPtr ()
{
return msSingleton;
}

PlayState&
PlayState::getSingleton ()
{ 
  assert(msSingleton);
  return *msSingleton;
}

void 
PlayState::createGUI(){
  GameManager::getSingletonPtr()->gui->loadLayout("game.layout");

  GameManager::getSingletonPtr()->gui->showWindow("game");

}

void
PlayState::destroyGUI(){
  GameManager::getSingletonPtr()->gui->destroyWindow("game");
}