#pragma once

#include <iostream>

namespace pr {

template <class T>
class unique_ptr {
public:
    unique_ptr(T* ptr) noexcept
        : ptr_(ptr) {}

    ~unique_ptr() noexcept {
        delete ptr_;
        ptr_ = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        this->ptr_ = other.realase();
        std::cout << "unique ptr move operator=\n";
        return *this;
    }

    unique_ptr(unique_ptr&& other) noexcept {
        this->ptr_ = other.realase();
        std::cout << "unique ptr move c'tor\n";
    }

    unique_ptr& operator=(const unique_ptr& other) = delete;
    unique_ptr(const unique_ptr& other) = delete;

    T* operator->() const noexcept {
        return this->get();
    }

    T& operator*() const noexcept {
        return *this->get();
    }

    T* get() const noexcept {
        return ptr_;
    }

    T* realase() noexcept {
        T* temporary = ptr_;
        ptr_ = nullptr;
        return temporary;
    }

    void reset(T* other) noexcept {
        delete ptr_;
        ptr_ = other;
    }

private:
    T* ptr_{nullptr};
};

}  // namespace pr
