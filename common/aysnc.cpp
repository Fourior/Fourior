//
// Created by zhangyu on 2018/11/18.
//
#include "async.h"

//template <class T>
//Async<T>::Async(std::string task) {
//    std::cout << "Construct!" << std::endl;
//}

//template <class T>
//Async<T>::~Async() {
//    std::cout << "Destruct!" << std::endl;
//}

template <class T>
void Async<T>::InitThread() {
    running_.store(true);
    std::thread t(std::bind(&Async::ThreadLoop, this));
}

template <class T>
void Async<T>::ThreadLoop() {
    auto status = std::cv_status::timeout;
    while(running_.load()) {
        std::unique_lock<std::mutex> lock(cv_mutex_);
        cv_.wait(lock);
    }
}

template <class T>
void Async<T>::Invoke(T& name) {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    task_queue_.emplace(name);
    if(task_queue_.size() >= 100) {
        cv_.notify_one();
    }
}



