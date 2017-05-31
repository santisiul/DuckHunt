#define UNUSED_VARIABLE(x) (void)x

#include "GameManager.h"
#include "IntroState.h"
#include "PlayState.h"
#include "PauseState.h"

#include <iostream>
#include <memory>

using namespace std;

int main () {

  unique_ptr<GameManager> game = make_unique<GameManager>();
  // unique_ptr<IntroState> introState = make_unique<IntroState>();
  // unique_ptr<PlayState> playState = make_unique<PlayState>();
  // unique_ptr<PauseState> pauseState = make_unique<PauseState>();

  // GameManager* game = new GameManager();
  IntroState* introState = new IntroState();
  PlayState* playState = new PlayState();
  PauseState* pauseState = new PauseState();

  UNUSED_VARIABLE(introState);
  UNUSED_VARIABLE(playState);
  UNUSED_VARIABLE(pauseState);
    
  try
    {
      // Inicializa el juego y transición al primer estado.
      game->start(IntroState::getSingletonPtr());
    }
  catch (Ogre::Exception& e)
    {
      std::cerr << "Excepción detectada: " << e.getFullDescription();
    }
  
  // delete game;
  
  return 0;
}
