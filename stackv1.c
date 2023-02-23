#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long

typedef struct Stack
{
    int *yk;
    size_t size;
    size_t last;
} Stack;

struct Stack* stack_ctr(size_t size, size_t element_size)
{
    Stack* neww = NULL;
    neww = (Stack* )malloc(sizeof(Stack));
    if(neww == NULL)
    {
        exit(-1);
    }
    neww->size = size;
    neww->yk = (int* )malloc(neww->size* element_size);
    if(neww->yk == NULL)
    {
        free(neww);
        exit(-1);
    }
    neww->last = 0;
    return neww;
}

struct Stack* stack_dtr(struct Stack* st)
{
    free(st);
    st = NULL;
    return st;
}

int push(struct Stack* st, void* buffer)
{
    if(st->last == st->size)
        return -1;
    int* cop = (int* )buffer;
    st->yk[st->last] = *cop;
    st->last++;
    return 1;
}

int pop(struct Stack* st)
{
    if(st->last == 0)
    {
        return 0;
    }
    st->last--;
    return 1;
}

int last(struct Stack* st, void* buffer)
{
    if(st->last == 0)
    {
        return 0;
    }
    return st->yk[st->last - 1];
}

int main()
{
    int i;
    //1 test
    Stack *st = stack_ctr(100, sizeof(int));
    int kol = 1000000;
    time_t begin = clock();
    for(int i = 0; i < kol; ++i)
        push(st, &i);
    while(kol >= 100000)
    {
        for(int i = 0; i < kol / 2; ++i)
            pop(st);
        for(int i = 0; i < kol / 4; ++i)
            push(st, &i);
        kol -= kol / 2 + kol / 4;
    }
    time_t end = clock();
    printf("The elapsed time is %ld ms\n", end - begin);
    stack_dtr(st);
    //2 test
    Stack *s1 = stack_ctr(100, sizeof(int));
    kol = 1000000;
    int count = 0;
    while(count < 9)
    {
        for(int i = 0; i < kol; ++i) push(s1, &i);
        for(int i = 0; i < kol; ++i) pop(s1);
        count++;
    }
    stack_dtr(s1);
    //3 test
    Stack *s2 = stack_ctr(100, sizeof(int));
    count = 0;
    begin = clock();
    for(int i = 0; i < kol; ++i)
        push(s1, &i);
    while(count < 1000000)
    {

        int flag = rand() % 2 + 1;
        if(flag == 1)
        {
            push(s2, &i);
            kol++;
        }
        else
        {
            pop(s2);
            kol--;
        }
        count++;
        if(kol == 1000000)
        {
            time_t end = clock();
//            printf("The elapsed time is %ld ms\n", end - begin);

        }
    }
    stack_dtr(s1);
    return 0;
}
