#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <cstdio>
using namespace std;

class gameobject {
    public:
        gameobject(int _x = 0, int _y = 0);
        ~gameobject();
        virtual void select() const = 0;
        virtual void move() = 0;
        int get_hp() const;
        void set_hp(int _hp);
    protected:
        int x, y;
        int hp;
};

class worker:public gameobject {
    public:
        worker(int _x = 0, int _y = 0);
        ~worker();
        virtual void select() const;
        virtual void move();
        void repair(gameobject* obj);
        void build(int h);
    protected:
        int dx, dy;
};

class zealot:public gameobject {
    public:
        zealot(int _x = 0, int _y = 0);
        ~zealot();
        virtual void select() const;
        virtual void move();
        void attack(gameobject* obj);
    protected:
        int dx, dy;
};

class tower:public gameobject {
    public:
        tower(int _x = 0, int _y = 0);
        ~tower();
        virtual void select() const;
        virtual void move();
        void attack(gameobject* obj);
    protected:
        int dx, dy;
};

gameobject::gameobject(int _x, int _y) {
    x = _x;
    y = _y;
    hp = 10;
}

gameobject::~gameobject() {}

int gameobject::get_hp() const {
    return hp;
}

void gameobject::set_hp(int _hp) {
    hp = _hp;
}

worker::worker(int _x, int _y):gameobject(_x, _y) {dx = dy = 1;}
zealot::zealot(int _x, int _y):gameobject(_x, _y) {dx = dy = 2;}
tower::tower(int _x, int _y):gameobject(_x, _y) {dx = dy = 0;}

worker::~worker() {}
zealot::~zealot() {}
tower::~tower() {}

void worker::select() const {
    cout << "Scv good to go, sir!" << endl;
}

void zealot::select() const {
    cout << "My life for Aiur!" << endl;
}

void tower::select() const {
    cout << "~" << endl;
}

void worker::move() {
    x = x + dx;
    y = y + dy;
    printf("Worker moves to (%d, %d)\n", x, y);
}

void zealot::move() {
    x = x + dx;
    y = y + dy;
    printf("Zealot moves to (%d, %d)\n", x, y);
}

void tower::move() {
    x = x + dx;
    y = y + dy;
    cout << "Tower cannot move." << endl;
}

void worker::repair(gameobject* obj) {
    obj -> set_hp(10);
}

void zealot::attack(gameobject* obj) {
    obj -> set_hp((obj -> get_hp()) - 1);
}

void tower::attack(gameobject* obj) {
    obj -> set_hp((obj -> get_hp()) - 1);
}

void worker::build(int h) {
    for (int i = 1; i < h + 1; ++i) {
        int space = h - i;
        int star = 2 * i - 1;
        while (space--)
            cout << " ";
        while (star--)
            cout << "*";
        cout << endl;
    }
}
#endif
