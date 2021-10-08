#include <gtest/gtest.h>
#include <utility>
#include "SimpleClass.hpp"
#include "unique_ptr.hpp"

TEST(UniquePtrTest, InitTest) {
    pr::unique_ptr<uint8_t> ptr1{nullptr};
    ASSERT_EQ(ptr1.get(), nullptr);

    pr::unique_ptr ptr2{new SimpleClass};
    ASSERT_NE(ptr2.get(), nullptr);

    auto raw_ptr3 = new SimpleClass;
    pr::unique_ptr ptr3{raw_ptr3};
    ASSERT_EQ(ptr3.get(), raw_ptr3);

    SimpleClass* raw_ptr4 = new SimpleClass;
    pr::unique_ptr ptr4 = raw_ptr4;
    ASSERT_EQ(ptr4.get(), raw_ptr4);
}

TEST(UniquePtrTest, MoveTest) {
    pr::unique_ptr ptr1{new SimpleClass};
    pr::unique_ptr<SimpleClass> ptr2{nullptr};
    auto helper_ptr = ptr1.get();

    // Move assignment operator
    ptr2 = std::move(ptr1);
    ASSERT_EQ(ptr2.get(), helper_ptr);
    ASSERT_EQ(ptr1.get(), nullptr);

    // Move constructor
    pr::unique_ptr ptr3{std::move(ptr2)};
    ASSERT_EQ(ptr3.get(), helper_ptr);
    ASSERT_EQ(ptr2.get(), nullptr);
}

TEST(UniquePtrTest, CallTest) {
    constexpr int val{10};
    pr::unique_ptr ptr{new SimpleClass};
    ASSERT_EQ(ptr->callMe(val), val);
}

TEST(UniquePtrTest, DereferenceTest) {
    pr::unique_ptr ptr1{new int(5)};
    auto helper_ptr = ptr1.get();

    ASSERT_EQ(*ptr1, *helper_ptr);
}

TEST(UniquePtrTest, ReleaseTest) {
    auto helper_ptr = new SimpleClass;
    pr::unique_ptr ptr{helper_ptr};
    auto released_ptr = ptr.release();

    ASSERT_EQ(released_ptr, helper_ptr);
    ASSERT_EQ(ptr.get(), nullptr);
}

TEST(UniquePtrTest, ResetTest) {
    constexpr int val{10};
    pr::unique_ptr ptr1{new int(1)};
    pr::unique_ptr ptr2{new int(val)};
    auto helper_ptr = ptr2.get();
    ptr1.reset(std::move(ptr2));
    ASSERT_EQ(ptr1.get(), helper_ptr);
    ASSERT_EQ(*ptr1.get(), val);
    ASSERT_EQ(ptr2.get(), nullptr);

    pr::unique_ptr ptr3{new int(1)};
    ptr3.reset(new int(val));
    ASSERT_EQ(*ptr3.get(), val);
}

TEST(UniquePtrTest, BoolOperatorTest) {
    pr::unique_ptr ptr1 {new SimpleClass};
    ASSERT_TRUE(ptr1);

    pr::unique_ptr<SimpleClass> ptr2 {nullptr};
    ASSERT_FALSE(ptr2);
}
