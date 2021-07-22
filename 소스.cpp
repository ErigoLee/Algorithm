#include <iostream>
using namespace std;

int main() {
    int count;

    string sol[100];

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string public_key[1001];
        string public_key2[1001];
        string cipher[1001];
        int solution[1001];
        int count2;
        cin >> count2;
        for (int j = 0; j < count2; j++)
        {
            string a;
            cin >> a;
            public_key[j] = a;
        }
        for (int j = 0; j < count2; j++)
        {
            string a;
            cin >> a;
            public_key2[j] = a;
        }


        for (int j = 0; j < count2; j++)
        {
            for (int k = 0; k < count2; k++)
            {
                if (public_key[j].compare(public_key2[k]) == 0)
                {
                    solution[j] = k;
                    break;
                }
            }
        }

        for (int j = 0; j < count2; j++)
        {
            string a;
            cin >> a;
            cipher[j] = a;
        }
        sol[i] = "";
        for (int j = 0; j < count2; j++)
        {
            sol[i] += (cipher[solution[j]] + " ");
        }

    }

    for (int i = 0; i < count; i++)
    {
        cout << sol[i] << endl;
    }

    return 0;
}