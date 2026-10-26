
// solve task with usage of
// dymanic arrays
#include <iostream>


void num_el(int* num);
void vibor(int* x);
void enter(int n, int* mass);
void enter_rand(int n, int* mass);
void vivod(int n, int* mass);
void sollution(int n, int* mass);



int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));
    int n, x, *mass = nullptr;
    num_el(&n);
    vibor(&x);
    mass = new int[n];
    switch (x) {
    case 1: enter(n, mass); break;
    case 2: enter_rand(n, mass); break;
    }
    vivod(n, mass);
    sollution(n, mass);
    vivod(n, mass);
    delete[] mass;
    mass = nullptr;
    return 0;
}

//размерность массива
void num_el(int* num) {
    std::cout << "Введите размер массива(число)\n";
    if (!(std::cin >> *num) || *num < 0) {
        if (*num > 2147483647) {
            std::cout << "Переполнение массива";
            std::exit(-1);
        }
        std::cout << "Должно быть введено неотрицательное число\n";
        std::exit(-1);
    }
    if (*num == 0) {
        std::cout << "Нулевой массив\n";
        std::exit(0);
    }
    if (*num > 2147483647) {
        std::cout << "Переполнение массива";
        std::exit(-1);
    }
}
//выбор ввода
void vibor(int* x) {
    std::cout << "Выберите, как хотите ввести массив: \n" << "1 если вручную, 2 если рандомом: ";
    if (!(std::cin >> *x) || (*x != 1 && *x != 2)) {
        std::cout << "Должно быть введено 1 или 2\n";
        std::exit(-1);
    }
}
//ввод вручную
void enter(int n, int* mass) {
    std::cout << "Введите елементы " << std::endl;
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> mass[i])) {
            std::cout << "Должны быть введены только числа\n";
            std::exit(-1);
        }
    }
}

//ввод рандомом
void enter_rand(int n, int* mass) {
    int a, b;
    std::cout << "Введите границы [a, b]: \n";
    if (!(std::cin >> a) || !(std::cin >> b)) {
        std::cout << "Должны быть введены только числа\n";
        std::exit(-1);
    }
    if (b < a) {
        std::cout << "a должно быть меньше b";
        std::exit(-1);
    }
    for (int i = 0; i < n; i++) {
        mass[i] = a + rand() % (b - a + 1);
    }
}

//вывод
void vivod(int n, int* mass) {
    std::cout << "Значения массива: ";
    for (int i = 0; i < n; i++) {
        std::cout << mass[i] << " ";
    }
    std::cout << std::endl;
}

//изменение массива
void sollution(int n, int* mass) {
    int m;
    std::cout << "Введите число m\n";
    if (!(std::cin >> m)) {
        std::cout << "Должно быть введено число\n";
        std::exit(-1);
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (std::abs(mass[i] ) <= m) {
            mass[j] = mass[i];
            j++;
        }
    }
    for (j; j < n; j++) {
        mass[j] = 0;
    }
    std::cout << "Массив изменен\n";
}
