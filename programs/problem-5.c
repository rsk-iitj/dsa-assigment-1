#include<stdio.h>

#define SIZE_STACK 100

int stack_ints[SIZE_STACK];

int top_stack = -1;

void push();
void delete_item();
void trace();

int main(int argc, char const *argv[])
{
    char operation;

    printf("\n SELECT THE OPERATION WHICH YOU WANT TO PERFORM\n");
    printf("\n CHOOSE 'P\p' FOR PUSH, 'D\d' FOR DELETE, 'T\t' FOR TRACE & 'E\e' FOR EXIT\n");
    do
    {
        printf("\n Enter the operation:-");
        scanf(" %c",&operation);
        switch(operation)
        {
            case 'P':
            {
                push();
                break;
            }
            case 'p':
            {
                push();
                break;
            }
            case 'D':
            {
                delete_item();
                break;
            }
            case 'd':
            {
                delete_item();
                break;
            }
            case 'T':
            {
                trace();
                break;
            }
            case 't':
            {
                trace();
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
                printf ("\n\t Please Enter a Valid Choice(P/p,E/e,D/d or T/t)");
            }

        }
    }
    while(operation!='E' && operation!='e' );
    return 0;
}
void push()
{
    if(top_stack>=SIZE_STACK-1)
    {
        printf("\n ERROR - STACK IS OVER FLOWING!");
    }
    else
    {
    	int value;
        printf("\n Enter a value to be pushed:-");
        scanf("%d",&value);
        top_stack++;
        stack_ints[top_stack]=value;
    }
}
void delete_item()
{
    if(top_stack<=-1)
    {
        printf("\n STACK IS EMPTY!");
    }
    else
    {
        printf("\n The DELETED elements is %d",stack_ints[top_stack]);
        top_stack--;
    }
}
void trace()
{
    if(top_stack>=0)
    {
        printf("\n The items of STACK are \n");
        for(int i=top_stack; i>=0; i--)
            printf("\n%d",stack_ints[i]);
        printf("\n Please choose next operation\n");
    }
    else
    {
        printf("\n The STACK is EMPTY!");
    }

}





