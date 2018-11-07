#include "stdafx.h"
#include "Engine.h"


Engine::Engine()
{
   // Get the screen resolution and create an SFML window and View
   Vector2f resolution;
   resolution.x = 1920;
   resolution.y = 1080;
   bulletCounter = 0;
   MAX_BULLETS = (sizeof(bullets) / sizeof(*bullets));
   fireRateCounter = 0;
   FIRE_RATE_IN_TICKS = 10;

   m_Window.create(VideoMode(resolution.x, resolution.y),
      "Simple Game Engine");

   // Load the background into the texture
   // Be sure to scale this image to your screen size
   m_BackgroundTexture.loadFromFile("background.jpg");

   // Associate the sprite with the texture
   m_BackgroundSprite.setTexture(m_BackgroundTexture);

   INNER_DEADZONE = 20;
   INPUT_MAX = 100;
}

void Engine::start()
{
   // Timing
   Clock clock;
   Time dt;

   while (m_Window.isOpen())
   {
      // Restart the clock and save the elapsed time into dt
      dt = clock.restart();

      // Make a fraction from the delta time
      dtAsSeconds = dt.asSeconds();

      input();
      update(dtAsSeconds);
      draw();
   }
}

