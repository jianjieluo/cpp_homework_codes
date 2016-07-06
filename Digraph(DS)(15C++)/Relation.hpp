#ifndef RELATION_H_
#define RELATION_H_

class Relation
{
public:
    Relation(int r = 0; int c = 0);
    ~Relation();

protected:
    BooleanMatrix matrix;
};

Relation::Relation(int r, int c) :BooleanMatrix(r, c)
{
}

Relation::~Relation()
{
}

#endif