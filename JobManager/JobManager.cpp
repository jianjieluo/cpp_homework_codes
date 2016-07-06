#include <iostream>
#include <string>
#include <cstdio>
#include "JobManager.h"
using namespace std;

JobManager* JobManager::instance = NULL;

JobManager::JobManager() {
    jobFrontPointer = NULL;
}

JobManager::~JobManager() {
    clear();
}

JobManager* JobManager::getInstance() {
    if (instance == NULL) instance = new JobManager;
    return instance;
}

bool JobManager::deleteInstance() {
    if (instance == NULL) {
        return false;
    } else {
        instance -> clear();
        delete instance;
        instance = NULL;
        return true;
    }
}

void JobManager::addJob(int priority) {
    Job* temp = new Job(priority);
    if (jobFrontPointer != NULL) {
        Job* ptr = jobFrontPointer;
        while ((ptr -> getNext()) != NULL) {
            ptr = ptr -> getNext();
        }
        ptr -> setNext(temp);
        ptr = NULL;
    } else {
        jobFrontPointer = temp;
    }
    temp = NULL;
}

void JobManager::finishOneJob() {
    Job* temp = jobFrontPointer;
    if (jobFrontPointer != NULL) {
        jobFrontPointer = jobFrontPointer -> getNext();
        delete temp;
        temp = NULL;
    }
}

void swap(int& a, int&b) {
    int temp = a;
    a = b;
    b = temp;
}

void JobManager::sortJob() {
    int count = getNumOfJob();
    int *_id = new int[count];
    int *_priority = new int[count];
    Job* ptr = jobFrontPointer;
    for (int i = 0; i < count; i++) {
        _id[i] = ptr -> getId();
        _priority[i] = ptr -> getPriority();
        ptr = ptr -> getNext();
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = count - 1; j > i; j--) {
            if (_priority[j - 1] < _priority[j]) {
                swap(_priority[j - 1], _priority[j]);
                swap(_id[j - 1], _id[j]);
            }
            if (_priority[j - 1] == _priority[j]) {
                if (_id[j - 1] > _id[j]) {
                    swap(_priority[j - 1], _priority[j]);
                    swap(_id[j - 1], _id[j]);
                }
            }
        }
    }
    ptr = jobFrontPointer;
    for (int i = 0; i < count; i++) {
        ptr -> setId(_id[i]);
        ptr -> setPriority(_priority[i]);
        ptr = ptr -> getNext();
    }
    delete []_id;
    delete []_priority;
    _id = _priority = NULL;
}

void JobManager::printJob() {
    if (jobFrontPointer != NULL) {
        cout << jobFrontPointer -> toString();
        Job* ptr = jobFrontPointer -> getNext();
        while (ptr != NULL) {
            cout << "->" << ptr -> toString();
            ptr = ptr -> getNext();
        }
        cout << endl;
    } else {
        cout << "empty!" << endl;
    }
}

int JobManager::getNumOfJob() {
    int count = 0;
    Job* ptr = jobFrontPointer;
    while (ptr != NULL) {
        count++;
        ptr = ptr -> getNext();
    }
    return count;
}

void JobManager::clear() {
    while (jobFrontPointer != NULL) {
        Job* temp = jobFrontPointer;
        jobFrontPointer = (jobFrontPointer -> getNext());
        delete temp;
    }
}

