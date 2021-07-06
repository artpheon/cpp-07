#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstdlib>
# include <exception>

template<typename T>
class Array {
    private:
        T* _arr;
        unsigned int  _size;
        class ExceptionWrongIndex: public std::exception {
        public:
            const   char*   what() const throw () {
                return "Wrong index";
            }
        };
        T*  _copyArr(const Array<T>& rhs) {
            if (rhs._size == 0)
                return 0;
            T* newArr = new T[rhs._size];
            for (unsigned int i = 0; i < rhs._size; i++) {
                newArr[i] = rhs._arr[i];
            }
            return newArr;
        }
    public:
        Array<T>() {
            _size = 0;
            _arr = 0;
        }
        Array<T>(unsigned int size) {
            _size = size;
            if (size > 0)
                _arr = new T[size];
            else
                _arr = 0;
            for (unsigned int i = 0; i < size; i++) {
                _arr[i] = T();
            }
        }
        Array<T>(const Array& rhs) {
            *this = rhs;
        }
        Array<T>& operator=(const Array<T>& rhs) {
            if (this != &rhs) {
                _arr = _copyArr(rhs);
                _size = rhs._size;
            }
            return *this;
        }
        ~Array<T>() {
            if (_size)
                delete [] _arr;
        }
        T&  operator[](unsigned int ind) {
            if (ind >= _size || ind < 0)
                throw Array::ExceptionWrongIndex();
            return _arr[ind];
        }
        unsigned int    size() const { return _size; }
};

#endif