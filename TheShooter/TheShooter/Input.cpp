#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
   // Handle the player quitting
   if (Keyboard::isKeyPressed(Keyboard::Escape))
   {
      m_Window.close();
   }

   if (Joystick::isButtonPressed(0, 1)) {
      m_Window.close();
   }

   // Handle the player moving
   player.moveX(Keyboard::isKeyPressed(Keyboard::A) &&
      !Keyboard::isKeyPressed(Keyboard::D) ? -INPUT_MAX
      : !Keyboard::isKeyPressed(Keyboard::A) &&
      Keyboard::isKeyPressed(Keyboard::D) ? INPUT_MAX : 0);
   player.moveY(Keyboard::isKeyPressed(Keyboard::W) &&
      !Keyboard::isKeyPressed(Keyboard::S) ? -INPUT_MAX
      : !Keyboard::isKeyPressed(Keyboard::W) &&
      Keyboard::isKeyPressed(Keyboard::S) ? INPUT_MAX : 0);

   if (Joystick::isConnected(0)) {
      player.moveX(Joystick::getAxisPosition(0, Joystick::X) > INNER_DEADZONE ? Joystick::getAxisPosition(0, Joystick::X) :
         Joystick::getAxisPosition(0, Joystick::X) < -INNER_DEADZONE ? Joystick::getAxisPosition(0, Joystick::X) : 0);
      player.moveY(Joystick::getAxisPosition(0, Joystick::Y) > INNER_DEADZONE ? Joystick::getAxisPosition(0, Joystick::Y) :
         Joystick::getAxisPosition(0, Joystick::Y) < -INNER_DEADZONE ? Joystick::getAxisPosition(0, Joystick::Y) : 0);

      if (Joystick::isButtonPressed(0, 5)) {
         if (fireRateCounter++ == FIRE_RATE_IN_TICKS) {
            if (Joystick::getAxisPosition(0, Joystick::U) > 10 || Joystick::getAxisPosition(0, Joystick::U) < -10 ||
               Joystick::getAxisPosition(0, Joystick::V) > 10 || Joystick::getAxisPosition(0, Joystick::V) < -10)
               bullets[bulletCounter++].shoot(player.getPosition(),
                  Joystick::getAxisPosition(0, Joystick::U),
                  Joystick::getAxisPosition(0, Joystick::V));
            if (bulletCounter >= MAX_BULLETS) bulletCounter = 0;
            fireRateCounter = 0;
         }
      }
   }
   Joystick::update();
}