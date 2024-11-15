#pragma once
#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <queue>
#include <functional>

using namespace std;

struct task {
    function<void(int, int)> func;
    int param1;
    int param2;

    task(function<void(int, int)> f, int p1, int p2)
        : func(f), param1(p1), param2(p2) {}
};

class threadsPool {
private:
    vector <thread> threads;
    int cntThreads = 0;
    queue <task> q;
    condition_variable condition;
    mutex m;

public:

    threadsPool();
    ~threadsPool();
    int GetCntThreads();
    void run();
    void passQ(function<void(int, int)> f, int p1, int p2);

};
