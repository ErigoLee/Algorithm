#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {

    int n;
    vector<vector<int> > lotte;
    vector<vector<int> > Com;

    while (true) {
        cin >> n;
        if (n == 0)
            break;
        vector<int> temp;
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            temp.push_back(a);
            if (i < 6)
                temp2.push_back(0);
            else
                temp2.push_back(1);
        }
        sort(temp2.begin(), temp2.end());
        lotte.push_back(temp);
        Com.push_back(temp2);
        temp.clear();
        temp2.clear();
    }
    int lsize = lotte.size();
    for (int i = 0; i < lsize; i++) {
        do {
            int Csize = Com[i].size();
            for (int j = 0; j < Csize; j++) {
                if (Com[i][j] == 0)
                    cout << lotte[i][j] << " ";
            }
            cout << endl;

        } while (next_permutation(Com[i].begin(), Com[i].end()));
        cout << endl;
    }



    return 0;
}