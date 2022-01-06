#include <stdio.h>
#include <stdlib.h>
#include "linkedgraph.h"

int main()
{
	LinkedGraph *pGraph1;
	LinkedGraph *pGraph2;
	LinkedGraph *pGraph3;

	pGraph1 = createLinkedGraph(6);
	pGraph2 = createLinkedDirectedGraph(6);
	pGraph3 = createLinkedDirectedGraph(6);

	for(int i = 0; i < 6; i++){
		addVertexLG(pGraph1, i);
		addVertexLG(pGraph2, i);
		addVertexLG(pGraph3, i);
	}

	addEdgeLG(pGraph1, 0, 1);
	addEdgeLG(pGraph1, 2, 1);
	addEdgeLG(pGraph1, 2, 3);
	addEdgeLG(pGraph1, 4, 3);
	addEdgeLG(pGraph1, 4, 5);
	addEdgeLG(pGraph1, 5, 3);
	addEdgeLG(pGraph1, 2, 0);

	addEdgewithWeightLG(pGraph2, 0, 1, 1);
	addEdgewithWeightLG(pGraph2, 1, 2, 1);
	addEdgewithWeightLG(pGraph2, 2, 1, 1);
	addEdgewithWeightLG(pGraph2, 2, 0, 1);
	addEdgewithWeightLG(pGraph2, 2, 3, 1);
	addEdgewithWeightLG(pGraph2, 3, 2, 1);
	addEdgewithWeightLG(pGraph2, 3, 4, 1);
	addEdgewithWeightLG(pGraph2, 5, 3, 1);
	addEdgewithWeightLG(pGraph2, 4, 5, 1);

	addEdgewithWeightLG(pGraph3, 0, 1, 4);
	addEdgewithWeightLG(pGraph3, 1, 2, 1);
	addEdgewithWeightLG(pGraph3, 2, 1, 3);
	addEdgewithWeightLG(pGraph3, 2, 0, 2);
	addEdgewithWeightLG(pGraph3, 2, 3, 2);
	addEdgewithWeightLG(pGraph3, 3, 2, 1);
	addEdgewithWeightLG(pGraph3, 3, 4, 1);
	addEdgewithWeightLG(pGraph3, 5, 3, 2);
	addEdgewithWeightLG(pGraph3, 4, 5, 1);

	printf("G1: 무방향 그래프\n");
	displayLinkedGraph(pGraph1);
	printf("\nG2: 방향 그래프 \n");
	displayLinkedGraph(pGraph2);
	printf("\nG3: 방향 가중 그래프\n");
	displayLinkedGraph(pGraph3);
}
