/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:44:13 by bokim             #+#    #+#             */
/*   Updated: 2021/12/13 15:31:27 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

void	visit(BinTreeNode *node){
	node->visited = TRUE;
	printf("node %c visited\n", node->data);
}

//전위순회
/*
1. 루트 먼저 방문
2. 왼쪽 subtree 방문
3. 오른쪽 subtree 방문
*/
void	preorderTraversalBinTree(BinTreeNode *node){
	if (node){
		visit(node);
		preorderTraversalBinTree(node->pLeftChild);
		preorderTraversalBinTree(node->pRightChild);
	}
}

//중위순회
/*
1. 왼쪽 subtree 방문
2. 루트방문
3. 오른쪽 subtree 방문
*/
void	inorderTraversalBinTree(BinTreeNode *node){
	if (node){
		inorderTraversalBinTree(node->pLeftChild);
		visit(node);
		inorderTraversalBinTree(node->pRightChild);
	}
}

//후위순회
/*
1. 왼쪽 subtree 방문
2. 오른쪽 subtree 방문
3. 루트방문
*/
void	postorderTraversalBinTree(BinTreeNode *node){
	if (node){
		postorderTraversalBinTree(node->pLeftChild);
		postorderTraversalBinTree(node->pRightChild);
		visit(node);
	}
}