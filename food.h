#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <cstdlib>
#include <windows.h>
#define HEIGHT 25
#define WIDTH 50

class Food{
    COORD pos ;
public :
    Food();
    void gen_food();
    COORD get_pos();
};

#endif