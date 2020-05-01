//Dictionary
#include <iostream>

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
    if(c == 'A') return 1;
    else if(c == 'C') return 2;
    else if(c == 'G') return 3;
    else if(c == 'T') return 4;
    return 0;
}

long long getKey(string str) {
    long long sum = 0, p = 1;
    for(int i=0; i<str.size(); i++) {
        sum += p * getInt(str[i]);
        p *= 5;
    }
    return sum;
}

class Dictionary {
private:
    string *data = new string[m];
public:
    Dictionary() {
        for(int i = 0; i < m; i++) data[i] = string("N");
    };
    void insert(string str) {
        int i=0, hash_key;
        while(i<m) {
            hash_key = h(int(getKey(str)), i);
            if(data[hash_key] == "N" || data[hash_key] == str) {
                data[hash_key] = str;
                break;
            }
            i++;
        }
    };
    string find(string str) {
        int i = 0, hash_key;
        while(i < m) {
            hash_key = h(int(getKey(str)), i);
            if(data[hash_key] == "N") return "no";
            else if(data[hash_key] == str) return "yes";
            i++;
        }
        return "no";
    };
};

int main() {
    int n;
    cin >> n;

    Dictionary D;
    string operation, operand;
    for(int i = 0; i < n; i++) {
        cin >> operation >> operand;
        if(operation[0] == 'i') D.insert(string(operand));
        else cout << D.find(string(operand)) << endl;
    }
}