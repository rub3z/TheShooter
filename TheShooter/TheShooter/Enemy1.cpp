#include "stdafx.h"
#include "Enemy1.h"
#include "ConstantsNStuff.h"

Enemy1::Enemy1() {
   pTexture.loadFromFile("Player.png"); 
   pSprite.setTexture(pTexture);
   pSprite.setOrigin(5, 5);
   pSprite.setScale(2, 2);
   pSprite.setColor(Color(255, 0, 0, 255));

   pAccX = 5;
   pAccY = 5;

   pMoveX = 10;
   pMoveY = 10;

   pPosition.x = 600;
   pPosition.y = 800;
}

Sprite& Enemy1::getSprite() {
   return pSprite;
}

Vector2f& Enemy1::getPosition() {
   return pPosition;
}

float Enemy1::getAccX() {
   return 5;
}

float Enemy1::getAccY() {
   return 5;
}


void Enemy1::move(float const &valX, float const &valY) {
   pMoveX = valX;
   pMoveY = valY;
}

void Enemy1::update(float& elapsedTime, Vector2f playerPos) {
   pPosition.x += pMoveX + 
      (5/(sqrt(pow(playerPos.x - pPosition.x, 2) + pow(playerPos.y - pPosition.y, 2))))
                  * ENEMY1_SPEED * elapsedTime;
   pPosition.y += pMoveY + 
      (5 / (sqrt(pow(playerPos.x - pPosition.x, 2) + pow(playerPos.y - pPosition.y, 2))))
                  * ENEMY1_SPEED * elapsedTime;
   /*pPosition.x += 2;
   pPosition.y -= 2;*/

   pSprite.setPosition(pPosition);
}
