#include "cutequeue.h"
/**
 * @brief 创建消息队列
 * @param queue 消息队列对象
 * @param msgNum 消息数量
 * @param data 数据指针
 */
void Queue_creat(Queue *queue, uint8_t msgNum, uint8_t msgSize, void *data)
{
    ASSERT(NULL != queue);
    ASSERT(0 != msgNum);
    ASSERT(0 != msgSize);
    ASSERT(NULL != data);
    queue->msgMax = msgNum;
    queue->msgNum = 0;
    queue->msgSize = msgSize;
    queue->pdata = data;
    queue->rp = 0;
    queue->wp = 0;
}
/**
 * @brief 推送消息到消息队列中
 * @param queue 消息队列对象
 * @param msg 待推送的消息
 * @return 推送成功或者失败
 */
uint8_t Queue_push(Queue *queue, void *msg)
{
    ASSERT(NULL != queue);
    ASSERT(NULL != msg);
    uint8_t *pData = queue->pdata;
    uint8_t *pMsg = msg;
    if (queue->msgNum == queue->msgMax)
    {
        return RET_ERR;
    }
    else
    {
        if (queue->wp == queue->msgMax) // 写入的位置落在0位置上
        {
            queue->wp = 0;
        }
        memcpy(pData + ((queue->wp) * (queue->msgSize)), pMsg, queue->msgSize);
        queue->wp += 1;
        queue->msgNum += 1;
        return RET_SUC;
    }
}
/**
 * @brief 从消息队列中取出消息
 * @param queue 消息队列对象
 * @param msg 待取出的消息
 * @return 取出成功或者失败
 */
uint8_t Queue_pull(Queue *queue, void *msg)
{
    ASSERT(NULL != queue);
    ASSERT(NULL != msg);
    uint8_t *pMsg = msg;
    uint8_t *pdata = queue->pdata;
    if (0 == queue->msgNum)
    {
        return RET_ERR;
    }
    else
    {
        if (queue->rp == queue->msgMax)
        {
            queue->rp = 0;
        }
        memcpy(pMsg, pdata + ((queue->msgSize) * (queue->rp)), queue->msgSize);
        queue->rp += 1;
        queue->msgNum -= 1;
        return RET_SUC;
    }
}
