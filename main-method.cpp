#include <iostream>
#include "fuc.h"
void point_func(){
    printf("函数指针\n");
}

int func() {
    printf("func函数\n");
    return 0;
}

//指针函数
int* int_add_func(void* vParam)
{
    printf("指针函数\n");
    int b=10;
    int*p=&b;
    return  p;
}

void point_func(int* a,int *b){
    *a=100,
    *b=200;

}
//回调函数
void populate_array(int* array,size_t arraySize,int(*getNextValue)(void )){
    for(size_t i=0; i<arraySize;i++){
        array[i]=getNextValue();
    }
}
int getNextValue(void){
    return rand();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    func();//调用函数
    int a=10;
    int_add_func(&a);//调用指针函数
    void (*funcp)();//声明函数指针
    funcp= point_func;//把一个函数赋值给函数指针
    funcp();//调用函数
    int b=20;

    void(*funCp)(int* a,int *b)=point_func;
    funCp(&a,&b);
    printf("a==%d   b==%d\n",a,b);

    int myArray[10];
    populate_array(myArray,10,getNextValue);
    for(int i=0;i<10;i++){
        printf("%d ",myArray[i]);
    }
    return 0;
}
//C++ 函数从上到下编译
