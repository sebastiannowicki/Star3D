#include "Bitmap.h"
#include "SFML/Graphics.hpp"


#ifndef __STARS3D_H__
#define __STARS3D_H__
class Stars3D {
public:
    Stars3D(sf::RenderWindow *_window, int _numStars, float _spread, float _speed);
    ~Stars3D();
    
    void Render(Bitmap *bmp, float delta);

private:
    float Random0to1();
    void InitStar(int index);

    float spread;
    float speed;

    float* starX;
    float* starY;
    float* starZ;

    int numStars;

    sf::RenderWindow *window;
};

#endif