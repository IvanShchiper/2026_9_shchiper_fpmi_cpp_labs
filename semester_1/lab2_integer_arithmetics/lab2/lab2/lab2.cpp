<<<<<<< HEAD
﻿#include <iostream>
#include <cmath>
int main()
{
    int a, b;
    std::cout << "enter a\n";
    std::cin >> a;
    std::cout << "enter b\n";
    std::cin >> b;
    int res = 3;
    for (int n = 1; res <= b; n++) {
        if (res >= a)
            std::cout << res << std::endl;
        res = pow(2, pow(2, n)) + 1;
    }
    
    return 0;
}
=======
﻿#include <iostream>
#include <cmath>
int main()
{
    int a, b;
    std::cout << "enter a\n";
    std::cin >> a;
    std::cout << "enter b\n";
    std::cin >> b;
    int res = 3;
    for (int n = 1; res <= b; n++) {
        if (res >= a)
            std::cout << res << std::endl;
        res = pow(2, pow(2, n)) + 1;
    }
    
    return 0;
}
>>>>>>> baa7e2c5b074b90d4ea7116398a9cb88fbab3b8d
