//failed code
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct star{
  int x;
  int y;
};
void solution(vector<star> s1,vector<star> s2,int *alpha,int *beta){
  
  for(int i=0;i<s2.size();i++){
    int num_x = s1[0].x-s2[i].x;
    int num_y = s1[0].y-s2[i].y;
    int index = 0;

    for(int j=1;j<s1.size();j++){
      for(int k=0;k<s2.size();k++){
        if((s1[j].x+num_x==s2[k].x)&&(s1[j].y+num_y==s2[k].y)){
          index = 0;
          break;
        }
        else
          index = 1;
      }
      if (index==1)
        break;

    }
    if(index==0){
      *alpha=num_x;
      *beta=num_y;
      break;
    }
  }
}

int main() {
  vector<star> want_star;
  vector<star> sky_star;
  int want_star_num;
  int sky_star_num;
  int x,y;
  struct star star_check;
  int place_x,place_y;

  cin>>want_star_num;
  for(int i=0;i<want_star_num;i++){
    cin>>x>>y;
    star_check.x=x;
    star_check.y=y;
    want_star.push_back(star_check);
  }
  cin>>sky_star_num;
  for(int i=0;i<sky_star_num;i++){
    cin>>x>>y;
    star_check.x=x;
    star_check.y=y;
    sky_star.push_back(star_check);
  }

  solution(want_star,sky_star,&place_x,&place_y);
  cout<<place_x<<place_y<<endl;
}
