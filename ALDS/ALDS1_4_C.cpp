//Dictionary
#include <iostream>
#include <stdio.h>

using namespace std;

const int m = 1000003;

int h1(int key) {
    return key % m;
}

int h2(int key) {
    return 1 + (key % (m - 1));
}

int h(int key, int i) {
    return (h1(key) + i * h2(key)) % m;
}

int getInt(char c) {
    switch(c) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;
    }
}

long long getKey(string str) {
    long long sum = 0, p = 1;
    for(int i = 0; i < str.size(); i++) {
        sum += p * getInt(str[i]);
        p *= 5;
    }
    return sum;
}

class Dictionary {
public:
    Dictionary();
    void insert(string str);
    string find(string str);
private:
    string * data = new string[m];
};

Dictionary::Dictionary() {
    for(int i = 0; i < m; i++) data[i] = string("N");
}

void Dictionary::insert(string str) {
    int i = 0, hash_key;
    while(i < m) {
        hash_key = h(int(getKey(str)), i);
        if(data[hash_key] == "N") {
            data[hash_key] = str;
            break;
        }
        else if(data[hash_key] == str) break;
        i++;
    }
}

string Dictionary::find(string str) {
    int i = 0, hash_key;
    while(i < m) {
        hash_key = h(int(getKey(str)), i);
        if(data[hash_key] == "N") return string("no");
        else if(data[hash_key] == str) return string("yes");
        i++;
    }
    return string("no");
}


int main() {
    int n;
    Dictionary D;

    cin >> n;
    char operation[7], operand[13];
    for(int i = 0; i < n; i++) {
        scanf("%s %s", operation, operand);
        if(operation[0] == 'i') D.insert(string(operand));
        else cout << D.find(string(operand)) << endl;
    }
}