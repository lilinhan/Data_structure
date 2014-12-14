/*************************************************************************
	> File Name: 1.c
	> Author: lewin
	> Mail: lewin@xiyoulinux.org
	> Weechat: 693465363
	> Company: XiyouLinux Group
	> Created Time: Sat 22 Nov 2014 05:22:17 PM CST
 ************************************************************************/
#include<stdio.h>

#define DEBUG 1

int main()
{
        int i , j;
        char ch[26];
        for( i = 'a',j = 0; i <= 'z' ; i++,j++ )  {
                ch[j] = i;
                #if DEBUG
                        printf("ch[%d] = %c\n",j,ch[j]);
                #endif
        }
        for( j = 0 ; j < 26 ;j++ )  {
                printf("%c",ch[j]);
        }
        printf("\n");
        return 0;
}
