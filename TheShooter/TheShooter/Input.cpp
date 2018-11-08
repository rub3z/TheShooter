#include "stdafx.h"
#include "Engine.h"

void Engine::input(float& dtAsSeconds)
{
   // Get the latest state of keyboard input.
   KEY_W =   Keyboard::isKeyPressed(Keyboard::W);
   KEY_A =   Keyboard::isKeyPressed(Keyboard::A);
   KEY_S =   Keyboard::isKeyPressed(Keyboard::S);
   KEY_D =   Keyboard::isKeyPressed(Keyboard::D);
   KEY_ESC = Keyboard::isKeyPressed(Keyboard::Escape);

   // Get the latest state of gamepad input.
   LSTICK_X =  Joystick::getAxisPosition(0, Joystick::X);
   LSTICK_Y =  Joystick::getAxisPosition(0, Joystick::Y);
   RSTICK_X =  Joystick::getAxisPosition(0, Joystick::U);
   RSTICK_Y =  Joystick::getAxisPosition(0, Joystick::V);
   BUTTON_RB = Joystick::isButtonPressed(0, 5);
   BUTTON_LB = Joystick::isButtonPressed(0, 4);
   BUTTON_B =  Joystick::isButtonPressed(0, 1);

   // Player can quit by pressing ESC or B button on pad.
   if (KEY_ESC || BUTTON_B) m_Window.close();

   // Keyboard movement.
   player.move(KEY_A && !KEY_D ? -INPUT_MAX :
                !KEY_A && KEY_D ? INPUT_MAX : 0,
               KEY_W && !KEY_S ? -INPUT_MAX : 
                !KEY_W && KEY_S ? INPUT_MAX : 0);

   // Gamepad movement (which is obviously much better).
   if (Joystick::isConnected(0)) {
      if (LSTICK_X > INNER_DEADZONE || LSTICK_X < -INNER_DEADZONE ||
          LSTICK_Y > INNER_DEADZONE || LSTICK_Y < -INNER_DEADZONE)
         player.move(LSTICK_X, LSTICK_Y);

      // Rapid fire with RB.
      if (BUTTON_RB) {
         if (fireRateDelta >= RAPID_FIRE_RATE) {
            if (RSTICK_X > 10 || RSTICK_X < -10 ||
               RSTICK_Y > 10 || RSTICK_Y < -10) {
               bullets[bulletCounter++].shootStraight(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
            }
            fireRateDelta = 0;
         }
      }
      // Spreadshot with LB. Repeats the same 3 lines 10 times.
      // Silly, but it works and it's not like there's much that can be done 
      // to improve it in terms of runtime.
      if (BUTTON_LB) {
         if (fireRateDelta >= SPREAD_FIRE_RATE) {
            if (RSTICK_X > 10 || RSTICK_X < -10 ||
               RSTICK_Y > 10 || RSTICK_Y < -10) {
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
               bullets[bulletCounter++].shootSpread(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;

            }
            fireRateDelta = 0;
         }
      }
   }
   Joystick::update();
}