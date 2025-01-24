
#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H
#include "Sequence.h"
#include "../data_structures/DynamicArray.h"
#include <stdexcept>

using namespace std;


template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* items;
public:
    ArraySequence() {
        this->items = new DynamicArray<T>;
        if (this->items == nullptr) {
            throw logic_error("");
        }
    }

    ArraySequence(size_t count) {
        this->items = new DynamicArray<T>(count);
        if (this->items == nullptr) {
            throw logic_error("");
        }
    }

    ArraySequence(T* items, int count) {
        this->items = new DynamicArray<T>(items, count);
        if (this->items == nullptr) {
            throw logic_error("");
        }
    }

    ArraySequence(const ArraySequence<T>& other) {
        this->items = new DynamicArray<T>(*other.items);
        if (this->items == nullptr) {
            throw logic_error("Failed to allocate memory");
        }
    }

    ArraySequence<T>& operator=(const ArraySequence<T>& other) {
        if (this != &other) {
            delete this->items;
            this->items = new DynamicArray<T>(*other.items);
            if (this->items == nullptr) {
                throw logic_error("Failed to allocate memory");
            }
        }
        return *this;
    }

    ~ArraySequence() {
        delete items;
    }

    size_t GetSize() const {
        return this->items->GetSize();
    }

    T & Get(const size_t index) {
        if (index < 0 || index >= GetSize()) {
            throw std::out_of_range("Invalid index");
        }
        return this->items->Get(index);
    }

    const T & Get(size_t index) const {
        if (index < 0 || index >= GetSize()) {
            throw std::out_of_range("Invalid index");
        }
        return this->items->Get(index);
    }

    T & GetLast() const {
        if (GetSize() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->GetLast();
    }

    T & GetFirst() const {
        if (GetSize() == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return this->items->GetFirst();
    }

    void Set(size_t index, const T & value) {
        if (index < 0 || index >= GetSize()) {
            throw std::out_of_range("Invalid index");
        }
        this->items->Set(index, value);
    }

    void Append(const T & value) {
        this->items->Append(value);
    }

    void PopBack() {
        items -> PopBack();
    }
};

template <class T>
void Print(const ArraySequence<T> & other) {
    cout << "{" << other.Get(0);
    for (int i = 1; i < other.GetLength(); i++) {
        cout << ", " << other.Get(i);
    }

    cout << "}" << endl;
}
#endif //ARRAYSEQUENCE_H
