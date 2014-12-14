/*************************************************************************
	> File Name: 3.c
	> Author: lewin
	> Mail: lewin@xiyoulinux.org
	> Weechat: 693465363
	> Company: XiyouLinux Group
	> Created Time: Sat 22 Nov 2014 05:48:25 PM CST
 ************************************************************************/
#include<stdio.h>

int main()
{
        int j ;

        printf("日期:%s\n",__DATE__);
        printf("时间:%s\n",__TIME__);
        printf("文件名:%s\n",__FILE__);
        printf("这是第%d行代码\n",__LINE__);
        printf("本编辑器%s标准C\n",(__STDC__)?"符合":"不符合");
        return 0;
}
