#include <iostream>

using namespace std;


//to display the board
void show_board(char arr[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        if(i == 0)
            cout << endl << endl;
        for(j = 0; j < 3; j++)
        {
            if(j != 1)
                cout << "\t  " << arr[i][j] << " ";
            else
                cout << "    |    " << arr[i][j] << "    |";
        }
        cout << endl;
        cout << endl;
        if(i != 2)
            cout << "       -------------------------------";
        cout << endl;
        cout << endl;
    }
}

//to check if current player has same 'X' or 'O' in the row
int check_row(char board[3][3], char curr, int row)
{
    int win = 1, a, b;
    a = row;
    for(b = 0; b < 3; b++)
    {
        if(board[a][b] != curr)
        {
            return 0;
        }
    }
    return win;
}

//to check if current player has same 'X' or 'O' in the column
int check_column(char board[3][3], char curr, int column)
{
    int win = 1, a, b;
    b = column;
    for(a = 0; a < 3; a++)
    {
        if(board[a][b] != curr)
        {
            return 0;
        }
    }
    return win;
}

/*
*   to check if current player has same 'X' or 'O' in left diagonal
*   example
    X
        X
            X
*/
int check_left_diag(char board[3][3], char curr)
{
    int win = 1, a, b;
    for(a = 0; a < 3; a++)
    {
        if(board[a][a] != curr)
        {
            return 0;
        }
    }
    return win;
}

/*
*   to check if current player has same 'X' or 'O' in right diagonal
*   example
            X
        X
    X
*/
int check_right_diag(char board[3][3], char curr)
{
    int win = 1, a, b;
    b = 2;
    for(a = 0; a < 3; a++, b--)
    {
        if(board[a][b] != curr)
        {
            return 0;
        }
    }
    return win;
}

