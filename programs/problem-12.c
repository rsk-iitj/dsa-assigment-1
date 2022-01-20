#include <stdio.h>

#define HEAP_CAPACITY 100


/*void intalizeHeap()
{
	heap_size = 0;
	heap[HEAP_CAPACITY];
	printf("\n HEAP CREATED!!");
}*/

int returnParent(int i) {

 	return (i-1)/2;

}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*void heapify(int heap[], int heap_size, int i)
{
    int parent = (i - 1) / 2;

    if (heap[parent] > 0) {

        if (heap[i] > heap[parent]) {
            swap(&heap[i], &heap[parent]);
            heapify(heap, heap_size, parent);
        }
    }
}*/




int leftNode(int i) {
    return (2*i + 1);
}

int rightNode(int i) {
    return (2*i + 2);
}


void heapify(int heap[],int heap_size,int i)
{
    int largest = i;
    int l = leftNode(i);
    int r = rightNode(i);

    if(l < heap_size && heap[l] > heap[largest] )
       largest=l;
    if(r < heap_size && heap[r]>heap[largest])
       largest=r;
    if(largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapify(heap,heap_size,largest);
    }
}

/*int insertMaxHeap(int heap[],int heap_size,int data)
{

    if (heap_size == HEAP_CAPACITY)
    {
        printf("\n HEAP OVERFLOW, COULD NOT INSERTED");
    }
    heap_size++;
    int i = heap_size - 1;
    heap[i] = data;
    heapify(heap,heap_size,heap_size-1);
    return heap_size;
}*/

void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

/*void printHeap()
{
   int k=0;
   while(k<=heap_size)
   {
      printf("--%d--",heap[k]);
      k++;
   }

}*/






int getMaximum(int heap[], int heap_size)
{
    if (heap_size <= 0)
        return -1;
    int root = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;
    heapify(heap,heap_size,0);
    return root;
}

int kThGreatest(int k, int heap[], int heap_size)
{
    for (int i = 1; i < k; ++i)
        getMaximum(heap,heap_size);
    return getMaximum(heap,heap_size);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
       printf("-- %d -- ",arr[i]);
    printf("\n");
}


int main(int argc, char const *argv[])
{

    int heap[HEAP_CAPACITY] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int heap_size = 11;

    char operation;
    printf("\n SELECT THE OPERATION WHICH YOU WANT TO PERFORM\n");
    printf("\n'c' for CREATE, 'K' for Kth Largest & 'e' FOR EXIT\n");
    do
    {
        printf("\n Enter the operation:-");
        scanf(" %c",&operation);
        switch(operation)
        {
            case 'c' :
            {
                buildHeap(heap,heap_size);
                printArray(heap,heap_size);
                            //  intalizeHeap();
                break;
            }
           /* case 'i':
            {
                int data;
                printf("\n Enter the data to be inserted-:");
                scanf("%d",&data);
            	heap_size=insertMaxHeap(heap,heap_size,data);
                printArray(heap,heap_size);
            	//printHeap();
                break;
            }*/
            case 'k':
            {
                int k,result;
                printf("\n Enter Value of K to find Kth Largest-:");
                scanf("%d",&k);
            	result = kThGreatest(k,heap,heap_size);
            	printf("Kth Largest = :%d",result);
                break;
            }
            case 'e':
            {
                printf("\n\t EXITING....! ");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice(c,k)");
            }

        }
    }
    while(operation!='E' && operation!='e' );
    return 0;
}



