//В каждой строке матрицы A n × m сдвинуть все ненулевые элементы влево, сохраняя их относительный порядок.
//Освободившиеся места в конце каждой строки заполнить нулями.
//Дополнительных массивов для хранения строк не использовать. Вывести исходную и получившуюся матрицы.
#include <iostream>
#include <iomanip>

void delete_memory(int n, int** matr);
void memory(int n, int m, int** matr);
void enter_h(int n, int m, int** matr);
void enter_rand(int n, int m, int** matr);
void enter(int n, int m, int** matr);
void vivod(int n, int m, int** matr);
void soll(int n, int m, int** matr);
void vvod(int* n, int* m);

int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));

    int n,m;
    vvod(&n, &m);

    int** matr = new int* [n];
    memory(n, m, matr);

    enter(n, m, matr);
    std::cout << "исходная матрица: \n";
    vivod(n, m, matr);
    soll(n, m, matr);
    std::cout << "измененная матрица: \n";
    vivod(n, m, matr);
    
    delete_memory(n,matr);

    return 0;
}
//выделение памяти
void memory(int n, int m, int** matr) {
    for (int i = 0; i < n; ++i) {
        matr[i] = new int[m];
    }
}
//удаление памяти
void delete_memory(int n, int **matr) {
    for (int i = 0; i < n; ++i) {
        delete[] matr[i];
    }
    delete[] matr;
}
//Сдвиг всех ненулевых элементов влево
void soll(int n,int m, int**matr) {

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m - 1; ++k) {
            std::swap(matr[i][k], matr[i][k + 1]);
        }
        
        int pos = 0;
        for (int k = 0;k < m;++k) {
            if (matr[i][k] != 0) {
                matr[i][pos] = matr[i][k];
                pos++;
            }
        }
        while (pos < m) {
            matr[i][pos] = 0;
            pos++;
        }
        
    }
}

//Ввод размерности
void vvod(int *n,int *m) {
    std::cout << "Введите число строк и столбцов\n";
    if (!(std::cin >> *n) || !(std::cin >> *m) || *n <= 0 || *m <= 0){
        std::cout << "Нужно ввести положительные числа";
        std::exit(-1);
    }
}
//заполнение массива вручную
void enter_h(int n, int m, int** matr) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Введите " << i + 1 << " строку: ";
        for (int k = 0; k < m; ++k) {
            if (!(std::cin >> matr[i][k])) {
                std::cout << "Нужно ввести только числа";
                std::exit(-1);
            }
        }
    }
}
//заполнение массива рандомом
void enter_rand(int n, int m, int** matr) {
    int a, b;
    std::cout << "Введите границы [a,b]: ";
    if (!(std::cin >> a) || !(std::cin >> b) || a>b) {
        std::cout << "Нужно ввести только числа(a>b)";
        std::exit(-1);
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            matr[i][k] = a + rand() % (b - a + 1);
        }
    }
}
//заполнение массива
void enter(int n, int m, int** matr) {
    int x;
    std::cout << "Выберите способ заполнения массива\n 1 - если вручную\n 2 - если рандомом\nВаш выбор: ";
    if (!(std::cin >> x) || (x != 1 && x != 2)) {
        std::cout << "Нужно ввести число(1 или 2)";
        std::exit(-1);
    }
    switch (x) {
    case 1: enter_h(n, m, matr);break;
    case 2: enter_rand(n, m, matr); break;
    }
}
//вывод массива
void vivod(int n, int m, int** matr) {
    for (int i = 0;i < n;++i) {
        for (int k = 0;k < m;++k) {
            std::cout << std::setw(3) << matr[i][k] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}