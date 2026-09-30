#include "DynamicArray.hpp" // if we give "" it accepts compated to <>

//This is old style
// DynamicArray::DynamicArray(int size)
// {
//     this->n = size;
//     arr = new int[n]{}; // Here if we do not give {} garbage values will be initialized
// }

//Using initializer list
DynamicArray::DynamicArray(int size):n(size),arr(new int[n]{})
{

}

int DynamicArray::getElement(int index)
{
    //Size check so that it is not out of range
    if(index< 0 || index >n)
    {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];

}

//We can also handle out of range with the operator overloading of [] /at()

int DynamicArray::operator[](int index)
{
    return arr[index];

}

int DynamicArray::at(int index)
{
    //Size check so that it is not out of range
    if(index< 0 || index >n)
    {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];

}

DynamicArray::DynamicArray(const DynamicArray& other):n(other.n),arr(new int[other.n])
{
    for(int i=0;i<n;i++)
    {
        arr[i] = other.arr[i];
    }
}

//copy assignment operator to prevent shallow copy
DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if(this == &other)
    return *this;

    delete[] this->arr;

    this->n = other.n;
    this->arr = new int[n];

    for(int i=0;i<n;i++)
    {
        this->arr[i] = other.arr[i];

    }
    return *this;

}


int DynamicArray::size()
{
    return n;
}

DynamicArray::~DynamicArray() 
{
    delete[] arr;
}
int main()
{
    return 0;
}
