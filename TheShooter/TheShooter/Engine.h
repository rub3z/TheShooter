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
   float fireRateDelta;
   float RAPID_FIRE_RATE;
   float SPREAD_FIRE_RATE;
   Projectile bullets[200];

   float dtAsSeconds;

   float INNER_DEADZONE;
   float INPUT_MAX;

   bool KEY_W, KEY_A, KEY_S, KEY_D, KEY_ESC;
   bool BUTTON_RB, BUTTON_LB, BUTTON_B;
   float LSTICK_X, LSTICK_Y, RSTICK_X, RSTICK_Y;


   // Private functions for internal use only.
   void input(float& dtAsSeconds);
   void update(float& dtAsSeconds);
   void draw();

public:
   // The Engine constructor.
   Engine();

   // start will call all the private functions.
   void start();

};