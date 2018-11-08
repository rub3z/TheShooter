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
   fireRateDelta = 0;
   RAPID_FIRE_RATE = 0.01f;
   SPREAD_FIRE_RATE = 0.15f;

   //RAINBOW!!!!
   /*for (int i = 0; i < MAX_BULLETS; i++) {
      switch (i % 7) {
      case 0:
         bullets[i].getSprite().setColor(Color::Red); break;
      case 1:
         bullets[i].getSprite().setColor(Color(255, 165, 0, 255)); break;
      case 2:
         bullets[i].getSprite().setColor(Color(255, 255, 0, 255)); break;
      case 3:
         bullets[i].getSprite().setColor(Color::Green); break;
      case 4:
         bullets[i].getSprite().setColor(Color::Blue); break;
      case 5:
         bullets[i].getSprite().setColor(Color(75, 0, 130, 255)); break;
      case 6:
         bullets[i].getSprite().setColor(Color(128, 0, 128, 255)); break;
      default: break;
      }
   }
*/
   /*for (int i = 0; i < MAX_BULLETS; i++) {
      bullets[i].getSprite().setColor(Color(rand()%255, rand()%255, rand()%255, 255));
   }*/

   m_Window.create(VideoMode(resolution.x, resolution.y),
      "MY SHOOTER GAME WOO"
      // Comment/uncomment this line to change between
      // windowed or fullscreen mode.
      , Style::Fullscreen
   );

   m_Window.setMouseCursorVisible(false);

   // Load the background texture.
   m_BackgroundTexture.loadFromFile("background.jpg");

   // Associate the sprite with the texture.
   m_BackgroundSprite.setTexture(m_BackgroundTexture);

   INNER_DEADZONE = 20;
   INPUT_MAX = 100;
}

void Engine::start()
{
   // Timing
   Clock clock;
   Time dt;
   dtAsSeconds = 0;
   while (m_Window.isOpen())
   {
      // Restart the clock and save the elapsed time into dt
      dt = clock.restart();

      // Make a fraction from the delta time
      dtAsSeconds   += dt.asSeconds();
      fireRateDelta += dt.asSeconds();

      input(fireRateDelta);
      /* Comment out one of the two lines below to test out the difference
         between an update rate of 60x per second vs. 120x per second.*/
      if (dtAsSeconds > 0.0083333f) {
      //if (dtAsSeconds > 0.0166666f) {
         update(dtAsSeconds);
         dtAsSeconds = 0;
      }
      draw();
   }
}

