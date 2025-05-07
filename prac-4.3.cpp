#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FuelType
{
protected:
    string fuel;

public:
    FuelType(string fuelType) : fuel(fuelType) {}

    string getFuelType()
    {
        return fuel;
    }
};

class Brand
{
protected:
    string brandName;

public:
    Brand(string brand) : brandName(brand) {}

    string getBrandName()
    {
        return brandName;
    }
};

class Car : public FuelType, public Brand
{
private:
    string model;
    int year;

public:
    Car(string fuelType, string brand, string model, int year)
        : FuelType(fuelType), Brand(brand), model(model), year(year) {}

    void displayCarInfo()
    {
        cout << "Car Brand: " << getBrandName() << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Fuel Type: " << getFuelType() << endl;
    }
};

void serviceQueue(vector<Car>& cars)
{
    for (auto& car : cars)
    {
        car.displayCarInfo();
        cout << "----------------------------------" << endl;
    }
}

int main()
{
    Car car1("Gasoline", "Toyota", "Camry", 2020);
    Car car2("Electric", "Tesla", "Model S", 2021);
    Car car3("Diesel", "Ford", "F-150", 2019);

    vector<Car> cars = {car1, car2, car3};

    serviceQueue(cars);

    return 0;
}
