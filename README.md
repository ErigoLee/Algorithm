# Algorithm
백준, 프로그래머스 등등 문제 풀이     
백준 https://www.acmicpc.net/problem/14888               
문제를 보니 순열로 푸는 문제라서                   
순열 형태로 풀었으나 오답이 발생해버렸습니다.   
해서 제 코드를 디버깅(인간 디버깅ㅋㅋㅋ)하던 중에       
sort(numbers.begin(),numbers.end());   
이 부분을 추가해서 오류가 발생했다는 것을 발견했습니다.      
이 부분을 제거했더니 바로 정답이 떴습니다.      
