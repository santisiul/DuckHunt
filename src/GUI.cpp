#include "GUI.h"

GUI::GUI(){}
GUI::~GUI(){}

void 
GUI::config(){
	renderer = &CEGUI::OgreRenderer::bootstrapSystem();
	CEGUI::Scheme::setDefaultResourceGroup("Schemes");
	CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
	CEGUI::Font::setDefaultResourceGroup("Fonts");
	CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");

	CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");
	CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont("DejaVuSans-12");
	CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

	// Let's make the OS and the CEGUI cursor be in the same place
	CEGUI::Vector2f mousePos = CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().getPosition();  
	CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseMove(-mousePos.d_x,-mousePos.d_y);
	 
	CEGUI::FontManager::getSingleton().createAll("*.font", "Fonts");
	
	//Sheet
	sheet = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow","Ex2");

	// CEGUI::Window* win = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("menu.layout");
 //    sheet->addChild(win);
 //    win->enable();
 //    win->show();

    CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
}

void 
GUI::loadLayout(const std::string& layout){
    CEGUI::Window* win = CEGUI::WindowManager::getSingleton().loadLayoutFromFile(layout);
    sheet->addChild(win);
    win->disable();
    win->hide();
}

void
GUI::addHooks(const std::string& button, const std::string& layout, const CEGUI::Event::Subscriber& callback){
	sheet->getChild(layout)->getChild(button)->subscribeEvent(CEGUI::PushButton::EventClicked, callback);
}

void
GUI::showWindow(const std::string& window){
	CEGUI::Window* win = sheet->getChild(window);
	win->enable();
	win->show();
}

void
GUI::hideWindow(const std::string& window){
	CEGUI::Window* win = sheet->getChild(window);
	win->disable();
	win->hide();
}

void
GUI::destroyWindow(const std::string& window){
	// CEGUI::WindowManager::getSingleton().destroyWindow(window);
	sheet->destroyChild(window);
}
// void
// GUI::cleanLayouts(){
// 	for (auto win = windows.begin(); win != windows.end(); ++win)
// 	{
// 		CEGUI::WindowManager::getSingleton().destroyWindow(*win);
// 	}
// }



// Gui::addHooks( string& layout, string& button, CEGUI::Event::Suscriber& callback){
// 	sheet->getChild(layout)->getChild(button)->subscribeEvent(CEGUI::PushButton::EventClicked, callback)
// }

