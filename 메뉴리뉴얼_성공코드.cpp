#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> candidates[11];
int MaxCnt[11];

void candidateSearch(string str, int pos, string candidate) {

    if (pos >= str.length()) {
        if (candidate.length() > 1) {
            candidates[candidate.length()][candidate]++;
            MaxCnt[candidate.length()] = max(MaxCnt[candidate.length()], candidates[candidate.length()][candidate]);
        }

        return;
    }

    candidateSearch(str,pos+1,candidate+str[pos]);
    candidateSearch(str,pos+1,candidate);

}



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string order : orders) {
        sort(order.begin(),order.end());
        candidateSearch(order,0,"");
    }

    for (int length : course) {
        if (MaxCnt[length]>1) {
            for (auto item : candidates[length]) {
                if (item.second == MaxCnt[length]) {
                    answer.push_back(item.first);
                }
            }
        }
    }
   
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    string orders_array[] = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
    int coures_array[] = { 2,3,5 };
    vector<string> orders;
    vector<int>coures;

    for (string order : orders_array) {
        orders.push_back(order);
    }

    for (int coure : coures_array) {
        coures.push_back(coure);
    }

    vector<string> answer = solution(orders,coures);
    
    for (string an : answer) {
        cout << an << endl;
    }
    

    return 0;
}