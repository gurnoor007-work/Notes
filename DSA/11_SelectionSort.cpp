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

int findMin(std::vector<int> a)
{
    int min_idx;
    for (int i; i < a.size(); i++)
    {
        int present = a[i];
        if (present < a[min_idx])
        {
            min_idx = i;
        }
    }
    return min_idx;
}

void selectionSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << "Divider on: " << arr[i] << "\n";
        std::vector<int> slice(arr.begin() + i, arr.end());
        int min_idx = findMin(slice);
        if (arr[min_idx] < arr[i])
        {
            std::cout << "Switching these: " << arr[i] << " and " << arr[min_idx] << "\n";
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            printArr(arr);
        }
    }
}

int main()
{
    std::vector<int> arr = {8, 9, 1, 3, 10};
    printArr(arr);
    selectionSort(arr);
    printArr(arr);
    return 0;
}