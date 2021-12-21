/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:50:27 by bokim             #+#    #+#             */
/*   Updated: 2021/12/03 13:43:20 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "maze.h"
#include "linkedstack.h"

int pushLSMapPosition(LinkedStack *pStack, MapPosition data){
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	else
	{
		MapPosition *newNode = (MapPosition *)malloc(sizeof(MapPosition));
		*newNode = data;
		newNode->pLink = pStack->pTopElement;
		pStack->pTopElement = newNode;
		pStack->currentElementCount++;
	}
	return (TRUE);
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]){
	
}

void printMaze(int mazeArray[HEIGHT][WIDTH]){
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++){
			printf("%d ", mazeArray[i][j]);
		}
		printf("\n");
	}
}

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack){
	mazeArray[endPos.y][endPos.x] = END;
	pushLSMapPosition(pStack, startPos);
	MapPosition location = startPos;
	while (mazeArray[location.y + 1][location.x] != END){
		mazeArray[location.y][location.x] = VISITED;
		//up
		if (mazeArray[location.y + 1][location.x] != WALL && mazeArray[location.y + 1][location.x] != VISITED){
			location.y++;
			location.direction = 'U';
			pushLSMapPosition(pStack, location);
		}
		//down
		else if (mazeArray[location.y - 1][location.x] != WALL && mazeArray[location.y - 1][location.x] != VISITED){
			location.y--;
			location.direction = 'D';
			pushLSMapPosition(pStack, location);
		}
		//left
		else if (mazeArray[location.y][location.x - 1] != WALL && mazeArray[location.y][location.x - 1] != VISITED){
			location.x--;
			location.direction = 'L';
			pushLSMapPosition(pStack, location);
		}
		//right
		else if (mazeArray[location.y][location.x + 1] != WALL && mazeArray[location.y][location.x + 1] != VISITED){
			location.x++;
			location.direction = 'R';
			pushLSMapPosition(pStack, location);
		}
		//실패 시
		else {
			location = *(popLS(pStack));
		}
	}
	printf("목적지 도착\n");
}

int	main(){

}