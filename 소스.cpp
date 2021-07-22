#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int count;
    vector<int> tree;
    int max = 0;

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int a;
        cin >> a;
        tree.push_back(a);
    }

    sort(tree.begin(), tree.end());

    for (int i = 0; i < count; i++)
    {
        int num = tree[count - (i + 1)] + (i + 1);
        if (num > max)
            max = num;
    }

    cout << max + 1 << endl;

    return 0;
}