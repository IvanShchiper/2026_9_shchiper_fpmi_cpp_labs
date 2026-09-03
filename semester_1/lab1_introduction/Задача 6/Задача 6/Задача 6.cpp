#include <iostream>

int main()
{
    int a, b, d;
    //a = a1/d=разность
    std::cout << "enter a,b,d\n";
    std::cin >> a >> b >> d;
    int x = a + d;
    if (a % 3 == 0 && d == 0) {
        std::cout << a;
    }
    else {
        for (int i = 0; i < b; i++) {
            if (x % 3 == 0 && x >= a && x <= b)
                std::cout << x << " ";
            x += d;
        }
    }
}

