#include "stdafx.h"
#include "Projectile.h"
#include <iostream>

using namespace std;

Projectile::Projectile() {
   pTexture.loadFromFile("Player.png");
   pSprite.setTexture(pTexture);
   pSprite.setScale(0.5f, 0.5f);
   speed = 8;
   lifeTimeCounter = 0.0;
   MAX_LIFETIME = 2.0;
}

Sprite Projectile::getSprite() {
   return pSprite;
}

void Projectile::shootStraight(Vector2f& pos, float& vX, float& vY) {
   pPosition = pos;
   pMoveX = (vX / sqrtf(pow(vX, 2) + pow(vY, 2))) * 100;
   pMoveY = (vY / sqrtf(pow(vX, 2) + pow(vY, 2))) * 100;
   lifeTimeCounter = 0;
}


void Projectile::shootSpread(Vector2f& pos, float& vX, float& vY) {
   pPosition = pos;
   pMoveX = ((vX + (((float)rand() / RAND_MAX) * 10) - 5) 
            / sqrtf(pow(vX, 2) + pow(vY, 2))) * 100;
   pMoveY = ((vY + (((float)rand() / RAND_MAX) * 10) - 5) 
            / sqrtf(pow(vX, 2) + pow(vY, 2))) * 100;
   lifeTimeCounter = 0;
}

void Projectile::update(float& elapsedTime) {
   pPosition.x += pMoveX * speed * elapsedTime;
   pPosition.y += pMoveY * speed * elapsedTime;
   lifeTimeCounter += elapsedTime;
   if (lifeTimeCounter > MAX_LIFETIME) { 
      pMoveX = 0; pMoveY = 0; 
      lifeTimeCounter = 0; 
   }
   if (pMoveX == 0 && pMoveY == 0) { 
      pPosition.x = -1337; pPosition.y = -1337; }

   pSprite.setPosition(pPosition);
}