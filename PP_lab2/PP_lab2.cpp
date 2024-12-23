﻿#include "ThreadsPool.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

const double PI = 3.14159265358979323846;

double factorial(int n) {
    if (n <= 1) return 1;
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

vector<double> generateRandomArray(int n) {
    // Вектор для хранения элементов
    vector<double> array(n);

    // Генератор случайных чисел
    random_device rd;  // Получение несущего семени для генератора
    mt19937 gen(rd()); // Инициализация генератора
    uniform_real_distribution<> dis(1e-300, 1e-10); // Диапазон значений

    // Заполнение массива случайными числами
    for (unsigned int i = 0; i < n; ++i) {
        array[i] = dis(gen);
    }

    return array;
}

void my_cos(double x) {
    // Приведение x к диапазону [0, 2*PI]
    x = fmod(x, 2 * PI);

    double  avgSum = 0.0;
    int N = 1000000;
    vector<double> tolerance = generateRandomArray(N);
    double term;
    double sum;
    int n;

    for (int i = 0; i < N; i++) {
        sum = 0.0;
        n = 0;
        do {
            term = (n % 2 == 0 ? 1 : -1) * (pow(x, 2 * n) / factorial(2 * n));
            sum += term;
            n++;
        } while (fabs(term) >= tolerance[i]); // проделываем, пока член больше заданной точности
        //printf("%.30f\n", sum);
        avgSum += sum;
    }
    avgSum /= N;
    printf("Cosinus of %.2f = %.30f\n", x, avgSum);
}


int main()
{
    threadsPool pool;
    unsigned int n = pool.GetCntThreads();
    printf("Number of Threads: %i\n", n);
    
    if (n != 0) {
        for (unsigned int i = 0; i < n; i++) {
            pool.passQ(my_cos, PI * i / 2);
        }
    }
    else {
        printf("No free threads..");
    }
    
  
   
}