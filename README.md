# CProject
C&amp;C++基础复习

### 函数
函数指针：函数指针是指向函数的**指针变量**
虽然说是个变量，但是可以用函数指针调用函数和传递参数

指针函数的声明方式
返回值类型(*变量名)(参数类型,...)
```c
typedef int (*fun_ptr)(int,int); //声明一个指向同样参数(int,int),返回值的为int的函数指针类型
```
回调函数：函数指针作为某个函数的参数
```c
void populate_array(int* array,size_t arraySize,int(*getNextValue)(void )){
    for(size_t i=0; i<arraySize;i++){
        array[i]=getNextValue();
    }
}
// 获取随机值
int getNextValue(void){
    return rand();
}

int main() {
    int myArray[10];
    /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(myArray,10,getNextValue);
    for(int i=0;i<10;i++){
        printf("%d ",myArray[i]);
    }
    return 0;
}
```