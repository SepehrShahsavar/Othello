#include <stdio.h>
void processing_moves( int possible_places [][8], char board[][8] , char player); 
int main(int argc, char *argv[])
{
    char board[8][8];
    char player ; 
    int possible_places [8][8];
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<8 ; j++){
            possible_places[i][j] = 0 ;
        }
    }
    // initializing the board 
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = argv[i + 1][j];
        }
    }
    player = argv[8][0];
    return 0;
}
