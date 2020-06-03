

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//大神代码参考，主要是队列的实现
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//方法二：创建队列
//1,构建队列，实现压入和弹出函数 Push_Queue 和 Pop_Queue
//2,利用队列先进先出的特性实现二叉树的层序遍历
//3,将二叉树根 root 压入队列，并将 NULL 作为每层的区分节点也压入队列
//4,从队列中读出节点，保存当前节点的值，并且将左右支分别压入队列
//5,遇到层的区分节点则处理下一层，直到队列为空

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

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
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
    pRet[iRetSize] = (int *)malloc(sizeof(int) * strQueue.iNum);
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
                pRet[iRetSize] = (int *)malloc(sizeof(int) * strQueue.iNum);

                Push_Queue(&strQueue, NULL);
            }
        }
        else
        {
            //5,处理当前层的节点，分别将左右支压入队列
            pRet[iRetSize][pRetCol[iRetSize]] = pTmpNode->val;
            pRetCol[iRetSize] += 1;

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
    *returnColumnSizes = pRetCol;
    return pRet;
}

/*
//方法一：递归法
//1，将每一层的节点都保存到队列中
//2，循环遍历队列，得到每一层的值
//3，将队列中节点的左右支保存到队列中，递归调用

#define     MAX_LEVEL       1000
#define     MAX_NODE        500

//函数一：递归函数
void recusiveLevelOrder(struct TreeNode** pNodeBuf, struct TreeNode** pTmpBuf, int iNum, int** pRet, int* pRetSize, int* pRetCol){
    int     i           = 0;
    int     iLevel      = *pRetSize;
    int     iLevelNum   = 0;
    int     iNextNum    = 0;

    if(0 == iNum) return;

    //1,遍历队列中的节点，作为当前层的值
    //2,队列节点的左右节点不为空，则放置 pTmpBuf 中
    pRet[iLevel] = (int*)malloc(sizeof(int) * iNum);
    for(i = 0; i < iNum; i++)
    {
        if(NULL != pNodeBuf[i])
        {
            pRet[iLevel][iLevelNum++] = pNodeBuf[i]->val;
        
            if(NULL != pNodeBuf[i]->left)
            {
                pTmpBuf[iNextNum++] = pNodeBuf[i]->left;
            }
            if(NULL != pNodeBuf[i]->right)
            {
                pTmpBuf[iNextNum++] = pNodeBuf[i]->right;
            }
        }
    }

    //2,将 pTmpBuf 中节点拷贝到 pNodeBuf 中
    memcpy(pNodeBuf, pTmpBuf, sizeof(struct TreeNode*) * MAX_NODE);

    //3,递归调用
    *pRetSize = iLevel + 1;
    pRetCol[iLevel] = iNum;
    recusiveLevelOrder(pNodeBuf, pTmpBuf, iNextNum, pRet, pRetSize, pRetCol);

    return;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int         iNum        = 0;
    int         iRetSize    = 0;
    int**       pRet        = NULL;
    int*        pRetCol     = NULL;
    struct TreeNode**    pNodeBuf   = NULL;     //存放每一层的节点
    struct TreeNode**    pTmpBuf    = NULL;     //临时空间，放置下一层的节点

    //1,申请空间
    pRet = (int**)malloc(sizeof(int*) * MAX_LEVEL);
    memset(pRet, 0x00, sizeof(int*) * MAX_LEVEL);
    pRetCol = (int*)malloc(sizeof(int) * MAX_LEVEL);
    memset(pRet, 0x00, sizeof(int) * MAX_LEVEL);
    pNodeBuf = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_NODE);
    memset(pNodeBuf, 0x00, sizeof(struct TreeNode*) * MAX_NODE);
    pTmpBuf = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_NODE);
    memset(pTmpBuf, 0x00, sizeof(struct TreeNode*) * MAX_NODE);

    //2,特殊处理
    if(NULL == root)
    {
        *returnSize = iRetSize;
        *returnColumnSizes = pRetCol;
        return pRet;
    }

    //3,递归调用
    pNodeBuf[iNum++] = root;
    recusiveLevelOrder(pNodeBuf, pTmpBuf, iNum, pRet, &iRetSize, pRetCol);

    //4,释放空间
    free(pNodeBuf);
    free(pTmpBuf);

    //5,返回
    *returnSize = iRetSize;
    *returnColumnSizes = pRetCol;
    return pRet;
}
*/
int main(int argc, char const *argv[])
{
    printf("aaaaa\n");
    return 0;
}