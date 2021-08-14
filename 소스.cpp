#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

map<string, int> Map;
vector<int> List[4][3][3][3];
vector<int> solution(vector<string> info, vector<string> query) {
    Map["-"] = 0;
    Map["cpp"] = 1;
    Map["java"] = 2;
    Map["python"] = 3;
    Map["backend"] = 1;
    Map["frontend"] = 2;
    Map["junior"] = 1;
    Map["senior"] = 2;
    Map["chicken"] = 1;
    Map["pizza"] = 2;

    for (string str : info) {
        stringstream ss(str);
        string a, b, c, d;
        int score;
        ss >> a >> b >> c >> d >> score;
        List[Map[a]][Map[b]][Map[c]][Map[d]].push_back(score);
        List[0][Map[b]][Map[c]][Map[d]].push_back(score);
        List[Map[a]][0][Map[c]][Map[d]].push_back(score);
        List[Map[a]][Map[b]][0][Map[d]].push_back(score);
        List[Map[a]][Map[b]][Map[c]][0].push_back(score);
        List[0][0][Map[c]][Map[d]].push_back(score);
        List[0][Map[b]][0][Map[d]].push_back(score);
        List[0][Map[b]][Map[c]][0].push_back(score);
        List[Map[a]][0][0][Map[d]].push_back(score);
        List[Map[a]][0][Map[c]][0].push_back(score);
        List[Map[a]][Map[b]][0][0].push_back(score);
        List[0][0][0][Map[d]].push_back(score);
        List[0][0][Map[c]][0].push_back(score);
        List[0][Map[b]][0][0].push_back(score);
        List[Map[a]][0][0][0].push_back(score);
        List[0][0][0][0].push_back(score);
    }


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    sort(List[i][j][k][l].begin(), List[i][j][k][l].end());
                }
            }
        }
    }

    vector<int> answer;

    for (string str : query) {
        stringstream ss(str);
        string a, b, c, d, temp;
        int score;
        ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;
        auto& slist = List[Map[a]][Map[b]][Map[c]][Map[d]];

        vector<int>::iterator low = lower_bound(slist.begin(), slist.end(), score);
        answer.push_back(slist.end() - low);
    }

    return answer;
}

int main() {


    string info_array[] = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    string query_array[] = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };

    vector<string> info;
    for (int i = 0; i < 6; i++) {
        info.push_back(info_array[i]);
    }
    vector<string> query;
    for (int i = 0; i < 6; i++) {
        query.push_back(query_array[i]);
    }

    vector<int> answer = solution(info, query);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}