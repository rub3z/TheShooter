#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
   // Get the screen resolution and create an SFML window and View
   Vector2f resolution;
   resolution.x = 1920;
   resolution.y = 1080;
   bulletCounter = 0;
   fireRateDeltaPlayer0 = 0;
   fireRateDeltaPlayer1 = 0;


   m_Window.create(VideoMode(resolution.x, resolution.y),
      "MY SHOOTER GAME WOO"
      // Comment/uncomment this line to change between
      // windowed or fullscreen mode.
      //, Style::Fullscreen
   );

   m_Window.setMouseCursorVisible(false);

   // Load the background texture.
   m_BackgroundTexture.loadFromFile("background.jpg");

   // Associate the sprite with the texture.
   m_BackgroundSprite.setTexture(m_BackgroundTexture);

   player0 = Player(0);
   player1 = Player(1);

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
   }*/

   /*for (int i = 0; i < MAX_BULLETS; i++) {
      bullets[i].getSprite()
         .setColor(Color(rand()%255, rand()%255, rand()%255, 255));
   }*/
   

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
      fireRateDeltaPlayer0 += dt.asSeconds();
      fireRateDeltaPlayer1 += dt.asSeconds();

      input();
      /* Comment out two of the three if statements below to compare 
         update rates of 30x vs. 60x vs. 120x per second.*/

      //if (dtAsSeconds > 0.0083333f) { // 120 ticks per second
      if (dtAsSeconds > 0.0166666f) { // 60 per second
      //if (dtAsSeconds > 0.0333333f) { // 30 per second
         update(dtAsSeconds);
         dtAsSeconds = 0;
      }
      draw();
   }
   /*Note: we may only be calling the update function 30/60/120 times per
      second, but we are continuously processing input and drawing to the
      screen. This way, the update rate of in-game objects remains consistent
      across systems running it; while ensuring that we are using the most
      up-to-date input; and drawing the picture as many times as the system
      can do so. Thus, we have achieved VARIABLE FRAMERATE!!! WOOHOO!!!
   */
}

