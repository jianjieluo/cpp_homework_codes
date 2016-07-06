#ifndef WORLD_H_
#define WORLD_H_
#include <iostream>
#include <vector>
using namespace std;

typedef struct person {
    int ID;
    static int count;
    vector<int> relation;
    person() {
        ID = count++;
    }
} person;

int person::count = 0;

class group {
    public:
        explicit group(int _type);
        ~group() {}
        void displayGroup();
        void addMember(person & p);
        void deleteMember(person & p);
        void makeFriend(person & p1, person & p2);
        void breakRelation(person & p1, person & p2);
        bool isIngroup(const person &p);
        bool isFriend(person &p1, person &p2);
        vector<person>::iterator getPerson(const person &p);
    private:
        int type;
        vector<person> Group;
};

group::group(int _type) {
    type = _type;
}

bool group::isIngroup(const person &p) {
    for (vector<person>::iterator i = Group.begin();
        i != Group.end(); ++i) {
        if ((i->ID) == p.ID) return true;
    }
    return false;
}

vector<person>::iterator group::getPerson(const person &p) {
    if (isIngroup(p)) {
        vector<person>::iterator i;
        for (i = Group.begin(); i != Group.end(); ++i) {
            if ((i->ID) == p.ID)
                return i;
        }
    }
    return Group.begin();
}

bool group::isFriend(person &p1, person &p2) {
    for (vector<int>::iterator i = getPerson(p1)->relation.begin();
        i != getPerson(p1)->relation.end(); ++i) {
        if (*i == p2.ID) return true;
    }
    return false;
}

void group::makeFriend(person & p1, person & p2) {
    if (!isFriend(p1, p2)) {
        (getPerson(p1)->relation).push_back(p2.ID);
        (getPerson(p2)->relation).push_back(p1.ID);
    }
}

void group::breakRelation(person & p1, person & p2) {
    if (isFriend(p1, p2)) {
        for (vector<int>::iterator i = getPerson(p1)->relation.begin();
            i != getPerson(p1)->relation.end(); ++i) {
            if ((*i) == p2.ID) {
                (getPerson(p1)->relation).erase(i);
                break;
            }
        }
        for (vector<int>::iterator i = getPerson(p2)->relation.begin();
            i != getPerson(p2)->relation.end(); ++i) {
            if ((*i) == p1.ID) {
                (getPerson(p2)->relation).erase(i);
                break;
            }
        }
    }
}

void group::addMember(person & p) {
    if (!isIngroup(p)) {
        Group.push_back(p);
        if (type) {
            if (Group.size() > 1) {
                for (vector<person>::iterator i = Group.begin();
                    i != Group.end() - 1; ++i)
                    makeFriend((*i), p);
            }
        }
    }
}

void group::deleteMember(person & p) {
    if (isIngroup(p)) {
        Group.erase(getPerson(p));
    }
}

void group::displayGroup() {
    for (vector<person>::iterator i = Group.begin(); i != Group.end(); ++i) {
        cout << "Person_" << i->ID << ": ";
        if ((i->relation).size() != 0) {
            cout << (i->relation).front();
            if ((i->relation).size() > 1) {
                for (vector<int>::iterator j = (i->relation).begin() + 1;
                    j != (i->relation).end(); ++j)
                    cout << ", " << (*j);
            }
        } else {
            cout << "null";
        }
        cout << endl;
    }
}
#endif
