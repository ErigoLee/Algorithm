#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int bottom[100001];
int up[100001];

//binary search
int BSearch(int arr[], int len, int target) {

    int first = 0;
    int last = len - 1;
    int mid;
    int ans = 0;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (target > arr[mid]) {
            ans = mid + 1;
            first = mid + 1;
        }
        else
            last = mid - 1;

    }
    return ans;
}


int main() {

    int count, level;
    int min = 1000000000;
    int cnt = 0;
    cin >> count >> level;

    for (int i = 0; i < count / 2; i++)
    {
        cin >> bottom[i] >> up[i];
    }

    sort(bottom, bottom + count / 2);
    sort(up, up + count / 2);


    for (int i = 1; i <= level; i++)
    {
        int down_count = 0, up_count = 0;
        int size = count / 2;
        down_count = size - BSearch(bottom, size, i);
        up_count = size - BSearch(up, size, level - i + 1);
        if (min > down_count + up_count) {
            min = down_count + up_count;
            cnt = 0;
        }

        if (min == down_count + up_count)
            cnt++;
    }

    cout << min << " " << cnt;

    return 0;
}