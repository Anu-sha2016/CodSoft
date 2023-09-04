#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    char playAgain;
    do
    {
        /* code */

        int num = rand() % 100 + 1;
        int userguess;
        int attempts = 0;
        int maxattempt = 7;

        cout << "Welcome to the Game" << endl;
        cout << "I've picked a number between 1 to 100. Try to guess it." << endl;

        while (attempts < maxattempt)
        {
            cout << "Enterr your guess:";
            cin >> userguess;
            attempts++;

            if (userguess < num)
            {
                cout << "Too low! Try a higher number" << endl;
            }
            else if (userguess > num)
            {
                cout << "Too high! Try a lower." << endl;
            }
            else
            {
                cout << "Congo! You guess right number" << endl;
                break;
            }
        }
        if (attempts == maxattempt)
        {
            cout << "Sorry, you've used all attempts. The Number was" << num << "." << endl;
        }
        cout << "Do you want to play again?(y/n)" << endl;
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing" << endl;

    return 0;
}