#ifndef AIRPLANE_H_
#define AIRPLANE_H_
#include <iostream>
using namespace std;

class Airplane {
    public:
        Airplane();
        ~Airplane();
        virtual void fly(const string& dest) = 0;
    protected:
        void defaultFly(const string& dest);
};

class ModelA:public Airplane {
    public:
        ModelA();
        ~ModelA();
        virtual void fly(const string& dest);
    private:
        string dest;
};

class ModelB:public Airplane {
    public:
        ModelB();
        ~ModelB();
        virtual void fly(const string& dest);
    private:
        string dest;
};

class ModelC:public Airplane {
    public:
        virtual void fly(const string& dest);
        ModelC();
        ~ModelC();
    private:
        string dest;
};;

Airplane::Airplane() {}

Airplane::~Airplane() {}

ModelA::ModelA() {
    dest = "";
}

ModelB::ModelB() {
    dest = "";
}

ModelC::ModelC() {
    dest = "";
}

ModelA::~ModelA() {}

ModelB::~ModelB() {}

ModelC::~ModelC() {}

void Airplane::defaultFly(const string& dest) {
    cout << "The airplane flies straightly to airport " << dest << "." << endl;
}

void ModelA::fly(const string& dest) {
    cout << "The airplane flies straightly to airport " << dest << "." << endl;
}

void ModelB::fly(const string& dest) {
    cout << "The airplane flies straightly to airport " << dest << "." << endl;
}

void ModelC::fly(const string& dest) {
    cout << "The airplane flies in a semi-circle track to airport "
    << dest << "." << endl;
}
#endif

