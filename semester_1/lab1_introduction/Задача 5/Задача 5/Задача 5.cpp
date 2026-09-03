#include <iostream>

int main()
{
    std::cout << "enter n\n";
    int n;
    std::cin >> n;
    int a = 0;
    int b = 1;
   
    

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            std::cout << a << " ";
            std::cout << b << " ";
            a += b;
            b += a;
        }
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            std::cout << a << " ";
            std::cout << b << " ";
            a += b;
            b += a;
        }
        std::cout << a;
    }
}

