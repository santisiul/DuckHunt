#ifndef IntroState_H
#define IntroState_H

//#include <Ogre.h>
//#include <OIS/OIS.h>

#include <CEGUI.h>
#include "GameState.h"
#include "GUI.h"

class IntroState : public Ogre::Singleton<IntroState>, public GameState
{
 public:
  IntroState() {}

  void enter ();
  void exit ();
  void pause ();
  void resume ();

  void keyPressed (const OIS::KeyEvent &e);
  void keyReleased (const OIS::KeyEvent &e);

  void mouseMoved (const OIS::MouseEvent &e);
  void mousePressed (const OIS::MouseEvent &e, OIS::MouseButtonID id);
  void mouseReleased (const OIS::MouseEvent &e, OIS::MouseButtonID id);

  bool frameStarted (const Ogre::FrameEvent& evt);
  bool frameEnded (const Ogre::FrameEvent& evt);

  // Heredados de Ogre::Singleton.
  static IntroState& getSingleton ();
  static IntroState* getSingletonPtr ();

  void createGUI();
  void destroyGUI();

  bool playGame(const CEGUI::EventArgs& e);
  bool showScore(const CEGUI::EventArgs& e);
  bool showCredits(const CEGUI::EventArgs& e);
  bool showMenu(const CEGUI::EventArgs& e);
  bool exitGame(const CEGUI::EventArgs& e);


 protected:
  Ogre::Root* _root;
  Ogre::SceneManager* _sceneMgr;
  Ogre::Viewport* _viewport;
  Ogre::Camera* _camera;

  bool _exitGame;
  // std::shared_ptr<GUI> gui;
};

#endif
