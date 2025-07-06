#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isempty(struct queue *q){
    if(q->front==q->rear){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct queue *q){
    if(q->rear==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue *q,int data){
     if(isfull(q)){
        printf("queue overflow\n");
        return;
     }else{
        q->rear++;
        q->arr[q->rear]=data;
     }
}

int dequeue(struct queue *q){
    int value;
    if(isempty(q)){
        printf("queue underflow\n");
        exit(1);
    }else{
        q->front++;
        value=q->arr[q->front];
        return value;
    }
}

void print(struct queue *q){
     if(isempty(q)){
        printf("queue is empty\n");
        exit(1);
     }
     else{
        printf("the elements in queue is\n");
        for(int i=q->front+1;i<=q->rear;i++){
            printf("%d ",q->arr[i]);
        }
        printf("\n");
     }
}

int main(){
    struct queue q;
    q.size=400;
    q.front=q.rear=-1;
    q.arr=(int *)malloc(q.size * sizeof(int));
    
    // BFS inmplmentation
      int i=3;
      int visited[7]={0,0,0,0,0,0,0};
      int a [7][7]={
                    {0,1,1,1,0,0,0},
                    {1,0,1,0,0,0,0},
                    {1,1,0,1,1,0,0},
                    {1,0,1,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0}            
                                      }; 
     visited[i]=1;
     printf("%d",i);  
     enqueue(&q,i);
     while(!isempty(&q))
     {
        int node = dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                visited[j]=1;
                printf("%d",j);
                enqueue(&q,j);
            }
        }
     }

      return 0;
}