#ifndef CUTE_QUEUE_H
#define CUTE_QUEUE_H
#include "stdint.h"
#include "stdio.h"
#define NULL (0)
#define RET_SUC (1)
#define RET_ERR (0)
#define log printf
#define ASSERT(x) do{if (!(x)){ log("<ERROR> file:%s,line:%d\r\n", __FILE__, __LINE__);while (1){};}} while (0);
typedef struct Queue_T
{
    uint8_t msgMax;  // 消息最大个数
    uint8_t msgNum;  // 消息实际个数
    uint8_t msgSize; // 消息体大小
    uint8_t rp;      // 读指针
    uint8_t wp;      // 写指针
    void *pdata;     // 数据池指针
} Queue;

/**
 * @brief 创建消息队列
 * @param queue 消息队列对象
 * @param msgNum 消息数量
 * @param data 数据指针
 */
void Queue_creat(Queue *queue, uint8_t msgNum, uint8_t msgSize, void *data);
/**
 * @brief 推送消息到消息队列中
 * @param queue 消息队列对象
 * @param msg 待推送的消息
 * @return 推送成功或者失败
 */
uint8_t Queue_push(Queue *queue, void *msg);
/**
 * @brief 从消息队列中取出消息
 * @param queue 消息队列对象
 * @param msg 待取出的消息
 * @return 取出成功或者失败
 */
uint8_t Queue_pull(Queue *queue, void *msg);
#endif