#include "stdafx.h"
#include "Enemy1.h"
#include "ConstantsNStuff.h"

Enemy1::Enemy1() {
   pTexture.loadFromFile("Player.png");
   pSprite.setTexture(pTexture);
   pSprite.setOrigin(5, 5);
   pSprite.setScale(2, 2);
}

Sprite& Enemy1::getSprite() {
   return pSprite;
}

Vector2f& Enemy1::getPosition() {
   return pPosition;
}

void Enemy1::move(float const &valX, float const &valY) {
   pMoveX = valX;
   pMoveY = valY;
}

void Enemy1::update(float& elapsedTime) {
   pPosition.x += pMoveX * ENEMY1_SPEED * elapsedTime;
   pPosition.y += pMoveY * ENEMY1_SPEED * elapsedTime;

   pSprite.setPosition(pPosition);
}

