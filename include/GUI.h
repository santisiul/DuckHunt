#ifndef GUI_H	
#define GUI_H

#include <CEGUI.h>
#include <RendererModules/Ogre/Renderer.h>

class GUI
{
public:
	GUI();
	~GUI();
	
	void config();
	void loadLayout(const std::string& layout);
	// void cleanLayouts();
	void addHooks(const std::string& button, const std::string& layout, const CEGUI::Event::Subscriber& callback);
	void showWindow(const std::string& window);
	void hideWindow(const std::string& window);
	void destroyWindow(const std::string& window);

	CEGUI::Window* sheet;
	CEGUI::OgreRenderer* renderer;

	// std::vector<CEGUI::Window*> windows;

};
#endif