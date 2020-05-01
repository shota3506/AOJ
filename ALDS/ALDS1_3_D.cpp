//Areas on the Cross-Section Diagram
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Area {
    int pos;
    int number;
    Area(int pos, int number): pos(pos), number(number) {};
};

int main() {
    string s;
    cin >> s;

    stack<int> st1;
    stack<Area> st2;
    int sum = 0;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '_') continue;
        else if(s[i] == '\\') st1.push(i);
        else {
            if(st1.empty()) continue;
            int j = st1.top(); st1.pop();
            int area = (i - j);
            sum += area;

            while(!st2.empty() && st2.top().pos > j) {
                area += st2.top().number;
                st2.pop();
            }

            st2.push(Area(j, area));
        }
    }

    vector<int> ans;
    while(!st2.empty()) {
        ans.insert(ans.begin(), st2.top().number);
        st2.pop();
    }

    cout << sum << endl;
    int k = ans.size();
    cout << k;
    if(k > 0) for (int i=0; i<k; i++) cout << " " << ans[i];
    cout << endl;
    return 0;
}