#include<iostream>

class DynamicArray
{
    //Declaring tow data members for arr and size n
    private:
    int n;
    int * arr;

    public:
    DynamicArray(int n);
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    int operator[](int index);
    int getElement(int index);
    int at(int index);
    int size();

    /*Automatic cleanup of the array*/
    ~DynamicArray();
};