#ifndef TODO_H_
#define TODO_H_

class point {
    public:
        point(double = 0, double = 0);
        ~point();
        void print();
    private:
        double x;
        double y;
};

class vector:public point {
    public:
        vector(double = 0, double = 0, double = 0, double = 0);
        ~vector();
        void print();
    protected:
        double dx;
        double dy;
        double length;
};

class circle:public point {
    public:
        circle(double = 0, double = 0, double = 0);
        ~circle();
        void print();
    protected:
        double r;
        double area;
};

class todo:public vector, public circle {
    public:
        todo(double = 0, double = 0, double = 0, double = 0, double = 0);
        ~todo();
        void print();
};
#endif
