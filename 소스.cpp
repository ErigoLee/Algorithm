#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    queue <int> q;
    vector <int> priority;
    vector <int> result;
    int count;  //È½¼ö
    int amount; //°³¼ö
    int index;
    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> amount >> index;
        for (int j = 0; j < amount; j++) {
            int a;
            cin >> a;
            q.push(a);
            priority.push_back(a);
        }

        int count2 = 0;
        sort(priority.begin(), priority.end());
        while (true) {
            if (q.front() == priority.back()) {
                count2++;
                if (index == 0) {
                    result.push_back(count2);
                    break;
                }
                q.pop();
                priority.pop_back();
            }
            else {
                int num = q.front();
                q.pop();
                q.push(num);
            }
            if (index == 0) index = q.size() - 1;
            else index--;
        }
        while (!q.empty()) q.pop();
        priority.clear();
    }

    for (int i = 0; i < count; i++)
        cout << result[i] << endl;

    return 0;
}