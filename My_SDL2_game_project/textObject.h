#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H
#include <SDL.h>
#include <iostream>
#include "CommonFunc.h"
#include<SDL_ttf.h>
#include <string>
const int TIME_LIMIT = 30;

class Text
{
public:
	enum TextColor
	{
		RED_TEXT = 0,
		WHITE_TEXT = 1,
		GREEN_TEXT = 2,
		PURPLE_TEXT = 3,
	};
	Text(const std::string& prefix = "") : prefix_(prefix), str_val_("") {}
	~Text();

	void SetText(const std::string& text) { str_val_ = text; }
	void SetColor(const int& type);
	void CreateGameText(TTF_Font* font, SDL_Renderer* renderer, int x, int y);
	void UpdateText(TTF_Font* font, SDL_Renderer* renderer, int x, int y, int time);
private:
	std::string str_val_ = "Time: ";
	std::string prefix_;
	SDL_Color text_color_;
	SDL_Surface* text_surface_;
};

#endif 