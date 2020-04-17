#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int sec = 0;
    vector<int> cross_bridge(bridge_length,0);
    while(true)
    {
      if(cross_bridge.size()==0)
        break;
      sec+=1;
      cross_bridge.erase(cross_bridge.begin());
      if(truck_weights.size()==0)
        continue;

      int temp = 0;
      for(size_t i=0;i<cross_bridge.size();i++)
        temp += cross_bridge.at(i);
      
      if(temp+truck_weights.back()<=weight){
        cross_bridge.push_back(truck_weights.back());
        truck_weights.pop_back();
      }
      else
        cross_bridge.push_back(0);
    }
    return sec;
}
