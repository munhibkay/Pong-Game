#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>

using namespace std;


int score1 = 0;
int score2 = 0;
int streak1 = 0;
int streak2 = 0;
int difficulty;
char boundary = -37;


void gotoRowColumn(int rowpos, int colpos) {

    COORD screen;
    HANDLE h_Output = GetStdHandle(STD_OUTPUT_HANDLE);

    screen.X = colpos;
    screen.Y = rowpos;

    SetConsoleCursorPosition(h_Output, screen);
}


void draw_bar_boundaries(int bar1, int bar2, int bar3, int bar4) {

    gotoRowColumn(0, 0);

    int boundary_width = 24;
    int boundary_length = 90;
    int Bar_length = 4;
    char wall = -37;

    for (int i = 0; i < boundary_width; i++) {
        for (int j = 0; j < boundary_length; j++) {

            if (i == 0 || i == boundary_width - 1 || j == 0 || j == boundary_length - 1) {
                cout << wall;
            }
            else {
                cout << " ";
            }

            if (j == 3 && i >= bar1 && i <= bar2) {

                gotoRowColumn(i, j);

                cout << wall;

            }

            if (j == 86 && i >= bar3 && i <= bar4) {

                gotoRowColumn(i, j);

                cout << wall;
            }
        }

        cout << endl;
    }
}

void bar_ball_move(char ball, int bar1, int bar2, int bar3, int bar4) {

    /*int bar1 = 9;
    int bar2 = 13;
    int bar3 = 9;
    int bar4 = 13;
    char ball = 'o';*/
    

    int ballpos_i = 24 / 2;
    int ballpos_j = 90 / 2;
    int direction_i = 1;
    int direction_j = -1;

    int playagain;

    gotoRowColumn(bar1, 3);
    cout << boundary;
    
    gotoRowColumn(bar2, 86);
    cout << boundary;

    while (true) {

        if (score1 == 5 || score2 == 5)
        {
            gotoRowColumn(0, 0);

            cout << "Do you want to play again?" << endl;
            cout << "1- Yes " << endl;
            cout << "2- No " << endl;
            cin >> playagain;

            if (playagain == 1) {
                score1 = 0;
                score2 = 0;

                system("ClS");

                cout << "Select Difficulty: " << endl;
                cout << "1- Easy" << endl;
                cout << "2- Medium" << endl;
                cout << "3- Hard" << endl;
                cout << "4- Expert" << endl;

                cin >> difficulty;

                gotoRowColumn(4, 100);
                cout << "Player 1" << " "<<boundary<<" " << "Player 2";
                
                gotoRowColumn(5, 100);
                cout << "     " << score1 << "   "<< boundary <<" " << "    " << score2;

                gotoRowColumn(7, 100);
                cout << "** WINNING STREAK **";
                gotoRowColumn(8, 100);
                cout << "     " << streak1 << "   "<< boundary <<" " << "    " << streak2;

                draw_bar_boundaries(9, 13, 9, 13);
                bar_ball_move('o', 9, 13, 9, 13);
            }
            
            else if (playagain == 2) {
                break;
            }

            else {

                cout << "I consider that as a no :) BYE!";
                break;
            }
        }

        
        if (_kbhit()) {
           
            char control = _getch();
           
            
            if (control == 'I' || control == 'i' && bar3 > 1) {
                gotoRowColumn(bar3 - 1, 86);
                cout << boundary;
                bar3--;
                
                gotoRowColumn(bar4, 86);
                cout << " ";
                bar4--; 
            }
           
            if (control == 'K' || control == 'k' && bar3 < 18) {
                gotoRowColumn(bar4 + 1, 86);
                cout << boundary;
                bar4++;

                gotoRowColumn(bar3, 86);
                cout << " ";
                bar3++; 
            }

            if (control == 'W' || control == 'w' && bar1 > 1) {

                gotoRowColumn(bar1 - 1, 3);
                cout << boundary;
                bar1--;

                gotoRowColumn(bar2, 3);
                cout << " ";
                bar2--;
            }

            if (control == 'S' || control == 's' && bar1 < 18) {
                gotoRowColumn(bar2 + 1, 3);
                cout << boundary;
                bar2++;

                gotoRowColumn(bar1, 3);
                cout << " ";
                bar1++;
            }
        }
        
        
        if (difficulty == 1) {
            Sleep(80);
        }
        else if (difficulty == 2) {
            Sleep(60);

        }
        else if (difficulty == 3) {
            Sleep(40);

        }
        else if (difficulty == 4) {
            Sleep(20);

        }

        
        gotoRowColumn(ballpos_i, ballpos_j);
        cout << " ";

        ballpos_i = ballpos_i + direction_i;
        ballpos_j = ballpos_j + direction_j;
        
        gotoRowColumn(ballpos_i, ballpos_j);
        cout << ball;

        if (ballpos_i == 22 || ballpos_i == 1) {
            direction_i = -direction_i;
        }

        
        if (ballpos_j == 1) {

            system("CLS");
            score2++;

            gotoRowColumn(4, 100);
            cout << "Player 1" << " " << boundary << " " << "Player 2";
           
            if (score2 == 5)
            {
                streak2++;
                gotoRowColumn(10, 40);
                {
                    cout << "PLAYER 2 WINS!";
                    break;
                }
            }
            
            gotoRowColumn(5, 100);
            cout << "     " << score1 << "   " << boundary << " " << "    " << score2;

            gotoRowColumn(7, 100);
            cout << "** WINNING STREAK **";
            gotoRowColumn(8, 100);
            cout << "     " << streak1 << "   " << boundary << " " << "    " << streak2;
            
            draw_bar_boundaries(9, 13, 9, 13);
            bar_ball_move('o', 9, 13, 9, 13);

        }
        
        
        if (ballpos_j == 88) {

            system("CLS");
            score1++;
            
            gotoRowColumn(4, 100);
            cout << "Player 1" << " " << boundary << " " << "Player 2";

            gotoRowColumn(5, 100);
            cout << "     " << score1 << "   " << boundary << " " << "    " << score2;

            gotoRowColumn(7, 100);
            cout << "** WINNING STREAK **";
            gotoRowColumn(8, 100);
            cout << "     " << streak1 << "   " << boundary << " " << "    " << streak2;

            if (score1 == 5)
            {
                streak1++;
                gotoRowColumn(10, 40);
                {
                    cout << "PLAYER 1 WINS!";
                    break;
                }
            }
            draw_bar_boundaries(9, 13, 9, 13);
            bar_ball_move('o', 9, 13, 9, 13);

        }

        
        if (ballpos_j == 4 && ballpos_i >= bar1 && ballpos_i <= bar2) {
            direction_j = -direction_j;
        }

        if (ballpos_j == 85 && ballpos_i >= bar3 && ballpos_i <= bar4) {
            direction_j = -direction_j;
        }
    }
}


int main() {
    
    int bar1 = 9;
    int bar2 = 13;
    int bar3 = 9;
    int bar4 = 13;
    char ball = 'o';
    
    cout << "Select Difficulty: " << endl;
    cout << "1- Easy" << endl;
    cout << "2- Medium" << endl;
    cout << "3- Hard" << endl;
    cout << "4- Expert" << endl;

    cin >> difficulty;

    gotoRowColumn(4, 100);
    cout << "Player 1" << " "<< boundary <<" " << "Player 2";
    
    gotoRowColumn(5, 100);
    cout << "     " << score1 << "   "<< boundary <<" " << "    " << score2;
    
    gotoRowColumn(7, 100);
    cout << "** WINNING STREAK **";
    gotoRowColumn(8, 100);
    cout << "     " << streak1 << "   "<< boundary <<" " << "    " << streak2;
    
    draw_bar_boundaries(bar1, bar2, bar3, bar4);
    bar_ball_move(ball, bar1, bar2, bar3, bar4);

    return 0;
}
