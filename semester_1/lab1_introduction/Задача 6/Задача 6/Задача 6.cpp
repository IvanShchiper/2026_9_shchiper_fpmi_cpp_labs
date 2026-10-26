#include <iostream>

int main()
{
    int a, b, d;
    bool p = false;
    //a = a1/d=разность
    std::cout << "enter a,b,d\n";
    std::cin >> a >> b >> d;
    int x = a + d;
    if (a % 3 == 0 && d == 0) {
        std::cout << a;
        return 0;
    }
   else if (d < 0) {
        std::cout << "None";
        return 0;
        }
   
    else {
        //for (int i = a; i <= b; i++) 
        for (int i = 0; i < b; i++) {
            if (x % 3 == 0 && x >= a && x <= b) {
                std::cout << x << " ";
                p = true;
            }
            x += d;
            
        }
        if (p == false)
            std::cout << "None";
        return 0;
    }
    std::cout << "None";
    return 0;
}

