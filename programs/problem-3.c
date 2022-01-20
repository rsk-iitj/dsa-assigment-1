#include <stdio.h>

#define NO_CHAR_ALPHA 256

int main(int argc, char const *argv[])
{
	const int SIZE=100;
    char inp_str1[SIZE];
    char inp_str2[SIZE];

    printf("\nEnter your first input string (Not Bigger then of Size 100 Chars):");
    scanf("%s",inp_str1);

    printf("\nEnter your second input string (Not Bigger then of Size 100 Chars):");
    scanf("%s",inp_str2);

    int lenStr1=0;
    int flagAnagram=0;
    int lenStr2=0;

    while(inp_str1[lenStr1++]!='\0');
    lenStr1--;


    while(inp_str2[lenStr2++]!='\0');
    lenStr2--;

    printf("\nLength of first string is:%d",lenStr1);

    printf("\nLength of Second string is:%d",lenStr2);


    int arr_ints1[NO_CHAR_ALPHA];
    int arr_ints2[NO_CHAR_ALPHA];

    for(int i=0;i<NO_CHAR_ALPHA;i++)
        arr_ints1[i]=0;

    for(int j=0;j<NO_CHAR_ALPHA;j++)
        arr_ints2[j]=0;



    if (lenStr2!=lenStr1)
    {
        flagAnagram=0;
    }
    else
    {
        for (int i = 0; i<lenStr1;i++)
        {
            arr_ints1[inp_str1[i]]++;
            arr_ints2[inp_str2[i]]++;
        }

        for (int k = 0; k < NO_CHAR_ALPHA ; k++)
        {
            if (arr_ints2[k] != arr_ints1[k])
            {
                flagAnagram=0;
                break;
            }
            else
            {
                flagAnagram=1;
                continue;
            }
        }
    }


    if(flagAnagram==1)
        printf("\nBoth the strings are anagram of each other");
    else
        printf("\nBoth the strings are not anagram of each other");

    return 0;


}


