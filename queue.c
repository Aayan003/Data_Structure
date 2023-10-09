#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int size, *a, front, rear;
}qu;
void init(qu *q, int lim)
{
    q -> size = lim;
    q -> a = (int*)malloc(q -> size * sizeof(int));
    q -> rear = q -> front = -1;
}
int isEmpty(qu *q)
{
    return (q -> front == -1);
}
int isFull(qu *q)
{
    return (q -> rear == q -> size - 1 && q -> front == 0) || (q -> front == q -> rear + 1);
}
void rearEnQueue(qu *q, int item)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    else if(q -> front == q -> rear && q -> front == -1)
    {
        q -> front = q -> rear = 0;
        q -> a[q -> rear] = item;
    }
    else if(q -> rear == q -> size -1)
    {
        q -> rear = 0;
        q -> a[q -> rear] = item;
    }
    else
    {
        q -> a[++q -> rear] = item;
    }
}
void frontEnQueue(qu *q, int item)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    else if(q -> front == q -> rear && q -> front == -1)
    {
        q -> front = q -> rear = 0;
        q -> a[q -> front] = item;
    }
    else if(q -> front == 0)
    {
        q -> front = q -> size - 1;
        q -> a[q -> front] = item;
    }
    else
    {
        q -> a[q -> front--] = item;
    }
}
int frontDeQueue(qu *q)
{
    int item;
    item = q -> a[q -> front];
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return 1;
    }
    else if(q -> front == q -> rear)
    {
        q -> front = q -> rear = -1;
    }
    else if(q -> front == q -> size -1)
    {
        q -> front = 0;
    }
    else
    {
        q -> front++;
    }

    return item;
}
int rearDeQueue(qu *q)
{
    int item;
    item = q -> a[q -> rear];
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return -999999991;
    }
    else if(q -> front == q -> rear)
    {
        q -> front = q -> rear = -1;
    }
    else if(q -> rear == 0)
    {
        q -> rear = q -> size - 1;
    }
    else
    {
        q -> rear--;
    }

    return item;
}
void disp(qu *q)
{
    if(q -> rear > q -> front)
    {
        for(int i = q -> front; i < q -> rear; i++)
            printf("%d, ", q -> a[i]);
    }
    else
        for(int i = 0; i < q -> rear; i++)
        {
            printf("%d, ", q->a[i]);
        }
        for(int u = q -> front; u < q -> size - 1; u++)
        {
            printf("%d, ", q->a[u]);
        }
}
int main()
{
    qu q;
    int item, lim;
    char type;
    printf("How much queue size do you want-\n");
    scanf("%d", &lim);
    init(&q, lim);
    do
    {
        printf("Enter \"E\" for en Rear En queueing and \"e\" for Front EN Queueing and \"D\" for Front de queueing, \"d\" for Rear De Queueing\n");
        scanf("\n%c", &type);
        switch(type)
        {
            case 'D' :
                if(!isEmpty(&q)) {
                    printf("after De Queuing %d\n", frontDeQueue(&q));
                    disp(&q);
                }
                break;
            case 'E' :
                if(!isFull(&q)) {
                    printf("Enter the element->\n");
                    scanf("%d", &item);
                    rearEnQueue(&q, item);
                }
               // disp(&q);
               // printf("\nIs it full %d\n", isFull(&q));

                break;
            case 'd' :
                if(!isEmpty(&q)) {
                    printf("after rear De Queuing %d\n", rearDeQueue(&q));
                    disp(&q);
                }
                break;
            case 'e' :
                if(!isFull(&q)) {
                    printf("Enter the element for front en queueing->\n");
                    scanf("%d", &item);
                    frontEnQueue(&q, item);
                }
                //printf("\nIs it full %d\n", isFull(&q));
                //disp(&q);
                break;
            default : printf("Invalid Input\n");
        }
    }while(type == 'D' || type == 'E' || type == 'd' || type == 'e');
    return 0;
}
