#include "IntroState.h"
#include "PlayState.h"

template<> IntroState* Ogre::Singleton<IntroState>::msSingleton = 0;

void
IntroState::enter ()
{
  _root = Ogre::Root::getSingletonPtr();

  if(_root->hasSceneManager("SceneManager")){
    _sceneMgr = _root->getSceneManager("SceneManager");
    _camera = _sceneMgr->getCamera("IntroCamera");
  }
  else{
    _sceneMgr = _root->createSceneManager(Ogre::ST_GENERIC, "SceneManager");
    _camera = _sceneMgr->createCamera("IntroCamera");
  }

  
  _camera->setPosition(Ogre::Vector3(0,20,75));
  _camera->lookAt(Ogre::Vector3(0,0,-10));
  _camera->setNearClipDistance(5);
  _camera->setFarClipDistance(10000);

  _viewport = _root->getAutoCreatedWindow()->addViewport(_camera);
  _viewport->setBackgroundColour(Ogre::ColourValue(0, 0, 0));


  _sceneMgr->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  _sceneMgr->setSkyBox(true, "skybox");



  _exitGame = false;



  
  // Se crea la GUI

  // gui = GameManager::getSingletonPtr()->gui;
  // gui = std::make_shared<GUI>(*GameManager::getSingletonPtr()->gui);
  createGUI();
  




}

void
IntroState::exit()
{
  _sceneMgr->clearScene();
  _root->getAutoCreatedWindow()->removeAllViewports();

  std::cout<<std::endl<<"IntroStater exit"<<std::endl;
  destroyGUI();
  //gui = nullptr;
}

void
IntroState::pause ()
{
}

void
IntroState::resume ()
{
}

bool
IntroState::frameStarted
(const Ogre::FrameEvent& evt) 
{
  return true;
}

bool
IntroState::frameEnded
(const Ogre::FrameEvent& evt)
{
  if (_exitGame)
    return false;
  
  return true;
}

void
IntroState::keyPressed
(const OIS::KeyEvent &e)
{
  // Transición al siguiente estado.
  // Espacio --> PlayState
  // if (e.key == OIS::KC_SPACE) {
  //   changeState(PlayState::getSingletonPtr());
  // }
}

void
IntroState::keyReleased
(const OIS::KeyEvent &e )
{
  if (e.key == OIS::KC_ESCAPE) {
    _exitGame = true;
  }
}

void
IntroState::mouseMoved
(const OIS::MouseEvent &e)
{
}

void
IntroState::mousePressed
(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
}

void
IntroState::mouseReleased
(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
}

IntroState*
IntroState::getSingletonPtr ()
{
return msSingleton;
}

IntroState&
IntroState::getSingleton ()
{ 
  assert(msSingleton);
  return *msSingleton;
}

void
IntroState::createGUI(){
  GameManager::getSingletonPtr()->gui->loadLayout("menu.layout");
  GameManager::getSingletonPtr()->gui->loadLayout("credits.layout");
  GameManager::getSingletonPtr()->gui->loadLayout("score.layout");

  GameManager::getSingletonPtr()->gui->addHooks("playButton", "menu", CEGUI::Event::Subscriber(&IntroState::playGame, this));
  GameManager::getSingletonPtr()->gui->addHooks("scoreButton","menu", CEGUI::Event::Subscriber(&IntroState::showScore, this));
  GameManager::getSingletonPtr()->gui->addHooks("creditsButton","menu", CEGUI::Event::Subscriber(&IntroState::showCredits, this));
  GameManager::getSingletonPtr()->gui->addHooks("exitButton","menu", CEGUI::Event::Subscriber(&IntroState::exitGame, this));

  GameManager::getSingletonPtr()->gui->addHooks("returnButton", "credits", CEGUI::Event::Subscriber(&IntroState::showMenu, this));
  GameManager::getSingletonPtr()->gui->addHooks("returnButton", "score", CEGUI::Event::Subscriber(&IntroState::showMenu, this));

  GameManager::getSingletonPtr()->gui->showWindow("menu");
}

void
IntroState::destroyGUI(){
  GameManager::getSingletonPtr()->gui->destroyWindow("menu");
  GameManager::getSingletonPtr()->gui->destroyWindow("credits");
  GameManager::getSingletonPtr()->gui->destroyWindow("score");
}

bool
IntroState::playGame(const CEGUI::EventArgs& e){
  changeState(PlayState::getSingletonPtr());
  return true;
}

bool
IntroState::showScore(const CEGUI::EventArgs& e){
  GameManager::getSingletonPtr()->gui->hideWindow("menu");
  GameManager::getSingletonPtr()->gui->showWindow("score");
  return true;
}

bool
IntroState::showCredits(const CEGUI::EventArgs& e){
  GameManager::getSingletonPtr()->gui->hideWindow("menu");
  GameManager::getSingletonPtr()->gui->showWindow("credits");
  return true;
}

bool
IntroState::showMenu(const CEGUI::EventArgs& e){
  GameManager::getSingletonPtr()->gui->hideWindow("score");
  GameManager::getSingletonPtr()->gui->hideWindow("credits");
  GameManager::getSingletonPtr()->gui->showWindow("menu");
  return true;
}

bool
IntroState::exitGame(const CEGUI::EventArgs& e){
  _exitGame = true;
  return true;
}