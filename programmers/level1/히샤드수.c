#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int save_x = x;

    while(x){
        sum += (x % 10);
        x /= 10;         
    }

    if( (save_x % sum) != 0)
        answer = false;

    return answer;
}