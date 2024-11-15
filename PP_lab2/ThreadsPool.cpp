#include "ThreadsPool.h"

threadsPool::threadsPool() {
    cntThreads = thread::hardware_concurrency();
    for (int i = 0; i <= cntThreads; i++) {
        threads.emplace_back(&threadsPool::run, this);
    }
    //lock_guard<mutex> M(m);
}

threadsPool::~threadsPool() {
    for (int i = 0; i <= cntThreads; i++) {
        if (threads[i].joinable())
            threads[i].join();
    }
    //unique_lock<mutex> M1(m);
}

int threadsPool::GetCntThreads()
{
    return cntThreads;
}

void threadsPool::run()
{
    while (true) {
        unique_lock<mutex> lk(m);
        condition.wait(lk, [this]() {return !q.empty(); });
        task t = q.front();
        q.pop();
        lk.unlock();
        t.func(t.param1,t.param2);
    }
}

void threadsPool::passQ(function<void(int, int)> f, int p1, int p2)
{
    lock_guard<mutex> lg(m);
    task t = task(f, p1, p2);
    q.push(t);
    condition.notify_one();
}

