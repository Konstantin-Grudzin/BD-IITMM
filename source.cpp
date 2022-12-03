#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void task2()
{
    int words, sentences = words = 0;

    char *s = (char*)malloc(100);
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        words += (s[i] == ' ');
        if (s[i] == '.')
        {
            sentences++;
            if (i < n - 1)
            {
                if (s[i + 1] != ' ')
                {
                    char* st = (char*)malloc(i + 1);
                    st = strncpy(st, s, i + 1);
                    st = strcat(st, " ");
                    s = strcat(st, s + i + 1);
                }
            }
        }
    }
    puts(s);
    printf("Sentences:%d words:%d", sentences, words);
    free(s);
}

void task3()
{
    char* s = (char*)malloc(100);
    gets(s);
    char* st;
    for (int i = 0; i < strlen(s); ++i)
    {
        switch (s[i])
        {
            case '+':
                st = (char*)malloc(i);
                st = strncpy(st, s, i);
                st = strcat(st, "Plus");
                s = strcat(st, s + i + 1);
                break;
            case '-':
                st = (char*)malloc(i);
                st = strncpy(st, s, i + 1);
                st = strcat(st, "Minus");
                s = strcat(st, s + i + 1);
                break;
            case '*':
                st = (char*)malloc(i);
                st = strncpy(st, s, i);
                st = strcat(st, "Multiply");
                s = strcat(st, s + i + 1);
                break;
            case ':':
                st = (char*)malloc(i);
                st = strncpy(st, s, i);
                st = strcat(st, "Divide");
                s = strcat(st, s + i + 1);
                break;
        }
    }
    puts(s);
    free(s);
}

int rowIndex;
int *mas;
void rek_task(int n)
{
    if(n==rowIndex+1)
        return;
    else
    {
        mas[n*rowIndex]=1;
        for(int i=1;i<=n;++i)
        {
            mas[n*rowIndex+i]=mas[(n-1)*rowIndex+i]+mas[(n-1)*rowIndex+i-1];
        }
        rek_task(n+1);
    }
}

int rek_2(int n)
{
    if(n<1)
        return 0;
    if(n==1)
        return 1;
    return (n>2)+rek_2(n-2)+rek_2(n-1);
}

int main()
{
    /*1 rek task
    scanf("%d",&rowIndex);
    rowIndex++;
    mas=(int*)calloc((rowIndex+1)*(rowIndex+1)*sizeof(int),sizeof(int));
    rek_task(1);
    for(int i=0;i<rowIndex;++i)
    {
        printf("%d ",mas[rowIndex*(rowIndex)+i]);
    }
    */
    int x=rek_2(3);
    printf("%d ",x);
    return 0;
}
