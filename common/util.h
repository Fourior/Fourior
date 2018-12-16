//
// Created by zhangyu on 2018/11/18.
//

#ifndef FOURIOR_UTIL_H
#define FOURIOR_UTIL_H
#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <random>
#include <atomic>
#include <future>
#include <chrono>
#include <shared_mutex>
#include <list>

class Util {
public:
    Util(){};

    Util(std::string name, int32_t age = 12) : name_(name), age_(age){
        std::cout << "Construct!" << std::endl;
    };

    Util(const Util& C) {
        name_ = C.name_;
        age_ = C.age_ + 5;
        std::cout << "Copy Construct!" << std::endl;
    }


    ~Util() {
        std::cout << "Destruct!" << std::endl;
    };

    Util& operator=(const Util& C) {
        std::cout << "operator=" << std::endl;
        if (this != &C) {
            name_ = C.name_;
            age_ = C.age_ * 2;
            return *this;
        }
        return *this;
    }

    std::string get_name() {
        return this->name_;
    }

    std::int32_t get_age() {
        return this->age_;
    }
    static float get_random_pct() {
        static thread_local std::mt19937 gen((std::random_device())());
        std::uniform_real_distribution<float> pct(0, 1.0);
        float r = pct(gen);
        return r;
    }

private:
    std::string name_;
    int32_t age_;
};


#endif //FOURIOR_UTIL_H
