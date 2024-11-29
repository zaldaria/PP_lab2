#include "ThreadsPool.h"

threadsPool::threadsPool() {
    cntThreads = thread::hardware_concurrency();
    for (int i = 0; i <= cntThreads; i++) {
        threads.emplace_back(&threadsPool::run, this);
    }

}

threadsPool::~threadsPool() {
    stop = true;
    condition.notify_all();

    for (int i = 0; i <= cntThreads; i++) {
        if (threads[i].joinable())
            threads[i].join();
    }
}

int threadsPool::GetCntThreads()
{
    return cntThreads;
}

void threadsPool::run()
{
    while (true) {
        unique_lock<mutex> lk(m);
        condition.wait(lk, [this]() {return !q.empty() || stop; });
        if (!q.empty()) {
            task t = q.front();
            q.pop();
            lk.unlock();
            t.func(t.param1);
        }
        if (stop)
            break;
       
    }
}

void threadsPool::passQ(function<void(double)> f, double p1)
{
    lock_guard<mutex> lg(m);
    task t = task(f, p1);
    q.push(t);
    condition.notify_one();
}

