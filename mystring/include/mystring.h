//
// Created by nte on 7/25/21.
//

#ifndef STRING_AND_LIST_UT_LEARN_MYSTRING_H
#define STRING_AND_LIST_UT_LEARN_MYSTRING_H
#include <iostream>
#include <cstring>
#include <memory>
#include <cstdlib>
#include <exception>
#define INITIAL_SIZE_OF_BUFFER 20

namespace pawel
{
    class mystring {
    protected:
        char* _buffer = nullptr;
        size_t _length = 0;
        size_t _buffer_size = INITIAL_SIZE_OF_BUFFER;
    public:
        mystring();
        virtual ~mystring();
        mystring(const char*);
        //Mystring(std::unique_ptr<const uchar[]> ptr);
        mystring(const mystring& mstr);
        mystring(mystring&& mstr);
        mystring& operator=(const mystring& mstr);
        mystring& operator=(mystring&& mstr);
        inline char& operator[](size_t index) {return _buffer[index];}
        inline bool operator<(const mystring& mstr) {return strcmp(_buffer, mstr._buffer) < 0;}
        bool operator==(const mystring& mstr);
        friend std::ostream& operator<<(std::ostream& os, const mystring& mstr) {
            return os << mstr._buffer << std::endl;
        }
        inline size_t length() const {return _length;}
        inline size_t size() const {return _buffer_size;}
        inline const char* buffer() const {return _buffer;};
        const void resize(size_t newSize);
    };
}


#endif //STRING_AND_LIST_UT_LEARN_MYSTRING_H
