#include<stdio.h>
#define MAX 10
#include<stdlib.h>

typedef struct{
  int arr[MAX];
  int front;
  int rear;
}queue;

void init(queue *q)
{
  q->front = q->rear = -1;
}

int isFull(queue *q)
{
  return q->rear == MAX-1 ? 1:0 ;
}

int isEmpty(queue *q)
{
  return q->front==-1 && q->rear==-1 ? 1:0;
}

void enqueue(queue *q,int data)
{
  if(isFull(q))
  {
    printf("queue is full cannot insert %d into the queue\n");
    return;
  }
  else if(isEmpty(q))
  {
    q->front = q->rear = 0;
    q->arr[q->rear] = data;
  }
  else
  {
    q->rear++;
    q->arr[q->rear] = data;
  }
}

void dequeue(queue *q)
{
  if(isEmpty(q))
  {
    printf("Underflow\n");
    return;
  }
  else if(q->front==q->rear)
  {
    printf("value deleted is %d\n",q->arr[q->front]);
    init(q);
  }
  else
  {
    printf("value deleted is %d \n",q->arr[q->front]);
    q->front++;
  }
}

void display(queue *q)
{
  if(isEmpty(q))
  {
    printf("queue is empty\n");
    printf("-");
    for(int i=0;i<MAX*6;i++)
      printf("-");
    printf("\n");
    printf("|");
    for(int i=0;i<MAX;i++)
       printf("     |");
    printf("\n");
    printf("-");
    for(int i=0;i<MAX*6;i++)
      printf("-");
    printf("\n");      
    
  }
  else
  {
    int elements = (q->rear- q->front +1);
    printf("-");
    for(int i =0;i < elements*6 ; i++)
      printf("-");
    for(int i =0;i < (MAX-elements)*6 ; i++)
      printf("-");

    printf("\n");

    printf("|");
    for(int i = q->front; i<=q->rear ; i++)
      printf("%5d|",q->arr[i]);
    for(int i=0;i<MAX-elements;i++)
       printf("     |");

    printf("\n");

    printf("-");
    for(int i =0;i < elements*6 ; i++)
      printf("-");
    for(int i =0;i < (MAX-elements)*6 ; i++)
      printf("-");
    printf("\n");
    
  }
}

void menu(queue *obj)
{
  printf("\t\tQUEUE SIMULATION\n");
  display(obj);
  printf("0. clear screen\n1. Enqueue\n2. Dequeue\n3. Display\n4. Delete Queue\n5. Exit\t\t");
}

void main()
{
  queue ob;
  init(&ob);
  int ch;
  int data;
  do
  {
    menu(&ob);
    scanf("%d",&ch);
    switch(ch)
    {
      case 0:
        system("clear");
      break;
      case 1:
          printf("enter element to be inserted : "); scanf("%d",&data);
          enqueue(&ob,data);
      break;
      case 2:
          dequeue(&ob);
      break;
      case 3:
          display(&ob);
      break;
      case 4:
          init(&ob);
          printf("Queue is Deleted successfully\n");
      break;
    }
  }while(ch!=5);
}
