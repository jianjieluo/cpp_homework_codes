#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <iostream>
#include <list>
#include "global.hpp"

class snake {
        point head;
        std::list<point> body;
    public:
        snake(point initial_head);
        snake();
        ~snake() {}
        point& getHead();
        std::list<point>& getbody();
        void grow(point);
        void setHead(point);
};

snake::snake() {
    head.x = 0;
    head.y = 0;
}

snake::snake(point initial_head) {
    setHead(initial_head);
}

void snake::setHead(point _head) {
    head = _head;
}

void snake::grow(point second_node) {
    this -> body.push_front(second_node);
}

point& snake::getHead() {
    return head;
}

std::list<point>& snake::getbody() {
    return body;
}
#endif
