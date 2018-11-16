#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{

   // Rub out the last frame
   m_Window.clear(Color::White);

   // Draw the background
   m_Window.draw(m_BackgroundSprite);
   m_Window.draw(player0.getSprite());
   m_Window.draw(player1.getSprite());
   for (Projectile& p : bullets) m_Window.draw(p.getSprite());
   m_Window.draw(enemy.getSprite());

   // Show everything we have just drawn
   m_Window.display();
}