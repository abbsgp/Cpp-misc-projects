#include <iostream>

using namespace std;

bool checkForWinner(int board[3][3]);
bool checkTie(int board[3][3]);
void displayBoard(int board[3][3]);

int main(){


    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;

    int board[3][3];
    int index[9]; // position on the board
    int pos = 0; 
    int key; // user input 
    bool result; // check if winner or tie is reached

    // assign elements from the 2D array to an index position (assigned with an array value that is)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            index[pos] = board[i][j];
            pos++;
            // cout << pos << "  " << i << "  " << j << endl;
        }
    }

    cout << currentPlayer << ", please choose a value on the board to assign 'X'" << endl;

    return 0;
}

void displayBoard(int board[3][3]){
    
}

bool checkForWinner(int board[3][3]){

    for(int i = 0; i < 3; i++){

        //check rows [i][0/1/2] and columns [0/1/2][i]
        if(board[i][0]==board[i][1] && board[i][1] == board[i][2]) {
            return true;
        } else if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]) { 
            return true;
        } 

    }

    return false;
}

bool checkTie(int board[3][3]){

    //checks if any positions on the board are empty, if so, return false
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' || board[i][j] != 'O'){
                return false; 
            }
        }
    }

    return true;
}