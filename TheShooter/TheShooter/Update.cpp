#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float& dtAsSeconds)
{
   player.update(dtAsSeconds);
   for (Projectile& p : bullets) p.update(dtAsSeconds);
}