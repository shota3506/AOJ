//Signboard
#include <iostream>

using namespace std;

int main() {
    int N;
    string base, str;
    bool flg;
    cin >> N;
    cin >> base;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> str;
        flg = false;
        for(int p = 0; p < str.size(); p++) {
            for(int s = 1; s < str.size() - p; s++) {
                string x = "";
                for(int j = 0; j < base.size(); j++) {
                    if(p + j * s < str.size()) x += str[p + j * s];
                }
                if(base == x) {flg = true; break;}
            }
            if(flg) break;
        }
        if(flg) cnt++;
    }

    cout << cnt << endl;
}