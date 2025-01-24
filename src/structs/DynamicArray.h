

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdexcept>
#include <iostream>

template<class T>
class DynamicArray {
private:
    T* data;
    size_t size;
public:
    DynamicArray() : data(nullptr), size(0) {}

    DynamicArray(size_t count) {
        data = new T[count];
        size = count;
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) {
        size = dynamicArray.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = dynamicArray.data[i];
        }
    }

    ~DynamicArray() {
        Clear();
    }

    void Clear() {
        delete[] data;
    }

    T& Get(size_t index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    size_t GetSize() const{
        return size;
    }

    T & GetFirst() const{
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }

        return data[0];
    }

    T & GetLast() const{
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }

        return data[size - 1];
    }


    void Set(size_t index, const T & value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        data[index] = value;
    }


    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    template <class T>
    void Resize(int newSize)
    {
        T *tmpElements = new T[size];
        memcpy(tmpElements, data, size * sizeof(T));
        delete[] data;
        data = new T[newSize];
        for (int i = 0; i < std::min(size, newSize); i++)
        {
            data[i] = tmpElements[i];
        }
        size = newSize;
    };

    void Append(const T & value) {
        this->Resize(this->size + 1);
        this->data[this->size - 1] = value;
    }

    void PopBack() {
        this->Resize(this->size - 1);
    }

};

#endif //DYNAMICARRAY_H
