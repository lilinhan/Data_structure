/*************************************************************************
	> File Name: 2.c
	> Author: lewin
	> Mail: lewin@xiyoulinux.org
	> Weechat: 693465363
	> Company: XiyouLinux Group
	> Created Time: Sat 22 Nov 2014 05:33:50 PM CST
 ************************************************************************/
#include<stdio.h>

#define MAX 100
#define OLD -1

int main()
{
    int i = 0;
#if  MAX > 50
    {
#if OLD > 3
        { i = 1; }
#elif OLD > 0
        { i = 2; }
#else
        { i = 3; }
#endif
    }
#else
    {
#if OLD > 3
        { i = 4; }
#elif OLD > 4
        { i = 5; }
#else
        { i = 6; }
#endif
    }
#endif
    printf(" i = %d\n",i);
    return 0;
}
