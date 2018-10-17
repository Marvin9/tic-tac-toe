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

int main()
{
    // board in 2d array
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int i, j, p1, mark, win, a, b;
    i = 0;
    p1 = 1;//this indicates players turn
    show_board(board);

    //maximum 9 steps are required
    while(i < 9)
    {
        int row, column;
        if(p1 == 1)
        {
            cout << "\nPlayer 1.. where you want to mark your O : ";
        }
        else
        {
            cout << "\nPlayer 2.. where you want to mark your X : ";
        }
        // store the mark location
        cin >> mark;

        //if mark is our of board
        if(mark < 0 || mark > 9)
        {
            cout << "\nInvalid mark";
            continue;
        }

        // convert mark location to 2d array location
        // for example if mark is 3 then it should be in [0,2] in our array
        row = (mark-1)/3; // if mark is 3, row = (3-1)/3 = 0
        column = (mark-1)%3; // column = (3-1)%3 = 2

        //if that location is already used
        if(board[row][column] == 'X' || board[row][column] == 'O')
        {
            cout << "\nAlready marked";
            continue;
        }

        //mark the location and change the player turn
        if(p1 == 1)
        {
            board[row][column] = 'O';
            p1 = 0;
        }
        else
        {
            board[row][column] = 'X';
            p1 = 1;
        }
        show_board(board);
        char curr = board[row][column];
        // step 5(here we starts i with 0 therefore step 4) is the minimum step where either player can win
        // therefore we starts checking from step 5(i = 4)
        if(i >= 4)
        {
            // check in row
            win = check_row(board, curr, row);
            if(win == 1)
                break;

            //check in column
            win = check_column(board, curr, column);
            if(win == 1)
                break;

            //check in left diagonal only
            /* to determine whether it is located in left diagonal or not, their row and column should be equal
                00
                    11
                        22
            */
            if(row - column == 0)
            {
                win = check_left_diag(board, curr);
                if(win == 1)
                    break;
            }
            if(win == 1)
                break;

            //if row and column is 1 and 1, then it is also located in right diagonal
            /*
                        02
                    11
                20
            */
            if(row == 1 && column == 1 || (row - column == 2 || row - column == -2))
            {
                win = check_right_diag(board, curr);
            }
            if(win == 1)
                break;
        }

        //increment steps
        i++;
    }

    if(win == 1)
    {
        /*
            here if p1 is 1 then and then player 1 is winner,
            but on line no.147 we change the player value
            so the winner is vice versa.
        */
        if(p1 == 0)
            cout << "\nPlayer 1 wins";
        else
            cout << "\nPlayer 2 wins";
    }
    return 0;
}
