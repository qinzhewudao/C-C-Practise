//����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������Ҫ���ܴ����κ�
//�µĽ�㣬ֻ����ָ���ָ��
// 1����������������
// 2����������������������˽�㰴��С����˳����ʣ�����֮ǰ���ʹ��Ľ���Ѿ�����Ϊһ��˫��������ô
//       ֻ��Ҫ����ǰ���������˫����������һ����㼴�ɣ��������˫������Ҳ�͵�������
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

BSTreeNode *pHead=NULL;//ָ��ѭ������ͷ���
BSTreeNode *pIndex=NULL;//ָ��ǰһ�����


/* ��������������                                                               */
void addBSTreeNode(BSTreeNode *&pCurrent,int value)//����������л�Ҫ�ı�ָ��ֵ��һ��Ҫ�ǵ�ʹ�����ô���
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

/* ���������������ͬʱ�������ָ��                                                                     */
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

/* �������ָ��                                                                   */
void convertToDoubleList(BSTreeNode* pCurrent)
{
    pCurrent->m_pLeft=pIndex;//ʹ��ǰ������ָ��ָ��˫�����������һ�����
    if (NULL==pIndex)//�����һ��Ԫ�ز����ڣ���ʱ˫��������δ��������˽���ǰ�����Ϊ˫������ͷ���
    {
        pHead=pCurrent;
    }
    else//ʹ˫�����������һ��������ָ��ָ��ǰ���
    {
        pIndex->m_pRight=pCurrent;
    }

    pIndex=pCurrent;//����ǰ�����Ϊ˫�����������һ�����

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
