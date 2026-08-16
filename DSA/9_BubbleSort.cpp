#include <iostream>
#include <vector>

void printArr(std::vector<int> arr)
{
    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void bubbleSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int change = 0;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                change++;
            }
        }
        // Make the algorithm adaptive
        if (change == 0)
        { // Break if there is no change at any pass (this means that array is already sorted for that pass)
            break;
        }
    }
}

int main()
{
    std::vector<int> arr = {15, 22, 1, 55, 2, 0};
    printArr(arr);
    bubbleSort(arr);
    printArr(arr);
    return 0;
}