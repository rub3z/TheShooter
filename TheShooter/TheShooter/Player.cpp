#include "stdafx.h"
#include "Player.h"
#include "ConstantsNStuff.h"


Player::Player() {
   pTexture.loadFromFile("Player.png");
   pSprite.setTexture(pTexture);
   pSprite.setOrigin(5, 5);

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
   pPosition.x += pMoveX * PLAYER_SPEED * elapsedTime;
   pPosition.y += pMoveY * PLAYER_SPEED * elapsedTime;

   pSprite.setPosition(pPosition);
}
