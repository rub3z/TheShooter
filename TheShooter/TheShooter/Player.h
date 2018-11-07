#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player {
   Vector2f pPosition;

   Sprite pSprite;

   Texture pTexture;

   float pMoveX, pMoveY;
   // or even a vector velocity variable if you're feeling fancy and want
   // to make your code more arcane and less readable.
   Vector2f pVelocity;

   float speed;

public:
   Player();
   Sprite getSprite(); // I like Sprite. Caffeine-free.

   Vector2f getPosition();

   void moveX(float val);

   void moveY(float val);

   void update(float& elapsedTime);

};