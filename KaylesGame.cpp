// FCAI - Programming 1 - 2022 - Assignment 2
// Program Name: Kayle's Game
// Program Description: This game begins with an arbitrary number of tokens in a single row. 
// Two players alternate turns. During a turn a player may change either one or two adjacent tokens to 10
// by position. Note that if tokens are changed from the middle of the row, then their change creates a gap 
// that divides the row to two parts. The player who changes the last token wins.
// Last Modification Date: 3/17/2022
// Author and ID and Group: Nour Wael - 20210429 - A

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

// function to make sure the user inputs right integer input
int get_int() {
    int value;
    while (true) {
        cin >> value;
        if (value < 0) {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }
        else {
            break;
        }
    }
    return value;
}

// function to show elements in a list
void showlist(list<int> g) {
    for (list<int>::iterator it = g.begin();
         it != g.end();
         it++)
        cout << *it << " ";
}

// main game
int main() {
    int arbit;
    int value;
    int num;
    int i;
    int j;
    int player;
    int win;
    string again;
    bool isPlay = true;
    list<int> gamelist;
    while (isPlay) {
        cout << "Welcome to Kayles Game!" << endl;
        cout << "Please enter an arbitrary number: ";
        value = get_int();
        list<int>::iterator it = gamelist.begin();
        for (int i = 1 ; i <= value; i++) {
            gamelist.insert(it,i%10);
        }
        cout << "Numbers are: ";
        showlist(gamelist);
        player = 1;
        win = 0; 
        while (true) {
            cout << "\nPlayer " << player << " , How many numbers do you want to remove? 1 or 2?" << endl;
            while (true) {
                num = get_int();
                if (num==1 || num==2) {
                    break;
                }
                else {
                    cout << "Error: Numbers should be 1 or 2. Please enter again." << endl;
                }
            }

            if (num==1) {
                cout << "Player " << player << " : ";
                i = get_int();
                it = gamelist.begin();
                advance(it, i-1);
                gamelist.insert(it, 10);
                gamelist.erase(it);
                showlist(gamelist);
                for (int i = 0; i <= 9; i++) {
                    bool found = (find(gamelist.begin(), gamelist.end(), i) != gamelist.end());
                    if (found == false) {
                        win = 1;
                    }
                    else {
                        win = 0;
                        break;
                    }
                }
            }

            else if (num==2) {
                while (true) {
                    cout << "Player " << player << endl;
                    cout << "Enter first number: ";
                    i = get_int();
                    cout << "Enter second number: ";
                    j = get_int();
                    if (i-j==1 || i-j==-1) {
                        break;
                    }
                    else {
                        cout << "Error: Numbers are not successive. Please enter again." << endl;
                    }
                }
                
                for (int x = i-1; x <= i; x++) {
                    it = gamelist.begin();
                    advance(it, x);
                    gamelist.insert(it, 10);
                    gamelist.erase(it);
                    it++;    
                }
                
                showlist(gamelist);

                for (int i = 0; i <= 9; i++) {
                    bool isFound = (find(gamelist.begin(), gamelist.end(), i) != gamelist.end());
                    if (isFound == false) {
                        win = 1;
                    }
                    else {
                        win = 0;
                        break;
                    }
                }
            }
                
            // check if player wins
            if (win==1) {
                cout << "\nPlayer " << player << " wins!" << endl;
                break;
            }
            // each player takes a turn
            if (player==1) {
                player = 2;
            }
            else {
                player = 1;
            }
        }
        // play again
        cout << "Play again? Yes or No?" << endl;
        cout << "Answer: ";
        cin >> again;
        if (again=="No" || again=="no")
        {
            isPlay = false;
            cout << "Thank you for playing!" << endl;
        }
    }
}
        
    
