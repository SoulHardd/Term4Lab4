
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
using namespace std;

template <class T>
class Sequence {
public:
    virtual T & Get(size_t index) = 0;
    virtual const T & Get(size_t index) const = 0;
    virtual T & GetFirst() const = 0;
    virtual T & GetLast() const = 0;
    virtual size_t GetSize() const = 0;
    virtual void Set(size_t index, const T & value) = 0;
    virtual void Append(const T & value) = 0;
    virtual ~Sequence(){};
};

template <class T>
void Print(const Sequence<T> & other) {
    cout << "{" << other.Get(0);
    for (int i = 1; i < other.GetLength(); i++) {
        cout << ", " << other.Get(i);
    }
    cout << "}" << endl;
}


#endif //SEQUENCE_H
