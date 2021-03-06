// SFML01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "Bitmap.h"
#include "Stars3D.h"


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    int W = 800;
    int H = 600;
    sf::RenderWindow window(sf::VideoMode(W, H, 32), "Test");
    Bitmap *bmp = new Bitmap(W, H);
    bmp->Clear();

    sf::Clock clock;
    sf::Clock clockForDetla;

    Stars3D* star = new Stars3D(&window, 4096, 64, 20);
    
    std::srand(static_cast<unsigned int>(std::time(NULL)));
   
    window.setFramerateLimit(60);
    auto timeDelta = clockForDetla.getElapsedTime();
    sf::Int64 previousTime = timeDelta.asMicroseconds();
    sf::Int64 currentTime;
    while (window.isOpen())
    {
        timeDelta = clockForDetla.getElapsedTime();
        currentTime = timeDelta.asMicroseconds();
        float delta = (float)(currentTime - previousTime) / 1000000.f;
        previousTime = currentTime;
        auto time = clock.getElapsedTime();
        
        clock.restart();

        float framePerSecend = 1 / time.asSeconds();
        star->Render(bmp, delta);

        window.clear();
        window.draw(bmp->GetSprite());
        window.display();

        std::cout << "FPS: " << framePerSecend << std::endl;
    }
   

    return EXIT_SUCCESS;
}