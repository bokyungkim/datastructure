#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

typedef struct LinkedQueueNodeType
{
	char data;
	struct LinkedQueueNodeType* pLink;
} LinkedQueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// ���� ������ ����
	LinkedQueueNode* pFrontNode;		// Front ����� ������
	LinkedQueueNode* pRearNode;		// Rear ����� ������
} LinkedQueue;

LinkedQueue* createLinkedQueue();
int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element);
LinkedQueueNode *dequeueLQ(LinkedQueue* pQueue);
LinkedQueueNode *peekLQ(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif