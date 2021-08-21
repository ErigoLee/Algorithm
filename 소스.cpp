#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cnt[360000]; //100*60*60
long long _max = 0;
int _max_sec = 360000;

void manyPeopleWatching(int endTime, int advtime) {
    long long sum = 0;
    for (int i = endTime - advtime; i < endTime; ++i) {
        sum += cnt[i];
    }
    if (sum > _max) {
        _max = sum;
        _max_sec = endTime - advtime;
    }
}

int stringTotime(string time) {
    return stoi(time.substr(0, 2)) * 60 * 60 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}

string timeTostring(int time) {
    int hour = _max_sec / (60 * 60);
    int min = (_max_sec - hour * 60 * 60) / 60;
    int sec = (_max_sec - hour * 60 * 60) % 60;
    string hour_str; string min_str; string sec_str;
    if (hour < 10) {
        hour_str = '0' + to_string(hour);
    }
    else {
        hour_str = to_string(hour);
    }

    if (min < 10) {
        min_str = '0' + to_string(min);
    }
    else {
        min_str = to_string(min);
    }

    if (sec < 10) {
        sec_str = '0' + to_string(sec);
    }
    else {
        sec_str = to_string(sec);
    }

    return hour_str + ":" + min_str + ":" + sec_str;

}


string solution(string play_time, string adv_time, vector<string> logs) {

    int playtime = stringTotime(play_time);
    int advtime = stringTotime(adv_time);


    

    if (playtime <= advtime) {
        _max_sec = 0;
    
    }
    else {
        for (int i = 0; i < logs.size(); ++i) {
            int startTime = stringTotime(logs[i].substr(0, 8));
            int endTime = stringTotime(logs[i].substr(9, 8));
            for (int j = startTime; j < endTime; ++j) {
                cnt[j]++;
            }
        }

        for (int i = advtime; i < playtime; ++i) {
            manyPeopleWatching(i, advtime);
        }
    }

    
    
    

    string answer = "";
    answer = timeTostring(_max_sec);

    return answer;
}

int main() {

    string play_time = "50:00:00";
    string adv_time = "50:00:00";
    string logs_str[3] = { "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" };
    vector<string> logs;
    for (int i = 0; i < 3; i++) {
        logs.push_back(logs_str[i]);
    }


    string answer = solution(play_time, adv_time, logs);

    cout << answer << endl;

}