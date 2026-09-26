//Преобразовать одномерный массив, состоящем из n целых элементов,
//оставив из всех цепочек идущих подряд одинаковых элементов только один такой элемент.
//Освободившиеся в конце места заполнить нулями.
#include <iostream>


void num_el(int* num);
void vibor(int* x);
void enter(int n, int *mass);
void enter_rand(int n, int *mass);
void vivod(int n, int *mass);
void sollution(int n, int *mass);



int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));
    const int max = 200000;
    int n, x, mass[max] = {0};


    num_el(&n);
    vibor(&x);

    switch (x) {
        case 1: enter(n, mass); break;
        case 2: enter_rand(n, mass); break;
    }
    vivod(n, mass);
    sollution(n,mass);
    vivod(n, mass);
    return 0;
}

//размерность массива
void num_el(int* num) {
    std::cout << "Введите размер массива(число)\n";
    if (!(std::cin >> *num) || *num < 0) {
        std::cout << "Должно быть введено неотрицательное число\n";
        std::exit(-1);
    }
    if (*num == 0) {
        std::cout << "Нет элементов\n";
        std::exit(0);
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
void enter(int n, int *mass) {
    std::cout << "Введите елементы " << std::endl;
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> mass[i])) {
            std::cout << "Должны быть введены только числа\n";
            std::exit(-1);
        }
    }
}

//ввод рандомом
void enter_rand(int n, int *mass) {
    int a, b;
    std::cout << "Введите границы a и b: \n";
    std::cin >> a >> b;
    for (int i = 0; i < n; i++) {
        mass[i] = a + rand() % (b - a + 1);
    }
}

//вывод
void vivod(int n, int *mass) {
    std::cout << "Значения массива: ";
    for (int i = 0; i < n; i++) {
        std::cout << mass[i] << " ";
    }
    std::cout << std::endl;
}

//изменение массива
void sollution(int n, int* mass) {
    int j = 1;
    for (int i = 1; i < n;i++) {
        if (mass[i] != mass[j - 1]) {
            mass[j] = mass[i];
            j++;
        }
    }
    for (int k=j;k < n; k++) {
        mass[k] = 0;
    }
    std::cout << "Изменение массива\n";
}
