#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Projectile {
   Vector2f pPosition;

   Sprite pSprite;

   Texture pTexture;

   float pMoveX, pMoveY;

   float speed;

   float lifeTimeCounter;
   float MAX_LIFETIME;

public:
   Projectile();
   Sprite getSprite();
   void shoot(Vector2f pos, float vX, float vY);
   void update(float& elapsedTime);
};