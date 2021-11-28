/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraystack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:17:09 by bokim             #+#    #+#             */
/*   Updated: 2021/11/28 23:53:30 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "arraystack.h"

ArrayStack*	createArrayStack(int maxElementCount){
	ArrayStack *arrayStack = (ArrayStack*)malloc(sizeof(ArrayStack));
	arrayStack->maxElementCount = maxElementCount;
	arrayStack->currentElementCount = 0;
	arrayStack->pElement = (ArrayStackNode *)malloc(maxElementCount * sizeof(ArrayStackNode));
	return (arrayStack);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element){
	if (!isArrayStackFull(pStack)){
		pStack->pElement[pStack->currentElementCount] = element;
		pStack->currentElementCount++;
		return (TRUE);
	}
	else {
		fprintf(stderr, "Stack is full!\n");
		exit(1);
	}
}

ArrayStackNode* popAS(ArrayStack* pStack){
	if (isArrayStackEmpty(pStack)){
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	else {
		ArrayStackNode *retNode = &(pStack->pElement[pStack->currentElementCount - 1]);
		pStack->currentElementCount--;
		return (retNode);
	}
}

ArrayStackNode* peekAS(ArrayStack* pStack){
	return (&(pStack->pElement[pStack->currentElementCount - 1]));
}

void	deleteArrayStack(ArrayStack *pStack){
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
	pStack = NULL;
}

int isArrayStackFull(ArrayStack* pStack){
	return (pStack->maxElementCount == pStack->currentElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack){
	return (pStack->currentElementCount == 0);
}

int main(void){
	ArrayStack *AS = createArrayStack(5);
	ArrayStackNode *node = malloc(sizeof(ArrayStackNode));
	node->data = 'a';
	pushAS(AS, *node);
	node->data = 'b';
	pushAS(AS, *node);
	node->data = 'c';
	pushAS(AS, *node);
	node->data = 'd';
	pushAS(AS, *node);
	printf("%c\n", popAS(AS)->data);
	printf("%c\n", peekAS(AS)->data);
	free(node);
	return (0);
}