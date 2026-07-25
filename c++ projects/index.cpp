#include<iostream>
using namespace std;

int currentPlayer;
char currentMarker;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void drawBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << endl;
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }

    return false;
}

int winner()
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
        {
            return currentPlayer;
        }
    }

    // Columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
        {
            return currentPlayer;
        }
    }

    // Main Diagonal
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
    {
        return currentPlayer;
    }

    // Secondary Diagonal
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
    {
        return currentPlayer;
    }

    return 0;
}

void swapPlayerAndMarker()
{
    if(currentMarker == 'X')
        currentMarker = 'O';
    else
        currentMarker = 'X';

    if(currentPlayer == 1)
        currentPlayer = 2;
    else
        currentPlayer = 1;
}

void game()
{
    cout << "Player 1, choose your marker (X/O): ";
    char markerP1;
    cin >> markerP1;

    markerP1 = toupper(markerP1);

    while(markerP1 != 'X' && markerP1 != 'O')
    {
        cout << "Invalid marker. Enter X or O: ";
        cin >> markerP1;
        markerP1 = toupper(markerP1);
    }

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();

    int playerWon = 0;

    for(int i = 0; i < 9; i++)
    {
        cout << "Player " << currentPlayer
             << " (" << currentMarker << "), enter your slot (1-9): ";

        int slot;
        cin >> slot;

        if(slot < 1 || slot > 9)
        {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if(!placeMarker(slot))
        {
            cout << "Slot already occupied! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        playerWon = winner();

        if(playerWon == 1)
        {
            cout << "🎉 Player 1 Wins!\n";
            return;
        }

        if(playerWon == 2)
        {
            cout << "🎉 Player 2 Wins!\n";
            return;
        }

        swapPlayerAndMarker();
    }

    cout << "🤝 It's a Tie!\n";
}

int main()
{
    game();
    return 0;
}