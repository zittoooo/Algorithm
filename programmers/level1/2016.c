#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char) * 4);
    char * name[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED","THU"};
    int result = 0 ;
    int days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    for(int i=0 ; i < a-1 ;i++){
      result += days[i];
     }
     result += b-1;
    
   // answer = name[result%7];
    
    return name[result%7];
}