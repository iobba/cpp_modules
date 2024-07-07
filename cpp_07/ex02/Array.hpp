#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class   Array
{
    private:
        T *arr;
        unsigned int _size;
    public:
        Array() : arr(new T()), _size(0) {}
        Array(unsigned int n) : arr(new T[n]()), _size(n) {}

        Array(const Array& other)
        {
            this->_size = other._size;
            this->arr = new T[other._size]();
            for (unsigned int i = 0; i < _size; i++)
                this->arr[i] = other.arr[i];
        }

        Array& operator=(const Array& other)
        {
            delete[] this->arr;
            this->_size = other._size;
            this->arr = new T[other._size]();
            for (unsigned int i = 0; i < _size; i++)
                this->arr[i] = other.arr[i];
            return (*this);
        }


        unsigned int size() const
        {
            return (this->_size);
        }

        class   OutOfBoundsException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return ("Exception : out of bounds");
            }
        };
        
        T&  operator[](unsigned int i)
        {
            if (i >= this->_size)
                throw OutOfBoundsException();
            return (this->arr[i]);
        }


        ~Array()
        {
            delete[] this->arr;
        }

};

#endif