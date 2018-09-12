#include "pch.h"
#include "Stars3D.h"
#include "Bitmap.h"
#include <SFML/Graphics.hpp>
#include <math.h>

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
    float tanHalfFOV = (float)tan(3.1418 * 45/180);

    auto screenSize = window->getSize();
    float halfWidth = screenSize.x /2.0f;
    float hanfHeight = screenSize.y / 2.0f;
    bmp->Clear();

    for (int i = 0; i < numStars; i++)
    {
        starZ[i] -= delta * speed;

        if (starZ[i] <= 0) 
        {
            InitStar(i); 
        }

        int x = (int)(((starX[i] / (starZ[i] * tanHalfFOV)) * halfWidth) + halfWidth);
        int y = (int)(((starY[i] / (starZ[i] * tanHalfFOV)) * hanfHeight) + hanfHeight);

        if((x < 0 || x >= screenSize.x) || (y < 0 || y  >= screenSize.y))
        {
            InitStar(i);
        }
        else 
        {
            bmp->DrawPixel(x, y, 255, 255, 255, 255);
        }        
    }
}