#include <iostream>

using namespace std;

bool checkForWinner(char board[3][3]);
bool checkTie(char board[3][3]);
bool markSpot(char board[3][3], int pos, char currentPlayer);
void displayBoard(char board[3][3]);

int main(){


    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    bool gameOver = false;

    char board[3][3] = {'1', '2', '3', 
                        '4', '5', '6',
                        '7', '8', '9'
                        };
    int pos; 

    displayBoard(board);

    // while it's not true (game is not over), continue
    while(!gameOver){
        cout << currentPlayer << ", please choose a position on the board" << endl;
        cin >> pos;

        while(pos < 1 || pos >9 || cin.fail()){
            cout << "Invalid input. Try again." << endl;
            cin.clear(); // removes error flag, allows input stream to be used again
            cin.ignore(100000, '\n'); // Discards up to 100000 characters or until a newline character is encountered
            cin >> pos;
        }

        while(markSpot(board, pos, currentPlayer) != true){
            cout << "Spot already taken, try again!" << endl;
            cin >> pos;
        }

        if(checkForWinner(board) == true){
            cout << currentPlayer << " Wins!!" << endl;
            gameOver = true;
        } else if (checkTie(board)) {
            cout << "TIE!" << endl;
            gameOver = true;
        }

        displayBoard(board);

        currentPlayer = (currentPlayer == player1)? player2 : player1;

    }

    return 0;
}

void displayBoard(char board[3][3]) 
{ 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << (char)board[i][j] << " | "; 
        } 
        cout << "\n-------------\n"; 
    } 
} 

bool markSpot(char board[3][3], int pos, char currentPlayer){
    /*  let's say pos = 7, that is the 3rd row and first column, but in programming terms, it's row 2 column 0, so:
    row -> (7 - 1) / 3 = 6 / 3 = 2
    col -> (7 - 1) % 3 = 1 = 6 % 3 = 0
    board[row][column] = board[2][0]
    */
    int row = (pos-1) / 3;
    int col = (pos-1) % 3;

    if(board[row][col] == 'X' || board[row][col] == 'O'){
        return false;
    }

    board[row][col] = currentPlayer;

    return true;
}

bool checkForWinner(char board[3][3]){

    for(int i = 0; i < 3; i++){

        //check rows [0/1/2][i] and columns [i][0/1/2]
        if(board[i][0]==board[i][1] && board[i][1] == board[i][2]) {
            return true;
        } else if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]) { 
            return true;
        } else if (board[0][0]==board[1][1] && board[1][1] == board[2][2]) {
            return true;
        } else if(board[0][2]==board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }

    }

    return false;
}

bool checkTie(char board[3][3]){

    //checks if any positions on the board are empty, if so, return false
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false; 
            }
        }
    }

    return true;
}