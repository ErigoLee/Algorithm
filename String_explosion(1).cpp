//failed code
#include <iostream>
#include <string>

using namespace std;

int main() 
{
  string str1;
  string str2;
  cin>>str1;
  cin>>str2;

  for(size_t a =0; a<str1.size();a++)
  {
    int count = 0;
    int temp = a;
    
    for(size_t i = 0;i<str2.size();i++){
      if(str1[temp]!=str2[i]&&temp!=a)
        break;
      if(str1[temp]==str2[i])
      {
        count++;
        temp++;
      }
    }
    if(count !=0){
      str1.erase(a,count);
      a--;
    }
  }

  if(str1.size()==0)
    cout<<"FRULA"<<endl;
  else
    cout<<str1<<endl;
  return 0;
}
