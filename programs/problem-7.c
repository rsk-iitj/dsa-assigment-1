#include<stdio.h>

#define SIZE_STACK 100

int stack_chars[SIZE_STACK];

int top_stack = -1;

void push(char);
char pop();
void trace();
int areBracketsBalanced(char []);

int main(int argc, char const *argv[])
{
    char inp_exp[SIZE_STACK];
    printf("\n Enter the expression you want to check-:");
    scanf("%s",inp_exp);
    int result = areBracketsBalanced(inp_exp);
    if(result==1)
        printf("\n Entered Parthenis expression is Balanced");
    else
        printf("\n Entered Parthenis expression is NOT Balanced");
    return 0;
}

int isNextBracketMatching(char thisChar, char nextChar)
{
   // printf("\n This char is -:%c",thisChar);
   // printf("\n This Next char is -:%c",nextChar);
    if (thisChar == '(' && nextChar == ')')
        return 1;
    else if (thisChar == '{' && nextChar == '}')
        return 1;
    else if (thisChar == '[' && nextChar == ']')
        return 1;
    else
        return 0;
}


int areBracketsBalanced(char inp_exp[])
{
    int i = 0;

    while (inp_exp[i])
    {
        char thisChar = inp_exp[i];
       // printf("\n This char is -:%c",thisChar);

        if (inp_exp[i] == '{' || inp_exp[i] == '(' || inp_exp[i] == '[')
                push(inp_exp[i]);

        if (inp_exp[i] == '}' || inp_exp[i] == ')' || inp_exp[i] == ']')
        {
            if (top_stack==-1)
                return 0;
            else if (isNextBracketMatching(pop(), inp_exp[i])!=1)
                return 0;
        }
        i++;
    }

    if (top_stack ==-1)
        return 1;
    else
        return 0;
}

void push(char value)
{
    if(top_stack>=SIZE_STACK-1)
    {
        printf("\n ERROR - STACK IS OVER FLOWING!");
    }
    else
    {
       // printf("\n This char getting pushed-:%c",value);
        top_stack++;
        stack_chars[top_stack]=value;

    }
}
char pop()
{
    char result;
    if(top_stack<=-1)
    {
        printf("\n STACK IS EMPTY!");
    }
    else
    {
        result = stack_chars[top_stack];
       // printf("\n This char getting poped-:%c",result);
        top_stack--;
        //printf("\Value of top %d",top_stack);
    }
    return result;
}
void trace()
{
    if(top_stack>=0)
    {
       //printf("\n The items of STACK are \n");
        for(int i=top_stack; i>=0; i--)
            printf("\n%c",stack_chars[i]);
    }
    else
    {
        printf("\n The STACK is EMPTY!");
    }

}





