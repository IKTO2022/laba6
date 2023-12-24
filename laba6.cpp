#include <iostream>
#include <string>

class Transport
{
public:
    Transport(std::string model, int horsepower, int age) : model(model), horsepower(horsepower), age(age) {}

    int checkHP() {
        return horsepower;
    }

    virtual int calculateAge() const { // Вычисляемый параметр
        return age;
    }

    void changeEngine(int new_HP) {
        horsepower = new_HP;
    }

    virtual void showData() const {
        std::cout << "Model: " << model << std::endl;
        std::cout << "Horsepower: " << horsepower << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

protected:
    int horsepower;
    int age;
    std::string model;

};

class Plane : public Transport {
public:
    Plane(std::string model, int horsepower, bool isAirBus, int age) : Transport(model, horsepower, age), isAirBus(isAirBus) {}

    void showData() const override {
        std::cout << "Plane: " << std::endl;
        Transport::showData();
        if (isAirBus == true)
        {
            std::cout << "Is AirBus" << std::endl;
        }
        else
        {
            std::cout << "Is not AirBus" << std::endl;
        }
    }

    int calculateAge() const override {
        return Transport::calculateAge() + 5; // Пример переопределения вычисляемого параметра
    }

    void changeLicense(bool new_status) {
        if (new_status == true)
        {
            std::cout << "Now is AirBus" << std::endl;
            isAirBus = true;
        }
        else 
        {
            std::cout << "Now is not AirBus" << std::endl;
            isAirBus = false;
        }
    }

private:
    bool isAirBus;
};

class Car : public Transport {
public:
    Car(std::string model, int horsepower, bool isFamily, int age) : Transport(model, horsepower, age), isFamily(isFamily) {}

    void showData() const override {
        std::cout << "Car: " << std::endl;
        Transport::showData();
        if (isFamily == true)
        {
            std::cout << "Is Family car" << std::endl;
        }
        else
        {
            std::cout << "Is not Family car" << std::endl;
        }
    }

    void changeLicense(bool new_status) {
        if (new_status == true)
        {
            std::cout << "Now is Family car" << std::endl;
            isFamily = true;
        }
        else
        {
            std::cout << "Now is not Family car" << std::endl;
            isFamily = false;
        }
    }
private:
    bool isFamily;
};


int main() {
    const int arraySize = 3;
    Transport* ts[arraySize];

    ts[0] = new Car("Renault", 110, true, 4);
    ts[1] = new Plane("Aeroflot", 110000, true, 5);
    ts[2] = new Car("Kia", 140, false, 5);

    int choice = -1;
    int option = 0;
    int min_ts = 0;
    int new_hp = 0;
    bool new_license = false;
    int min_age = 1000;

    std::cout << "You have a list of transport" << std::endl;
    std::cout << "Yoo should choose one option: " << std::endl;
    std::cout << "1: Total information" << std::endl;
    std::cout << "2: Change the engine" << std::endl;
    std::cout << "3: Calculate the newest transport" << std::endl;
    
    

    while (choice != 0)
    {
        std::cout << "Print the option, otherwise print 0 and exit" << std::endl;
        std::cin >> choice;
        switch (choice) 
        {
        case 0:
        {
            choice = 0;
            std::cout << "Exiting the programm" << std::endl;
            break;
        }
        case 1:
        {
            for (int i = 0; i < arraySize; i++)
            {
                std::cout << "Transport " << (i + 1) << std::endl;
                ts[i]->showData();
            }
            break;
        }
        case 2: 
        {
            std::cout << "Choose the line you want to change" << std::endl;
            std::cin >> option;
            std::cout << "Type new amount of horsepower in your engine" << std::endl;
            std::cin >> new_hp;
            ts[option - 1]->changeEngine(new_hp);
            std::cout << "Engine has changed" << std::endl;
            break;
        }
        case 3:
        {
            for (int i = 0; i < arraySize; i++)
            {
                if (ts[i]->calculateAge() < min_age)
                {
                    min_age = ts[i]->calculateAge();
                    min_ts = i;
                }
            }
            std::cout << "The newest ts in the " << min_ts + 1 << " line" << std::endl;
            std::cout << "Age is " << min_age << std::endl;
            break;
        }

        default:
        {
            std::cout << "You picked the wrong number. Try again" << std::endl;
            break;
        }

        }
        
    }

    // Освобождение памяти
    for (int i = 0; i < arraySize; ++i) {
        delete ts[i];
    }

    return 0;
}


