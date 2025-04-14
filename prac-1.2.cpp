#include<iostream>
using namespace std;

class Product
{
private:
    int product_id;
    string name;
    int quantity;
    double price;

public:
    Product(int id = 0, string n = "", int qty = 0, double p = 0.0)
        : product_id(id), name(n), quantity(qty), price(p) {}

    int getProductId() const { return product_id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void updateQuantity(int qty)
    {
        quantity += qty;
    }

    double getValue() const
    {
        return quantity * price;
    }

    void display() const
    {
        cout << "ID: " << product_id
             << ", Name: " << name
             << ", Quantity: " << quantity
             << ", Price: " << price << endl;
    }
};

class StoreInventory
{
private:
    Product inventory[100];
    int productCount;

public:
    StoreInventory() : productCount(0) {}

    void addProduct(int id, string name, int quantity, double price)
    {
        if (productCount < 100)
        {
            inventory[productCount] = Product(id, name, quantity, price);
            productCount++;
        }
        else
        {
            cout << "Inventory is full! Cannot add more products." << endl;
        }
    }

    void updateQuantity(int id, int qty)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (inventory[i].getProductId() == id)
            {
                inventory[i].updateQuantity(qty);
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    double calculateTotalValue() const
    {
        double total = 0;
        for (int i = 0; i < productCount; i++)
        {
            total += inventory[i].getValue();
        }
        return total;
    }

    void displayInventory() const
    {
        for (int i = 0; i < productCount; i++)
        {
            inventory[i].display();
        }
    }
};

int main()
{
    StoreInventory store;

    store.addProduct(1, "Apple", 100, 0.50);
    store.addProduct(2, "Banana", 200, 0.30);
    store.addProduct(3, "Orange", 150, 0.40);

    cout << "Inventory: " << endl;
    store.displayInventory();

    store.updateQuantity(1, -50);

    cout << "\nUpdated Inventory: " << endl;
    store.displayInventory();

    double totalValue = store.calculateTotalValue();
    cout << "\nTotal value of inventory: " << totalValue << endl;

    return 0;
}





