#include <iostream>
#include <string>
#include <vector>

template <typename T>
void swap(T &a, T &b)
{
    std::cout << "erster Wert: " << a << '\n' << "zweiter wert:" << b << std:: endl;

    T temp = a;
    a = b;
    b = temp;

    std::cout << "erster Wert: " << a << '\n' << "zweiter wert:" << b << std:: endl;
    return;
}

int printArray(int *arr, int size)
{
    for(
}

int main()
{
    /*
    int zahl1 = 10;
    int zahl2 = 12;

    swap(zahl1, zahl2);
    */

    std::vector<int> v = {2,4,3,2,6,8};
}