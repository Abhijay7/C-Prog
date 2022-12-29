/* program to play tic tac toe b/ween computer and user */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define plr 'X'     // defining players symbol
#define comp '0'    // defining computers symbol

void board();
void player();
void comp_move();
char check();

char square[3][3]={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; //2d string

//main driver function
void main()
{
    char c;
    c=' ';
    do
    {
    
     board();

     
     comp_move();
     board();
     c=check();
     if(c!=' ') break;
     
     player();
     c=check();
     board();
    }while(c==' ');
     
    
    if(c=='X')
    {
        printf("\n\n\nYou win");
    }

    else if(c=='0')
    {
        printf("\n\n\nI win, hahaha...");
    }

    else 
    {
        printf("\n\n\nDraw");
    }

}

// function to generate board
void board()
{
    system("cls");
    printf("\n\n\ntIc tAc tOe\n\n\n");
    printf("User (X)    Jarvis (0)\n\n\n\n");

    printf("    |    |\n");
    printf(" %c  | %c  | %c\n",square[0][0],square[0][1],square[0][2]);
    printf("____|____|____\n");
    printf("    |    |\n");
    printf(" %c  | %c  | %c\n",square[1][0],square[1][1],square[1][2]);
    printf("____|____|____\n");
    printf("    |    |\n");
    printf(" %c  | %c  | %c\n",square[2][0],square[2][1],square[2][2]);
    printf("    |    |");


}

// function for player's turn
void player()
{
    int x,y;
    printf("\n\nEnter the Coordinates:");
    scanf("%d %d",&x, &y);

    if(square[x][y]!=' ')
    {
    printf("Invalid move");
    player();
    }

    else
    {
        square[x][y]=plr;
    }

}

// function for computer's turn
void comp_move()
{
    int x,y;
    label1:
    srand(time(NULL));
    x=rand()%3;

    
    y=rand()%3;


    

    if(square[x][y]!=' ')
    {
        
        goto label1;
    }

    else
    {
        square[x][y]=comp;
    }
}

// function to check result
char check()
{

    int i, j, k;

    // checking rows
    for(i=0; i<3; i++)
    {
        if(square[i][0]==square[i][1] && square[i][1]==square[i][2])
        return square[i][0];
    }

    // checking column
    for(i=0; i<3; i++)
    {
        if(square[0][i]==square[1][i] && square[1][i]==square[2][i])
        return square[i][0];
    }

    // checking diagnols
    if(square[0][0]==square[1][1] && square[0][0]==square[2][2])
    return square[0][0];

    //checking diagnols
    if(square[0][2]==square[1][1] && square[1][1]==square[2][0])
    return square[0][2];

    if(square[0][0]!=' ' && square[0][1]!=' ' && square[0][2]!=' ' && square[1][0]!=' ' && square[1][1]!=' ' && square[1][2]!=' ' && square[2][0]!=' ' && square[2][1]!=' ' && square[2][2]!=' ' )
    {
        return '1';
    }

    else
    return ' ';

}
