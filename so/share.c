/*
 *
 * share.c
 *
 * Created by zhouruibin734 on 2019/06/20.
 * Copyright (c) 2019年 zhouruibin734 All rights reserved.
 */

#include <stdio.h>

void shareTest001(int a)
{
    printf("shareTest001: %d\n", a);
}

int shareTest002(int a)
{
    printf("shareTest002: %d\n", a);

    return a*a;
}




