//Write a program that will act as a guessing game in which the user has eight tries to
//guess a randomly generated number. The program will tell the user each time whether
//he guessed high or low.
//test

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

    int randed, guessed;
    bool guess = 0;

    //initializing random seed
    srand(time(NULL));
    randed = rand(); 

    for (int i = 0; i < 8; i++){

        cout << "Turn " << i+1 << ": " << "guess a number: " << endl;
        cin >> guessed; 

        if (randed == guessed){
            cout << "You won!" << endl;
            return 0;
        } else if (randed < guessed){
            cout << "Too much" << endl;
        } else {
            cout << "Too less" << endl;
        }
    }

    cout << "You lose :(" << endl << "The number was: " << randed << endl;
    return 0;
}