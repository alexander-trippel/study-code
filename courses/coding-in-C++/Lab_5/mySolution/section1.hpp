#include <iostream>

template <typename T>
T swap(T &a, T &b)
{
    std::cout << "erster Wert: " << a << '\n' << "zweiter wert:" << b << std:: endl;

    T temp = a;
    a = b;
    b = temp;

    std::cout << "erster Wert: " << b << '\n' << "zweiter wert:" << a << std:: endl;
}
