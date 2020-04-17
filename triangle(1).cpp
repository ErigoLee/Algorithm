//failed code
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int max(int a, int b){
  if(a>=b)
    return a;
  else
    return b;
}


int solution(vector<vector<int>> triangle) {
    
    int num = triangle.size();
    for(int i = 0;i<num;i++){
      int num2=triangle[i].size();
      if(num2>1){
        for(int j=0;j<num2;j++){
          if(j==0)
            triangle[i][j]+=triangle[i-1][j];
          else if(j==i)
            triangle[i][j]+=triangle[i-1][j-1];
          else{
            int num_max = max(triangle[i-1][j-1],triangle[i-1][j]);
            triangle[i][j]+=num_max;
          }
        }
      }
    }
    int maximum = triangle[num-1][0];
    int num3 = triangle[num-1].size();
    for(int i=1;i<num3;i++){
      if(maximum<triangle[num-1][i])
        maximum = triangle[num-1][i];
    }

    return maximum;
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
