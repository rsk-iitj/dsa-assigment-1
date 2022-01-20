#include <stdio.h>

#define HEAP_CAPACITY 100

//int heap_size;

//int heap[0];



int leftNode(int i) {
    return (2*i + 1);
}

int rightNode(int i) {
    return (2*i + 2);
}


int returnParent(int i) {

    return (i-1)/2;

}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void insertMinHeap(int heap[],int *heap_size) {
    if (*heap_size >= HEAP_CAPACITY) {
        printf("%s\n", "THE HEAP IS FULL - FURTHER INSERTION NOT ALLOWED");
        return;
    }

    int data;
    printf("\n Enter the data to be inserted-:");
    scanf("%d",&data);

    heap[*heap_size] = data;
    *heap_size = *heap_size + 1;

    int i = *heap_size - 1;
    while (i != 0 && heap[returnParent(i)] > heap[i]) {
        swap(&heap[returnParent(i)], &heap[i]);
        i = returnParent(i);
    }
}


void minHipify(int heap[], int i, int heap_size){
    int left = leftNode(i);

    int right = rightNode(i);

    int smallest = i;

    if (left <= heap_size && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right <= heap_size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap[smallest],&heap[i]);
        minHipify(heap, smallest, heap_size);
    }

}


void buildMinHeap(int heap[], int heap_size) {
    int i;
    for (i = heap_size/2; i >= 0; i--) {
        minHipify(heap,i,heap_size);
    }
}


int getMin(int a[]) {
    return a[0];
}


int deleteMin(int heap[], int *heap_size) {
    int min = heap[0];


    heap[0] = heap[*heap_size - 1];
    *heap_size = *heap_size - 1;

    minHipify(heap,0,*heap_size);
    return min;
}


void printTheheap(int heap[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ->", heap[i]);
    }
    printf("\n");
}

void printheap(int heap[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ->", heap[i]);

    }
    printf("\n");
}






/*void intalizeHeap()
{
	heap_size = 0;
	heap[HEAP_CAPACITY];
	printf("\n HEAP CREATED!!");
}



void insertMinHeap()
{
	int data;

    if (heap_size == HEAP_CAPACITY)
    {
        printf("\n HEAP OVERFLOW, COULD NOT INSERTED");
    }
    printf("\n Enter the data to be inserted-:");
	scanf("%d",&data);
    heap_size++;
    int i = heap_size - 1;
    heap[i] = data;

    while (i != 0 && heap[returnParent(i)] > heap[i])
    {
       swap(&heap[i], &heap[returnParent(i)]);
       i = returnParent(i);
    }
}



void heapify(int i)
{
    int l = leftNode(i);
    int r = rightNode(i);
    int smallest = i;
    if (l < heap_size && heap[l] < heap[smallest])
        smallest = l;
    if (r < heap_size && heap[r] < heap[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void deleteMin()
{
    if (heap_size <= 0)
      printf("\n HEAP IS EMPTY - NOTHING TO DELETE");
    if (heap_size == 1)
    {
        heap_size--;
    }

    int root = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;
    heapify(0);
}
*/
  void printSmallerThan(int  heap[], int heap_size, int key, int pos)
  {

        if (pos >= heap_size)
            return;

        if (heap[pos] >= key)
        {
            return;
        }

        printf("%d->",heap[pos]);

        printSmallerThan(heap,heap_size,key, leftNode(pos));
        printSmallerThan(heap,heap_size,key, rightNode(pos));
}


int main(int argc, char const *argv[])
{

    int heap[HEAP_CAPACITY];
    char operation;
    int heap_size=10;
    heap[0]=39;heap[1] = 10; heap[2] = 12; heap[3] = 9; heap[4] = 78; heap[5] = 33; heap[6] = 21; heap[7] = 35; heap[8] = 29; heap[9] = 5; heap[10] = 66;
    printf("\n SELECT THE OPERATION WHICH YOU WANT TO PERFORM\n");
    printf("\n CHOOSE 'i' for INSERT, 'c' for CREATE, 'd' for DELETE , 'm' for MINIMUM & 'e' FOR EXIT\n");
    do
    {
        printf("\n Enter the operation:-");
        scanf(" %c",&operation);
        switch(operation)
        {
            case 'c' :
            {
                buildMinHeap(heap,heap_size);
                break;
            }
            case 'i':
            {
            	insertMinHeap(heap,&heap_size);
                break;
            }
            case 'p':
            {

                printTheheap(heap,heap_size);
                break;
            }
            case 's':
            {
                int pos=0,key;
                 printf("\n Enter the value less then which heap to be printed-:");
                 scanf("%d",&key);
                printSmallerThan(heap,heap_size,key,pos);
                break;
            }
            case 'd':
            {
            	int result = deleteMin(heap,&heap_size);
            	printf("The Deleted Item is -:%d",result);
                break;
            }

            case 'm':
            {
            	int result = getMin(heap);
            	printf("The Minimum Item is -:%d",result);
                break;
            }

            case 'e':
            {
                printf("\n\t EXITING....! ");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice(c,i,d,s,e)");
            }

        }
    }
    while(operation!='E' && operation!='e' );
    return 0;
}



