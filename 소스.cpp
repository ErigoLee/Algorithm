#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int card_count[100];
int main() {
    int N, M;
    int result = 0;
    int gap = 100000;
    cin >> N >> M;
    vector<int>Com;

    for (int i = 0; i < N; i++) {
        cin >> card_count[i];
        if (i < 3)
            Com.push_back(1);
        else
            Com.push_back(0);
    }

    sort(Com.begin(), Com.end());

    do {
        int max = 0;
        int gap2;
        for (int i = 0; i < N; i++) {
            if (Com[i] == 1)
                max += card_count[i];
        }
        if (max <= M) {
            gap2 = M - max;
            if (gap2 < gap) {
                result = max;
                gap = gap2;
            }
        }

    } while (next_permutation(Com.begin(), Com.end()));

    cout << result << endl;

    return 0;
}