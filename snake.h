#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <list>
#include <set>
using namespace std;


class Snake{
    int length; // keeps a track of length of the snake
    char direction; //keeps the track of the direction of movement of the snake
    COORD position ;
    int vel;
    list<COORD>body;
    set<COORD>b;
public :
    Snake(int len,COORD pos,int v = 1);
    void change_direction(char d);
    void grow();
    int get_len();
    void change_position(int x,int y);
    void move();
    COORD get_pos();
    bool eaten(COORD pos);
    bool in_body(COORD pos);
    void print_body();
    void move_head();
    bool did_bite();
};


#endif