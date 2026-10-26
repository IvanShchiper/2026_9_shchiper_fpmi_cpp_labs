<<<<<<< HEAD
﻿#include <iostream>

int main()
{
    int n, k;

    std::cout << "enter n,k\n";
    std::cin >> n >> k;

    for (int i = 1; i < n; i++) {
        std::cout << "   ";

    }
    int x = 1;
    for (int i = 0; i < k; i++) {
        if(x<10)
            std::cout << "  " << x;
        else
            std::cout << " " << x;
        x++;
        
        if (n == 7) {
            std::cout << std::endl;
            n = 0;
        }
        n++;
        
    }
    

}

=======
﻿#include <iostream>

int main()
{
    int n, k;

    std::cout << "enter n,k\n";
    std::cin >> n >> k;

    for (int i = 1; i < n; i++) {
        std::cout << "   ";

    }
    int x = 1;
    for (int i = 0; i < k; i++) {
        if(x<10)
            std::cout << "  " << x;
        else
            std::cout << " " << x;
        x++;
        
        if (n == 7) {
            std::cout << std::endl;
            n = 0;
        }
        n++;
        
    }
    

}

>>>>>>> baa7e2c5b074b90d4ea7116398a9cb88fbab3b8d
