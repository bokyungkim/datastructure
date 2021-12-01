/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:50:27 by bokim             #+#    #+#             */
/*   Updated: 2021/12/01 16:31:20 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "maze.h"
#include "../linkedstack/linkedstack.h"

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

}

int	main(){

}