#include "cutequeue.h"
uint8_t arrTable[5];

Queue testQueue;

void queue_push_function(uint8_t *num,uint8_t value)
{
    *num = value;
    uint8_t ret;
    ret = Queue_push(&testQueue, num);
    if (RET_ERR == ret)
    {
        printf("<ERROR> %d\r\n", *num);
    }
}

void queue_pull_function(uint8_t *num)
{
    uint8_t ret;
    ret = Queue_pull(&testQueue, num);
    if (RET_ERR == ret)
    {
        printf("<ERROR> PULL\r\n");
    }
    else
    {
        printf("PULL %d\r\n", *num);
    }
}


int main()
{
    uint8_t pushMsg;
    uint8_t pullMsg;
    uint8_t ret;
    Queue_creat(&testQueue, 5, sizeof(uint8_t), arrTable);
    queue_push_function(&pushMsg,1);
    queue_push_function(&pushMsg,2);
    queue_pull_function(&pullMsg);
    queue_push_function(&pushMsg,3);
    queue_push_function(&pushMsg,4);
    queue_pull_function(&pullMsg);
    queue_push_function(&pushMsg,5);
    queue_push_function(&pushMsg,6);
    queue_push_function(&pushMsg,7);
    queue_pull_function(&pullMsg);
    queue_pull_function(&pullMsg);
    queue_pull_function(&pullMsg);
    queue_pull_function(&pullMsg);
    queue_pull_function(&pullMsg);
    queue_pull_function(&pullMsg);
    queue_push_function(&pushMsg,8);
    queue_push_function(&pushMsg,9);
    queue_pull_function(&pullMsg);
    queue_pull_function(&pullMsg);
}