#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};


struct LinkedList
{
	struct Node* head;
	struct Node* tail;
};


struct Node* createNewNode(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	return temp;

}



struct LinkedList* createLinkedList()
{
	struct LinkedList* temp = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	temp->head = NULL;
	temp->tail = NULL;
	return temp;
}

void insertInStart(struct LinkedList* linkedList)
{
	int data;
	printf("\n Enter the data to be inserted-:");
	scanf("%d",&data);
	struct Node* temp = createNewNode(data);
	if(linkedList->head==NULL)
	{
		linkedList->head = temp;
		linkedList->tail = temp;
	}
	else
	{
		temp->next = linkedList->head;
		linkedList->head = temp;
	}
}


void insertAtEndstruct(struct LinkedList* linkedList)
{
	int data;
	printf("\n Enter the data to be inserted-:");
	scanf("%d",&data);
	struct Node* temp = createNewNode(data);
	if(linkedList->head==NULL)
	{
		linkedList->head = temp;
		linkedList->tail = temp;
	}
	else
	{
		linkedList->tail->next = temp;
		linkedList->tail=temp;
	}
}

struct Node* findTheMiddle(struct LinkedList* linkedList)
{
	struct Node* slow=linkedList->head;
	struct Node* fast = linkedList->head;
	if(fast==NULL)
        return NULL;
    if(fast->next==NULL)
        return slow;
	if(fast->next->next==NULL)
        return slow;
	while(fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


void insertAtMiddle(struct LinkedList* linkedList)
{
	int data;
	printf("\n Enter the data to be inserted-:");
	scanf("%d",&data);
	struct Node* middle = findTheMiddle(linkedList);
	struct Node* temp = createNewNode(data);
	struct Node* temp2;
	if(linkedList->head==NULL)
	{
		linkedList->head = temp;
		linkedList->tail = temp;
	}
	else
	{
		temp2 = middle->next;
		middle->next=temp;
		temp->next=temp2;
	}
}



void printLinkedList(struct LinkedList* linkedList)
{

	struct Node* temp=linkedList->head;
	while(temp!=NULL)
	{
		printf("---- %d --->",temp->data);
		temp = temp->next;
	}
}

void search(struct LinkedList* linkedList)
{
	struct Node* temp=linkedList->head;
	int flag = 0;
	int data;
	printf("\n Enter the data to be searched-:");
	scanf("%d",&data);
	while(temp->next!=NULL)
	{
		if(temp->data==data)
		{
			flag =1;
			break;
		}
		else
		{
			flag =0;
		}
		temp=temp->next;
	}

	if(flag==0)
	{
		printf("\n Searched Item Not Found");
	}
	else
	{
		printf("\n Searched Item found");

	}
}

int main(int argc, char const *argv[])
{

    char operation;
    struct LinkedList* linkedList = createLinkedList();
    printf("\n SELECT THE OPERATION WHICH YOU WANT TO PERFORM\n");
    printf("\n CHOOSE FOR INSERT INTO START-i, INSERT INTO MIDDLE-'m' and INSERT INTO END-'d' & 'e' FOR EXIT\n");
    do
    {
        printf("\n Enter the operation:-");
        scanf(" %c",&operation);
        switch(operation)
        {
            case 'i' :
            {
                insertInStart(linkedList);
                printLinkedList(linkedList);
                break;
            }
            case 'd':
            {
            	insertAtEndstruct(linkedList);
            //	printLinkedList(linkedList->head);
                printLinkedList(linkedList);
                break;
            }
            case 'm':
            {
            	insertAtMiddle(linkedList);
            	//printLinkedList(linkedList->head);
            	printLinkedList(linkedList);
                break;
            }

            case 's':
            {
            	search(linkedList);
            	//printLinkedList(linkedList->head);
            	printLinkedList(linkedList);
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


