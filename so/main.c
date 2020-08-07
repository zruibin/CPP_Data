/*
 *
 * main.c
 *
 * Created by zhouruibin734 on 2019/06/20.
 * Copyright (c) 2019年 zhouruibin734 All rights reserved.
 */

#include <stdio.h>
#include <dlfcn.h>

/*
 * gcc -shared -o share.so share.c
 * gcc -o main main.c
 * */


typedef void (*Fun001)(int a);
typedef int (*Fun002)(int a);

int main(int argc, char **argv)
{
    void *handler = dlopen("./share.so", RTLD_LAZY);
    if (handler == NULL) {
        printf("handler is null\n");
        //exit(0);
        return 0;
    }
    
    Fun001 fun001 = (Fun001)dlsym(handler, "shareTest001");
    if (fun001) {
        fun001(10);
    } else {
        printf("%s\n", dlerror());
    }

    Fun002 fun002 = (Fun002)dlsym(handler, "shareTest002");
    if (fun002) {
        printf("fun002: %d\n", fun002(10));
    } else {
        printf("%s\n", dlerror());
    }
 
    dlclose(handler);
    return 0;
}



