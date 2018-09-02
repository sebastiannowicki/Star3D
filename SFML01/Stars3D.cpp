#include "pch.h"
#include "Stars3D.h"
#include "Bitmap.h"
#include <SFML/Graphics.hpp>

#include <cmath>
#include <ctime>
#include <cstdlib>

Stars3D::Stars3D(sf::RenderWindow *_window, int _numStars, float _spread, float _speed)
{
    window = _window;
    
    spread = _spread;
    speed = _speed;
    numStars = _numStars;
    starX = new float[_numStars];
    starY = new float[_numStars];
    starZ = new float[_numStars];

    for (int i = 0; i < _numStars; i++) 
    {
        InitStar(i);    
    }   
}

Stars3D::~Stars3D()
{
   delete[] starX;
   delete[] starY;
   delete[] starZ;    
}

void Stars3D::InitStar(int index) 
{
    starX[index] = ((Random0to1() - 0.5f) * 2.0f) * spread;
    starY[index] = ((Random0to1() - 0.5f) * 2.0f) * spread;
    starZ[index] = ((Random0to1()) + 0.000001f) * spread;
}

float Stars3D::Random0to1() 
{
    return (float)((((double)rand() / (RAND_MAX)) + 1) - 1);
}

void Stars3D::Render(Bitmap *bmp, float delta) 
{
    window->clear(sf::Color(0, 0, 0, 255));
    auto screenSize = window->getSize();
    float halfWidth = screenSize.x /2.0f;
    float hanfHeight = screenSize.y / 2.0f;

    for (int i = 0; i < numStars; i++)
    {
        starZ[i] -= delta * speed;

        if (starZ[i] <= 0) 
        {
            InitStar(i); 
        }

        int x = (int)((starX[i] * halfWidth) + halfWidth);
        int y = (int)((starY[i] * hanfHeight) + hanfHeight);

        if((x < 0 || x >= screenSize.x) || (y < 0 || x >= screenSize.y))
        {
            InitStar(i);
        }
        else 
        {
            bmp->DrawPixel(x, y, 255, 255, 255, 255);
        }        
    }
}