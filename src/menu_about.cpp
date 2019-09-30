#include "menu_about.h"

MenuAbout::MenuAbout():
	Menu("About")
{
		idea = Screen::getTextSurface(Screen::getLargeFont(), "idea: Toro Iwatani - Namco", Constants::GRAY_COLOR);
		coding = Screen::getTextSurface(Screen::getLargeFont(), "coding: Martin Prussak", Constants::GRAY_COLOR);
		coding2 = Screen::getTextSurface(Screen::getLargeFont(), "         Daniel Wuerfel", Constants::GRAY_COLOR);
		coding3 = Screen::getTextSurface(Screen::getLargeFont(), "Nintendo Switch Port: KranK", Constants::GRAY_COLOR);
		addMenuItem("back");
}
MenuAbout::~MenuAbout() {
	SDL_FreeSurface(idea);
	SDL_FreeSurface(coding);
	SDL_FreeSurface(coding2);
	SDL_FreeSurface(coding3);
}

void MenuAbout::draw(bool updateAll) {
	Screen::getInstance()->clear();
	drawTitle();
	drawMenuItems();
	Screen::getInstance()->draw(idea, 320 - (idea->w >> 1), 200 - (idea->h >> 1));
	Screen::getInstance()->draw(coding, 320 - (coding->w >> 1), 270 - (coding->h >> 1));
	Screen::getInstance()->draw(coding2, 320 - (coding2->w >> 1), 310 - (coding2->h >> 1));
	Screen::getInstance()->draw(coding3, 320 - (coding3->w >> 1), 350 - (coding3->h >> 1));
	if (updateAll)
		Screen::getInstance()->addUpdateClipRect();
	Screen::getInstance()->Refresh();
}

int MenuAbout::handleSelection() {
	return selection == BACK ? 2 : 0;
}
