//
// Created by zhangyu on 2018/11/18.
//

#ifndef FOURIOR_ASYNC_H
#define FOURIOR_ASYNC_H
#pragma once
#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <queue>

template <class T>
class Async {
public:
    Async():running_(false) {};

    explicit Async(std::string name):running_(false) {
        std::cout << "Construct!" << std::endl;
    };

    ~Async() {
        std::cout << "Destruct!" << std::endl;
    }

    void ThreadLoop();
    void InitThread();

    void Invoke(T& name);
private:
    std::condition_variable cv_;
    std::mutex queue_mutex_;
    std::mutex cv_mutex_;
    std::atomic<bool> running_;

    std::queue<T> task_queue_;

};

class Task {
public:
    Task();
    ~Task() = default;

    std::string name_;
};
#endif //FOURIOR_ASYNC_H
