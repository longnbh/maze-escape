#include "textObject.h"

Text::Text() {}

Text::~Text()
{
    if (text_surface_ != nullptr)
        SDL_FreeSurface(text_surface_);
}

void Text::SetColor(const int& type)
{
    if (type == RED_TEXT)
    {
        text_color_ = { 255, 0, 0 };
    }
    else if (type == WHITE_TEXT)
    {
        text_color_ = { 255, 255, 255 };
    }
    else
    {
        text_color_ = { 0, 0, 0 };
    }
}

void Text::CreateGameText(TTF_Font* font, SDL_Renderer* renderer, int x, int y)
{
    if (text_surface_ != nullptr)
        SDL_FreeSurface(text_surface_);

    text_surface_ = TTF_RenderText_Solid(font, str_val_.c_str(), text_color_); // create a new text surface
    if (text_surface_ == nullptr)
    {
        std::cerr << "Unable to create text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    else
    {
        SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface_);
        if (text_texture == nullptr)
        {
            std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            // Draw texture on renderer at (x,y)
            SDL_Rect renderQuad = { x, y, text_surface_->w, text_surface_->h };
            SDL_RenderCopy(renderer, text_texture, NULL, &renderQuad);
            SDL_DestroyTexture(text_texture); // Giai phong texture
        }
    }
}

void Text::UpdateText(TTF_Font* font, SDL_Renderer* renderer, int x, int y, int time)
{
    // Cập nhật văn bản với thời gian đếm ngược mới
    std::string time_str = std::to_string(time);
    SetText(time_str);
    CreateGameText(font, renderer, x, y);
}
