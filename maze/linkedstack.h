#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct
{
	int	x;
	int	y;
	char direction;
	struct MapPosition* pLink;
} MapPosition;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	MapPosition* pTopElement;		// Top ����� ������
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, MapPosition element);
MapPosition* popLS(LinkedStack* pStack);
MapPosition* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif