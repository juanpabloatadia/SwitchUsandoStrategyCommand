class IFruitOptionStrategy:
    def execute(self):
        pass

class AppleStrategy(IFruitOptionStrategy):
    def execute(self):
        print("Has seleccionado una manzana.")

class BananaStrategy(IFruitOptionStrategy):
    def execute(self):
        print("Has seleccionado un banana.")

class OrangeStrategy(IFruitOptionStrategy):
    def execute(self):
        print("Has seleccionado un naranja.")

class InvalidOptionStrategy(IFruitOptionStrategy):
    def execute(self):
        print("Opción no válida. Seleccione una fruta válida.")

class FruitMenu:
    def __init__(self):
        self.strategy = None

    def set_strategy(self, strategy):
        self.strategy = strategy

    def execute_option(self):
        self.strategy.execute()

if __name__ == "__main__":
    fruit_menu = FruitMenu()
    print("Seleccione una fruta:")
    print("1. Manzana")
    print("2. Banana")
    print("3. Naranja")
    choice = int(input())

    if choice == 1:
        fruit_menu.set_strategy(AppleStrategy())
    elif choice == 2:
        fruit_menu.set_strategy(BananaStrategy())
    elif choice == 3:
        fruit_menu.set_strategy(OrangeStrategy())
    else:
        fruit_menu.set_strategy(InvalidOptionStrategy())

    fruit_menu.execute_option()
