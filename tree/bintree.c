/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:08:34 by bokim             #+#    #+#             */
/*   Updated: 2021/12/13 15:35:11 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode){
	BinTree *tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree){
		fprintf(stderr, "Memory allocation error\n");
		return (FALSE);
	}
	tree->pRootNode = &rootNode;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree){
	if (!pBinTree){
		fprintf(stderr, "Tree does not exist\n");
		return (FALSE);
	}
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
	pParentNode->pLeftChild = &element;
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
	pParentNode->pRightChild = &element;
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode){
	return (pNode->pLeftChild);	
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode){
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree){
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
	pBinTree = NULL;
}

// 올바른 접근 위해 후위순회 이용
void deleteBinTreeNode(BinTreeNode* pNode){
	if (pNode){
		preorderTraversalBinTree(pNode->pLeftChild);
		preorderTraversalBinTree(pNode->pRightChild);
		free(pNode);
		pNode = NULL;
	}	
}

int	main(void){
	BinTreeNode *root = malloc(sizeof(BinTreeNode));
	root->data = 'R';
	BinTreeNode *node1 = malloc(sizeof(BinTreeNode));
	node1->data = '1';
	BinTreeNode *node2 = malloc(sizeof(BinTreeNode));
	node2->data = '2';
	BinTreeNode *node3 = malloc(sizeof(BinTreeNode));
	node3->data = '3';
	BinTreeNode *node4 = malloc(sizeof(BinTreeNode));
	node4->data = '4';
	BinTreeNode *node5 = malloc(sizeof(BinTreeNode));
	node5->data = '5';
	BinTree *tree = makeBinTree(*root);
	insertLeftChildNodeBT(root, *node1);
	insertRightChildNodeBT(root, *node2);
	insertLeftChildNodeBT(node1, *node3);
	insertRightChildNodeBT(node1, *node4);
	insertLeftChildNodeBT(node2, *node5);
	printf("node1's leftChild = %c\n", node1->pLeftChild->data);
	printf("node1's rightChild = %c\n", node1->pRightChild->data);
	printf("node2's leftChild = %c\n", node2->pLeftChild->data);
	// printf("===Preorder===\n");
	// preorderTraversalBinTree(root);
	// printf("===Inorder===\n");
	// inorderTraversalBinTree(root);
	printf("===Postorder===\n");
	postorderTraversalBinTree(root);
	return (0);
}