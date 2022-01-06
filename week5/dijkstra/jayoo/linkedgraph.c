#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedgraph.h"
#include "linkedlist.h"

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	pGraph->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
	if (!pGraph->pVertex || !pGraph->ppAdjEdge){
		free(pGraph->ppAdjEdge);
		free(pGraph->pVertex);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++){
		pGraph->ppAdjEdge[i] = createLinkedList();
		if (!pGraph->ppAdjEdge[i]){
			free(pGraph->ppAdjEdge[i]);
			free(pGraph->ppAdjEdge);
			free(pGraph->pVertex);
			return (NULL);
		}
		pGraph->ppAdjEdge[i]->headerNode.data.vertexID = i;
	}
	pGraph->currentEdgeCount  = 0;
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	return (pGraph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	pGraph = createLinkedGraph(maxVertexCount);
	pGraph->graphType = GRAPH_DIRECTED;
	return (pGraph);
}

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
		return ;
	free(pGraph->pVertex);
	for(int i = 0; i < pGraph->maxVertexCount; i++){
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	}
	free(pGraph->ppAdjEdge);
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (FALSE);
	if (pGraph->currentVertexCount > 0)
		return (TRUE);
	return (FALSE);
}

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FAIL);
	if (vertexID > pGraph->maxVertexCount)
		return (FAIL);
	if (pGraph->pVertex[vertexID] == USED)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED));
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	GraphVertex pVertex;
	ListNode pNode;

	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID))
		return (FAIL);
	if (!checkVertexValid(pGraph, toVertexID))
		return (FAIL);

	pNode.data.vertexID = toVertexID;
	pNode.data.weight = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, pNode);
	pGraph->currentEdgeCount++;
	if (pGraph->graphType == GRAPH_UNDIRECTED){
		pNode.data.vertexID = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, pNode);
		pGraph->currentEdgeCount++;
	}
	return (SUCCESS);
}

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FAIL);
	if (vertexID > pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
		return (FAIL);
	return (SUCCESS);
}

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, vertexID))
		return(FAIL);
	for(int i=0; i < pGraph->maxVertexCount; i++){
		removeEdgeLG(pGraph, vertexID, i);
		removeEdgeLG(pGraph, i, vertexID);
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	return (SUCCESS);
}

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID))
		return (FAIL);
	if (!checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	return (SUCCESS);
}
void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int position;

	if (!pList)
		return ;
	position = findGraphNodePosition(pList, delVertexID);
	if (position >= 0)
		removeLLElement(pList, position);
}
int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode *pNode;
	int position;

	position = 0;
	if (!pList)
		return (FAIL);
	pNode = pList->headerNode.pLink;
	while (pNode)
	{
		if (pNode->data.vertexID == vertexID)
			return (position);
		position++;
		pNode = pNode->pLink;
	}
	return (-1);
}

// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FAIL;
	return (pGraph->currentEdgeCount);
}

// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FAIL;
	return (pGraph->currentVertexCount);
}

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FAIL;
	return (pGraph->maxVertexCount);
}

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FAIL;
	return (pGraph->graphType);
}

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph)
{
	int position;
	ListNode *pNode;

	if (!pGraph)
		return;
	for(int i = 0; i < pGraph->maxVertexCount; i++){
		for(int j = 0; j < pGraph->maxVertexCount; j++){
			position = findGraphNodePosition(pGraph->ppAdjEdge[i], j);
			if (position >= 0){
				pNode = getLLElement(pGraph->ppAdjEdge[i], position);
				printf("%d ",pNode->data.weight);
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}
