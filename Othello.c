#include <stdio.h>
void processing_moves(int possible_places[][8], char board[][8], char player); //harja ke +1 gozashtam yani az khune badi check kone dige ghaedatan
void proper_move(char board[][8], char player, int possible_places[][8] , int *x , int *y);
void biggest(int copy_of_board[][8] , int *x , int *y);


int main(int argc, char *argv[])
{
    // argv , board , possible_places

    char board[8][8];
    char player;
    int possible_places[8][8];
    int x , y;
    // initializing possible_places to zero
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            possible_places[i][j] = 0;
        }
    }

    // initializing the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = argv[i + 1][j];
            // printf("%2c", board[i][j]) ;
        }
        // printf("\n");
    }

    player = argv[9][0];

    processing_moves(possible_places, board, player);
    proper_move(board , player , possible_places , &x , &y) ;

    for (int i = 0; i < 8; ++i)
    {
        // putchar('@') ;
        for (int j = 0; j < 8; ++j)
        {
            // putchar('#') ;
            if (possible_places[i][j] == 1)
                board[i][j] = 'A';

            printf("%2c", board[i][j]);
        }

        printf("\n");
    }
    return 0;

}

void processing_moves(int possible_places[][8], char board[][8], char player)
{
    char component;
    if (player == '1')
        component = '2';
    else
        component = '1';

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == player) //residim be khuneye range man
            {

                //horizontal - rightside
                /* in alan mire az khuneye badio check mikone age khali bashe ke break! age khali nabud
                    va rangesh mokhaalef bud khunehaye badisham check mikone bebine bade una jaye khali has ya na
                    un jaye khalio too possible places 1 mizare */
                if (board[i][j + 1] == component) //residim be khuneye range mokhaalef
                {
                    for (int x = j + 2; x < 8; ++x)
                    {
                        if (board[i][x] == '0')
                            possible_places[i][x] = 1;
                        if (board[i][x] != component)
                            break;
                    }
                }

                //horizontal - leftside
                if (board[i][j - 1] == component) //residim be khuneye range mokhaalef
                {
                    for (int x = j - 2; x >= 0; --x)
                    {
                        if (board[i][x] == '0')
                            possible_places[i][x] = 1;
                        if (board[i][x] != component)
                            break;
                    }
                }

                //vertical - downside
                if (board[i + 1][j] == component) //residim be khuneye range mokhaalef
                {
                    for (int x = i + 2; x < 8; ++x)
                    {
                        if (board[x][j] == '0')
                            possible_places[x][j] = 1;
                        if (board[x][j] != component)
                            break;
                    }
                }

                //vertical - upside
                if (board[i - 1][j] == component) //residim be khuneye range mokhaalef
                {
                    for (int x = i - 2; x < 8; --x)
                    {
                        if (board[x][j] == '0')
                            possible_places[x][j] = 1;
                        if (board[x][j] != component)
                            break;
                    }
                }

                //diagonal check
                if (board[i + 1][j + 1] == component)
                {
                    int x = i + 2, y = j + 2;
                    while (x < 8 && y < 8)
                    {
                        if (board[x][y] != component)
                            break;

                        if (board[x][y] == '0')
                        {
                            possible_places[x][y] = 1;
                            break;
                        }
                        ++x;
                        ++y;
                    }
                }

                else if (board[i - 1][j - 1] == component)
                {
                    int x = i - 2, y = j - 2;
                    while (x >= 0 && y >= 0)
                    {
                        if (board[x][y] != component)
                            break;
                        if (board[x][y] == '0')
                        {
                            possible_places[x][y] = 1;
                            break;
                        }
                        --x;
                        --y;
                    }
                }

                if (board[i + 1][j - 1] == component)
                {
                    int x = i + 2, y = j - 2;
                    while (x < 8 && y >= 0)
                    {
                        if (board[x][y] != component)
                            break;
                        if (board[x][y] == '0')
                        {
                            possible_places[x][y] = 1;
                            break;
                        }
                        ++x;
                        --y;
                    }
                }

                if (board[i - 1][j + 1] == component)
                {
                    int x = i - 2, y = j + 2;
                    while (y < 8 && x >= 0)
                    {
                        if (board[x][y] != component)
                            break;
                        if (board[x][y] == '0')
                        {
                            possible_places[x][y] = 1;
                            break;
                        }
                        ++y;
                        --x;
                    }
                }
            }
        }
    }
}

void proper_move(char board[][8], char player, int possible_places[][8], int *x, int *y)
{
    int weight[8][8] = {{16.16, -3.03, 0.99, 0.43, 0.43, 0.99, -3.03, 16.16},
                        {-4.12, -1.81, -0.08, -0.27, -0.27, -0.08, -1.81, -4.12},
                        {1.33, -0.04, 0.51, 0.07, 0.07, 0.51, -0.04, 1.33},
                        {0.63, -0.18, -0.04, -0.01, -0.01, -0.04, -0.18, 0.63},
                        {0.63, -0.18, -0.04, -0.01, -0.01, -0.04, -0.18, 0.63},
                        {1.33, -0.04, 0.51, 0.07, 0.07, 0.51, -0.04, 1.33},
                        {-4.12, -1.81, -0.08, -0.27, -0.27, -0.08, -1.81, -4.12},
                        {16.16, -3.03, 0.99, 0.43, 0.43, 0.99, -3.03, 16.16}};

    //jahaye dorosto vase positione alan darim

    int copy_of_board[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (possible_places[i][j] == 0)
            {
                copy_of_board[i][j] = -100;
            }
            else if (possible_places[i][j] == 1)
            {
                copy_of_board[i][j] = weight[i][j];
            }
        }
    }
    biggest(copy_of_board , x , y);
}


void sort(int copy_of_board[][8], int *x , int *y)
{
    int biggest = copy_of_board[0][0];

    for(int i=0 ; i<8 ; ++i)
        for(int j=0 ; j<8 ; ++j)
                if(copy_of_board[i][j] > biggest)
                    {
                        if(copy_of_board[i][j] == -100)
                            continue ;

                        biggest = copy_of_board[i][j] ;
                        *x = i ;
                        *y = j ;
                    }
}
