#pragma once

namespace pr {

template <class T>
class unique_ptr {
public:
    unique_ptr(T* ptr)
        : ptr_(ptr) {}

    ~unique_ptr() {
        delete ptr_;
        ptr_ = nullptr;
    }

    unique_ptr(const unique_ptr& other) = delete;
    unique_ptr& operator=(const unique_ptr& other) = delete;

    T* operator->() const noexcept {
        return this->get();
    }

    T& operator*() const noexcept {
        return *this->get();
    }

    T* get() const  {
        return ptr_;
    }

    T* realase() {
        T* temporary = ptr_;
        ptr_ = nullptr;
        return temporary;
    }

    void reset(T* other) {
        delete ptr_;
        ptr_ = other;
    }

private:
    T* ptr_{nullptr};
};

}  // namespace pr
