//Write a program that reads a line from the standard input and then prints it backwards.

#include <iostream>
using namespace std;

int main(){
    
    string str;

    cout << "Write a string: ";
    cin >> str;

    for (int i = str.length(); i >= 0; i--){

        cout << str[i];

    }
}