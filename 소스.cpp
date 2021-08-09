#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> candidates;

bool stringCompair(string candidate, string order) {

    int count = 0;
    for (int i = 0; i < order.size(); i++) {
        for (int j = 0; j < candidate.size(); j++) {
            if (candidate[j] == order[i]) {
                count++;
                break;
            }
        }
    }

    if (count == candidate.size()) {
        return true;
    }
    else {
        return false;
    }

}



void candidateSearch(vector<string> piece, vector<string> comb,int index, int depth) {
    if (depth == comb.size()) {
        string candidate_str;
        for (int i = 0; i < comb.size(); i++) {
            candidate_str += comb[i];
        }
        candidates.push_back(candidate_str);
        return;
    }

    

    for (int i = index; i < piece.size(); i++) {
        comb[depth] = piece[i];
        candidateSearch(piece,comb ,i + 1, depth + 1);
    }

}



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    vector<string> piece;

    
    for (char a = 'A' ; a <= 'Z' ; a++) {
        bool check = false;
        string str;
        str.push_back(a);
        //cout << str << endl;
        for (int j = 0; j < orders.size(); j++) {
            if (orders[j].find(str)!=string::npos) {
                check = true;
                break;
            }
        }
        if (check) {
            piece.push_back(str);
        }
        
    }
    
    for (int i = 0; i < course.size(); i++) {
        vector<string> comb(course[i]);
        vector<string> candidate2;
        candidateSearch(piece, comb,0, 0);
        int max = 0;
        for (int i = 0; i < candidates.size(); i++) {
            int count = 0;
            bool check = false;
            for (int j = 0; j < orders.size(); j++) {
                
                
                if (stringCompair(candidates[i], orders[j])) {
                    count++;
                }
                
                if (count == 2) {
                    check = true;
                }
                
            }
            if (check) {
                if (count > max) {
                    candidate2.clear();
                    candidate2.push_back(candidates[i]);
                    max = count;
                }
                else if (count == max) {
                    candidate2.push_back(candidates[i]);
                }
            }
            
        }

        for (int k = 0; k < candidate2.size(); k++) {
            answer.push_back(candidate2[k]);
        }
        candidate2.clear();
        candidates.clear();
    }
    
    sort(answer.begin(),answer.end());

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