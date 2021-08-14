#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (int i = 0; i < query.size(); i++) {
        int count = 0;
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

        for (int j = 0; j < info.size(); j++) {
            string language2, field2, level2, meal2;
            if (info[j].find("cpp") != string::npos)
                language2 = "cpp";
            else if (info[j].find("java") != string::npos)
                language2 = "java";
            else
                language2 = "python";

            if (info[j].find("backend") != string::npos)
                field2 = "backend";
            else
                field2 = "frontend";

            if (info[j].find("junior") != string::npos)
                level2 = "junior";
            else
                level2 = "senior";

            if (info[j].find("chicken") != string::npos)
                meal2 = "chicken";
            else
                meal2 = "pizza";

            string score_str2 = "";
            for (int l = 0; l < info[j].size(); l++) {
                if (info[j][l] >= '0' && info[j][l] <= '9')
                    score_str2 += info[j][l];
            }

            int score2 = stoi(score_str2);

            if (language.find("-")==string::npos) {
                if (language.find(language2) == string::npos)
                    continue;
            }
            if (field.find("-")==string::npos) {
                if (field.find(field2) == string::npos)
                    continue;
            }
            if (level.find("-")==string::npos) {
                if (level.find(level2)==string::npos)
                    continue;
            }
            if (meal.find("-")==string::npos) {
                if (meal.find(meal2)==string::npos)
                    continue;
            }

            if (score <= score2)
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