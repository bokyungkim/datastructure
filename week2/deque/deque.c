/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:21:56 by bokim             #+#    #+#             */
/*   Updated: 2021/12/06 18:50:09 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

Deque* createDeque(){
	Deque *deque = (Deque *)malloc(sizeof(Deque));
	if (!deque){
		fprintf(stderr, "Memory allocation error\n");
		return (FALSE);
	}
	deque->currentElementCount = 0;
	deque->pFrontNode = NULL;
	deque->pRearNode = NULL;
	return (deque);
}

int insertFront(Deque* pDeque, DequeNode element){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return (FALSE);
	}
	DequeNode *newNode = (DequeNode *)malloc(sizeof(DequeNode));
	*newNode = element;
	newNode->pLLink = NULL;
	newNode->pRLink = NULL;
	if (pDeque->currentElementCount == 0){
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else {
		pDeque->pFrontNode->pLLink = newNode;
		newNode->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRear(Deque* pDeque, DequeNode element){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return (FALSE);
	}
	DequeNode *newNode = (DequeNode *)malloc(sizeof(DequeNode));
	*newNode = element;
	newNode->pLLink = NULL;
	newNode->pRLink = NULL;
	if (pDeque->currentElementCount == 0){
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else {
		pDeque->pRearNode->pRLink = newNode;
		newNode->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode *deleteFront(Deque* pDeque){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return (FALSE);
	}
	if (isDequeEmpty(pDeque)){
		fprintf(stderr, "Deque is Empty\n");
		return (FALSE);
	}
	DequeNode *node = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	node->pRLink = NULL;
	if (pDeque->currentElementCount == 1){
		pDeque->pRearNode = NULL;
	}
	else {
		pDeque->pFrontNode->pLLink = NULL;
	}
	pDeque->currentElementCount--;
	return (node);
}

DequeNode *deleteRear(Deque* pDeque){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return (FALSE);
	}
	if (isDequeEmpty(pDeque)){
		fprintf(stderr, "Deque is Empty\n");
		return (FALSE);
	}
	DequeNode *node = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	node->pLLink = NULL;
	if (pDeque->currentElementCount == 1){
		pDeque->pFrontNode = NULL;
	}
	else {
		pDeque->pRearNode->pRLink = NULL;
	}
	pDeque->currentElementCount--;
	return (node);
}

DequeNode *peekFront(Deque* pDeque){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return (FALSE);
	}
	if (isDequeEmpty(pDeque)){
		fprintf(stderr, "Deque is Empty\n");
		return (FALSE);
	}
	return (pDeque->pFrontNode);
}
DequeNode *peekRear(Deque* pDeque){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return (FALSE);
	}
	if (isDequeEmpty(pDeque)){
		fprintf(stderr, "Deque is Empty\n");
		return (FALSE);
	}
	return (pDeque->pRearNode);
}

void deleteDeque(Deque* pDeque){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return ;
	}
	DequeNode *node = NULL;
	for (int i = 0 ; i < pDeque->currentElementCount; i++){
		node = deleteFront(pDeque);
		free(node);
		node = NULL;
	}
	pDeque->currentElementCount = 0;
	free(pDeque);
	pDeque = NULL;
}

int isDequeEmpty(Deque* pDeque){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return (FALSE);
	}
	return (pDeque->currentElementCount == 0);
}

void displayDeque(Deque* pDeque){
	if (!pDeque){
		fprintf(stderr, "Deque does not exist\n");
		return ;
	}
	DequeNode *node = pDeque->pFrontNode;
	for (int i = 0; i < pDeque->currentElementCount; i++){
		printf("[%d] %c\n", i, node->data);
		node = node->pRLink;
	}
	if (isDequeEmpty(pDeque))
		printf("Deque is Empty\n");
	printf("===========\n");
}

int	main(void){
	Deque* deque = createDeque();
	DequeNode node1, node2, node3, node4, node5;
	node1.data = 'a';
	node2.data = 'b';
	node3.data = 'c';
	node4.data = 'd';
	node5.data = 'e';
	
	insertFront(deque, node3);
	insertFront(deque, node2);
	insertFront(deque, node1);
	insertRear(deque, node4);
	insertRear(deque, node5);
	displayDeque(deque);
	
	deleteFront(deque);
	displayDeque(deque);
	
	deleteRear(deque);
	displayDeque(deque);

	return (0);
}