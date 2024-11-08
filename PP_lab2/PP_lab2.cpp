#include "ThreadsPool.h"
#include <iostream>

using namespace std;


void printOk() {
    cout << "Okk";
}

int main()
{
    threadsPool pool;
    int n = pool.GetCntThreads();

    for (int i = 0; i < n; i++) {
        pool.passQ(printOk);
    }



}