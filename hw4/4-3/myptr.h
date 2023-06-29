#include <bits/stdc++.h>
using namespace std;

template<typename T>
class my_ptr {
private:
    T* data = nullptr;
public:
    static T *dustbin;
    my_ptr() {
        cout << "my_ptr constructed." << endl;
    }
    ~my_ptr() {
        if(data != nullptr) {
            delete data;
        }
        cout << "my_ptr destructed." << endl;
    }
    my_ptr(T* _data) : data(_data) {
        cout << "my_ptr constructed." << endl;
    }
    my_ptr(const my_ptr & other) {
        cout << "Copying of my_ptr is forbidden!" << endl;
        data = nullptr;
        cout << "my_ptr constructed." << endl;
    }
    my_ptr& operator=(const my_ptr & other) {
        cout << "Copying of my_ptr is forbidden!" << endl;
        return *this;
    }
    my_ptr(my_ptr && other) {
        this->data = other.data;
        other.data = nullptr;
        cout << "my_ptr constructed." << endl;
    }
    my_ptr& operator=(my_ptr && other) {
        this->data = other.data;
        other.data = nullptr;
        cout << "my_ptr updated." << endl;
        return *this;
    }
    T &operator*(){
        if(data == nullptr) {
            cout << "Do not attempt to read a nullptr!" << endl;
            return *dustbin;
        }
        else {
            return *data;
        }
    }
    T *operator->() {
        if(data == nullptr) {
            cout << "Do not attempt to read a nullptr!" << endl;
            return dustbin;
        }
        else {
            return data;
        }
    }
};

template<typename T>
T *my_ptr<T>::dustbin = new T();