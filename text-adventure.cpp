// code got deleted so ima wing it this time

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

int main()
{
  // int t = srand(time(NULL));
  srand(time(NULL));

  // intro
  std::cout << "========================\n"
            << " Welcome to the danger! \n"
            << "========================\n"
            << " Shall you test your strength or wisdom?: \n"
            << "  1) Strength\n"
            << "  2) Wisdom\n"
            << "\n";

  // user input path choice 1
  int p;
  std::cin >> p;

  switch (p)
  {
  case 1:
  {
    // red senerio
    std::cout << " You walk through a red doorway into a forest, dyed crimson. A dirt trail cuts a clean path through to the next room yet a creature stands in your way.\n"
              << "\n"
              << "How shall you proceed? \n"
              << "\n"
              << "  1) Exit\n"
              << "  2) Evade\n"
              << "  3) Engage\n"
              << "\n";

    // input r
    int r;
    std::cin >> r;

    switch (r)
    {
    case 1:
    {
      // exit
      std::cout << " You leave danger, never to return.\n";
    }
    break;
    case 2:
    {
      // evade
      // initiate 'evade' as a random number
      srand(time(NULL));
      int evade = 1 + rand() % 20;
      // debug print
      std::cout << evade;

      if (evade >= 11)
      {
        //
        std::cout << " You duck into the bushes before the creature spots you! Creeping along the underbrush, you sucessfully reach the far doorway without issue.\n"
                  << "\n"
                  << " Within this room rest 3 magical objects. What shall you do?: \n"
                  << "  1) Exit \n"
                  << "  2) Inspect \n"
                  << "  3) Take \n"
                  << "\n";
        // initiate r2
        int r2;
        std::cin >> r2;

        switch (r2)
        {
        case 1:
        {
          // exit
          std::cout << " You beome warry of traps in a room with such unprotected tresure and you have no way of uncovering them. You leave out the way you came and exit danger safely.\n";
        }
        break;
        case 2:
        {
          // inspect
          std::cout << " You reach into your bag and pull out an ancient text. Matching the symbols on the walls to the ones on the pages before you, you unravel a tale of greed and misfortune.\n"
                    << "\n"
                    << " Do you test your luck?\n"
                    << " 1) Yes     2) No\n";

          // test your luck
          int l;
          int l2;
          std::cin >> l;

          if (l == 2)
          {
            // no or other input
            std::cout << " You resist the temptation of greed and return home with peace in your heart and lint in your wallet.";
          }
          else
          {
            // yes
            l2 = 1 + rand() % 20;
            if (l2 >= 6)
            {
              // pass
              std::cout << " As you approach, your skin tingles. As you take your treasure your heart races. As you don your new armor your mind numbs. You have never been and will never be more powerful and with all that might in your hands...\n"
                        << "\n"
                        << " you can stay...  and protect the dungeon... \n"
                        << "\n"
                        << " forever\n";
            }
            else
            {
              // fail
              std::cout << " As you approach your knees buckle. You reach out our hand and the tip burns in the light. Your eyes close for the last time with greed never wavering. The ashes left in your wake blow back into the crimson forest, feeding the dungeon.\n";
            }
          }
        }
        break;
        case 3:
        {
          // take
          int l2 = 1 + rand() % 20;
          if (l2 >= 13)
          {
            // pass
            std::cout << " Your confidence leaves behind all doubt in who you are. Every step towards your goal is a declaration of your right to rule and the inevitablity of your reach. As you bask in yor victory, you hear footsteps from behind. At this moment you realize your task was never finished.\n";
          }
          else
          {
            // fail
            std::cout << " You approach the treasure confidently. You never have a single misgiving as you extend your hand, and the hand passes through. You turn to see yourself, face down in the dirt. Light fades from the world, and so does your confidence.\n";
          }
        }
        break;
        }
      }
      else
      {
        // evade fail
        std::cout << " You leap into the brush to your left, making a light ruffling noise as you do. It only takes a moment for you to right yourself, and as you take your first steps a hand gentley tightens around your neck. Before you can blink you have a CRUNCH as the world tilts to one side. You cannot move, realizing you will never move again. \n"
                  << "\n";
      }
    }
    break;
    case 3:
    {
      // engage
      std::cout << " Tightening the strap on your shield and drawing your sword, you ready yourself for battle: \n" << "\n";

      // battle game. monster health, your health, loop for battle, nat 20 = auto win
      int m_health = 100; // monster health
      int p_health = 50;      // player health

      for (;m_health > 0 && p_health > 0;)
      {
        int ad;           //attack or dodge
        int at;           //attack
        int dg;           //dodge
        //int cp_health;      //current player health
        //int cm_health;      //current monster health
        //fight machanic
        //std::cout << p_health << "   " << m_health;
        std::cout << " Will you:   1) Attack   or  2) Dodge \n" << "\n";
        std::cin >> ad;

        if (ad == 1)                  //attack
        {
          at = 1 + (rand() % 20);
          int dam;
          if (at >= 10)
          {
            dam = (5 + rand() % 25);   //hit
            m_health -= dam;
            std::cout << " You land a blow on the monster, carving chunks away as ash flies through the air. \n" << " The monster before you has only " << m_health << " health left.\n" << "\n";
          } else {
            dam = (1 + rand() % 10);   //miss
            p_health -= dam;
            std::cout << " You swing wide, leaving yourself open to a strike. Blood drips from your wounds. \n" << " You have only " << p_health << " health left.\n" << "\n";
          }
        } else if (ad == 2){          //dodge
          dg = 1 + (rand() % 20);
          int dam;
          if (dg >= 5)
          {
            dam = (0 + rand() % 5);    //good dodge
            m_health -= dam;
            std::cout << " You watch as your opponent's blade whistles past your nose. Turning as you step forward, your blade finds flesh only for ash to burst forth. \n" << " The monster before you has only " << m_health << " health left.\n" << "\n"; 
          } else {
            dam = (1 + rand() % 10);   //bad dodge
            p_health -= dam;
            if (p_health < 0)
            {
              p_health == 0; 
            }
            std::cout << " You do not move swiftly enough. You opponent's blade catches up to you. \n" << " You have only " << p_health << " health left." << "\n";
          }
        } else {
          std::cout << " You hesitate yet your opponent does not. As you fall the face of a hero, lost to time, gazes down on you in pitty. \n" << "\n";
          p_health == 0;
        }
      }

      if (m_health <= 0)
      {
        //if player wins fight
        std::cout << " Swiftly dodging strikes and countering with your own, your opponent is no match for you. With a brutal trust your blade's destination is inevitable. As the monster fades into ash, rellief rests on the face of an old hero. \n"
                  << "\n"
                  << " You march your haggard body into the next room where you see 3 treasures. Do you approach? \n"
                  << " 1) Yes     2) No \n"
                  << "\n";
        int c;
        std::cin >> c;

        // final decision
        if (c == 2)
        {
          // no
          std::cout << " Your eyes gaze at the prize ahead yet your heart turn towards home. Without taking another glance at the wealth and power you've shed blood for, you begin the long walk home." << "\n";
        }
        else
        {
          // anything but no
          std::cout << " Your strength paves your path. Your every step is conquest. Your word is law. Donning the crown, only now does the thrown show itself before you. The seat fit your rear perfectly, as if destined to rest there.\n" << "\n";
        }
      }

      if (p_health <= 0)
      {
        // player death
        std::cout << " Your blocks fail, your sword arm falters, your knees buckle. You stare into the distance, at the last doorway, as a sword parts your head from your body. \n" << "\n";
      }
    }
    }
    break;
  }
  case 2:
  {
    std::cout << " You look to your left and see ash. You look to your left and see bone. In front of your lies a doorway, painted as crimson as blood. Using your greater wisdom, you turn around and go home. Money and power cannot help the dead. \n" << "\n";
  }
  }
}