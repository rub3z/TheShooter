#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


class Enemy1 {
   Vector2f pPosition;

   Sprite pSprite;

   Texture pTexture;

   float pMoveX, pMoveY;

public:
   Enemy1();
   Sprite& getSprite();
   Vector2f& getPosition();
   void move(float const &valX, float const &valY);

   void update(float& elapsedTime);

};