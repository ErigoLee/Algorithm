# Algorithm
백준, 프로그래머스 등등 문제 풀이      
백준 https://www.acmicpc.net/problem/14501     
14501번 문제입니다.     
BFS형태구조를 이용한 문제로 queue에 현재 위치 날짜와 그 동안 더한 비용을   
넣어서 구했습니다.    
이렇게 설명하면 못 알아 들을 수 있기 때문에    
조금더 자세하게 설명하겠습니다.    
//현재 날짜 위치, 비용       
queue <pair<int, int>> _queue;    
이 부분을 보면 pair의 첫 부분에는 날짜 위치이고, pair의 두번째 부분은 그 동안 비용입니다.     
큐의 내부를 보게 되면
int palace = _queue.front().first;        
int totalExpense = _queue.front().second;     
이와 같은 형태의 변수들이 있을 것입니다.     
palace는 현재 위치고, totalExpense는 알 수 있다시피, 그 동안 더한 비용입니다.   
여기서 저는
for (int i = palace; i < N; i++) {    
                        pair<int, int> _day = days[i];      
                        int time = _day.first;          
                        int expense = _day.second;          
                        if (i + time <= N) {            
                                int nextPalace = i + time;          
                                int nextExpense = expense + totalExpense;           
                                pair<int, int> _next = make_pair(nextPalace,nextExpense);     
                                _queue.push(_next);       
                         }         
}       
이와 같이 탐색해서, 다음 날에 근무할 지 아니면 다다음날에 근무할지를 결정해야 하는 데,    
퇴사 전까지 안전하게 근무할 수 있는 여부는    
if문에서 걸려줍니다. 
if문을 사용한 이유는 N+1일에도 근무하는 것을 막아주기 위해서 입니다.       
이와 같은 탐색하고,        
totalExpense가 다른 경우에서 구한 값보다 큰 지를 비교하는 등과   
같은 과정을 가지게 되면, 정답을 맞출 수 있습니다.    
