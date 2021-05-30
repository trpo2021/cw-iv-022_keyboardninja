//Вывод на экран информации различных режимов
#include "../keynlibs/mainlib.hpp"

void display_sarr(char **cstrings, int x, int snumber)
{

     system("clear");

     if (snumber < x)
     {
          cout << "\x1b[5;33m"
               << "->"
               << "\x1b[0m";
          cout << "\x1b[1;34m" << cstrings[snumber] << "\x1b[0m\n";
     }

     if (snumber < x - 2)
     {
          cout << "  next -> ";
          cout << "\x1b[1;35m" << cstrings[snumber + 1] << "\x1b[0m\n";
          cout << "  next -> "
               << "\x1b[1;35m" << cstrings[snumber + 2] << "\x1b[0m\n";
     }
     else if (snumber < x - 1)
          cout << "  next -> "
               << "\x1b[1;35m" << cstrings[snumber + 1] << "\x1b[0m\n";

     if (snumber != x)
     {
          cout << "\n\n\t\x1b[5;36m"
               << "Your Answer : "
               << "\x1b[0m\n\n";
          cout << "\x1b[5;33m"
               << "->"
               << "\x1b[0m";
     }
}

void display_results(time_t start, time_t stop, int sleeps, int fails, int sym, smode *user0)
{

     int time = difftime(stop, start) - sleeps;
     double persent_miss = count_percent_miss(fails, sym);
     double coefficient_miss = count_coefficient_miss(persent_miss);
     double speed_of_print = speed_print(sym, time);
     double score = count_score(user0, speed_of_print, coefficient_miss);

     if (persent_miss == -1)
     {
          cout << "\x1b[1;31m"
               << "ERROR: persent of miss. how did you do that?"
               << "\x1b[0m" << endl;
          return;
     }

     if (coefficient_miss == -1)
     {
          cout << "\x1b[1;31m"
               << "ERROR: persent of miss. how did you do that?"
               << "\x1b[0m" << endl;
          return;
     }
     cout << "\x1b[1;32m";
     for (int i = 0; i < 30; i++)
     {
          cout << "_";
     }
     cout << "\x1b[0m" << endl;
     cout << "\x1b[1;32m"
          << "|"
          << "\x1b[0m";
     cout << "\x1b[1;35m"
          << "Time"
          << "\x1b[0m";
     cout << "\x1b[1;32m"
          << "    |"
          << "\x1b[0m";
     cout << "\x1b[1;35m" << time << "\x1b[0m" << endl;

     cout << "\x1b[1;32m"
          << "|"
          << "\x1b[0m";
     cout << "\x1b[1;35m"
          << "Speed"
          << "\x1b[0m";
     cout << "\x1b[1;32m"
          << "   |"
          << "\x1b[0m";
     cout << "\x1b[1;35m" << speed_of_print << "\x1b[0m" << endl;

     cout << "\x1b[1;32m"
          << "|"
          << "\x1b[0m";
     cout << "\x1b[1;35m"
          << "Score"
          << "\x1b[0m";
     cout << "\x1b[1;32m"
          << "   |"
          << "\x1b[0m";
     cout << "\x1b[1;35m" << score << "\x1b[0m" << endl;

     cout << "\x1b[1;32m"
          << "|"
          << "\x1b[0m";
     cout << "\x1b[1;35m"
          << "Level"
          << "\x1b[0m";
     cout << "\x1b[1;32m"
          << "   |"
          << "\x1b[0m";
     cout << "\x1b[1;35m";

     int rang = rangs(score);
     if (rang == 1)
     {
          cout << "shinigami";
     }
     if (rang == 2)
     {
          cout << "experienced chuunin";
     }
     if (rang == 3)
     {
          cout << "squad captain";
     }
     if (rang == 4)
     {
          cout << "Plush";
     }

     if (rang == 5)
     {
          cout << "Paladin";
     }

     if (rang == 6)
     {
          cout << "NIKITA, LOG OUT!";
     }

     cout << "\x1b[0m" << endl;

     cout << "\x1b[1;32m"
          << "|"
          << "\x1b[0m";
     cout << "\x1b[1;35m"
          << "Name"
          << "\x1b[0m";
     cout << "\x1b[1;32m"
          << "    |"
          << "\x1b[0m";
     cout << "\x1b[1;35m" << user0->username << "\x1b[0m" << endl;

     cout << "\x1b[1;32m";
     for (int i = 0; i < 30; i++)
     {
          cout << "_";
     }
     cout << "\x1b[0m"
          << "\n\tPress any key to skip...\n";
     getchar();
}
