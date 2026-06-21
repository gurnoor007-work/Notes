#include <iostream>
#include <format>
using namespace std;

// Structs are used to define a "Data Type" and things related to it
struct myArray
{
    int total_size;
    int used_size;
    int *ptr; // pointer which points to the start (first element) of array
};

// function to create an array
void createArray(struct myArray *a, int tSize, int uSize)
{
    // a is a pointer. *a will be the actual objects with values
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int*) malloc(tSize*sizeof(int));

    // BETTER WAY TO DO THIS:
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

// function to show the array - Also TRANVERSAL4
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << a->ptr[i] << " ";
    }
    cout << '\n';
}

// function to set values
void setVal(struct myArray *a){
    for (int i = 0; i < a->used_size; i++){
        std::cout << std::format("Enter number {}:", i+1);
        std::cin >> a->ptr[i];
    }
}

// Insertion Function (O(n))
int indInsertion(struct myArray* a, int index, int value){
    if(a->used_size == a->total_size) {
        printf("not enough size");
        return -1;
    }
    else if(index == a->used_size){
        printf("Value added at end");
        a->ptr[index] = value;
        a->used_size += 1;
        return 0;
    }

    for (int i = a->used_size - 1; i >= index; i--){
        a->ptr[i+1] = a->ptr[i];
        cout << format("value {} at index {} shifted to index {}\n", a->ptr[i], i, i+1);
    }
    a->used_size += 1;
    a->ptr[index] = value;
    return 0;
}

// Deletion Function
int indDelete(struct myArray* a, int index){
    if (index > a->used_size - 1){
        cout << "index out of array";
        return -1;
    }

    for (int i = index; i <= a->used_size; i++){
        a->ptr[i] = a->ptr[i+1];
        cout << format("value {} at index {} shifted to index {}\n", a->ptr[i+1], i+1, i);
    }
    return 0;
}

int main()
{
    struct myArray marks;
    createArray(&marks, 15, 5);
    setVal(&marks);

    indInsertion(&marks, 2, 100);
    show(&marks);

    indDelete(&marks, 2);
    show(&marks);

    return 0;
}