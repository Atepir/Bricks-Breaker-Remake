#include "graphics/Font.hpp"
#include <map>

using namespace Graphics;

SDL_Color make_color(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Color c = {r, g, b};
    return c;
}

#define WHITE make_color(0xff, 0xff, 0xff)
#define BLACK make_color(0x00, 0x00, 0x00)
#define RED make_color(0xff, 0x00, 0x00)
#define GREEN make_color(0x00, 0xff, 0x00)
#define BLUE make_color(0x00, 0x00, 0xff)
#define YELLOW make_color(0xff, 0xff, 0x00)
#define CYAN make_color(0x00, 0xff, 0xff)
#define MAGENTA make_color(0xff, 0x00, 0xff)

std::map<int, SDL_Color> colors = {
    {0, WHITE},
    {1, BLACK},
    {2, RED},
    {3, GREEN},
    {4, BLUE},
    {5, YELLOW},
    {6, CYAN},
    {7, MAGENTA}};

Font::Font(std::string text, eColor pColor) : text(text), width(100), height(10)
{
    font = defaultFont;
    std::cout << "Default font: " << defaultFont << std::endl;
    SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), colors[pColor]);
    if (surface == nullptr)
    {
        std::cout << "Surface is null" << std::endl;
    }
    SDL_Renderer *renderer = *Graphics::GraphicsManager::getInstance()->getRenderer().get();
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    std::cout << "texture: " << texture << std::endl;
    std::cout << "Width: " << width << " Height: " << height << std::endl;
    // SDL_FreeSurface(surface);
}

Font::~Font()
{
    // if (texture != nullptr)
    // SDL_DestroyTexture(texture);
}

std::string Font::getText() const
{
    return text;
}

void Font::setText(std::string text, eColor pColor)
{
    this->text = text;
    // if (texture != nullptr)
    // {
    //     SDL_DestroyTexture(texture);
    // }
    SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), colors[(int)pColor]);
    if (surface == nullptr)
    {
        std::cout << "Surface is null" << std::endl;
    }
    SDL_Renderer *renderer = *Graphics::GraphicsManager::getInstance()->getRenderer();
    texture = SDL_CreateTextureFromSurface(
        renderer, surface);
    std::cout << "texture: " << texture << std::endl;
    std::cout << "Width: " << width << " Height: " << height << std::endl;
    // SDL_FreeSurface(surface);
}

SDL_Texture *Font::getTexture() const
{
    return texture;
}

void Font::setDefaultFonts(TTF_Font *small, TTF_Font *large)
{
    defaultFont = small;
    defaultBigFont = large;
}
