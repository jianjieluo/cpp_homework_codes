#include <string>
#include <cstdio>
#include <cstdlib>
#include "Job.h"
using namespace std;

int Job::number = 0;

Job::Job(int priority) {
    setId(number++);
    setPriority(priority);
    nextJob = NULL;
}

void Job::setId(int id) {
    this -> id = id;
}

int Job::getId() const {
    return id;
}

void Job::setPriority(int priority) {
    this -> priority = priority;
}

int Job::getPriority() const {
    return priority;
}

void Job::setNext(Job *job) {
    nextJob = job;
}

Job* Job::getNext() const {
    return nextJob;
}

string Job::toString() {
    char a[50];
    snprintf(a, sizeof(a), "[%d:%d]", id, priority);
    string temp(a);
    return temp;
}
