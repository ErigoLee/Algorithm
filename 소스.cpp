#include <iostream>
using namespace std;
int chess[15];
int N;
int num;

int abs(int a, int b)
{
    if (a >= b)
        return a - b;
    else
        return b - a;
}

bool possible(int present)
{
    for (int i = 0; i < present; i++)
    {
        if (chess[i] == chess[present] || present - i == abs(chess[present], chess[i]))
            return false;
    }
    return true;
}


void queue_count(int present)
{

    if (N == present)
    {
        num++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        chess[present] = i;
        if (possible(present))
        {
            queue_count(present + 1);
        }

    }


}



int main() {


    cin >> N;


    queue_count(0);

    cout << num << endl;

    return 0;
}