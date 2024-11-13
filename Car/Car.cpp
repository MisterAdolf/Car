#include <iostream>
using namespace std;

class Car {
private:
    double fuelLevel;         
    double fuelConsumption;   
    bool isStarted;           
    bool headlightsOn;        

public:
    Car(double fuelLevel = 0, double fuelConsumption = 10)
        : fuelLevel(fuelLevel), fuelConsumption(fuelConsumption),
        isStarted(false), headlightsOn(false) {}

    void start() {
        if (!isStarted) {
            isStarted = true;
            cout << "Car's running." << endl;
        }
        else {
            cout << "The car's already started." << endl;
        }
    }

    void stop() {
        if (isStarted) {
            isStarted = false;
            cout << "The car's shut down." << endl;
        }
        else {
            cout << "The car's already shut down." << endl;
        }
    }

    
    void toggleHeadlights() {
        headlightsOn = !headlightsOn;
        cout << "Headlights " << (headlightsOn ? "enabled." : "turned off.") << endl;
    }

    
    void drive(double distance) {
        if (!isStarted) {
            cout << "You have to start the car first!" << endl;
            return;
        }

        
        double adjustedConsumption = fuelConsumption * (headlightsOn ? 1.1 : 1.0);
        double fuelNeeded = (adjustedConsumption / 100.0) * distance;

        if (fuelLevel >= fuelNeeded) {
            fuelLevel -= fuelNeeded;
            cout << "Bygones. " << distance << " km. Fuel left: " << fuelLevel << " l." << endl;
        }
        else {
            cout << "Not enough fuel to travel that distance." << endl;
        }
    }

    
    void refuel(double amount) {
        fuelLevel += amount;
        cout << "The machine is fueled on " << amount << " l. Current fuel level: " << fuelLevel << " l." << endl;
    }
};

int main() {
    Car car(20, 8); 
    car.start(); 
    car.toggleHeadlights(); 
    car.drive(50); 
    car.toggleHeadlights(); 
    car.refuel(10); 
    car.drive(50); 
    car.stop();

    return 0;
}
