#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int compChoose(int stones);
int userChoose(int stones);
int random1()
{
        int random1;
        random1=(rand()%(3-1+1)+1);
        return random1;
}
void Intructions()
{
        cout << "This Program plays the game of sticks with the user \n\n";
        cout << "The user starts first by entering the number of sticks\n";
        cout << "they wish to takes away (Between 1 and 3)\n";
        cout << "Then the computer will take away another amount between 1 and 3\n";
        cout << "Who ever is the last player to take the last stick looses\n";
        cout << "ENJOY!";
}
int compChoose(int stones)
{
        int choice;
        do {
                choice = (random() % 3) + 1;
        } while (stones - choice < 1);
        return choice;
}
int main ()
{
        srand((unsigned)time(NULL));
        Intructions();
        bool winner = false;
        int computeChoose;
        int stones = (rand()%(30-15+1)+15);
        cout << "Welcome to the game.  There are " << stones <<" sticks."<< endl;;

        while (!winner)
        {

                cout <<"Enter how many you would like to take away: "<< endl;
                stones -= userChoose(stones);
                cout <<"The number of sticks left is " << stones << ".\n\n" << endl;
                if (stones == 1)
                {
                        winner = true;
                        cout << "You win!" << endl;
                }
                else
                {
                        computeChoose = compChoose(stones);
                        stones -= computeChoose;
                        cout << "Computer chooses " << computeChoose << endl;
                        cout << "The number of sticks left is " << stones << ".\n\n" << endl;
                        if (stones == 1)
                        {
                                winner = true;
                                cout << "Computer wins" << endl;
                        }
                }
        }
}
int userChoose(int stones)
{
        int choice;
        cin >> choice;
        while (choice <1 || choice > 3 || stones - choice <= 0)
        {
                if (choice < 1 || choice > 3)
                {
                        cout << "Your choice must be between 1 and 3" << endl;
                        cout << "Enter another choice: " << endl;
                        cin >> choice;
                }
                else if (stones - choice <= 1)
                {
                        cout << "You must leave at least one stick" << endl;
                        cout << "Enter another choice: " << endl;
                        cin >>  choice;
                }
                return choice;
        }
        return choice;
}

