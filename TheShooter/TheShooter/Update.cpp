#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float& dtAsSeconds)
{
   player0.update(dtAsSeconds);
   player1.update(dtAsSeconds);
   for (Projectile& p : bullets) p.update(dtAsSeconds);
   enemy.update(dtAsSeconds, player0.getPosition());
}