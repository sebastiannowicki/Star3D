#include "pch.h"
#include "Bitmap.h"

Bitmap::Bitmap(int _width, int _height) 
{
    width = _width;
    height = _height;

    texture.create(width, height);     
    pixels = new sf::Uint8[width * height * 4];
    sf::Sprite tmpSprite(texture);
    sprite = tmpSprite;
    
}

Bitmap::~Bitmap()
{
    delete[] pixels;
}

void Bitmap::Clean()
{
    for (register int i = 0; i < width * height * 4; i += 4) {
        pixels[i] = 0;
        pixels[i + 1] = 0;
        pixels[i + 2] = 0;
        pixels[i + 3] = 255;
    }
}

sf::Uint8* Bitmap::GetPixels()
{
    return pixels;
}
sf::Sprite Bitmap::GetSprite() 
{
    texture.update(pixels);
    return sprite;
}

void Bitmap::DrawPixel(int x, int y, sf::Uint8 a, sf::Uint8 r, sf::Uint8 g, sf::Uint8 b)
{
    int offset = (y * width + x) * 4;
    pixels[offset] = r;
    pixels[offset + 1] = g;
    pixels[offset + 2] = b;
    pixels[offset + 3] = a;
}
