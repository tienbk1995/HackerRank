#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef enum STag_Queries
{
    ENQUEUE = 1,
    DEQUEUE,
    PEEK
} QUERY;

void enQueue (int *queue, int *rear, int data)
{
    queue[*rear] = data;
    (*rear)++;
}

int deQueue (int *queue, int *front, int *rear)
{
    if (*front == *rear) return -1;
    int temp = queue[*front];
    (*front)++;
    return temp;
}

int peekFront (int *queue, int *front)
{
    return queue[*front];
}

int main() 
{
    int numOfQuery;
    scanf("%d",&numOfQuery);
    int *queue = calloc(100001, sizeof(int));
    int front = 0;
    int rear = 0;
    int data;
    QUERY query;
    while (numOfQuery--)
    {
        scanf("%d",&query);
        switch (query)
        {
            case ENQUEUE:
                scanf("%d",&data);
                enQueue(queue,&rear,data);
                break;
            case DEQUEUE:
                deQueue (queue, &front, &rear);
                break;
            case PEEK:
                printf ("%d\n", peekFront (queue, &front));
                break;
            default:
                break;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
