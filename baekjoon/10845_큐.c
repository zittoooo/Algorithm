#include<stdio.h>
   #include<string.h>
   int main(){
       char cmd[50];
       int x,front =0,back=0,N;
       scanf("%d",&N);
      int Q[10000];
       for(int i=0;i<N;i++){
       scanf("%s",cmd);
          if(strcmp(cmd,"push")==0 ){
              scanf("%d",&x);
              Q[back]=x;
              back++; }
          if(strcmp(cmd,"pop")==0){
              if(front == back)   printf("-1\n");
              else{
                      printf("%d\n",Q[front]);
                          front++;   }    }
          if(strcmp(cmd,"size")==0){
              printf("%d\n",back-front);  }
          if(strcmp(cmd,"empty")==0){
                  if(front == back) printf("1\n");
                  else printf("0\n");             }
          if(strcmp(cmd,"front")==0){
                  if(front ==back)
                  printf("-1\n");
              else printf("%d\n",Q[front]);       }
          if(strcmp(cmd,"back")==0){
                  if(front ==back)
                          printf("-1\n");
                  else printf("%d\n",Q[back-1]);  }   }
  return 0;
}