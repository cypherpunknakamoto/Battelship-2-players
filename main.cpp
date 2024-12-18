#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

// Prints the board
void printArray(`char array[10][10]) {
    for (int i = 0; i < 1; i++) {
        cout << "\t\t" << "  ";
        for (int j = 0; j < 10; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < 10; i++) {
        cout << "\t\t" << i << " ";
        for (int j = 0; j < 10; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // player 1's board
    char num1[10][10];
    
    // Player 2's board
    char num2[10][10];

    // Player 1's visible board for Player 2's hits
    char player1_visible[10][10];
    
    // Player 2's visible board for Player 1's hits
    char player2_visible[10][10];

    // declaring variables
    int bomb = 0;
    int shoot = 0;
    int all = 0;
    int x, y;
    int size;
    char direction;
    int test = 0;
    int restart = 0;
    char menu;
    int count1 = 0;
    int count2 = 0;

    // creates a blank board for player 1, 2, and the visible boards
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            num1[i][j] = '-';
            num2[i][j] = '-';
            player1_visible[i][j] = '-';
            player2_visible[i][j] = '-';
        }
    }

    int ship1, ship2, ship3;
    printArray(num1);

    // Menu function for the whole game
    while (menu != 'q') {
        cout << "\n";
        cout << "Type (a) to add new ship, (b) to see the board, (p) to play or (q) to quit:\n";
        cin >> menu;
        if (menu == 'a') {
            restart = 0;
            test = 0;
            size = 0;
            int test2 = 0;
            while (restart != 1) {
                test = 0;
                cout << "Please choose how big your ship will be (please note can not be less than 3 or greater than 5): \n";
                cin >> size;
                while (size > 5 || size < 3) {
                    cout << "Ship size does not exist please try again\n";
                    cout << "Please choose how big your ship will be (please note can not be less than 3 or greater than 5): \n";
                    cin >> size;
                }

                cout << "Please choose your X location for your ship: \n";
                cin >> x;

                cout << "Please choose your Y location for your ship: \n";
                cin >> y;

                // check for overlap
                while (num1[x][y] == 'B') {
                    cout << "Error X and y values need to be changed\n";
                    cout << "Please choose your X location for your ship: \n";
                    cin >> x;
                    cout << "Please choose your Y location for your ship: \n";
                    cin >> y;
                }
                cout << "Please choose the direction your ship will go in vertical(v) Horizontal(h): \n";
                cin >> direction;
                if (direction != 'v' && direction != 'h') {
                    while (direction != 'v' && direction != 'h') {
                        cout << "Please choose the direction your ship will go in vertical(v) Horizontal(h): \n";
                        cin >> direction;
                    }
                }

                int v = 0;

                // Controls the direction the ship will be pointing in
                if (direction == 'h') {
                    v += 1;
                    if (num1[x][y + v] == 'B') {
                        test2 += 1;
                        cout << "Error X and y values need to be changed\n";
                        cout << "Please choose your X location for your ship: \n";
                        cin >> x;
                        cout << "Please choose your Y location for your ship: \n";
                        cin >> y;
                        cout << "Please choose the direction your ship will go in vertical(v) Horizontal(h): \n";
                        cin >> direction;
                    }
                }

                if (direction == 'v') {
                    v += 1;
                    if (num1[x + v][y] == 'B') {
                        cout << "Error X and y values need to be changed\n";
                        cout << "Please choose your X location for your ship: \n";
                        cin >> x;
                        cout << "Please choose your Y location for your ship: \n";
                        cin >> y;
                        cout << "Please choose the direction your ship will go in vertical(v) Horizontal(h): \n";
                        cin >> direction;
                    }
                }

                // Tests to make sure the direction the ship is within the board and doesn't overlap another ship
                while (test != 1) {
                    if (direction == 'h') {
                        if ((y + size) > 10) {
                            cout << "Error X and y values need to be changed\n";
                            cout << "Please choose your X location for your ship: \n";
                            cin >> x;
                            cout << "Please choose your Y location for your ship: \n";
                            cin >> y;
                            cout << "Please choose the direction your ship will go in vertical(v) Horizontal(h): \n";
                            cin >> direction;
                        } else {
                            test = 1;
                        }
                    } else if (direction == 'v') {
                        if ((x + size) > 10) {
                            cout << "Error X and y values need to be changed\n";
                            cout << "Please choose your X location for your ship: \n";
                            cin >> x;
                            cout << "Please choose your Y location for your ship: \n";
                            cin >> y;
                            cout << "Please choose the direction your ship will go in vertical(v) Horizontal(h): \n";
                            cin >> direction;
                        } else {
                            test = 1;
                        }
                    }
                    if ((y + size) <= 10 && (x + size) <= 10) {
                        restart = 1;
                        test = 1;
                    }
                }

                // Part of the bomb function
                if (restart == 1) {
                    num1[x][y] = 'B';
                    for (int i = 0; i < size; i++) {
                        if (direction == 'h') {
                            num1[x][y + i] = 'B';
                        }
                        if (direction == 'v') {
                            num1[x + i][y] = 'B';
                        }
                        count1 += 1;
                    }
                }
            }
        }

        // prints the board if menu equals 'b'
        if (menu == 'b') {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            printArray(num1);
        }

        // Begins the play function of the game
        if (menu == 'p') {
            while (count1 != 0 && count2 != 0) {
                // Player 1's turn
                cout << "Player 1: Please choose your location Y location for your bomb: \n";
                cin >> y;
                cout << "Player 1: Please choose your location X location for your bomb: \n";
                cin >> x;
                while (player2_visible[x][y] == 'x') {
                    cout << "You have already fired here please choose again\n";
                    cout << "Please choose your X location for your bomb: \n";
                    cin >> x;
                    cout << "Please choose your Y location for your bomb: \n";
                    cin >> y;
                }
                shoot += 1;
                if (num2[x][y] == 'B') {
                    player2_visible[x][y] = 'x';
                    count2 -= 1;
                    cout << "You hit Player 2's ship! " << count2 << " ships remaining\n";
                } else {
                    player2_visible[x][y] = 'o';
                    cout << "You missed\n";
                }
                cout << "\n";
                printArray(player2_visible);
                cout << "\n\n";

                // Player 2's turn
                cout << "Player 2: Please choose your location Y location for your bomb: \n";
                cin >> y;
                cout << "Player 2: Please choose your location X location for your bomb: \n";
                cin >> x;
                while (player1_visible[x][y] == 'x') {
                    cout << "You have already fired here please choose again\n";
                    cout << "Please choose your X location for your bomb: \n";
                    cin >> x;
                    cout << "Please choose your Y location for your bomb: \n";
                    cin >> y;
                }
                shoot += 1;
                if (num1[x][y] == 'B') {
                    player1_visible[x][y] = 'x';
                    count1 -= 1;
                    cout << "You hit Player 1's ship! " << count1 << " ships remaining\n";
                } else {
                    player1_visible[x][y] = 'o';
                    cout << "You missed\n";
                }
                cout << "\n";
                printArray(player1_visible);
                cout << "\n\n";
            }

            if (count1 == 0) {
                cout << "Player 2 has successfully sunk all Player 1's ships\n";
            } else if (count2 == 0) {
                cout << "Player 1 has successfully sunk all Player 2's ships\n";
            }
            cout << "It took you " << shoot << " shots in total\n";
        }
    }
}
