#include <iostream>
#include <string>

using namespace std;
#define MAX_SIZE 100000

int stack[MAX_SIZE + 1];
int top = -1;

int isEmpty()
{
    if (top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top >= MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int x)
{
    if (isFull() == 1)
    {
        printf("Stack is Full.\n");
    }
    else
    {
        stack[++top] = x;
    }
}

int pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack is Empty.\n");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

int sum_stack()
{
    int sum = 0;
    if (isEmpty() == 1)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < top + 1; i++)
        {
            sum += stack[i];
        }
    }
    return sum;
}

int main()
{
    int cnt = 0, i, num;
    scanf("%d", &cnt);

    for (i = 0; i < cnt; i++)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            pop();
        }
        else
        {
            push(num);
        }
    }

    printf("%d\n", sum_stack());

    return 0;
}