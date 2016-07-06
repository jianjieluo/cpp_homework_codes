#ifndef _MAP_H_
#define _MAP_H_
#include <iostream>
#include "global.hpp"
#include "snake.hpp"

class map {
    private:
        char** _map;
        snake _snake;
        int height, width;
        std::list<point> foods;
    public:
        map();
        map(point initial_size, point initial_head,
        std::list<point> initial_foods);
        ~map();
        void move(direction d);
        void print();
        bool isGameOver();
        bool isEat();;
        void makemap(void);
};

map::map() {
    _map = NULL;
    height = width = 0;
}

void map::makemap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            _map[i][j] = 0;
    }
    for (std::list<point>::iterator i = foods.begin(); i != foods.end(); ++i) {
        _map[i->x][i->y] = FOOD;
    }
    _map[_snake.getHead().x][_snake.getHead().y] = HEAD;
    for (std::list<point>::iterator i = _snake.getbody().begin();
    i != _snake.getbody().end(); ++i) {
        _map[i->x][i->y] = BODY;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width;  j++) {
            if (_map[i][j] == 0)
                _map[i][j] = EMPTY;
        }
    }
}

map::map(point initial_size, point initial_head, std::list<point> initial_foods)
{
    height = initial_size.x;
    width = initial_size.y;
    _map = new char*[height];
    for (int i = 0; i < height; i++)
        _map[i] = new char[width]();
    _snake.setHead(initial_head);
    foods = initial_foods;
    makemap();
}

map::~map() {
    for (int i = 0; i < height; i++) {
        delete []_map[i];
    }
    delete []_map;
}

void map::print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << _map[i][j];
        }
        std::cout << std::endl;        
    }
    std::cout << std::endl;
}

bool map::isGameOver() {
    point temp = _snake.getHead();
    if (temp.x == height || temp.y == width || temp.x < 0 || temp.y < 0)
        return true;
    if (_map[temp.x][temp.y] == BODY) return true;
    return false;
}

bool map::isEat() {
    point temp = _snake.getHead();
    if (temp.x == height || temp.y == width || temp.x < 0 || temp.y < 0)
        return false;
    if (_map[temp.x][temp.y] == FOOD) return true;
    else return false;
}

void map::move(direction d) {
    point temp_f = _snake.getHead();
    if (!(_snake.getbody().empty())) {  // 为了避免追尾问题
        _map[_snake.getbody().back().x][_snake.getbody().back().y] = EMPTY;
    }
    _snake.getHead().move(d);
    if (_snake.getHead() == _snake.getbody().front()) {  // 判断蛇是否往回走
        _snake.setHead(temp_f);
        _map[_snake.getbody().back().x][_snake.getbody().back().y] = BODY;
        return;
    }
    if (!isGameOver()) {
        if (isEat()) {
            point eaten = _snake.getHead();
            foods.remove(eaten);
            _snake.grow(temp_f);
        } else {
            _snake.getbody().push_front(temp_f);
            _snake.getbody().pop_back();
        }
        makemap();
    } else {
        if (!(_snake.getbody().empty())) {
            _map[_snake.getbody().back().x][_snake.getbody().back().y] = BODY;
        }
    }
}
#endif

