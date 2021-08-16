//
// Created by nte on 7/25/21.
//

#include "mystring.h"
namespace pawel {

    mystring::mystring() {
        try {
            _buffer = new char[INITIAL_SIZE_OF_BUFFER];
        }
        catch (std::bad_alloc& e) {
            _buffer = nullptr;
            _buffer_size = 0;
            _length = 0;
            std::cerr << "Niepowodzenie konstruktor domyslny\n";
        }
        if (_buffer != memcpy(_buffer, "", (_length + 1) * sizeof(char)))
        {
            std::cerr << "Niepowodzenie memcpy\n";
            _length = 0;
            delete[] _buffer;
            _buffer = nullptr;
            _buffer_size = 0;
        }
    }

    mystring::~mystring() {
        std::cout << "Zwalniam zasoby:: destruktor\n";
        delete[] _buffer;
    }

    mystring::mystring(const char* str) {
        size_t len = strlen(str);
        _length = len;
        if(len > _buffer_size) {
            _buffer_size = len + 10;
        }
        try {
            _buffer = new char[_buffer_size];
        }
        catch(std::bad_alloc& e)
        {
            _buffer = nullptr;
            _buffer_size = 0;
            _length = 0;
            std::cerr << "Niepowodzenie konstruktor const char*\n";
        }
        if (_buffer != memcpy(_buffer, str, (len + 1) * sizeof(char)))
        {
            std::cerr << "Niepowodzenie memcpy\n";
            _length = 0;
            delete[] _buffer;
            _buffer = nullptr;
            _buffer_size = 0;
        }
    }

    mystring::mystring(const mystring &mstr) {
        _length = mstr._length;
        _buffer_size = mstr._buffer_size;
        try {
            _buffer = new char[_buffer_size];
        }
        catch (std::bad_alloc& e) {
            _buffer = nullptr;
            _buffer_size = 0;
            _length = 0;
            std::cerr << "Niepowodzenie konstruktor kopiujacy\n";
        }
        if (_buffer != memcpy(_buffer, mstr._buffer, _buffer_size * sizeof(char))) {
            std::cerr << "Niepowodzenie memcpy\n";
            _length = 0;
            delete[] _buffer;
            _buffer = nullptr;
            _buffer_size = 0;
        }
    }

    mystring::mystring(mystring &&mstr) {
        //std::cout << "Konstruktor przenoszacy\n";
        _length = mstr._length;
        _buffer_size = mstr._buffer_size;
        _buffer = mstr._buffer;
        mstr._buffer = nullptr;
        mstr._buffer_size = 0;
        mstr._length = 0;
    }

    mystring& mystring::operator=(const mystring &mstr) {
        _length = mstr._length;
        _buffer_size = mstr._buffer_size;
        try {
            _buffer = new char[_buffer_size];
        }
        catch (std::bad_alloc& e) {
            _buffer = nullptr;
            _buffer_size = 0;
            std::cerr << "Niepowodzenie operator kopiujacy\n";
        }
        if (_buffer != memcpy(_buffer, mstr._buffer, _buffer_size * sizeof(char))) {
            std::cerr << "Niepowodzenie memcpy\n";
            _length = 0;
            delete[] _buffer;
            _buffer = nullptr;
            _buffer_size = 0;
        }
        return *this;
    }

    mystring& mystring::operator=(mystring&& mstr) {
        _length = mstr._length;
        _buffer_size = mstr._buffer_size;
        _buffer = mstr._buffer;
        mstr._buffer = nullptr;
        mstr._buffer_size = 0;
        mstr._length = 0;
        return *this;
    }

    bool mystring::operator==(const mystring& mstr)
    {
        if(_length != mstr._length)
            return false;
        if(strcmp(_buffer, mstr._buffer) != 0)
            return false;
        return true;
    }

    void mystring::resize(size_t newSize) {
        if(newSize > _buffer_size) {
            char* tmp;
            try {
                tmp = new char[newSize];
            }
            catch(std::bad_alloc& e) {
                std::cerr << "Mystring::resize, za malo pamieci\n";
                return;
            }
            if (_buffer != memcpy(_buffer, tmp, _buffer_size * sizeof(char))) {
                std::cerr << "Niepowodzenie memcpy\n";
                _length = 0;
                delete[] _buffer;
                delete[] tmp;
                _buffer = nullptr;
                _buffer_size = 0;
            }
            delete[] _buffer;
            _buffer = tmp;
            _buffer_size = newSize;
        }
    }

} // namespace pawel