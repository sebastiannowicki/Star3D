#include "pch.h"
#include <SFML/Graphics.hpp>

#ifndef __BITMAP_H__
#define __BITMAP_H__

class Bitmap {
public:
    Bitmap(int width, int height);
    sf::Uint8* GetPixels();
    sf::Sprite GetSprite();
    ~Bitmap();
    void DrawPixel(int x, int y, sf::Uint8 a, sf::Uint8 r, sf::Uint8 g, sf::Uint8 b);
    void Clear();

private: 
    sf::Uint8 *pixels;
    sf::Texture texture;
    sf::Sprite sprite;
    int width;
    int height;
};

#endif