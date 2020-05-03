//Largest Rectangle
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Rectangle {
public:
    int pos, height;
    Rectangle(int pos, int height): pos(pos), height(height) {}
};

int largestRectangle(int h, int w, vector<vector<int>> &G) {
    vector<vector<int>> dp(h+1, vector<int>(w+1, 0));

    for(int i=1; i<h+1; i++) {
        for(int j=1; j<w+1; j++) {
            if(G[i][j] == 1) continue;
            dp[i][j] = dp[i-1][j]+1;
        }
    }

    int s = 0;
    stack<Rectangle> st;
    for(int i=1; i<h+1; i++) {
        for(int j=1; j<w+1; j++) {
            Rectangle rect = Rectangle(j, dp[i][j]);
            if(st.empty()) st.push(rect);
            else if(dp[i][j] > st.top().height) st.push(rect);
            else if(dp[i][j] < st.top().height) {
                int pos = j;
                while(!st.empty() && st.top().height > dp[i][j]) {
                    s = max(s, st.top().height * (j - st.top().pos));
                    pos = st.top().pos;
                    st.pop();
                }
                rect.pos = pos;
                st.push(rect);
            }
        }

        while(!st.empty()) {
            s = max(s, st.top().height * (w + 1 - st.top().pos));
            st.pop();
        }
    }

    return s;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> G(h+1, vector<int>(w+1, 1));
    for(int i=1; i<h+1; i++)
        for(int j=1; j<w+1; j++)
            cin >> G[i][j];

    cout << largestRectangle(h, w, G) << endl;

    return 0;
}
