/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:08:34 by bokim             #+#    #+#             */
/*   Updated: 2021/12/13 20:52:07 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode){
	BinTree *tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree){
		fprintf(stderr, "Memory allocation error\n");
		return (FALSE);
	}
	BinTreeNode *new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	tree->pRootNode = new;
	new->data = rootNode.data;
	new->pLeftChild = NULL;
	new->pRightChild = NULL;
	new->visited = FALSE;
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
	// pParentNode->pLeftChild = &element;
	if (pParentNode->pLeftChild){
		return (NULL);
	}
	BinTreeNode *new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	pParentNode->pLeftChild = new;
	new->data = element.data;
	new->pLeftChild = NULL;
	new->pRightChild = NULL;
	new->visited = FALSE;
	return (new);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
	if (pParentNode->pRightChild){
		return (NULL);
	}
	BinTreeNode *new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	pParentNode->pRightChild = new;
	new->data = element.data;
	new->pLeftChild = NULL;
	new->pRightChild = NULL;
	new->visited = FALSE;
	// pParentNode->pRightChild = &element;
	return (new);
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
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
		pNode = NULL;
	}
}

int	main(void){
    BinTree *pBinTree;
    BinTreeNode new;
    new.data = 'A';
    pBinTree = makeBinTree(new);
    new.data = 'B';
    insertLeftChildNodeBT(pBinTree->pRootNode, new);
    new.data = 'C';
    insertRightChildNodeBT(pBinTree->pRootNode, new);
    new.data = 'D';
    insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild, new);
    new.data = 'E';
    insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild, new);
    new.data = 'F';
    insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild, new);
    new.data = 'G';
    insertRightChildNodeBT(pBinTree->pRootNode->pRightChild, new);
    new.data = 'H';
    insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, new);
    new.data = 'I';
    insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, new);
    new.data = 'J';
    insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pRightChild, new);
    new.data = 'K';
    insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pLeftChild, new);
    new.data = 'L';
    insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, new);
    new.data = 'M';
    insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, new);
    printf("PREORDER\n");
    preorderTraversalBinTree(pBinTree->pRootNode);
    printf("\n");
    printf("INORDER\n");
    inorderTraversalBinTree(pBinTree->pRootNode);
    printf("\n");
    printf("POSTORDER\n");
    postorderTraversalBinTree(pBinTree->pRootNode);
    deleteBinTree(pBinTree);
    return (0);
}