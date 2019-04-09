#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
   // Get the screen resolution and create an SFML window and View
   Vector2f resolution;
   resolution.x = 1920;
   resolution.y = 1080;
   bulletCounter = 0;
   spreadBulletCounter = 0;
   fireRateDeltaPlayer0 = 0;
   fireRateDeltaPlayer1 = 0;
   fireRateDeltaPlayer2 = 0;
   fireRateDeltaPlayer3 = 0;


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

   //player0 = Player(0);
   //player1 = Player(1);

   //RAINBOW!!!!
   //for (int i = 0; i < MAX_BULLETS; i++) {
   //   switch (i % 7) {
   //   case 0:
   //      bullets[i].getSprite().setColor(Color::Red); break;
   //   case 1:
   //      bullets[i].getSprite().setColor(Color(255, 165, 0, 255)); break;
   //   case 2:
   //      bullets[i].getSprite().setColor(Color(255, 255, 0, 255)); break;
   //   case 3:
   //      bullets[i].getSprite().setColor(Color::Green); break;
   //   case 4:
   //      bullets[i].getSprite().setColor(Color::Blue); break;
   //   case 5:
   //      bullets[i].getSprite().setColor(Color(75, 0, 130, 255)); break;
   //   case 6:
   //      bullets[i].getSprite().setColor(Color(128, 0, 128, 255)); break;
   //   default: break;
   //   }
   //}

   enemy = Enemy(2);

   for (int i = 0; i < MAX_ENEMY1; i++) {
      enemies[i] = Enemy(2);
      enemies[i].getPosition().x = i * 10;
   }

   //for (int i = 0; i < MAX_BULLETS; i++) {
   //   bullets[i].getSprite()
   //      .setColor(Color(rand()%255, rand()%255, rand()%255, 255));
   //}
   

}

void Engine::start()
{
   // Timing
   Clock clock;
   Time dt;
   dtAsSeconds = 0;
   frameTime = 0;
   float deltaTime = 0;
   float tickRate =
      0.0083333f;  // 120 ticks per second
      //0.01f; // 100 per second
      //0.0166666f; // 60 per second
      //0.02f; // 50 per second
      //0.0333333f; // 30 per second
   float accumulator = 0.0;
   int updateCount = 0;
   int drawCount = 0;

   while (m_Window.isOpen())
   {
      // Restart the clock and save the elapsed time into dt
      dt = clock.getElapsedTime();

      // Make a fraction from the delta time (frameTime)
      frameTime = dt.asSeconds() - dtAsSeconds;
      if (frameTime > 0.25) frameTime = 0.25;
      dtAsSeconds = dt.asSeconds();

      accumulator += frameTime;

      while (accumulator >= tickRate) {
         fireRateDeltaPlayer0 += tickRate;
         fireRateDeltaPlayer1 += tickRate;
         fireRateDeltaPlayer2 += tickRate;
         input();
         update(tickRate);
         accumulator -= tickRate;
         dtAsSeconds += tickRate;
         updateCount++;
      }
      draw();
      drawCount++;
      if (updateCount % 10 == 0) {
         printf("dtAsSeconds: %f Frametime: %f updateCount: %d drawCount: %d \n",
            dtAsSeconds, frameTime, updateCount, drawCount);
         printf("  Updates/Second: %f  Draws/Second: %f \n", 
            (updateCount / dtAsSeconds), (drawCount / dtAsSeconds));
      }
   }
   
}

