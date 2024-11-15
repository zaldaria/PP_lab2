#include "ThreadsPool.h"
#include <windows.h>
#include <iostream>

using namespace std;


void printOk(int a, int b) {
    printf("Wait...");
    for (int i = 0; i < 10; i++) {
        //printf(".");
        printf("\na = %i; b = %i;", a, b);
        Sleep(2000);
    }
    //printf("\na = %i; b = %i;", a, b);
    printf("\nOkk");
}

void power(double a, double n) {
    double res = pow(a, n);
    cout << res;
}

int main()
{
    /*threadsPool pool;
    int n = pool.GetCntThreads();

    for (int i = 0; i < n; i++) {
        pool.passQ(printOk, i, i + 1);
    }*/
    power(10, 500);

}