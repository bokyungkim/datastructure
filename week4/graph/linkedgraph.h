/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedgraph.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:43:25 by bokim             #+#    #+#             */
/*   Updated: 2021/12/21 18:13:33 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GRAPH_LIST_
#define _GRAPH_LIST_

#define MAX_VERTICES 50

typedef struct LinkedNodeType
{
	int vertexID;
	int weight;
	LinkedNode *pLink;
} LinkedNode;

typedef struct LinkedGraphType
{
	int currentVertexCount;				// 현재 사용되는 노드의 개수
	int graphType;						// 그래프 종류: 1-Undirected, 2-Directed
	LinkedNode *ppVertex[MAX_VERTICES];	// 정점들에 대한 헤드노드
} LinkedGraph;

// 그래프 생성
LinkedGraph* createLinkedGraph();
LinkedGraph* createLinkedDirectedGraph();

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph);

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph);

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, LinkedNode vertex);

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유효성 점검
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, LinkedNode* vertex);

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, LinkedNode* fromVertex, LinkedNode* toVertex);

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
