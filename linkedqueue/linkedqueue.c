/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:25:21 by bokim             #+#    #+#             */
/*   Updated: 2021/12/06 18:27:03 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedqueue.h"
#include <stdio.h>
#include <stdlib.h>

LinkedQueue* createLinkedQueue(){
	LinkedQueue *linkedQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (!linkedQueue){
		fprintf(stderr, "Memory allocation error\n");
		return (FALSE);
	}
	linkedQueue->currentElementCount = 0;
	linkedQueue->pFrontNode = NULL;
	linkedQueue->pRearNode = NULL;
	return (linkedQueue);
}

int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	LinkedQueueNode *newNode = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
	*newNode = element;
	newNode->pLink = NULL;
	if (pQueue->currentElementCount == 0){
		pQueue->pFrontNode = newNode;
		pQueue->pRearNode = newNode;
	}
	else {
		pQueue->pRearNode->pLink = newNode;
		pQueue->pRearNode = newNode;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

LinkedQueueNode *dequeueLQ(LinkedQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	if (isLinkedQueueEmpty(pQueue)){
		fprintf(stderr, "Queue is Empty\n");
		return (FALSE);
	}
	LinkedQueueNode *node = pQueue->pFrontNode;
	if (pQueue->currentElementCount == 1){
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	else {
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		node->pLink = NULL;
	}
	pQueue->currentElementCount--;
	return (node);
}

LinkedQueueNode *peekLQ(LinkedQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	if (isLinkedQueueEmpty(pQueue)){
		fprintf(stderr, "Queue is Empty\n");
		return (FALSE);
	}
	return (pQueue->pFrontNode);
}

void deleteLinkedQueue(LinkedQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	LinkedQueueNode *node = NULL;
	for (int i = 0; i < pQueue->currentElementCount; i++){
		node = dequeueLQ(pQueue);
		free(node);
		node = NULL;
	}
	pQueue->currentElementCount = 0;
	free(pQueue);
	pQueue = NULL;
}

int isLinkedQueueEmpty(LinkedQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	return (pQueue->currentElementCount == 0);
}