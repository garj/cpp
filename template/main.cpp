#include <iostream>

using namespace std;

template<typename T>
T MYMAX(const T&a, const T&b)
{
    return a > b ? a : b;
}

// using template explicit specialization   
// non-speciliazed funtion needs to be defined first
template<>
float MYMAX(const float&a, const float&b)
{
    cout << "This is used for float \n";
    return a > b ? a : b;    
}

template<typename T>
void SIZE_OF()
{
    cout << "Size of type is " << sizeof(T) << "\n";
}

template<typename T1, typename T2>
void TWO_TYPES(const T1& a, const T2& b)
{
    cout << a << "\n";
    cout << b << "\n";
}

int main(int argc, char* argv[])
{
    // compiler infer type
    cout << MYMAX(1, 2) << "\n";

    // using template explicit specialization    
    cout << MYMAX(1.2f, 1.3f) << "\n";

    // Explicit template argument specification
    cout << MYMAX<int>(1.2f, 2.5f) << "\n";

    //SIZE_OF(); // this wont compile as it has no type to infer T
    SIZE_OF<int>(); // prints 4
    SIZE_OF<double>(); // prints 8

    // Mutiple types function template
    TWO_TYPES<int, float>(1, 1.1);
}