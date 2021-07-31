#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    int length = new_id.length();
    //1단계
    for (int i = 0; i < length; i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = new_id[i] - 'A' + 'a';
        }
    }

    //2단계
    string temp = "";
    for (int i = 0; i < length;i++) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            temp += new_id[i];
        }
    }
    new_id = temp;
    

    //3단계
    temp = "";
    length = new_id.length();
    bool special_char = false;

    for (int i = 0; i < length; i++) {

        if (special_char) {
            if (new_id[i] != '.') {
                special_char = false;
                temp += new_id[i];
            }
        }
        else {
            temp += new_id[i];
            if (new_id[i] == '.') {
                special_char = true;
            }
        }
    }
    new_id = temp;
    
    //4단계
    temp = "";
    length = new_id.length();
    if (new_id[0] == '.') {
        if (new_id[length - 1] == '.') {
            temp = new_id.substr(1, length - 2);
            new_id = temp;
        }
        else {
            temp = new_id.substr(1, length - 1);
            new_id = temp;
        }
    }
    else {
        if (new_id[length - 1] == '.') {
            temp = new_id.substr(0, length - 1);
            new_id = temp;
        }
    }
    
    //5단계
    length = new_id.length();
    if (length == 0) {
        new_id += 'a';
    }

    //6단계
    temp = "";
    length = new_id.length();
    if (length >= 16) {
        temp = new_id.substr(0, 15);
        if (temp[14] == '.') {
            new_id = temp.substr(0, 14);
        }
        else {
            new_id = temp;
        }
        
    }
    
    
    //7단계
    length = new_id.length();
    if (length <= 2) {
        char input_char = new_id[length - 1];
        while (true) {
            new_id += input_char;
            length = new_id.length();
            if (length >= 3)
                break;
        }
    }

    answer = new_id;
    return answer;
}

int main() {

    string input_string = "abcdefghijklmn.p";

    string result = solution(input_string);

    cout << result << endl;
    return 0;
}
