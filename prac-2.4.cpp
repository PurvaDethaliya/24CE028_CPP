#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item
{
public:
    string itemID;
    string itemName;
    double price;
    int quantity;

    Item(string id, string name, double p, int q)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    void addStock(int quantityToAdd)
    {
        quantity += quantityToAdd;
    }

    bool sellItem(int quantityToSell)
    {
        if (quantityToSell > quantity)
        {
            cout << "Not enough stock available to complete the sale!" << endl;
            return false;
        }
        else
        {
            quantity -= quantityToSell;
            return true;
        }
    }

    void displayItemDetails() const
    {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity Available: " << quantity << endl;
    }
};

void displayInventory(const vector<Item>& inventory)
{
    cout << "\n--- Inventory List ---\n";
    for (const auto& item : inventory)
    {
        item.displayItemDetails();
        cout << "-----------------------" << endl;
    }
}

int main()
{
    vector<Item> inventory;

    while (true)
    {
        cout << "\n--- Retail Store Inventory Management ---\n";
        cout << "1. Add New Item\n";
        cout << "2. Increase Stock\n";
        cout << "3. Process Sale\n";
        cout << "4. Display Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string itemID, itemName;
                double price;
                int quantity;
                cout << "Enter Item ID: ";
                cin >> itemID;
                cout << "Enter Item Name: ";
                cin.ignore();
                getline(cin, itemName);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Initial Quantity: ";
                cin >> quantity;

                inventory.push_back(Item(itemID, itemName, price, quantity));
                cout << "Item added successfully!" << endl;
                break;
            }
            case 2: {
                // Increase Stock
                string itemID;
                int quantityToAdd;
                cout << "Enter Item ID to increase stock: ";
                cin >> itemID;
                cout << "Enter Quantity to Add: ";
                cin >> quantityToAdd;

                bool itemFound = false;
                for (auto& item : inventory) {
                    if (item.itemID == itemID) {
                        item.addStock(quantityToAdd);
                        cout << "Stock updated successfully!" << endl;
                        itemFound = true;
                        break;
                    }
                }
                if (!itemFound) {
                    cout << "Item not found!" << endl;
                }
                break;
            }
            case 3: {
                string itemID;
                int quantityToSell;
                cout << "Enter Item ID to process sale: ";
                cin >> itemID;
                cout << "Enter Quantity to Sell: ";
                cin >> quantityToSell;

                bool itemFound = false;
                for (auto& item : inventory) {
                    if (item.itemID == itemID) {
                        if (item.sellItem(quantityToSell)) {
                            cout << "Sale processed successfully!" << endl;
                        }
                        itemFound = true;
                        break;
                    }
                }
                if (!itemFound) {
                    cout << "Item not found!" << endl;
                }
                break;
            }
            case 4: {

                displayInventory(inventory);
                break;
            }
            case 5: {

                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
