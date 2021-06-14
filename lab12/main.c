#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

struct zap
{
    int key;
    int info;
    struct zap* NEXT;
} data[N];

void setup(void)
{
    for (int i = 0; i < N; i++)
    {
        data[i].info = (-1);
        data[i].NEXT = NULL;
    }
}

void slFiling(struct zap* i, struct zap* start)
{
    struct zap* old;
    old = start;
    while (start)
    {
        old = start;
        start = start->NEXT;
    }
    old->NEXT = i;
    i->NEXT = NULL;
}

void filing(int i)
{
    int v = rand() % 10000;
    int h = v % N;
    int loc = v % 100 + v % 1000;
    struct zap* p;

    if (data[h].info == -1 || data[h].info == loc)
    {
        data[h].info = loc;
        data[h].key = v;
    }
    else
    {
        p = (struct zap*)malloc(sizeof(struct zap));
        if (!p)
        {
            printf("error with memory\n");
            return;
        }
        p->info = loc;
        p->key = v;
        slFiling(p, &data[h]);
    }
}

void findDelete(int i)
{
    int h = data[i].key % N;
    int loc = data[i].key % 100 + data[i].key % 1000;
    struct zap* p;

    if (data[h].key % 2 == 0)
    {
        data[h].key = -2;
    }
    p = data[h].NEXT;
    while (p)
    {
        if (p->key % 2 == 0)
        {
            p->key = -2;
        }
        p = p->NEXT;
    }
}

void printTab(void)
{
    struct zap *p;

    for (int i = 0; i < N; i++)
    {
        printf("%d with collisions: ", data[i].key);
        p = data[i].NEXT;
        while (p)
        {
            printf("- [%d] -", p->key);
            p = p->NEXT;
        }
        printf("\n");
    }
}

int main(void)
{
    setup();

    for (int i = 0; i < N; i++)
    {
        filing(i);
    }

    for (int i = 0; i < N; i++)
    {
        findDelete(i);
    }

    printTab();

    return 0;
}