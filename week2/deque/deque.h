#ifndef _DEQUE_
#define _DEQUE_

typedef struct DequeNodeType
{
	char data;
	struct DequeNodeType* pLLink;
	struct DequeNodeType* pRLink;
} DequeNode;

typedef struct DequeType
{
	int currentElementCount;	// ���� ������ ����
	DequeNode* pFrontNode;		// Front ����� ������
	DequeNode* pRearNode;		// Rear ����� ������
} Deque;

Deque* createDeque();
int insertFront(Deque* pDeque, DequeNode element);
int insertRear(Deque* pDeque, DequeNode element);
DequeNode *deleteFront(Deque* pDeque);
DequeNode *deleteRear(Deque* pDeque);
DequeNode *peekFront(Deque* pDeque);
DequeNode *peekRear(Deque* pDeque);
void deleteDeque(Deque* pDeque);
int isDequeEmpty(Deque* pDeque);

#endif

#ifndef _COMMON_DEQUE_DEF_
#define _COMMON_DEQUE_DEF_

#define TRUE		1
#define FALSE		0

#endif