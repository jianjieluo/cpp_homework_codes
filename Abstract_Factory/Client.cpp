
#include <iostream>
#include <string>

#include "Factory.hpp"
#include "Product.hpp"

int main() {
  UIFactory* ui = 0;

  int choose;

  std::cin >> choose;

  switch (choose) {
    case 0:
      ui = new MFCUIFactory();
      break;
    case 1:
      ui = new GtkUIFactory();
      break;
    case 2:
    default:
      ui = new QtUIFactory();
  }

  /* Use the factory to build interface. */
  Window* toolbox = ui->getToolboxWindow();
  Window* layers = ui->getLayersWindow();
  Window* main = ui->getMainWindow();

  /* See what have we recieved. */
  std::cout << toolbox->getToolkit() << ":" << toolbox->getType() << std::endl;
  std::cout << layers->getToolkit() << ":" << layers->getType() << std::endl;
  std::cout << main->getToolkit() << ":" << main->getType() << std::endl;

  ui->deleteWindow(toolbox);
  ui->deleteWindow(layers);
  ui->deleteWindow(main);

  delete ui;
}

