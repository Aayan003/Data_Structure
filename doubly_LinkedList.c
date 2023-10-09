/*For binary searching Linked List is not a good Idea and for even Sorting a linked list Sorting is expensive*/

#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
	int data;
	struct NODE *prev;
	struct NODE *next;
}node;
node *search(node *ptr, node **head, int key)
{
	while(ptr -> data != key && ptr -> prev != *head)
		ptr = ptr -> next;
	if(ptr -> data == key)
		return ptr;
	else
		return NULL;
}
void disp(node **tail, node *ptr, node *p)
{
	printf("Forward-\n\"");
	while((ptr) != (*tail) -> next)
	{
		printf("%d, ", (ptr) -> data);
		(ptr) = (ptr) -> next;
	}
	printf("\"\n");
	printf("Backward-\n\"");
	while((p) != NULL)
	{
		printf("%d, ", (p) -> data);
		p = p -> prev;
	}
	printf("\"\n");
}
void disp_back(node *ptr)
{
	printf("\n\"");
	while((ptr) != NULL)
	{
		printf("%d, ", (ptr) -> data);
		(ptr) = (ptr) -> prev;
	}
	printf("\"\n");
}
void front_append(node **head, node **tail, int item)
{
	node *new_node;
	new_node = (node*)malloc(sizeof(node));
	new_node -> data = item;
	new_node -> next = *head;
	new_node -> prev = *tail;
	(*head) -> prev = new_node;
	(*head) = new_node;
	(*tail) -> next = *head;
}
void rear_append(node **head, node **tail, int item)
{
	node *new_node;
	new_node = (node*)malloc(sizeof(node));
	node *ptr = *head;
	new_node -> prev = NULL;
	new_node -> data = item;
	new_node -> next = NULL;
	//printf("(%p    %p    %p\n", new_node -> next, *head, *head);
	if(*head == NULL)
	{
		new_node -> prev = new_node -> next = new_node;
		*head = *tail = new_node;
	}
	else
	{
		new_node -> next = *head;
		(*head) -> prev = new_node;
		new_node -> prev = *tail;
		(*tail) -> next = new_node;
		*tail = new_node;
	}
}
void pos_append(node **head, node **tail, int pos, int item)
{
	node *new_node, *cpy;
	int cnt = 1;
	new_node = (node*)malloc(sizeof(node));
	node *ptr = *head;
	new_node -> prev = NULL;
	new_node -> data = item;
	new_node -> next = NULL;
	if(*head == NULL)
	{
		new_node -> prev = new_node -> next = new_node;
		*head = *tail = new_node;
	}
	else
	{
		while(cnt != pos - 1 && ptr != *head)
		{
			//printf("99\n");
			ptr = ptr -> next;
			cnt++;
		}
		if(cnt == pos - 1)
		{
			new_node -> next = ptr -> next;
			new_node -> prev = ptr;
			(ptr -> next) -> prev = new_node;
			ptr -> next = new_node;
		}
	}
	//new_node -> next = ptr;
}
void key_after_append(node **head, node **tail, int key, int item)
{
	if((search(*head, &head, key)) != NULL)
	{
		node *new_node, *cpy;#include <stdio.h>
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

		new_node = (node*)malloc(sizeof(node));
		node *ptr = search(*head, key);
		new_node -> prev = NULL;
		new_node -> data = item;
		new_node -> next = NULL;
		if(*head == NULL)
		{
			new_node -> prev = new_node -> next = new_node;
			*head = *tail = new_node;
		}
		else
		{
			new_node -> prev = ptr;
			new_node -> next = ptr -> next;
			ptr -> next -> prev = new_node;
			if(ptr == *tail)
				(*tail) = new_node;
			else
				ptr -> next = new_node;
		}
	}
	//new_node -> next = ptr;
}
void key_before_append(node **head, node **tail, int key, int item)
{
	node *new_node, *cpy;
	new_node = (node*)malloc(sizeof(node));
	node *ptr = search(*head, &head, key);
	new_node -> prev = NULL;
	new_node -> data = item;
	new_node -> next = NULL;
	if(*head == NULL)
	{
		*head = *tail = new_node;
	}
	else
	{
		new_node -> prev = ptr -> prev;
		new_node -> next = ptr;
		ptr -> prev -> next = new_node;
		if(ptr == *head)
			*head = new_node;
		else
			ptr -> prev = new_node;
	}
	//new_node -> next = ptr;
}
void rear_del(node **head, node **tail)
{
	node *ptr = *tail, *cpy = *head;
	if(*head == *tail)
	{
		*head = *tail = NULL;
	}
	else
	{
		*tail = ptr -> prev;
		(*tail) -> next = NULL;
	}
	free(ptr);
}
void front_del(node **head, node **tail)
{
	node *ptr = *head;
	if(*head == *tail)
		*head = *tail = NULL;
	else
	{
		(*head) = ptr -> next;
		(*head) -> prev = NULL;
	}
	free(ptr);
}
void key_del(node **head, node **tail, int item)
{
	node *ptr = search(*head, item);
	//node *cpy = ptr -> next;
	//int flag = 0;
	if(*head == *tail)
	{
		*head = *tail = NULL;
	}
	else if(ptr == *tail)
	{
		(ptr -> prev) -> next = NULL;
		*tail = ptr -> prev;
	}
	else
	{
		(ptr -> prev) -> next = ptr -> next;
		printf("87");
		(ptr -> next) -> prev = ptr -> prev;
		//cpy -> prev = ptr -> prev;
	}
	free(ptr);
	//if(flag)
		//free(ptr);
}
int main()
{
	int item, pos;
	char type = '1';
	node *head = NULL, *new_node, *tail = NULL;
	//head -> next = NULL;
	do
	{
		switch(type)
		{
			case '1' :
				printf("Enter the item-\n");
				scanf("%d", &item);
				rear_append(&head, &tail, item);
				break;
			case '2' :
				printf("Enter the item-\n");
				scanf("%d", &item);
				front_append(&head, &tail, item);
				break;
			case '3' :
				printf("Enter the key and item-\n");
				scanf("%d %d", &pos, &item);
				key_after_append(&head, &tail, pos, item);
				break;
			case '5' :
				rear_del(&head, &tail);
				break;
			case '6' :
				front_del(&head, &tail);
				break;
			case '7' :
				printf("Enter the Key-\n");
				scanf("%d", &pos);
				if(head -> data != pos)
					key_del(&head, &tail, pos);
				else
					front_del(&head, &tail);
				break;
			case '4' : printf("Enter the position and item-\n");
				scanf("%d %d", &pos, &item);
				if(pos == 1)
					front_append(&head, &tail, item);
				else
					pos_append(&head, &tail, pos, item);
				break;
			case '8' :
				//new_node = head;
				disp(head, tail);
				break;
			case '9' :printf("Enter the key and item-\n");
				scanf("%d %d", &pos, &item);
				key_before_append(&head, &tail, pos, item);
				break;
			default : printf("Invalid input\n");
		}
		printf("Want to continue?\nGive-\n1 for Rear Insertion of elements\n2 for Front Insertion of elements\n3 for Key After Specific Insertion\n4 for Position Specific Insertion\n5 for Rear end Deletion\n6 for Front end Position Deletion\n7 for Key Specific Deletion\n8 for Display of the Linked List\n9 for Key Before Specific Insertion\n");
		scanf("\n%c", &type);
	}while(type >= '1' && type <= '9' || (type >= 'A' && type <= 'D'));
	free(head);
	return 0;
}
