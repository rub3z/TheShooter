#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


class Enemy1 {
   Vector2f pPosition;

   Sprite pSprite;

   Texture pTexture;

   float pVelX, pVelY;
   float pAccX, pAccY;
   float distance;

public:
   Enemy1();
   Sprite& getSprite();
   Vector2f& getPosition();
   void hit(FloatRect& other);
   void update(float& elapsedTime, Vector2f playerPos);

};