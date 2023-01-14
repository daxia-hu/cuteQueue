#include "cutequeue.h"
/**
 * @brief ������Ϣ����
 * @param queue ��Ϣ���ж���
 * @param msgNum ��Ϣ����
 * @param data ����ָ��
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
 * @brief ������Ϣ����Ϣ������
 * @param queue ��Ϣ���ж���
 * @param msg �����͵���Ϣ
 * @return ���ͳɹ�����ʧ��
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
        if (queue->wp == queue->msgMax) // д���λ������0λ����
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
 * @brief ����Ϣ������ȡ����Ϣ
 * @param queue ��Ϣ���ж���
 * @param msg ��ȡ������Ϣ
 * @return ȡ���ɹ�����ʧ��
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
