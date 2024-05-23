#include <iostream>

using namespace std;

int main(){


    char player1 = 'x';
    char player2 = 'o';
    char currentPlayer = player1;

    int board[3][3];
    int index[9]; // position on the board
    int pos;

    // assign elements from the 2D array to an index position (assigned with an array value that is)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = index[pos];
            pos++;
            // cout << pos << "  " << i << "  " << j << endl;
        }
    }

    // cout << "   " << "|" << "   " << "|" << "   " << endl;
    // cout << "---" << "|" << "---" << "|" << "---" << endl;
    // cout << "   " << "|" << "   " << "|" << "   " << endl;
    // cout << "---" << "|" << "---" << "|" << "---" << endl;
    // cout << "   " << "|" << "   " << "|" << "   " << endl;



    return 0;
}