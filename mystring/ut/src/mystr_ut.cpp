//
// Created by nte on 7/25/21.
//
#include <mystring.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace pawel;

TEST(FUNCTIONS, LENGTH) {
    mystring f0;
    mystring f1 = "a";
    mystring f2 = "ab";
    mystring f3 = "abc";
    mystring f4 = "abd";
    ASSERT_EQ(f0.length(), 0);
    ASSERT_EQ(f1.length(), 1);
    ASSERT_EQ(f2.length(), 2);
    ASSERT_EQ(f3.length(), 3);
    ASSERT_EQ(f4.length(), 3);
}

TEST(FUNCTIONS, SIZE) {
    mystring f0;
    mystring f1 = "ab";
    const char* st = "\"123456789012345678901\"";
    mystring f2(st);
    ASSERT_EQ(f0.size(), f1.size());
    ASSERT_GE(f2.size(), strlen(st));
}

TEST(FUNCTIONS, BUFFER) {
    ;
}

TEST(FUNCTIONS, RESIZE) {
    ;
}

TEST(KONSTRUKTOR_DOMYSLNY, EMPTY_OBJECT) {
    mystring empt;
    ASSERT_EQ(0, empt.length());
    ASSERT_EQ(INITIAL_SIZE_OF_BUFFER, empt.size());
    ASSERT_STREQ("", empt.buffer());
}

TEST(KONSTRUKTOR_CONST_CHAR, OBJECT) {
    const char* text = "Hello world";
    int text_len = strlen(text);
    mystring obj(text);
    ASSERT_EQ(text_len, obj.length());
    ASSERT_LE(obj.length(), obj.size());
    ASSERT_STREQ(text, obj.buffer());
}

TEST(KONSTRUKTOR_CONST_CHAR, EMPTY_OBJECT) {
    mystring emp("");
    ASSERT_EQ(0, emp.length());
    ASSERT_GE(emp.size(), emp.length());
    ASSERT_STREQ(emp.buffer(), "");
}

TEST(KONSTRUKTOR_KOPIUJACY, OBJECT) {
    const char* text = "Hello world";
    int text_len = strlen(text);
    mystring obj(text);
    mystring obj_test(obj);
    ASSERT_EQ(strlen(text), obj_test.length());
    ASSERT_EQ(INITIAL_SIZE_OF_BUFFER, obj_test.size());
    ASSERT_STREQ(text, obj_test.buffer());

}

TEST(KONSTRUKTOR_KOPIUJACY, EMPTY_OBJECT) {
    mystring emp("");
    mystring obj_test(emp);
    ASSERT_EQ(0, obj_test.length());
    ASSERT_EQ(INITIAL_SIZE_OF_BUFFER, obj_test.size());
    ASSERT_STREQ("", obj_test.buffer());
}

TEST(KONSTRUKTOR_PRZENOSZACY, OBJECT) {
    const char* str = "Hello world";
    int strlength = strlen(str);
    mystring ob1(str);
    mystring obj2(std::move(ob1));
    mystring obj3(mystring("Hello world"));
    ASSERT_STREQ(obj2.buffer(), obj3.buffer());
    ASSERT_STREQ(obj2.buffer(), str);
    EXPECT_EQ(strlength, obj2.length());
    EXPECT_EQ(strlength, obj3.length());
}

TEST(KONSTRUKTOR_PRZENOSZACY, EMPTY_OBJECT) {
    const char* str = "";
    int strlength = 0;
    mystring ob1("");
    mystring obj2(std::move(ob1));
    mystring obj3(mystring("Hello world"));
    ASSERT_STRNE(obj2.buffer(), obj3.buffer());
    ASSERT_STREQ(obj2.buffer(), str);
    EXPECT_EQ(strlength, obj2.length());
    EXPECT_NE(strlength, obj3.length());
}

TEST(KOPIUJACY_OPERATOR_PRZYPISANIA, OBJECT) {
    const char* str = "Hello world";
    int strlength = strlen(str);
    mystring ob1(str);
    mystring obj2 = ob1;
    mystring obj3 = obj2;
    ASSERT_STREQ(obj2.buffer(), obj3.buffer());
    ASSERT_STREQ(obj2.buffer(), str);
    EXPECT_EQ(strlength, obj2.length());
    EXPECT_EQ(strlength, obj3.length());
}

TEST(KOPIUJACY_OPERATOR_PRZYPISANIA, EMPTY_OBJECT) {
    const char* str = "";
    int strlength = strlen(str);
    mystring ob1(str);
    mystring obj2 = ob1;
    mystring obj3 = obj2;
    ASSERT_STREQ(obj2.buffer(), obj3.buffer());
    ASSERT_STREQ(obj2.buffer(), str);
    EXPECT_EQ(strlength, obj2.length());
    EXPECT_EQ(strlength, obj3.length());
}

TEST(PRZENOSZACY_OPERATOR_PRZYPISANIA, OBJECT) {
    const char* str = "Hello world";
    int strlength = strlen(str);
    mystring obj2 = mystring(str);
    mystring obtest = mystring(str);
    mystring obj3 = std::move(obtest);
    ASSERT_STREQ(obj2.buffer(), obj3.buffer());
    ASSERT_STREQ(obj3.buffer(), str);
    EXPECT_EQ(strlength, obj3.length());
}

TEST(PRZENOSZACY_OPERATOR_PRZYPISANIA, EMPTY_OBJECT) {
    const char* str = "";
    int strlength = strlen(str);
    mystring obj2 = mystring(str);
    mystring obtest = mystring(str);
    mystring obj3 = std::move(obtest);
    ASSERT_STREQ(obj2.buffer(), obj3.buffer());
    ASSERT_STREQ(obj3.buffer(), str);
    EXPECT_EQ(strlength, obj3.length());
}