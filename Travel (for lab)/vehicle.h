#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

typedef struct City {
    double x, y;
    std::string name;
} City;

class Vehicle {
    public:
        explicit Vehicle(double _speed = 0);
        virtual void doTravel(const City& src, const City& dest) = 0;
        double getSpeed() const {
            return speed;
        }
        virtual ~Vehicle() {}
    protected:
        double speed;
};

Vehicle::Vehicle(double _speed) {
    speed = _speed;
}

class BicycleStrategy: public Vehicle {
    public:
        explicit BicycleStrategy(double sp);
        ~BicycleStrategy() {}
        void doTravel(const City& src, const City& dest);
};

class TrainStrategy: public Vehicle {
    public:
        explicit TrainStrategy(double sp);
        ~TrainStrategy() {}
        void doTravel(const City& src, const City& dest);
};

class AirplaneStrategy: public Vehicle {
    public:
        explicit AirplaneStrategy(double sp);
        ~AirplaneStrategy() {}
        void doTravel(const City& src, const City& dest);
};

void BicycleStrategy::doTravel(const City& src, const City& dest) {
    double distance = fabs(src.x - dest.x) + fabs(src.y - dest.y);
    double time = distance / speed;
    std::cout << "It takes " << time << " hours to Travel from ";
    std::cout << src.name << " to " << dest.name << " by Bicycle." << std::endl;
}

void TrainStrategy::doTravel(const City& src, const City& dest) {
    double distance = sqrt(pow(src.x - dest.x, 2) + pow(src.y - dest.y, 2));
    double time = distance / speed;
    std::cout << "It takes " << time << " hours to Travel from ";
    std::cout << src.name << " to " << dest.name << " by Train." << std::endl;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

void AirplaneStrategy::doTravel(const City& src, const City& dest) {
    double distance = max(fabs(src.x - dest.x), fabs(src.y - dest.y));
    double time = distance / speed;
    std::cout << "It takes " << time << " hours to Travel from ";
    std::cout << src.name << " to " << dest.name << " by Airplane." << std::endl;
}

BicycleStrategy::BicycleStrategy(double sp) : Vehicle(sp) {}
TrainStrategy::TrainStrategy(double sp) : Vehicle(sp) {}
AirplaneStrategy::AirplaneStrategy(double sp) : Vehicle(sp) {}

#endif
