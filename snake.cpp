#include <iostream>
#include "snake.h"
using namespace std;

bool operator<(const _COORD& lhs, const _COORD& rhs) {
    if (lhs.X < rhs.X) return true;
    if (lhs.X > rhs.X) return false;
    return lhs.Y < rhs.Y;
}

Snake :: Snake(int len,COORD pos,int v){
    length = len;
    position = pos;
    vel = v;
}

void Snake :: change_direction(char d){direction = d; }

void Snake :: move(){
    if(b.size() != 0){
    COORD temp= body.front();
    body.pop_front();
    body.push_back(position);
    auto it = b.find(temp);
    b.erase(it);
    b.insert(position);
    }
    switch(direction)
    {
        case('u'):position.Y -= vel;break;
        case('d'):position.Y += vel;break;
        case('l'):position.X -= vel;break;
        case('r'):position.X += vel;break;
    }
}

int Snake ::get_len(){
    return length;
}

void Snake :: change_position(int x,int y){
    position.X = x;
    position.Y = y;
}

void Snake::grow(){
    length ++ ;
    b.insert(position);
    body.push_front(position);
}
COORD Snake::get_pos(){
    return position ;
}

bool Snake::eaten(COORD pos){
    return (pos.X == position.X && pos.Y == position.Y);
}

bool Snake :: in_body(COORD pos){
    return (b.find(pos) != b.end());
}

void Snake :: print_body(){
    cout<<'{'<<position.Y<<"'"<<position.X<<'}'<<" ";
    int count =0 ;
    for(auto i: body){count++;
        cout<<'{'<<i.Y<<"'"<<i.X<<'}'<<" ";
    }
    cout<<"coutn = "<<count<<" ";
}

void Snake :: move_head(){
    switch(direction)
    {
        case('u'):position.Y -= vel;break;
        case('d'):position.Y += vel;break;
        case('l'):position.X -= vel;break;
        case('r'):position.X += vel;break;
    }
}

bool Snake :: did_bite(){
    return (b.find(position) != b.end());
}