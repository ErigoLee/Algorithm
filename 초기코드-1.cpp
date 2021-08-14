#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<tuple<string, string, string, string, int>> _info;
    for (int i = 0; i < info.size(); i++) {
        string language, field, level, meal;
        if (info[i].find("cpp") != string::npos)
            language = "cpp";
        else if (info[i].find("java") != string::npos)
            language = "java";
        else
            language = "python";

        if (info[i].find("backend") != string::npos)
            field = "backend";
        else
            field = "frontend";

        if (info[i].find("junior") != string::npos)
            level = "junior";
        else
            level = "senior";

        if (info[i].find("chicken") != string::npos)
            meal = "chicken";
        else
            meal = "pizza";

        string score_str = "";
        for (int k = 0; k < info[i].size(); k++) {
            if (info[i][k] >= '0' && info[i][k] <= '9')
                score_str += info[i][k];
        }

        int score = stoi(score_str);

        tuple<string, string, string, string, int> temp = make_tuple(language,field,level,meal,score);
        _info.push_back(temp);
    }
    vector<tuple<string, string, string, string, int>> _query;
    for (int i = 0; i < query.size(); i++) {
        string language, field, level, meal;
        if (query[i].find("cpp") != string::npos)
            language = "cpp";
        else if (query[i].find("java") != string::npos)
            language = "java";
        else if (query[i].find("python") != string::npos)
            language = "python";
        else
            language = "-";

        if (query[i].find("backend") != string::npos)
            field = "backend";
        else if (query[i].find("frontend") != string::npos)
            field = "frontend";
        else
            field = "-";

        if (query[i].find("junior") != string::npos)
            level = "junior";
        else if (query[i].find("senior") != string::npos)
            level = "senior";
        else
            level = "-";

        if (query[i].find("chicken") != string::npos)
            meal = "chicken";
        else if (query[i].find("pizza") != string::npos)
            meal = "pizza";
        else
            meal = "-";

        string score_str = "";
        for (int k = 0; k < query[i].size(); k++) {
            if (query[i][k] >= '0' && query[i][k] <= '9')
                score_str += query[i][k];
        }

        int score = stoi(score_str);

        tuple<string, string, string, string, int> temp = make_tuple(language, field, level, meal, score);
        _query.push_back(temp);

    }


    for (int i = 0; i < _query.size(); i++) {
        int count = 0;
        for (int j = 0; j < _info.size(); j++) {
            if (!(get<0>(_query[i]))._Equal("-")) {
                if(!(get<0>(_query[i]))._Equal(get<0>(_info[j])))
                    continue;
            }
            if (!(get<1>(_query[i]))._Equal("-")) {
                if (!(get<1>(_query[i]))._Equal(get<1>(_info[j])))
                    continue;
            }
            if (!(get<2>(_query[i]))._Equal("-")) {
                if (!(get<2>(_query[i]))._Equal(get<2>(_info[j])))
                    continue;
            }
            if (!(get<3>(_query[i]))._Equal("-")) {
                if (!(get<3>(_query[i]))._Equal(get<3>(_info[j])))
                    continue;
            }

            if (get<4>(_info[j]) >= get<4>(_query[i]))
                count++;
        }
        answer.push_back(count);
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