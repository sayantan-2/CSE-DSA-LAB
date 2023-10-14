#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front[2] = {-1, MAX_SIZE};
int rear[2] = {-1, MAX_SIZE};

void enqueue(int element, int queueNumber)
{
   if (front[queueNumber] == rear[queueNumber] - 1)
   {
      printf("Queue overflow\n");
      return;
   }
   if (queueNumber == 0)
   {
      queue[++front[queueNumber]] = element;
   }
   else if (queueNumber == 1)
   {
      queue[--rear[queueNumber]] = element;
   }
   else
   {
      printf("Invalid queue number\n");
   }
}

int dequeue(int queueNumber)
{
   if (front[queueNumber] == -1 || front[queueNumber] > rear[queueNumber])
   {
      printf("Queue underflow\n");
      return -1;
   }
   if (queueNumber == 0)
   {
      return queue[front[queueNumber]--];
   }
   else if (queueNumber == 1)
   {
      return queue[rear[queueNumber]++];
   }
   else
   {
      printf("Invalid queue number\n");
      return -1;
   }
}

void display(int queueNumber)
{
   if (front[queueNumber] == -1 || front[queueNumber] > rear[queueNumber])
   {
      printf("Queue is empty\n");
      return;
   }
   printf("Queue %d elements are: ", queueNumber);
   if (queueNumber == 0)
   {
      for (int i = front[queueNumber]; i <= rear[queueNumber]; i++)
      {
         printf("%d ", queue[i]);
      }
   }
   else if (queueNumber == 1)
   {
      for (int i = rear[queueNumber]; i <= front[queueNumber]; i++)
      {
         printf("%d ", queue[i]);
      }
   }
   else
   {
      printf("Invalid queue number\n");
   }
}

int main()
{
   enqueue(10, 0);
   enqueue(20, 0);
   enqueue(30, 1);
   enqueue(40, 1);
   display(0);
   display(1);
   dequeue(0);
   dequeue(1);
   display(0);
   display(1);
}
