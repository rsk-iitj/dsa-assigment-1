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
  	for(int i=0;i<len/2;i++)
  	{
  	    temp_ch = inp_str[i];
  	    printf("\nThis char is %c",temp_ch);
  		inp_str[i] = inp_str[rev_count];
        inp_str[rev_count--] = temp_ch;
  	}
  	printf("\nRevered string is:%s",inp_str);
  	printf("\n");
    
	return 0;
}


