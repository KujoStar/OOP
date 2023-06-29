#include "altset.h"
#include <bits/stdc++.h>
using namespace std;

Altset::Altset() {
    datas = NULL;
}

Altset::~Altset() {
    delete[] datas;
}

Altset::Altset(const char *data, int len) {
    datas = new char[len + 1];
    strcpy(datas, data);
    length = len;
}

Altset& Altset::operator=(const Altset &altset) {
    this->length = altset.length;
    this->datas = new char[this->length + 1];
    strcpy(this->datas, altset.datas);
    return *this;
}

Altset& Altset::operator=(Altset &&altset) {
    this->length = altset.length;
    this->datas = altset.datas;
    altset.datas = nullptr;
    altset.length = 0;
    //delete[] altset.datas;
    return *this;
}

void Altset::inverse(int index) {
    char after = this->datas[this->length - index - 1] == '0' ? '1' : '0';
    this->datas[this->length - index - 1] = after;
}

void Altset::append(int value) {
    char *new_data = new char[this->length + 2];
    new_data[0] = value + '0';
    strcpy(new_data + 1, this->datas);
    this->length += 1;
    delete[] this->datas;
    this->datas = new char [this->length + 2];
    strcpy(this->datas, new_data);
    delete[] new_data;
}

bool Altset::get(int index) const {
    return this->datas[length - index - 1] - 48;
}

bool Altset::empty() const {
    if(this->length == 0) {
        return true;
    }
    else {
        return false;
    }
}

int Altset::count() const {
    int cnt = 0;
    for(int i = 0; i < this->length; i ++) {
        if(this->datas[i] == '1') {
            cnt ++;
        }
    }
    return cnt;
}