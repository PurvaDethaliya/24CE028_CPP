#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; ++i)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;

        arr = newArr;
    }

public:
    DynamicArray() : size(0), capacity(2)
    {
        arr = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    void addElement(int element)
    {
        if (size == capacity)
        {
            resize();
        }
        arr[size++] = element;
    }

    void removeElementAtPosition(int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Error: Invalid position!" << endl;
            return;
        }

        for (int i = position; i < size - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }

        --size;
    }

    void display() const
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    DynamicArray data;
    int option;

    while (true)
    {
        cout << "\n--- Dynamic Array Operations ---\n";
        cout << "1. Add element\n";
        cout << "2. Remove element at specific position\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> option;

        if (option == 1)
        {
            int element;
            cout << "Enter element to add: ";
            cin >> element;
            data.addElement(element);
            cout << "Element added successfully!" << endl;
        }
        else if (option == 2)
        {
            int position;
            cout << "Enter position to remove element: ";
            cin >> position;
            data.removeElementAtPosition(position);
        }
        else if (option == 3)
        {
            cout << "Current array: ";
            data.display();
        }
        else if (option == 4)
        {
            cout << "Exiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
