#pragma once
#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <queue>
#include <functional>

using namespace std;

class threadsPool {
private:
    vector <thread> threads;
    int cntThreads = 0;
    queue <function <void()>> q;
    condition_variable condition;
    mutex m;

public:

    threadsPool();
    ~threadsPool();
    int GetCntThreads();
    void run();
    void passQ(function<void()> f);

};
