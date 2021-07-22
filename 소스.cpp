#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

int line[10001];
pair<int, int> node[10001];
int high[10001];
int low[10001];

int index;

void inorder(int num, int level)
{

    if (node[num].first > 0)
        inorder(node[num].first, level + 1);

    if (low[level] > index)
        low[level] = index;

    if (high[level] < index)
        high[level] = index;

    index++;

    if (node[num].second > 0)
        inorder(node[num].second, level + 1);
}

int main() {

    int count;

    int root = 0;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a] = make_pair(b, c);
        line[a]++;
        if (b != -1)
            line[b]++;
        if (c != -1)
            line[c]++;
    }

    for (int i = 1; i <= count; i++) low[i] = INF;

    for (int i = 1; i <= count; i++)
    {
        if (line[i] == 1)
        {
            root = i;
            break;
        }
    }
    index = 1;
    inorder(root, 1);
    int max_level = 0;
    int max = 0;

    for (int i = 1; i <= count; i++)
    {
        int width = high[i] - low[i] + 1;
        if (width > max)
        {
            max = width;
            max_level = i;
        }
    }

    cout << max_level << " " << max << endl;
    return 0;
}