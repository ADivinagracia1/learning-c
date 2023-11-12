#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void Setup();
void Draw();
void Input();
void Logic();

void drawSnake(int x, int y);
void drawFruit(int x, int y);

bool gameOver;

//Map dimensions
const int width = 40;
const int height = 20;

//Object Variables
int snkX, snkY, fruitX, fruitY, score  = 0;
int tailX[100] = {0}, tailY[100] = {0};

//Controls 
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

//Hardcoded Game Settings;
int nTail = 5; //Starting Tail
bool wallDeath = true; 

int main()
{
    cout << "yeet two" << endl;

    Setup();

    while(!gameOver == true)
    {
        Draw();
        Input();
        Game();
        //Sleep(10); //Slows game a little bit
    }

    return 0;  
}

void Setup()
{
    gameOver = false;
    dir = LEFT;
    snkX = width*2/3;
    snkY = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw()
{
    system("cls");

    //Print Top Border
    for (size_t i = 0; i < width; i++)
        cout << "#";
    cout << endl;

    //Print Side walls + SNAKE
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            
            //Generate objects
            if ( i == snkY && j == snkX)
                cout << "O";
            else if ( i == fruitY && j == fruitX)
                cout << "&";
            else
            {
                //Print Tail
                bool showTail = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        showTail = true;
                    }
                }

                if(!showTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
    
    //Print bottom border
    for (size_t i = 0; i < width; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{

    //Asynchronous functions: during keypress
    if(_kbhit())
    {
        switch (_getch())
        {
        case 'w': if(dir != DOWN)  dir = UP;    break;
        case 'a': if(dir != RIGHT) dir = LEFT;  break;
        case 's': if(dir != UP)    dir = DOWN;  break;
        case 'd': if(dir != LEFT)  dir = RIGHT; break;
        case 'x':   
            gameOver = true;        
            break;
        default:
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    //Tail follow the haed
    tailX[0] = snkX;
    tailY[0] = snkY;

    //NOTE: UNDERSTAND THIS A LOT
    //Counts number of tails
    for (size_t i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
    //Controls input logic
    switch (dir)
    {
    case UP:
        snkY--;
        break;
    case LEFT:
        snkX--;
        break;
    case DOWN:
        snkY++;
        break;
    case RIGHT:
        snkX++;
        break;
    default:
        break;
    }

    //If Snake eats fruit, grow
    if (snkX == fruitX && snkY == fruitY)
    {    
        nTail++;
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

    if(wallDeath)
    {
        //If snake hits wall, game over
        if (snkX > width-1 || snkX < 0 || snkY > height-1 || snkY < 0)
            gameOver = true;
    }
    else
    {
        //If hits wall, comes out the other side
        if (snkX > width)   snkX = 0;
            else if (snkX < 0)  snkX = width - 1;
        if (snkY > height)  snkY = 0;
            else if (snkY < 0)  snkY = height - 1;
    }


    //If snake hits itself, game 
    //NOTE: This wont be good for embedded programming
    for (int i = 0; i < nTail; i++)
        if ( tailX[i] == snkX && tailY[i] == snkY )
            gameOver = true;
    

}