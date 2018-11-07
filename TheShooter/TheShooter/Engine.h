#pragma once
// This code is modified from a gamecodeschool.com tutorial:
// http://gamecodeschool.com/sfml/building-a-simple-game-engine-in-c-plus-plus/
// Thanks to John Horton on getting me started.

#pragma once
#include "Player.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Engine
{
private:

   // A regular RenderWindow.
   RenderWindow m_Window;

   // Declare a sprite and a Texture for the background.
   Sprite m_BackgroundSprite;
   Texture m_BackgroundTexture;

   // An instance of Player.
   Player player;
   Projectile bullet;

   int bulletCounter;
   int MAX_BULLETS;
   int fireRateCounter;
   int FIRE_RATE_IN_TICKS;
   Projectile bullets[100];

   float dtAsSeconds;

   float INNER_DEADZONE;
   float INPUT_MAX;


   // Private functions for internal use only.
   void input();
   void update(float& dtAsSeconds);
   void draw();

public:
   // The Engine constructor.
   Engine();

   // start will call all the private functions.
   void start();

};