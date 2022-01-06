/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:04:16 by bokim             #+#    #+#             */
/*   Updated: 2021/12/22 22:10:08 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *createLinkedList()
{
	LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));
	if (!linkedList)
		return (NULL);
	linkedList->currentElementCount = 0;
	linkedList->headerNode.pLink = NULL;
	return (linkedList);
}

int addLLElement(LinkedList *pList, int position, ListNode element)
{
	if (!pList)
		return (FALSE);
	if (position >= 0 && position <= pList->currentElementCount)
	{
		ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
		*newNode = element;
		newNode->pLink = NULL;
		ListNode *preNode = &(pList->headerNode);
		for (int i = 0; i < position; i++)
		{
			preNode = preNode->pLink;
		}
		newNode->pLink = preNode->pLink;
		preNode->pLink = newNode;
		pList->currentElementCount++;
	}
	else
		return (FALSE);
	return (TRUE);
}

int removeLLElement(LinkedList *pList, int position)
{
	if (!pList)
		return (FALSE);
	if (position >= 0 && position <= pList->currentElementCount)
	{
		ListNode *preNode = 0;
		if (position == 0)
			preNode = &(pList->headerNode);
		else
			preNode = getLLElement(pList, position - 1);
		ListNode *node = getLLElement(pList, position);
		preNode->pLink = node->pLink;
		free(node);
		pList->currentElementCount--;
	}
	else
		return (FALSE);
	return (TRUE);
}

ListNode *getLLElement(LinkedList *pList, int position)
{
	if (!pList)
		return (FALSE);
	if (position >= 0 && position <= pList->currentElementCount)
	{
		ListNode *preNode = &(pList->headerNode);
		for (int i = 0; i < position; i++)
		{
			preNode = preNode->pLink;
		}
		return (preNode->pLink);
	}
	else
		return (FALSE);
}

void clearLinkedList(LinkedList *pList)
{
	if (!pList)
		return ;
	ListNode *preNode = &(pList->headerNode);
	while (pList->currentElementCount > 0)
	{
		removeLLElement(pList, pList->currentElementCount - 1);
	}
	pList->headerNode.pLink = 0;
}

int getLinkedListLength(LinkedList *pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList *pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}

void displayLinkedList(LinkedList *pList)
{
	int i = 0;

	if (pList->currentElementCount > 0)
	{
		for (i = 0; i < pList->currentElementCount; i++)
		{
			printf("[%d] : %d\n", i, getLLElement(pList, i)->data);
		}
		printf("--------\n");
	}
	else
	{
		printf("No elements\n");
	}
}