#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
   KEY_W = Keyboard::isKeyPressed(Keyboard::W);
   KEY_A = Keyboard::isKeyPressed(Keyboard::A);
   KEY_S = Keyboard::isKeyPressed(Keyboard::S);
   KEY_D = Keyboard::isKeyPressed(Keyboard::D);
   KEY_ESC = Keyboard::isKeyPressed(Keyboard::Escape);

   LSTICK_X = Joystick::getAxisPosition(0, Joystick::X);
   LSTICK_Y = Joystick::getAxisPosition(0, Joystick::Y);
   RSTICK_X = Joystick::getAxisPosition(0, Joystick::U);
   RSTICK_Y = Joystick::getAxisPosition(0, Joystick::V);
   BUTTON_RB = Joystick::isButtonPressed(0, 5);
   BUTTON_LB = Joystick::isButtonPressed(0, 4);
   BUTTON_B = Joystick::isButtonPressed(0, 1);

   // Handle the player quitting
   if (KEY_ESC || BUTTON_B) m_Window.close();

   // Handle the player moving
   player.move(KEY_A && !KEY_D ? -INPUT_MAX :
                !KEY_A && KEY_D ? INPUT_MAX : 0,
               KEY_W && !KEY_S ? -INPUT_MAX : 
                !KEY_W && KEY_S ? INPUT_MAX : 0);


   if (Joystick::isConnected(0)) {
      if (LSTICK_X > INNER_DEADZONE || LSTICK_X < -INNER_DEADZONE ||
          LSTICK_Y > INNER_DEADZONE || LSTICK_Y < -INNER_DEADZONE)
         player.move(LSTICK_X, LSTICK_Y);

      if (BUTTON_RB) {
         if (fireRateCounter++ == FIRE_RATE_IN_TICKS) {
            if (RSTICK_X > 10 || RSTICK_X < -10 ||
               RSTICK_Y > 10 || RSTICK_Y < -10) {
               bullets[bulletCounter++].shootStraight(player.getPosition(),
                  RSTICK_X, RSTICK_Y);
               if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
            }
            fireRateCounter = 0;
         }
      }
      if (BUTTON_LB) {
         if (fireRateCounter++ == FIRE_RATE_IN_TICKS * 10) {
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
            fireRateCounter = 0;
         }
      }
   }
   Joystick::update();
}