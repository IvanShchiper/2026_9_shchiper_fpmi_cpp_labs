#include <iostream>

int main()
{
    int num,a,b,c,d;
    std::cout << "Enter Number\n";
    std::cin >> num;
    a = num % 10;
    b = ((num % 100) - a) / 10  ;
    c = ((num % 1000) - b) / 100;
    d = (num - c) / 1000;
    if (a == d && b == c) 
        std::cout << "Polindrom";
    else
        std::cout << "Not polindrom";
}
