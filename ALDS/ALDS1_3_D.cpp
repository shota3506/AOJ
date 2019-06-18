//Areas on the Cross-Section Diagram
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> S1;
    stack<pair<int, int> > S2;
    char c;

    int i = 0;
    int areas = 0;
    while(cin >> c) {
        switch(c) {
            case '\\':
                S1.push(i);
                break;
            case '/':
                if(S1.empty()) {
                    i++;
                    continue;
                }
                int j = S1.top();
                S1.pop();
                int a = i - j;
                areas += a;
                while(!S2.empty()) {
                    pair<int, int> b = S2.top();
                    if(b.first > j) {
                        S2.pop();
                        a += b.second;
                    }
                    else break;
                }
                S2.push(make_pair(j, a));
        }
        i++;
    }

    cout << areas << endl;

    vector<int> ans;
    while(!S2.empty()) {
        pair<int, int> a = S2.top();
        S2.pop();
        ans.insert(ans.begin(), a.second);
    }
    cout << ans.size();
    for(int i = 0; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;
}