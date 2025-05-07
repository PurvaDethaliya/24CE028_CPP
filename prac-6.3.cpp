#include <iostream>
using namespace std;

int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2)
{
    int* mergedArray = new int[size1 + size2];

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            mergedArray[k++] = arr1[i++];
        }
        else {
            mergedArray[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        mergedArray[k++] = arr1[i++];
    }

    while (j < size2)
    {
        mergedArray[k++] = arr2[j++];
    }

    return mergedArray;
}

int main()
{
    int size1, size2;

    cout << "Enter the size of the first sorted array: ";
    cin >> size1;

    cout << "Enter the size of the second sorted array: ";
    cin >> size2;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    cout << "Enter " << size1 << " elements for the first sorted array:\n";
    for (int i = 0; i < size1; ++i)
    {
        cin >> arr1[i];
    }

    cout << "Enter " << size2 << " elements for the second sorted array:\n";
    for (int i = 0; i < size2; ++i)
    {
        cin >> arr2[i];
    }

    int* mergedArray = mergeSortedArrays(arr1, size1, arr2, size2);

    cout << "\nMerged sorted array: ";
    for (int i = 0; i < size1 + size2; ++i)
    {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArray;

    return 0;
}

