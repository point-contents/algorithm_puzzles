#include <algorithm>
#include <assert.h>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

std::map<int, std::string> addItem(int id, std::string name, std::map<int, std::string> menu)
{
    menu.insert({ id, name });
    return menu;
}

std::map<std::string, int> addPrice(std::string name, int price, std::map<std::string, int> items)
{
    items.insert({ name, price });
    return items;
}

void printItemPrice(std::map<std::string, int> priceMenu)
{

    std::cout << "Name\t Price"
              << "\n";
    for (std::pair<std::string, int> element : priceMenu) {
        std::string itemName = element.first;
        int itemPrice = element.second;
        //		assert(itemPrice != 0);
        std::cout << itemName << "\t" << itemPrice << "\n";
    }
    std::cout << "\n";
}

void printMenu(std::map<int, std::string> entireMenu)
{
    std::cout << "ID\t Name"
              << "\n";
    for (std::pair<int, std::string> element : entireMenu) {
        int item = element.first;
        std::string itemName = element.second;
        assert(item != 0);
        std::cout << item << "\t" << itemName << "\n";
    }
    std::cout << "\n";
}

int main()
{
    std::map<int, std::string> Menu;
    std::map<std::string, int> Price;

    Menu = addItem(10, "Pizza", Menu);
    Menu = addItem(1, "Coffee", Menu);
    Menu = addItem(2, "Milk", Menu);
    Menu = addItem(3, "Pie", Menu);
    Menu = addItem(4, "Tea", Menu);
    Menu = addItem(5, "Music", Menu);
    Menu = addItem(6, "Bread", Menu);
    Menu = addItem(7, "Salt", Menu);
    Menu = addItem(8, "Pepper", Menu);
    Menu = addItem(9, "Mayo", Menu);

    Price = addPrice("Pizza", 10, Price);
    Price = addPrice("Coffee", 3, Price);
    Price = addPrice("Milk", 2, Price);
    Price = addPrice("Pie", 6, Price);
    Price = addPrice("Tea", 3, Price);
    Price = addPrice("Music", 5, Price);
    Price = addPrice("Bread", 1, Price);
    Price = addPrice("Salt", 3, Price);
    Price = addPrice("Pepper", 0, Price);
    Price = addPrice("Mayo", 1, Price);

    printMenu(Menu);
    printItemPrice(Price);
    printMenu(Menu);
    printItemPrice(Price);

    printMenu(Menu);
    printItemPrice(Price);
    printMenu(Menu);
    printItemPrice(Price);

    printMenu(Menu);
    printItemPrice(Price);
    printMenu(Menu);
    printItemPrice(Price);
    return 0;
}
