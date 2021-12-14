/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxheap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:35:16 by bokim             #+#    #+#             */
/*   Updated: 2021/12/15 00:14:10 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maxheap.h"

MaxHeap* makeMaxHeap(int rootData){
	MaxHeap *newHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
	if (!newHeap)
		return (NULL);
	newHeap->pElement[1].key = rootData;
	newHeap->currentElementCount = 1;
	return (newHeap);
}

HeapNode* insertMaxHeap(MaxHeap* heap, int data){
	if (!heap)
		return (NULL);
	heap->currentElementCount++;
	int i = heap->currentElementCount;
	while ((i != 1) && (data > heap->pElement[i / 2].key)){
		heap->pElement[i] = heap->pElement[i / 2];
		i /= 2;
	}
	heap->pElement[i].key = data;
	return (&heap->pElement[i]);
}

int removeMaxHeap(MaxHeap* heap){
	if (!heap)
		return (-1);
	//루트 노드 삭제
	int result = heap->pElement[1].key;

	//트리 마지막 자리 노드의 임시 이동
	int i = heap->currentElementCount;
	int temp = heap->pElement[i].key;
	heap->currentElementCount--;
	
	//자식 노드와 키 값 비교 및 이동
	int parent = 1;
	int child = 2;
	while (child <= heap->currentElementCount){
		if ((child < heap->currentElementCount)
				&& heap->pElement[child].key < heap->pElement[child + 1].key){
				child++;
		}
		if (temp >= heap->pElement[child].key){
			break;
		}
		heap->pElement[parent] = heap->pElement[child];
		parent = child;
		child *= 2;
	}
	heap->pElement[parent].key = temp;
	return (result);
}

void deleteMaxHeap(MaxHeap* heap){
	free(heap);
	heap = NULL;
}

int main(){
	MaxHeap *heap = makeMaxHeap(20);
	insertMaxHeap(heap, 6);
	insertMaxHeap(heap, 12);
	insertMaxHeap(heap, 2);
	insertMaxHeap(heap, 4);
	// insertMaxHeap(heap, 30);
	insertMaxHeap(heap, 40);
	removeMaxHeap(heap);
	printf("idx	key\n");
	for (int i = 1; i <= heap->currentElementCount; i++){
		printf("[%d]	%d\n", i, heap->pElement[i].key);
	}
	return (0);
}