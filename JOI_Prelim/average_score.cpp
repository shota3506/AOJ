//Average Score
#include <iostream>

using namespace std;

int main() {
    int total_score = 0, score;
    for(int i = 0; i < 5; i++) {
        cin >> score;
        total_score += max(40, score);
    }

    cout << total_score / 5 << endl;
}