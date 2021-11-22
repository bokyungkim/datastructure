/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:04:16 by bokim             #+#    #+#             */
/*   Updated: 2021/11/22 21:17:51 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList(){
	LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	linkedList->currentElementCount = 0;
	linkedList->headerNode.pLink = NULL;
	return (linkedList);
}

int addLLElement(LinkedList* pList, int position, ListNode element){
	ListNode *preNode = NULL;
	ListNode *newNode = NULL;
	if (position >= 0 && position <= pList->currentElementCount){
		newNode = (ListNode*)malloc(sizeof(ListNode));
		*newNode = element;
		newNode->pLink = NULL;
		*preNode = pList->headerNode;
		for (int i = 0; i < position; i++)
		{
			preNode = preNode->pLink;
		}
		newNode->pLink = preNode->pLink;
		preNode->pLink = newNode;
	}
	else {
		fprintf(stderr, "Invalid access\n");
		exit(1);
	}
	pList->currentElementCount++;
}

int removeLLElement(LinkedList* pList, int position){
	
}

ListNode* getLLElement(LinkedList* pList, int position){
	ListNode *preNode = NULL;
	if (position >= 0 && position <= pList->currentElementCount){
		*preNode = pList->headerNode;
		for (int i = 0; i < position; i++){
			preNode = preNode->pLink;
		}
		return (preNode);
	}
}

void clearLinkedList(LinkedList* pList){
	
}

int getLinkedListLength(LinkedList* pList){
	
}

void deleteLinkedList(LinkedList* pList){
	
}

void displayLinkedList(LinkedList* pList){
		int i = 0;

	if (pList != NULL) {

		printf("현재 원소 개수 : %d\n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {

			printf("[%d], %d\n", i, getLLElement(pList, i)->data);

		}

	}

	else {

		printf("원소가 없습니다.\n");

	}



}

int	main(){
	int i = 0;

	int arrayCount = 0;

	LinkedList * pList = NULL;

	ListNode * pNode = NULL;

	ListNode node;

	pList = createLinkedList();

	if (pList != NULL) {

		node.data = 1;

		addLLElement(pList, 0, node);

		node.data = 3;

		addLLElement(pList, 1, node);

		node.data = 5;

		addLLElement(pList, 2, node);

		displayLinkedList(pList);

		// removeLLElement(pList, 0);

		// displayLinkedList(pList);

		// deleteLinkedList(pList);

	}

	return 0;


	// LinkedList *pList = createLinkedList();
	// ListNode *element1 = malloc(sizeof(ListNode));
	// element1->data = 3;
	// element1->pLink = NULL;
	// addLLElement(pList, 0, *element1);
	// displayLinkedList(pList);
}