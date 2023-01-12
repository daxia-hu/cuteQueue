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
    uint8_t msgMax;  // ��Ϣ������
    uint8_t msgNum;  // ��Ϣʵ�ʸ���
    uint8_t msgSize; // ��Ϣ���С
    uint8_t rp;      // ��ָ��
    uint8_t wp;      // дָ��
    void *pdata;     // ���ݳ�ָ��
} Queue;

/**
 * @brief ������Ϣ����
 * @param queue ��Ϣ���ж���
 * @param msgNum ��Ϣ����
 * @param data ����ָ��
 */
void Queue_creat(Queue *queue, uint8_t msgNum, uint8_t msgSize, void *data);
/**
 * @brief ������Ϣ����Ϣ������
 * @param queue ��Ϣ���ж���
 * @param msg �����͵���Ϣ
 * @return ���ͳɹ�����ʧ��
 */
uint8_t Queue_push(Queue *queue, void *msg);
/**
 * @brief ����Ϣ������ȡ����Ϣ
 * @param queue ��Ϣ���ж���
 * @param msg ��ȡ������Ϣ
 * @return ȡ���ɹ�����ʧ��
 */
uint8_t Queue_pull(Queue *queue, void *msg);
#endif