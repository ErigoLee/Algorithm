//failed code
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct star{
  int x;
  int y;
};
int want_sumx=0,want_sumy=0;
void solution(vector<star>s1,vector<star>s2,int*alpha,int*beta){
  vector<int>check;
  bool star_check=false;
  check.assign(s1.size(), 1);
  for(size_t i=0;i<s2.size()-s1.size();i++)
    check.push_back(0);
  sort(check.begin(),check.end());
  do{
    int sumx=0,sumy=0;
    for(size_t i=0;i<check.size();i++){
      if(check[i]==1){
        sumx+=s2[i].x;
        sumy+=s2[i].y;
      }
    }
    cout<<sumx<<' '<<sumy<<endl;
  
    int x_pos = (sumx-want_sumx)/s1.size();
    int y_pos = (sumy-want_sumy)/s1.size();
    cout<<x_pos<<' '<<y_pos<<endl;
    int checkx = s1[0].x+x_pos;
    int checky = s1[0].y+y_pos;
    star_check=false;

    for(size_t i=0;i<check.size();i++){
      if(check[i]==1){
        if((checkx==s2[i].x)&&(checky==s2[i].y)){
          star_check=true;
          *alpha=x_pos;
          *beta=y_pos;
          break;
        }
      }
    }

    
  }while(next_permutation(check.begin(),check.end())&&star_check==false);

}



int main() {
  vector<star> want_star;
  vector<star> sky_star;
  int want_star_num;
  int sky_star_num;
  int x,y;
  struct star star_check;
  int place_x,place_y;

  //원하는 별자리
  cin>>want_star_num;
  want_sumx=0,want_sumy=0;
  for(int i=0;i<want_star_num;i++){
    cin>>x>>y;
    want_sumx+=x;
    want_sumy+=y;
    star_check.x=x;
    star_check.y=y;
    want_star.push_back(star_check);
  }
  cout<<want_sumx<<' '<<want_sumy<<endl;
  //실제 별자리
  cin>>sky_star_num;
  for(int i=0;i<sky_star_num;i++){
    cin>>x>>y;
    star_check.x=x;
    star_check.y=y;
    sky_star.push_back(star_check);
  }

  solution(want_star,sky_star,&place_x,&place_y);
  cout<<place_x<<' '<<place_y<<endl;
}
