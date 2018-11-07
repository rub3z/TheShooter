#include "stdafx.h"
#include "Player.h"

Player::Player() {
   speed = 4;

   pTexture.loadFromFile("Player.png");
   pSprite.setTexture(pTexture);

   pPosition.x = 500;
   pPosition.y = 800;

}

Sprite Player::getSprite() {
   return pSprite;
}

Vector2f Player::getPosition() {
   return pPosition;
}

void Player::move(float const &valX, float const &valY) {
   pMoveX = valX;
   pMoveY = valY;
}

void Player::update(float& elapsedTime) {
   pPosition.x += pMoveX * speed * elapsedTime;
   pPosition.y += pMoveY * speed * elapsedTime;

   pSprite.setPosition(pPosition);
}
