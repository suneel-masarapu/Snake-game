#include <iostream>
#include <windows.h>
#include <conio.h> // for the console input and output to capture the keboard hits
#include <ctime>
#include "snake.h"
#include "food.h"
using namespace std;


//first we build the board 
#define HEIGHT 25
#define WIDTH 50
int X = 10,Y = 10;

Snake snake(1,{15,12},1);
Food f;
void board(){
    for(int i = 0;i<=HEIGHT;i++){
        for(int j = 0;j<=WIDTH;j++){
            COORD temp = { static_cast<SHORT>(j), static_cast<SHORT>(i) };
            if(j == 0)cout<<"\t\t";
            if(i == snake.get_pos().Y && j == snake.get_pos().X)cout<<'O';
            else if(snake.in_body(temp))cout<<'o';
            else if(i == f.get_pos().Y && j ==f.get_pos().X)cout<<"o";
            else if(i == 0  || i == HEIGHT || j == WIDTH || j == 0)cout<<"'";
            else cout<<' ';
        }
        cout<<endl;
    }
}

void printGameOver() {
    system("cls");
    cout<<"\033[H";
    board();
    Sleep(500);
    system("cls");
    const char* gameOver[] = {
        " #####     #    #     # #######    #####   ####### ######  ",
        "#     #   # #   ##   ## #         #     #  #       #     # ",
        "#        #   #  # # # # #         #     #  #       #     # ",
        "#  #### #     # #  #  # #####     #     #  #####   ######  ",
        "#     # ####### #     # #         #     #  #       #   #   ",
        "#     # #     # #     # #         #     #  #       #    #  ",
        " #####  #     # #     # #######    #####   ####### #     # "
    };
    cout<<"\033[H";
    for (int i = 0; i < 7; ++i) {
        cout<<"\t\t";
        cout << gameOver[i] << endl;
    }
    Sleep(1000);
}

int main(){
    system("cls");
    srand(time(nullptr));
    int count = 0;
    while(true){
        cout<<"\033[H";
        if(kbhit()){
            switch(getch()){
                case('w') : snake.change_direction('u');break;
                case('a') : snake.change_direction('l');break;
                case('s') : snake.change_direction('d');break;
                case('d') : snake.change_direction('r');break;
            }
        }
        board();
        COORD pos = snake.get_pos();
        if(pos.X == 0 || pos.X == WIDTH || pos.Y == 0 || pos.Y == HEIGHT){
            printGameOver();
            return 0;
        }
        //cout<<"here"<<count<<endl;
        if(snake.eaten(f.get_pos())){
            cout<<"yaay ";
            f.gen_food();
            snake.grow();
            //cout<<"here"<<snake.get_len()<<" eaten ";snake.print_body();cout<<endl;
        }
        
        else {
            snake.move();
            if(snake.did_bite()){
                printGameOver();
                return 0;
            }
            //cout<<"here"<<snake.get_len()<<" alive ";snake.print_body();cout<<endl;
        }
        count++;
        //cout<<"here"<<count<<endl;
        Sleep(100);
        //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,3}); //i used 3 here because 0 is hetting ugly;
    }
    return 0;
}