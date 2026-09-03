#include <iostream>


int main()
{
    std::string n;
    std::cout << "Enter n\n";
    std::cin >> n;
    int sum1 = n[0] - '0';
    sum1 += n[1] - '0';
    sum1 += n[2]- '0';
    int sum2 = n[3] - '0';
    sum2 += n[4] - '0';
    sum2 += n[5] - '0';
    if (sum1 == sum2)
        std::cout << "number is happy";
    else
        std::cout << "number isn't happy";
}

