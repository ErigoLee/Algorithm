#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    while(heights.size()!=0){
      int num = heights.back();
      int count=-1;
      heights.pop_back();
      for(int i=heights.size()-1;i>=0;i--){
        if(num<heights[i]){
          count = i;
          break;
        }
      }
      answer.push_back(count+1);
    }
    reverse(answer.begin(),answer.end());

    return answer;
}

int main() {
  vector<int> sol;
  vector<int> heights;
  heights.push_back(6);
  heights.push_back(9);
  heights.push_back(5);
  heights.push_back(7);
  heights.push_back(4);

  sol = solution(heights);
  for(int i = 0; i<sol.size();i++){
    cout<<sol[i]<<endl;
  }

}
