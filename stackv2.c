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
    int yk;
    struct Stack* next;
} Stack;

void push(Stack** st, int x)
{
    Stack* neww = NULL;
    neww = (Stack*)malloc(sizeof(Stack));
    if(!neww)
        exit(-1);
    neww->yk = x;
    neww->next = *st;
    *st = neww;
    return ;
}

int top(struct Stack *st)
{
    if(st != NULL)
        return st->yk;
    else
        return -1;
}

int pop(Stack** st)
{
    Stack* neww;
    if (*st == NULL)
        return -1;
    int verh = top(*st);
    neww = *st;
    *st = (*st)->next;
    free(neww);
    return verh;
}

struct Stack* stack_dtr(Stack* st)
{
    while(pop(&st) != -1);
}

int main()
{
    int i;
    //1 test
    time_t begin = clock();
    Stack *st = NULL;
    int kol = 1000000;
    for(int i = 0; i < kol; ++i)
    {
//        printf("%d", i);
        push(&st, &i);
    }
    while(kol >= 100000)
    {
//        printf("%d", kol);
        for(int i = 0; i < kol / 2; ++i)
            pop(&st);
        for(int i = 0; i < kol / 4; ++i)
            push(&st, &i);
        kol -= kol / 2 + kol / 4;
    }
    time_t end = clock();
    printf("The elapsed time test 1 is %ld ms\n", end - begin);
    stack_dtr(st);
    //2 test
    begin = clock();
    int cc = 0;
    st = NULL;
    kol = 1000000;
    while(cc < 9)
    {
        for(int i = 0; i < kol; ++i)
            push(&st, &i);
        for(int i = 0; i < kol; ++i)
            pop(&st);
        cc++;
    }
    stack_dtr(st);
    end = clock();
    printf("The elapsed time test 2 is %ld ms\n", end - begin);
    //3 test
    begin = clock();
    st = NULL;
    cc = 0;
    for(int i = 0; i < kol; ++i)
        push(&st, &i);
    while(cc < 1000000)
    {

        int flag = rand() % 2 + 1;
        if(flag == 1)
        {
            push(&st, i);
            kol++;
        }
        else
        {
            pop(&st);
            kol--;
        }
        cc++;
        if(kol == 1000000)
        {
            time_t end = clock();
            printf("The elapsed time test 3 is %ld ms\n", end - begin);

        }
    }
    stack_dtr(st);
    return 0;
}
