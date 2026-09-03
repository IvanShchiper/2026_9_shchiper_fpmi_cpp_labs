#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    int n, m;
    cout << "Input n\n";
    cin >> n;
    cout << "Input m\n";
    cin >> m;
    int min = std::min(n, m);
    if (n <= 0 || m <= 0) {
        cout << "n, m must be positive";
        std::exit(-1);//экстренно закончить программу
    }
    cout << 1 << " ";
    for (int i = 2; i <= min; i++)
    {
        if (n % i == 0 && m % i == 0) {
            cout << i << " ";
        }
    }
}

