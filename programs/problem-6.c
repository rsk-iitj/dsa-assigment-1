#include<stdio.h>
#include<stdlib.h>

struct QueueElement
{
	int data;
	struct QueueElement *next;
};


struct Queue
{
	struct QueueElement *start;
	struct QueueElement *end;
};


struct QueueElement* createNewQueueElement(int key);
void insertInQueue(struct Queue *queue);
struct Queue* intializeEmptyQueue();
void deleteFromQueue(struct Queue* queue);
void displayAllElement(struct Queue* queue);


int main(int argc, char const *argv[])
{
	/* code */
	char operation;
	struct Queue* queue = intializeEmptyQueue();

    printf("\n SELECT THE OPERATION WHICH YOU WANT TO PERFORM\n");
    printf("\n CHOOSE 'I or i' FOR INSERT, 'D or d' FOR DELETE, 'p or P' FOR DISPLAYING ALL ELEMENTS & 'E or e' FOR EXIT\n");
    do
    {
        printf("\n Enter the operation:-");
        scanf(" %c",&operation);
        switch(operation)
        {
            case 'i':
            {
                insertInQueue(queue);
                break;
            }
            case 'I':
            {
               insertInQueue(queue);
                break;
            }
            case 'D':
            {
                deleteFromQueue(queue);
                break;
            }
            case 'd':
            {
                deleteFromQueue(queue);
                break;
            }
            case 'p':
            {
                displayAllElement(queue);
                break;
            }
            case 'P':
            {

                displayAllElement(queue);
                break;
            }
            case 'E':
            {
                printf("\n\t EXITING....!");
                break;
            }
            case 'e':
            {
                printf("\n\t EXITING....! ");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice(P/p,E/e,D/d or i/I)");
            }

        }
    }
    while(operation!='E' && operation!='e' );
    return 0;
}


struct QueueElement* createNewQueueElement(int key)
{
    struct QueueElement* temp = (struct QueueElement*)malloc(sizeof(struct QueueElement));
    temp->data = key;
    temp->next = NULL;
    return temp;
}


void insertInQueue(struct Queue *queue)
{
	int value;
	printf("\n Enter the element to be inserted into Queue-:");
	scanf("%d",&value);
	struct QueueElement* temp = createNewQueueElement(value);

    if (queue->end == NULL) {
        queue->start = queue-> end = temp;
    }
    else
    {
        queue->end->next = temp;
        queue->end = temp;
    }

}

struct Queue* intializeEmptyQueue()
{
	struct Queue* queue= (struct Queue*)malloc(sizeof(struct Queue));
    queue->start = queue->end = NULL;
    return queue;
}

void deleteFromQueue(struct Queue* queue)
{

    if (queue->start == NULL)
        return;

    struct QueueElement* temp = queue->start;

    queue->start = queue->start->next;

    if (queue->start == NULL)
        queue->end = NULL;

    free(temp);
}

void displayAllElement(struct Queue* queue)
{
	if(queue->start == NULL && queue->end == NULL)
	{
		printf("\n Queue is EMPTY!");
	}
	else
	{
		struct QueueElement* temp = queue->start;
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp= temp->next;
		}
	}

}



