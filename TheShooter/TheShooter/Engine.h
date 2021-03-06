#pragma once
// This code is modified from a gamecodeschool.com tutorial:
// http://gamecodeschool.com/sfml/building-a-simple-game-engine-in-c-plus-plus/
// Thanks to John Horton on getting me started.

#pragma once
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "ConstantsNStuff.h"
#include "RectangularBoundaryCollision.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
using namespace collision;

class Engine
{
private:

   // A regular RenderWindow.
   RenderWindow m_Window;

   // Declare a sprite and a Texture for the background.
   Sprite m_BackgroundSprite;
   Texture m_BackgroundTexture;

   // An instance of Player.
   Player player0 = Player(0);
   Player player1 = Player(1);
   Player player2 = Player(2);
   Projectile bullet;

   int bulletCounter;
   int spreadBulletCounter;
   float fireRateDeltaPlayer0;
   float fireRateDeltaPlayer1;
   float fireRateDeltaPlayer2;
   float fireRateDeltaPlayer3;
   Projectile bullets[MAX_BULLETS];

   Enemy enemy;
   Enemy enemies[MAX_ENEMY1];

   float dtAsSeconds;
   float frameTime;

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