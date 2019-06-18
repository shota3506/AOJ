//Ring
#include <iostream>
#include <string>

using namespace std;

int main() {
    string base, str;
    int N;
    cin >> base;
    cin >> N;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < base.size(); j++) str += str[j];
        int pos = 0;
        int bpos = 0;
        while(pos < str.size() && bpos < base.size()) {
            if(str[pos + bpos] == base[bpos]) {
                bpos++;
            } else {
                pos++;
                bpos = 0;
            }
        }
        if(bpos == base.size()) cnt++;
    }

    cout << cnt << endl;

    return 0;
}