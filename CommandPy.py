class Fruit:
    def eat(self):
        pass

class Apple(Fruit):
    def eat(self):
        print("Comiendo una manzana.")

class Banana(Fruit):
    def eat(self):
        print("Comiendo una banana.")

class Orange(Fruit):
    def eat(self):
        print("Comiendo una naranja.")

class Menu:
    def __init__(self):
        self.fruits = []

    def addFruit(self, fruit):
        self.fruits.append(fruit)

    def eatFruit(self, choice):
        if choice >= 0 and choice < len(self.fruits):
            self.fruits[choice].eat()
        else:
            print("Opción no válida.")

if __name__ == "__main__":
    menu = Menu()
    apple = Apple()
    banana = Banana()
    orange = Orange()

    menu.addFruit(apple)
    menu.addFruit(banana)
    menu.addFruit(orange)

    choice = 0
    while choice != -1:
        print("Seleccione una fruta (0=Manzana, 1=Banana, 2=Naranja, -1 para salir):")
        choice = int(input())
        if choice != -1:
            menu.eatFruit(choice)
