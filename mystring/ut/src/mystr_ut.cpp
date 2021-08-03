//
// Created by nte on 7/25/21.
//
#include <mystring.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace pawel;

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
    mystring emp("");
    ASSERT_EQ(0, emp.length());
    ASSERT_GE(emp.size(), emp.length());
    ASSERT_STREQ(emp.buffer(), "");
}