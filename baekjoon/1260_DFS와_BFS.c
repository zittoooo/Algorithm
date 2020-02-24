 #include<stdio.h>
   int map[1001][1001]; int check1[1001];int check2[1001];int queue[1001];
   int link, rear,front,node;
   void DFS(int visit){
       check1[visit] = 1;
       printf("%d ",visit);
      for(int k=1;k<=node;k++){
           if(map[visit][k] ==1  && !check1[k]  )  {
               DFS(k);
          }
      }
  }
  void BFS(int visit){
      check2[visit] = 1;
      queue[rear++] = visit;
      printf("%d ",visit);
      while(front < rear){
          visit = queue[front++];
          for(int i=1;i <= node;i++){
              if(map[visit][i] ==1 && !check2[i] ){
                  printf("%d ",i);
                      check2[i] = 1;
                  queue[rear++] = i;
              }
          }
      }
  }
 int main(void){
      int start;
      int visit1, visit2;
      scanf("%d%d%d", &node, &link ,& start);
      for(int i=1; i<=link ;i++){
          scanf("%d%d", &visit1, &visit2);
          map[visit1][visit2] = map[visit2][visit1] = 1;
      }
      DFS(start);
      printf("\n");
      BFS(start);
  return 0;
  }
