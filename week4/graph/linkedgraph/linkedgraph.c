/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedgraph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:43:28 by bokim             #+#    #+#             */
/*   Updated: 2021/12/22 14:49:19 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount){
	LinkedGraph *graph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));
	graph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList *));
	graph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	graph->graphType = GRAPH_UNDIRECTED;
	graph->maxVertexCount = maxVertexCount;
	return (graph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount){
	LinkedGraph *graph = createLinkedGraph(maxVertexCount);
	graph->graphType = GRAPH_DIRECTED;
	return (graph);
}

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph){
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		removeVertexLG(pGraph, i);
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = NULL;
	free(pGraph->pVertex);
	pGraph->pVertex = NULL;
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph){
	if (!pGraph)
		return (FAIL);
	return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID){
	if (!pGraph->pVertex[vertexID]){
		pGraph->pVertex[vertexID] = 1;
		pGraph->currentVertexCount++;
		return (SUCCESS);
	}
	return (FAIL);
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
	ListNode tmp;
	
	if (!pGraph || fromVertexID < 0 || toVertexID < 0
			|| fromVertexID >= pGraph->maxVertexCount || toVertexID >= pGraph->maxVertexCount
				|| !pGraph->pVertex[fromVertexID] || !pGraph->pVertex[toVertexID])
		return (FAIL);
	if (pGraph->graphType == 1 && findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID) == -1){
		if (!pGraph->ppAdjEdge[toVertexID])
			pGraph->ppAdjEdge[toVertexID] = (LinkedList *)calloc(1, sizeof(LinkedList));
			tmp.id = fromVertexID;
			tmp.data = fromVertexID;
			addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, tmp);
	}
	if (findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID) != -1)
		return (FAIL);
	if (!pGraph->ppAdjEdge[fromVertexID])
		pGraph->ppAdjEdge[fromVertexID] = (LinkedList *)calloc(1, sizeof(LinkedList));
	tmp.id = toVertexID;
	tmp.data = toVertexID;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, tmp);
	pGraph->currentEdgeCount++;
	return (SUCCESS);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight){
	ListNode tmp;
	
	if (!pGraph || fromVertexID < 0 || toVertexID < 0
			|| fromVertexID >= pGraph->maxVertexCount || toVertexID >= pGraph->maxVertexCount
				|| !pGraph->pVertex[fromVertexID] || !pGraph->pVertex[toVertexID])
		return (FAIL);
	if (pGraph->graphType == 1 && findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID) == -1){
		if (!pGraph->ppAdjEdge[toVertexID])
			pGraph->ppAdjEdge[toVertexID] = (LinkedList *)calloc(1, sizeof(LinkedList));
			tmp.id = fromVertexID;
			tmp.data = weight;
			addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, tmp);
	}
	if (findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID) != -1)
		return (FAIL);
	if (!pGraph->ppAdjEdge[fromVertexID])
		pGraph->ppAdjEdge[fromVertexID] = (LinkedList *)calloc(1, sizeof(LinkedList));
	tmp.id = toVertexID;
	tmp.data = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, tmp);
	pGraph->currentEdgeCount++;
	return (SUCCESS);
	
}

// 노드의 유효성 점검 : 존재하면 TRUE, 없으면 FALSE
int checkVertexValid(LinkedGraph* pGraph, int vertexID){
	if (pGraph->ppAdjEdge[vertexID])
		return (TRUE);
	return (FALSE);
}

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID){
	int result;

	result = FAIL;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	if (findGraphNodePosition(pGraph->ppAdjEdge[vertexID], i) != -1)
		result |= removeEdgeLG(pGraph, vertexID, i);
	free(pGraph->ppAdjEdge[vertexID]);
	pGraph->ppAdjEdge[vertexID] = NULL;
	pGraph->pVertex[vertexID] = 0;
	return (result);
}

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
	int idx;

	if (!checkVertexValid(pGraph, fromVertexID)
		|| (pGraph->graphType == GRAPH_UNDIRECTED && !checkVertexValid(pGraph, toVertexID)))
		return (FAIL);
	if ((idx = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID)) != -1)
		removeLLElement(pGraph->ppAdjEdge[fromVertexID], idx);
	idx = findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	if (idx != -1 && pGraph->graphType == GRAPH_UNDIRECTED)
		removeLLElement(pGraph->ppAdjEdge[toVertexID], idx);
	pGraph->currentEdgeCount--;
	return (SUCCESS);
}

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph){
	ListNode *tmp;

	if (!pGraph->ppAdjEdge)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++){
		printf("Vertex %d : ", i);
		if (pGraph->ppAdjEdge[i]){
			tmp = pGraph->ppAdjEdge[i]->headerNode.pLink;
			for (int j = 0; j < pGraph->ppAdjEdge[i]->currentElementCount; j++){
				printf("%d ", tmp->data);
				tmp = tmp->pLink;
			}
		}
		printf("\n");
	}
}

int findGraphNodePosition(LinkedList *pList, int vertexID){
	ListNode *tmp;
	int idx = -1;
	
	if (!pList)
		return (-1);
	tmp = pList->headerNode.pLink;
	while (tmp){
		idx++;
		if (tmp->id == vertexID)
			return (idx);
		tmp = tmp->pLink;
	}
	return (-1);
}