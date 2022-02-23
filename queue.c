#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int key;
	struct element *next, *front, *rear;
}node,copy;

node *addnode()
{
	int a;
    printf("enter node value\t");
    scanf("%d",&a);
    node *temp = (struct element*)malloc(sizeof(struct element));
	temp->key = a;
	temp->next = NULL;
	return temp;
}

node *createQueue()
{
	node* q = (struct element*)malloc(sizeof(struct element));
	q->front = q->rear = NULL;
	return q;
}

void insert(node **head, node *element)
{
    node *temp = element;
    node *q=*head;
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

node *delete(node **head)
{
    node *q;
    q = *head;
    printf(" %d deleted\n", q->front->key);
    if (q->front == NULL)
		return (*head);

	node* temp = q->front;

	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
    return (*head);
    
}

void display (node *r)
{
    int c=1;
    node *p;
    free(p);
    p = r;
    while(p!=NULL)
    {
        printf("Node %d:  %d\n",c , p->key );
        c++;
        p = p->next;
    }
    printf("\n");
    return;
}

int main()
{
	int c;
    node* q = createQueue();
    do
    {
        printf(" Enter operation\n1)insert 2)delete 3)display 100)exit\n");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            insert(&q,addnode());
            break;

            case 2:
	        q=delete(&q);
            break;

            case 3:
            display(q->front);
            break;

            default:
            printf("ERROR\n");
            break;

        }

       
    } while (c!=100);
	return 0;
}
