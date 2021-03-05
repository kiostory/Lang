#include<string.h>
#include<stdio.h>

int main()
{
char str[100];

strncpy(str, "abcdefghi",99);  //str[3]='\0'; 필요  >> strncpy는 null을 마지막에 자동으로 넣어주지 않음
//str[3]='\0';
printf("%s\n",str);
return 0;

}