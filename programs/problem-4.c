#include <stdio.h>


int main(int argc, char const *argv[])
{
	int size_array=0;
    printf("\n Enter the size of Array-:");
    scanf("%d",&size_array);
    int array[size_array];
    int thisInt;
    for(int i=0;i<size_array;i++)
    {
    	printf("\nEnter the element-%d-:",i);
    	scanf("%d",&thisInt);
    	array[i]=thisInt;
    }
    int max=0;
    for(int j=0;j<size_array;j++)
    {
    	int thisElm = array[j];
    	if(thisElm>max)
    		max=thisElm;
    }
    int min=0;
    for(int k=0;k<size_array;k++)
    {
    	int thisElmt = array[k];
    	if(thisElmt<max)
    		min=thisElmt;
    }
    int diff=max-min;
    printf("\nDifferenece of Max & Minimum=%d",diff);
    printf("\n");
	return 0;
}


