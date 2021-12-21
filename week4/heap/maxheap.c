/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxheap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:35:16 by bokim             #+#    #+#             */
/*   Updated: 2021/12/17 14:22:39 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maxheap.h"

/*
heap은 우선순위 큐를 위해 만들어짐
최대값 또는 최소값을 빠르게 찾기 위해서 고안된 트리 모양의 자료구조
max heap은 가장 큰 값을 빠르게 찾기 위함, min heap은 가장 작은 값을 빠르게 찾기 위함
heap은 완전이진트리여야 하고, (완전이진트리: 마지막 레벨을 제외하고 모든 레벨이 완전히 채워져 있으며,
마지막 레벨의 모드 노드는 가장 왼쪽에 있는 트리)
그 중에서도 max heap은 부모 노드의 값이 자식 노드의 값보다 큼
heap의 활용 예시:
- 시뮬레이션 시스템, 네트워크 트래픽 제어, 운영체제에서의 작업 스케쥴링, 수치 해석적인 계산
*/

MaxHeap* makeMaxHeap(int rootData){
	MaxHeap *newHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
	if (!newHeap)
		return (NULL);
	newHeap->pElement[1].key = rootData;
	newHeap->currentElementCount = 1;
	return (newHeap);
}

/* 삽입 함수
1. 완전이진트리의 가장 마지막 원소에 원하는 값 삽입
2. 부모가 더 작다면 부모와 자식의 값 교환
3. 2번에서 부모가 없거나, 부모가 자식보다 클 경우에 끝
트리의 높이만큼 비교를 해야한다.
트리의 높이는 완전이진트리이기 때문에 logN
그러므로 삽입 함수의 시간 복잡도는 O(logN)
*/
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

/* 삭제 함수
1. root 노드를 heap의 가장 마지막 노드와 교환
2. 교환된 가장 마지막 노드 삭제
3. 새로운 root 노드의 알맞은 위치를 찾아서 내려간다.
삭제를 한 후에 자신의 자식들을 비교하면서 자리를 찾아가기 때문에
이 또한 시간복잡도 O(logN)
*/
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
		//왼쪽 자식 노드와 오른쪽 자식 노드 중 더 큰 자식 노드
		if ((child < heap->currentElementCount)
				&& heap->pElement[child].key < heap->pElement[child + 1].key){
				child++;
		}
		//마지막 노드가 자식 노드보다 크면 종료
		if (temp >= heap->pElement[child].key){
			break;
		}
		//부모 노드와 자식 노드 교환
		heap->pElement[parent] = heap->pElement[child];
		//한 레벨 아래로 이동
		parent = child;
		child *= 2;
	}
	//마지막 노드를 재설정한 위치에 삽입
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