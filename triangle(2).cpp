//failed code
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int func(vector<vector<int>> triangle, int trans, int index, int index2) {
    int num_sum = 0;
    int num_sum2 = 0;
    if (index == triangle.size())
        return 0;

    if (trans == 0) {
        num_sum = func(triangle, 0, index+1, index2);
        num_sum2 = func(triangle, 1, index+1, index2);

        if (num_sum >= num_sum2)
            return triangle[index][index2] + num_sum;
        else
            return triangle[index][index] + num_sum2;
    }
    else {
        num_sum = func(triangle, 0, index+1, index2 + 1);
        num_sum2 = func(triangle, 1, index+1, index2 +1);
        return triangle[index][index2] + num_sum;
        if (num_sum >= num_sum2)
            return triangle[index][index2] + num_sum;
        else
            return triangle[index][index] + num_sum2;
    }

}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int a, b;
    int num = triangle.size();
    a = func(triangle, 0, 0, 0);
    b = func(triangle, 1, 0, 0);
    if (a >= b)
        answer = a;
    else
        answer = b;

    return answer;
}
int main() {
    vector<vector<int>> triangle;
    vector<int> a;

    a.push_back(7);
    triangle.push_back(a);
    a.clear();
    a.push_back(3);
    a.push_back(8);
    triangle.push_back(a);
    
    a.clear();
    a.push_back(8);
    a.push_back(1);
    a.push_back(0);
    triangle.push_back(a);
    
    a.clear();
    a.push_back(2);
    a.push_back(7);
    a.push_back(4);
    a.push_back(4);
    triangle.push_back(a);
    
    
    a.clear();
    a.push_back(4);
    a.push_back(5);
    a.push_back(2);
    a.push_back(6);
    a.push_back(5);
    triangle.push_back(a);
    a.clear();
    
    int answer = solution(triangle);
    cout << answer << endl;
    return 0;
}
