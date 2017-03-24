//输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。要求不能创建任何
//新的结点，只调整指针的指向。
// 1：构造二叉查找树；
// 2：中序遍历二叉查找树，因此结点按从小到大顺序访问，假设之前访问过的结点已经调整为一个双向链表，那么
//       只需要将当前结点连接至双向链表的最后一个结点即可，访问完后，双向链表也就调整完了
#include <iostream>
using namespace std;
struct BSTreeNode
{
    int m_nValue; // value of node
    BSTreeNode *m_pLeft; // left child of node
    BSTreeNode *m_pRight; // right child of node
};

void addBSTreeNode(BSTreeNode *&pCurrent,int value);
void inOrderBSTree(BSTreeNode* pBSTree);
void convertToDoubleList(BSTreeNode* pCurrent);

BSTreeNode *pHead=NULL;//指向循环队列头结点
BSTreeNode *pIndex=NULL;//指向前一个结点


/* 建立二叉排序树                                                               */
void addBSTreeNode(BSTreeNode *&pCurrent,int value)//在这个函数中会要改变指针值，一定要记得使用引用传递
{
    if (pCurrent==NULL)
    {
        BSTreeNode* pBSTree=new BSTreeNode();
        pBSTree->m_nValue=value;
        pBSTree->m_pLeft=NULL;
        pBSTree->m_pRight=NULL;
        pCurrent=pBSTree;
    }
    else if (pCurrent->m_nValue<value)
    {
        addBSTreeNode(pCurrent->m_pRight,value);
    }
    else if (pCurrent->m_nValue>value)
    {
        addBSTreeNode(pCurrent->m_pLeft,value);
    }
    else
    {
        cout<<"node repeated"<<endl;
    }

}

/* 中序遍历二叉树，同时调整结点指针                                                                     */
void inOrderBSTree(BSTreeNode* pBSTree)
{

    if (NULL==pBSTree)
    {
        return;
    }
    if (NULL!=pBSTree->m_pLeft)
    {
        inOrderBSTree(pBSTree->m_pLeft);
    }

    convertToDoubleList(pBSTree);

    if (NULL!=pBSTree->m_pRight)
    {
        inOrderBSTree(pBSTree->m_pRight);
    }

}

/* 调整结点指针                                                                   */
void convertToDoubleList(BSTreeNode* pCurrent)
{
    pCurrent->m_pLeft=pIndex;//使当前结点的左指针指向双向链表中最后一个结点
    if (NULL==pIndex)//若最后一个元素不存在，此时双向链表尚未建立，因此将当前结点设为双向链表头结点
    {
        pHead=pCurrent;
    }
    else//使双向链表中最后一个结点的右指针指向当前结点
    {
        pIndex->m_pRight=pCurrent;
    }

    pIndex=pCurrent;//将当前结点设为双向链表中最后一个结点

    cout<<pCurrent->m_nValue<<" ";

}

int main()
{
    BSTreeNode *pRoot=NULL;
    addBSTreeNode(pRoot,10);
    addBSTreeNode(pRoot,6);
    addBSTreeNode(pRoot,14);
    addBSTreeNode(pRoot,4);
    addBSTreeNode(pRoot,8);
    addBSTreeNode(pRoot,12);
    addBSTreeNode(pRoot,16);
    inOrderBSTree(pRoot);
    return 0;
}
