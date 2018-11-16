#include "stdafx.h"
#include "Enemy1.h"
#include "ConstantsNStuff.h"

Enemy1::Enemy1() {
   pTexture.loadFromFile("Player.png"); 
   pSprite.setTexture(pTexture);
   pSprite.setOrigin(5, 5);
   pSprite.setScale(2, 2);
   pSprite.setColor(Color(255, 0, 0, 255));

   pAccX = 0;
   pAccY = 0;

   pVelX = 0;
   pVelY = 0;

   pPosition.x = 2000;
   pPosition.y = 1000;
}

Sprite& Enemy1::getSprite() {
   return pSprite;
}

Vector2f& Enemy1::getPosition() {
   return pPosition;
}

void Enemy1::update(float& elapsedTime, Vector2f playerPos) {
   distance = sqrt(pow(playerPos.x - pPosition.x, 2) +
      pow(playerPos.y - pPosition.y, 2));
   pAccX = 0;
   pAccY = 0;
   if (distance < 300) {
      pAccX = (ENEMY1_ACCEL / distance) * (playerPos.x - pPosition.x);
      pAccY = (ENEMY1_ACCEL / distance) * (playerPos.y - pPosition.y);
      pVelX += pAccX;
      pVelY += pAccY;
   }
   else {
      pVelX = (ENEMY1_SPEED / distance) * (playerPos.x - pPosition.x) + pAccX;
      pVelY = (ENEMY1_SPEED / distance) * (playerPos.y - pPosition.y) + pAccY;
   }
   pPosition.x += pVelX;
   pPosition.y += pVelY;

   //pPosition.x += pAccX + (((float)rand() / RAND_MAX) * BULLET_SPREAD) - (BULLET_SPREAD / 2);
   //pPosition.y += pAccY + (((float)rand() / RAND_MAX) * BULLET_SPREAD) - (BULLET_SPREAD / 2);

   pSprite.setPosition(pPosition);
}
