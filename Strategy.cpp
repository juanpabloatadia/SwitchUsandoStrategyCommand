#include <iostream>
using namespace std;

class IFruitOptionStrategy
{
public:
    virtual void Execute() = 0;
};

class AppleStrategy : public IFruitOptionStrategy
{
public:
    void Execute() override
    {
        cout << "Has seleccionado una manzana." << endl;
    }
};

class BananaStrategy : public IFruitOptionStrategy
{
public:
    void Execute() override
    {
        cout << "Has seleccionado un banana." << endl;
    }
};

class OrangeStrategy : public IFruitOptionStrategy
{
public:
    void Execute() override
    {
        cout << "Has seleccionado un naranja." << endl;
    }
};

class InvalidOptionStrategy : public IFruitOptionStrategy
{
public:
    void Execute() override
    {
        cout << "Opcion no valida. Seleccione una fruta valida." << endl;
    }
};

class FruitMenu
{
private:
    IFruitOptionStrategy* strategy;

public:
    void SetStrategy(IFruitOptionStrategy* strategy)
    {
        this->strategy = strategy;
    }

    void ExecuteOption()
    {
        strategy->Execute();
    }
};

int main()
{
    FruitMenu fruitMenu;
    cout << "Seleccione una fruta:" << endl;
    cout << "1. Manzana" << endl;
    cout << "2. Banana" << endl;
    cout << "3. Naranja" << endl;
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        fruitMenu.SetStrategy(new AppleStrategy());
    }
    else if (choice == 2)
    {
        fruitMenu.SetStrategy(new BananaStrategy());
    }
    else if (choice == 3)
    {
        fruitMenu.SetStrategy(new OrangeStrategy());
    }
    else
    {
        fruitMenu.SetStrategy(new InvalidOptionStrategy());
    }

    fruitMenu.ExecuteOption();

    return 0;
}

