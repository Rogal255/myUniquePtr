#pragma once

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
        this->ptr_ = other.release();
        return *this;
    }

    unique_ptr(unique_ptr&& other) noexcept {
        this->ptr_ = other.release();
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

    T* release() noexcept {
        T* temporary = ptr_;
        ptr_ = nullptr;
        return temporary;
    }

    void reset(T* other) noexcept {
        delete ptr_;
        ptr_ = other;
    }

    void reset(unique_ptr other) noexcept {
        delete ptr_;
        ptr_ = other.release();
    }

private:
    T* ptr_{nullptr};
};

}  // namespace pr
