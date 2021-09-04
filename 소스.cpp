#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {


    vector<string> answer;
    vector<string> id;
    map<string, string> id_nickname;
    int size = record.size();
    for (int i = 0; i < size; i++) {
        stringstream aa(record[i]);
        string _situation, _id, _nickname;
        aa >> _situation >> _id >> _nickname;
        if (_situation.compare("Enter") == 0) {
            id_nickname[_id] = _nickname;
            string _answer = "님이 들어왔습니다.";
            answer.push_back(_answer);
            id.push_back(_id);
        }
        else if (_situation.compare("Leave") == 0) {
            string _answer = "님이 나갔습니다.";
            answer.push_back(_answer);
            id.push_back(_id);
        }
        else {
            id_nickname[_id] = _nickname;
        }
        
    }

    
    int size2 = answer.size();

    for (int i = 0; i < size2; i++) {
        answer[i] = id_nickname[id[i]] + answer[i];
    }

    

    
    return answer;
}

int main() {


    string record_array[] = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    vector<string> record;
    for (int i = 0; i < 5; i++) {
        record.push_back(record_array[i]);
    }

    vector<string> answer = solution(record);
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    
    //["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    //["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]



    return 0;
}