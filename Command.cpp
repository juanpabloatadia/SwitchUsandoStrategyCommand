#include <iostream>
#include <vector>
using namespace std;

class Fruit 
{
public:
    virtual void eat() = 0;
};

class Apple : public Fruit 
{
public:
    void eat() override 
    {
        cout << "Comiendo una manzana." << endl;
    }
};

class Banana : public Fruit 
{
public:
    void eat() override 
    {
        cout << "Comiendo una banana." << endl;
    }
};

class Orange : public Fruit 
{
public:
    void eat() override 
    {
        cout << "Comiendo una naranja." << endl;
    }
};

class Menu 
{
private:
    vector<Fruit*> fruits;

public:
    void addFruit(Fruit* fruit) 
    {
        fruits.push_back(fruit);
    }

    void eatFruit(int choice) 
    {
        if (choice >= 0 && choice < fruits.size()) 
        {
            fruits[choice]->eat();
        } 
        
        else 
        {
            cout << "Opcion no valida." << endl;
        }
    }
};

int main() 
{
    Menu menu;
    Apple apple;
    Banana banana;
    Orange orange;

    menu.addFruit(&apple);
    menu.addFruit(&banana);
    menu.addFruit(&orange);

    int choice;
    do 
    {
        cout << "Seleccione una fruta (0=Manzana, 1=Banana, 2=Naranja, -1 para salir): ";
        cin >> choice;

        if (choice != -1) 
        {
            menu.eatFruit(choice);
        }
    } 
    
    while (choice != -1);

    return 0;
}

