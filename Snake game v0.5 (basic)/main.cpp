#include <iostream>
#include <conio.h>

using namespace std;

const int width = 20;
const int height = 20;
int x,y; //current position of head of snake
int fruitX, fruitY; //position of food item
int score;

enum eDirection {STOP=0, LEFT ,RIGHT ,UP ,DOWN};  // enumaration list representing directions.

eDirection dir;

void Setup()
{
    dir = STOP; //initially no movement
    x= width/2 ; y= height /2 ;  // place at center initially

    fruitX=rand()%width ;
    fruitY=rand()%height ;

    score =0 ;

}
void clearscreen(){
    system("cls");
}
void Draw()
{
     system("cls");

     for(int i=0;i<width+2 ;i++)
     {
         cout<<"#";
     }

     for(int i=0;i<height ;i++)
     {
         for(int j=0;j<width;j++)
         {
             if(j== 0)   cout<<"#";

             if(i == y && j ==x)    cout<<"O" ; // head of snake

             else if(i==fruitY && j == fruitX )   cout<< "F"; // food item

             else    cout<<" ";

            if( j== width-1 )   cout<<"#" ;
           }

           cout<<endl;
      }

      for(int i=0;i<width+2 ;i++)    //bottom boundary
      {
          cout << "#";
      }

}

void Input()
{
    if(_kbhit())  //check whether a key has been pressed or not.

        switch(_getch())

        {

            case 'a': dir = LEFT; break;

            case 'd': dir = RIGHT; break;

            case 'w': dir = UP; break;

            case 's': dir = DOWN; break;

            case 'x' :dir =STOP;break;
        }
}
void Logic()
{


       switch(dir)
       {
           case LEFT: x--;break;

           case RIGHT: x++;break;

           case UP: y-- ;break ;

           case DOWN :y++ ;break ;

          default:

              break;

       }


       //checking collision with wall

       if(x> width || x < 0 || y > height||y < 0 )

          Setup();





         /*if snake eats the fruit increase length and score */

         if(x == fruitX && y == fruitY)

         {

              score+=10 ;

              fruitX=rand()%width ;

              fruitY=rand()%height ;

         }

}

int main()
{
char aaa='1';
char bbb='2';
char ccc='3';
char ddd='4';

cout<<" hello welcome to basic and deafult snake game :)"<< endl;
cout<<"   "<<endl;
cout<<" 1: new game"<<endl;
cout<<" 2: continue"<<endl;
cout<<" 3: how to play?"<<endl;
cout<<" 4: exit the game"<<endl;

cout<<" choose an option: ";
char userchoice;
userchoice=getch();
cin >> userchoice;


if(userchoice==aaa){
         Setup();

    while(1)
    {
        Draw();

        Input();

        Logic();


     }
}
else if(userchoice==bbb){
             Setup();

    while(1)
    {
        Draw();

        Input();

        Logic();


     }
}
else if(userchoice==ccc){
        clearscreen();
    cout<<"Ok, goal of game: you have to eat a 'F'(frute) to alive and continue a game"<<endl;
    cout<<"for control snake: for up 'W' || for down 'S' || for right 'D' || for left 'A'"<<endl;
    cout<<"ok you get it ??? Let's play :)  (press 'P' to play): ";
    char play='p';
    cin>> userchoice;
    if(userchoice==play){
         Setup();

    while(1)
    {
        Draw();

        Input();

        Logic();


     }
    }
    else
        cout<<"wrong input!";
}
else if(userchoice==ddd) return 0;






    return 0;
}
