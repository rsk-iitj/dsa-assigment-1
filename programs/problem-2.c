#include <stdio.h>


int main(int argc, char const *argv[])
{
	const int SIZE=100;
	char inp_str[SIZE],temp_ch;
  	printf("Enter your input string (Not Bigger then of Size 100 Chars):");
  	scanf("%s",inp_str);
  	printf("\nInputed String is :%s",inp_str);
  	int len=0;
	while(inp_str[len++]!='\0');
	len--;
	printf("\nLength of string is:%d",len);
	int rev_count=len-1;
	int flag=0;
  	for(int i=0;i<len/2;i++)
  	{
  	    
  	 
  		if(inp_str[i] == inp_str[rev_count])
  		{
  			flag=1;
  			continue;
  		}
  		else 
  		{
  			flag=0;
  			break;
  		}
  	}

  	if(flag==1)
  		printf("\nGiven String is Palindrom");
  	else
  		printf("\nGiven String is Not A Palindrom");
  	printf("\n");
    
	return 0;
}


