#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float& dtAsSeconds)
{
   player0.update(dtAsSeconds);
   //player1.update(dtAsSeconds);
   //player2.update(dtAsSeconds);
   
   /*for (Projectile& p : bullets) {
      p.update(dtAsSeconds);
      for (Enemy& e : enemies) {
         e.update(dtAsSeconds, player0.getPosition());
         if (areColliding(e.getSprite(), p.getSprite()))
            e.hit();
      }
   }*/
   for (Projectile& p : bullets) p.update(dtAsSeconds);
   for (Enemy& e : enemies) e.update(dtAsSeconds, player0.getPosition());
   enemy.update(dtAsSeconds, player0.getPosition());
   if (areColliding(enemy.getSprite(), player0.getSprite()))
      enemy.hit();
   //for (Projectile& p : bullets) {
   //   if (areColliding(enemy.getSprite(), p.getSprite()))
   //      enemy.hit();



}