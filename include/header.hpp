
// Copyright 2018 Your Name <your_email>
#ifndef STACK_HEADER_HPP
#define STACK_HEADER_HPP
#include <iostream>
#include <string>
#include <utility>
#include "example.cpp"

template<typename T>
struct data {
    T value;
    data *prev = nullptr;
};

template<typename T>
class stack {
public:
    stack() {}

    explicit stack(T &&value) {
        push(value);
    }
   // stack(const stack &) = delete;

    stack(stack &&a) {
        this->top = a.top;
        a.top = nullptr;
    }
   // void operator=(const stack &) = delete;

    void operator=(stack &&a) {

        if (this == &&a)
        {
            return *this;
        }
        this->top = a.top;
        a.top = nullptr;
    }

    void clearer() {
        if (top) {
            /*while (top->prev) {
                data<T> *tmp = std::move(top->prev);
                delete (top);
                top = nullptr;
                std::cout << "cleared";
                top = tmp;
            }*/
            delete (top);
            top = nullptr;
            std::cout << "cleared";
        }
    }


    void push(T &&value) {
        data<T> *tmp;
        tmp = top;
        top = new data<T>;
        top->prev = tmp;
        top->value = value;
    }

    void push(T &value) {
        data<T>*tmp;
        tmp = top;
        top = new data<T>;
        top->prev = tmp;
        top->value = std::move(value);
    }

    T pop() {
        data<T> *tmp;
        tmp = top;
        top = top->prev;
        T tmps = tmp->value;
        if (tmp) { delete (tmp); tmp = nullptr; }
        return tmps;
    }

    const T &head() const {
        return top->value;
    }

    template<typename ... Args>
    void push_emplace(Args &&... value) {
        push(std::forward<T>(T(value...)));
    }

    data<T> *top = nullptr;

    ~stack() { clearer(); }
};

#endif //STACK_HEADER_HPP
