#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAX_LEVEL 1000

//声明队列节点结构
struct QueueNode
{
    struct TreeNode *pTreeNode;  //队列元素：二叉树节点指针
    struct TreeNodeQueue *pNext; //队列元素：下一个节点指针
};

//声明队列结构
struct TreeNodeQueue
{
    int iNum;                //队列元素个数
    struct QueueNode *pHead; //队列头指针
    struct QueueNode *pTail; //队列尾指针
};

//函数一：向队列中增加元素
bool Push_Queue(struct TreeNodeQueue *pQueue, struct TreeNode *pTreeNode)
{
    struct QueueNode *pQueueNode = NULL;

    if (NULL == pQueue)
        return false;

    pQueueNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    pQueueNode->pTreeNode = pTreeNode;
    pQueueNode->pNext = NULL;

    if (0 == pQueue->iNum)
    {
        pQueue->pHead = pQueueNode;
        pQueue->pTail = pQueueNode;
        pQueue->iNum += 1;
    }
    else
    {
        pQueue->pTail->pNext = pQueueNode;
        pQueue->pTail = pQueueNode;
        pQueue->iNum += 1;
    }

    return true;
}

//函数二：从队列中取出元素
struct TreeNode *Pop_Queue(struct TreeNodeQueue *pQueue)
{
    struct TreeNode *pRet = NULL;
    struct QueueNode *pTmp = NULL;

    if ((NULL == pQueue) || (0 == pQueue->iNum))
        return NULL;

    pRet = pQueue->pHead->pTreeNode;

    pQueue->iNum -= 1;
    if (0 == pQueue->iNum)
    {
        free(pQueue->pHead);
        pQueue->pHead = NULL;
        pQueue->pTail = NULL;
    }
    else
    {
        pTmp = pQueue->pHead->pNext;
        free(pQueue->pHead);
        pQueue->pHead = pTmp;
    }

    return pRet;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int iNum = 0;
    int iRetSize = 0;
    int **pRet = NULL;
    int *pRetCol = NULL;
    struct TreeNodeQueue strQueue;
    struct TreeNode *pTmpNode = NULL;

    //1,申请空间,并初始化
    pRet = (int **)malloc(sizeof(int *) * MAX_LEVEL);
    memset(pRet, 0x00, sizeof(int *) * MAX_LEVEL);
    pRetCol = (int *)malloc(sizeof(int) * MAX_LEVEL);
    memset(pRetCol, 0x00, sizeof(int) * MAX_LEVEL);
    memset(&strQueue, 0x00, sizeof(struct TreeNodeQueue));

    //2,特殊处理
    if (NULL == root)
    {
        *returnSize = iRetSize;
        *returnColumnSizes = pRetCol;
        return pRet;
    }

    //3,将二叉树根节点加入队列,并且加入空节点作为每层的区分节点
    Push_Queue(&strQueue, root);
    pRet[MAX_LEVEL - iRetSize - 1] = (int *)malloc(sizeof(int) * strQueue.iNum);
    Push_Queue(&strQueue, NULL);

    //4,处理队列中的二叉树节点，直到队列为空
    while (strQueue.iNum != 0)
    {
        pTmpNode = Pop_Queue(&strQueue);
        if (NULL == pTmpNode)
        {
            if (0 != strQueue.iNum)
            {
                //6,当前层处理完，进入下一层
                iRetSize += 1;
                pRet[MAX_LEVEL - iRetSize - 1] = (int *)malloc(sizeof(int) * strQueue.iNum);

                Push_Queue(&strQueue, NULL);
            }
        }
        else
        {
            //5,处理当前层的节点，分别将左右支压入队列
            pRet[MAX_LEVEL - iRetSize - 1][pRetCol[MAX_LEVEL - iRetSize - 1]] = pTmpNode->val;
            pRetCol[MAX_LEVEL - iRetSize - 1] += 1;

            if (NULL != pTmpNode->left)
            {
                Push_Queue(&strQueue, pTmpNode->left);
            }
            if (NULL != pTmpNode->right)
            {
                Push_Queue(&strQueue, pTmpNode->right);
            }
        }
    }

    //7,返回
    *returnSize = iRetSize + 1;
    *returnColumnSizes = &pRetCol[MAX_LEVEL - iRetSize - 1];
    return &pRet[MAX_LEVEL - iRetSize - 1];
}
