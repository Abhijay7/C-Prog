/* program for snake game */
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
#define Width 50      // symbolic constants (columns)
#define Height 30     // symbolic constants (rows)
void draw();
void setup();
void input();
void logic();


// declaring global variables
int i, j, x, y;
int flag, fruitx, fruity;
int gameover=3, score=0;

// main driver function
void main()
{
    system("cls");
    system("Color 2F");
    printf("\t\t\t\t\t\t\t\t\t\tSNAKE GAME\n\n");
    printf("(Press any key to continue)");
    getch();

    system("cls");
    printf("\t\t\t\t\t\t\t\t\t\tGame Instructions: ");
    printf("\n\nPress:\n 'w' for movig Up\n 's' for moving Down\n 'a' for moving Left\n 'd' for moving Right");
    printf("\n\nYou got '3' lives, each time snake touches a boundary life will be reduced by '1'.");
    printf("\n\nEach time snake eats a fruit score will be increased by 10 points.");
    printf("\n\nPress 'x' to exit.");
    printf("\n\nPress space bar to pause and resume the game.");
    printf("\n\nPress any key to play game. . .");
    getch();

    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tloading...\n");
    printf("\t\t\t\t\t\t\t\t\t\t::");
    sleep(1);
    printf("::");
    sleep(2);
    printf("::");
    sleep(3);
    printf("::");
    sleep(3);
    printf("::");
    printf("\n\nPress any key to continue...");
    getch();
    
    

    setup();
    while(gameover>0)
    {
    
    draw();
    input();
    logic();
    
    }

    getch();
    system("cls");
    printf("\n\nYour SCORE is: %d",score);
    if(score<=100)
    {
    printf("\nBetter Luck Next Time!!!");
    }

    else if(score>100 && score<500)
    {
        printf("\nKeep it up!!!");
    }

    else
    {
        printf("\nAce Player!!!");
    }
    
    
}



// function to draw boundary
void draw()
{
    system("cls");
    printf("Score: %d",score);
    printf("\t\t\t\tLife Remaining: %d",gameover);
   
    printf("\n");
    printf("Press 'x' to exit.\n\n\n");
    for(i=1;i<=Height;i++)   // for row
    {
        for(j=1;j<=Width;j++) // for column
        {
            if(i==1 || i==Height || j==1 || j==Width)
            {
                printf("*");
            }
            else if(i==y && j==x)
            {
                printf("#");
            }
            else if(i==fruity && j==fruitx)
            {
                printf("0");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    

}


// function to generate snake and fruit
void setup()
{
    // to generate snake
    srand(time(NULL));
    label5:
    x=rand()%50;
    if(x<=1)
    goto label5;
    
    srand(time(NULL));
    label6:
    y=rand()%30;
    if(x<=1)
    goto label6;

    // to generate fruit
    srand(time(NULL));
    label1:
    fruitx=rand()%50;
    if(fruitx<=1)
    goto label1;

    srand(time(NULL));
    label2:
    fruity=rand()%30;
    if(fruity<=1)
    goto label2;


    

}

// function for taking input from keyboard
void input()
{
    
    if(kbhit())
    {
        switch(getch())
        {
            
            case 'w':
            flag=1;
            break;

            case 's':
            flag=2;
            break;

            case 'a':
            flag=3;
            break;

            case 'd':
            flag=4;
            break;

            case 'x':
            gameover=0;
            break;

            case (int)32:  // casting of char as int
            do
            {

            }while(!getch());
            break;

            




        }
    }
}

//logic function
void logic()
{
    Sleep(0.01);
    switch(flag)
    {

        case 1:
        y--;
        break;

        case 2:
        y++;
        break;

        case 3:
        x--;
        break;

        case 4:
        x++;
        break;
    }

    // if snake reaches the boundary
    
    if(x==1 || x==Width || y==1 || y==Height)
    {
        

        // to regenerate snake
        srand(time(NULL));
        label5:
        x=rand()%50;
        if(x<=1)
        goto label5;
    
        srand(time(NULL));
        label6:
        y=rand()%30;
        if(x<=1)
        goto label6;

        
        gameover--;
    
    }

    // when snake reaches eats a fruit
    // new fruit will be generated
    // score will be increased by 10 points
    if(x==fruitx && y==fruity)
    {
    label3:
    fruitx=rand()%50;
    if(fruitx<=1)
    goto label3;

    label4:
    fruity=rand()%30;
    if(fruity<=1)
    goto label4;
    score = score+10;
    }
    
}

