#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


class Enemy1 {
   Vector2f pPosition;

   Sprite pSprite;

   Texture pTexture;

   float pMoveX, pMoveY;
   float pAccX, pAccY;

public:
   Enemy1();
   Sprite& getSprite();
   Vector2f& getPosition();
   float getAccX();
   float getAccY();

   void move(float const &valX, float const &valY);

   void update(float& elapsedTime, Vector2f playerPos);

};