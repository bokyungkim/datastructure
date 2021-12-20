/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:00:34 by bokim             #+#    #+#             */
/*   Updated: 2021/12/06 20:06:31 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "circularqueue.h"

ArrayQueue*	createArrayQueue(int maxElementCount){
	ArrayQueue *arrayQueue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	if (!arrayQueue)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (FALSE);
	}
	arrayQueue->maxElementCount = maxElementCount;
	arrayQueue->currentElementCount = 0;
	arrayQueue->front = -1;
	arrayQueue->rear = -1;
	arrayQueue->pElement = (ArrayQueueNode *)malloc(maxElementCount * sizeof(ArrayQueueNode));
	return (arrayQueue);
}

void	deleteArrayQueue(ArrayQueue *pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return ;
	}
	free(pQueue);
	pQueue = NULL;
}

int isArrayQueueFull(ArrayQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	return (pQueue->maxElementCount == pQueue->currentElementCount);
}

int isArrayQueueEmpty(ArrayQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	return (pQueue->currentElementCount == 0);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	if (isArrayQueueFull(pQueue)){
		fprintf(stderr, "Queue is full\n");
		return (FALSE);
	}
	pQueue->pElement[(pQueue->rear + 1) % pQueue->maxElementCount] = element;
	pQueue->rear++;
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	if (isArrayQueueEmpty(pQueue)){
		fprintf(stderr, "Queue is empty\n");
		return (FALSE);
	}
	ArrayQueueNode *node = peekAQ(pQueue);
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (node);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return (FALSE);
	}
	if (isArrayQueueEmpty(pQueue)){
		fprintf(stderr, "Queue is empty\n");
		return (FALSE);
	}
	return (&(pQueue->pElement[pQueue->front + 1]));
}

void	displayAQ(ArrayQueue* pQueue){
	if (!pQueue){
		fprintf(stderr, "Queue does not exist\n");
		return ;
	}
	// if (pQueue->front > pQueue->rear) {
	// 	for (int i = pQueue->front + 1; i < pQueue->maxElementCount; i++){
	// 		printf("[%d] %c\n", i, pQueue->pElement[i].data);
	// 	}
	// 	for (int i = 0; i < pQueue->rear + 1; i++){
	// 		printf("[%d] %c\n", i, pQueue->pElement[i].data);
	// 	}
	// }
	// else {
	// 	for (int i = pQueue->front + 1; i < pQueue->rear + 1; i++){
	// 		printf("[%d] %c\n", i, pQueue->pElement[i].data);
	// 	}
	// }
	for (int i = 0; i < pQueue->maxElementCount; i++){
		printf("[%d] %c\n", i, pQueue->pElement[i].data);
	}
	if (isArrayQueueEmpty(pQueue))
		printf("Queue is Empty\n");
	if (isArrayQueueFull(pQueue))
		printf("Queue is Full\n");
	printf("===========\n");
}

int	main(void){
	ArrayQueue* arrayQueue = createArrayQueue(3);
	ArrayQueueNode node1, node2, node3;
	node1.data = 'a';
	node2.data = 'b';
	node3.data = 'c';
	
	enqueueAQ(arrayQueue, node1);
	enqueueAQ(arrayQueue, node2);
	enqueueAQ(arrayQueue, node3);
	displayAQ(arrayQueue);
	dequeueAQ(arrayQueue);
	displayAQ(arrayQueue);
	dequeueAQ(arrayQueue);
	displayAQ(arrayQueue);
	dequeueAQ(arrayQueue);
	displayAQ(arrayQueue);
	enqueueAQ(arrayQueue, node2);
	displayAQ(arrayQueue);
	return (0);
}