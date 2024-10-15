// Brij Malhotra
// hw3.cpp
// This program is the game Chutes and Ladders
// Input: Player names, prompt to roll dice
// Output: Random dice movement, players moves up or down depending on position
// Example: P1: Brij, Press 'R' to roll, R, you rolled a 6! Your new position is
//              18 as you climbed up the ladder from position 6 to 18!
//              Game stops when either player reaches position 100 first.


#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


//Function declaration

void welcome();
void goodbye();
int Dice();
int Ladders();
int Chutes();

// Welcome message

void welcome() {
  cout << "Welcome to Chutes and Ladders! Players start at 0, first to 100 wins! I hope you have fun playing and may the ";
  cout << "best player win! Have a blast :D" << endl << endl;
}

// Goodbye message

void goodbye() {
  cout << "Thanks for playing my version of Chutes and Ladders! I hope you both enjoyed!" << endl << endl;
}

// Dice roll function, it also ignores the roll if the roll goes past 100.

int Dice(int newpos)
{
  int roll;
  roll = rand() % (6 - 1 + 1) + 1;
  cout << "You rolled a " << roll << " this turn!";
  newpos += roll;

  if(newpos > 100){
    cout << "Wait for your next turn and hope you land on 100!" << endl << endl;
    newpos -= roll;
  }
  return newpos;
}

// Function to check whether player moves up the ladder

int Ladders(int newpos)
{
  if(newpos == 1)
    newpos+= 37;
  else if(newpos == 4)
    newpos += 10;
  else if(newpos == 9)
    newpos += 12;
  else if(newpos == 23)
    newpos += 21;
  else if(newpos == 28)
    newpos += 56;
  else if(newpos == 36)
    newpos += 8;
  else if(newpos == 51)
    newpos += 15;
  else if(newpos == 71)
    newpos += 19;
  else if(newpos == 80)
    newpos += 20;
  else
    return newpos;
  cout << " You get to climb up a ladder!" << endl;
  return newpos;
}

// Function to check whether player goes down with a chute

int Chutes(int newpos)
{
  if(newpos == 98 || newpos == 95 || newpos ==93)
    newpos -= 20;
  else if(newpos == 87)
    newpos -= 63;
  else if(newpos == 64)
    newpos -=4;
  else if(newpos == 62)
    newpos -= 43;
  else if(newpos == 56)
    newpos -= 3;
  else if(newpos == 49)
    newpos -= 38;
  else if(newpos == 48)
    newpos -= 22;
  else if(newpos == 16)
    newpos -=10;
  else
    return newpos;
  cout << "Uh oh!! You landed on a chute! Better luck next time..." << endl;
  return newpos;
}

int main()
{
  string p1, p2;
  char choice = 'y';

  // Welcome message

  cout << endl << endl;
  welcome();
  cout << endl << endl;

  // Starting of the game , getting the player names!

  cout << "Enter the name of Player1: ";
  getline(cin, p1);
  cout << endl;
  cout << "Enter the name of Player2: ";
  getline(cin, p2);
  cout << endl;

  // Loop for the game so that players can play again if they want to

  while(choice == 'y')
    {
      int chance = 0;

      int p1pos = 0, p2pos =0;

      while(p1pos != 100 && p2pos != 100){
        if( chance == 0){
          cout << p1 << " Your turn" << endl;
          p1pos = Dice(p1pos);
          p1pos = Ladders(p1pos);
          p1pos = Chutes(p1pos);
          cout << " You are now at: " << p1pos << endl << endl;
          chance = 1;
        } else {
          cout << endl << p2 << " Your turn" << endl;
          p2pos = Dice(p2pos);
          p2pos = Ladders(p2pos);
          p2pos = Chutes(p2pos);
          cout << " You are now at: " << p2pos << endl << endl;
          chance = 0;
        }
      }

      if(p1pos == 100){
        cout << endl << endl;
        cout << "Congratulations " << p1 << "! You won this game of Chutes and Ladders!" << endl;
      }else{
        cout << "Congratulations " << p2 << "! You won this game of Chutes and Ladders!" << endl;
      }

      cout << "If you want to play again please enter either y or n: ";
      cin >> choice;
      cout << endl << endl;
    }

  // Goodbye message

  cout << endl;
  goodbye();
  cout << endl << endl;
}
