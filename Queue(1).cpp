//failed code
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector <int> q;
  vector <int> priority;
  vector <int> result;
  int count;  //횟수
  int amount; //개수
  int index;
  cin>>count;

  for(size_t i=0;i<count;i++){
    cin>>amount>>index;
    for(size_t j=0;j<amount;j++){
      int a;
      cin>>a;  
      q.push_back(a);
      priority.push_back(a);
    }

    int count2=0;
    sort(priority.begin(),priority.end());
    while(true){
      count2++;
      if(q.begin()==priority.end()){
        if(index==0){
          result.push_back(count2);
          break;
        }
        q.erase(q.begin());
        priority.pop_back();
      }

      int num = q.front();
      q.erase(q.begin());
      q.push_back(num);
    }
    q.clear();
    priority.clear();
  }
  
  for(size_t i=0;i<count;i++)
    cout<<result[i]<<endl;
    
  return 0;
}
