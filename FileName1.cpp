#include <iostream>
#include <string>
#include <ctime>
using namespace std;

typedef struct bitree {
    int data;
    bitree* lchild;
    bitree* rchild;
} bitree;

// 修改插入逻辑：正确处理空树情况
bitree* inserttree(bitree* root, int data) {
    if (root == NULL) {
        bitree* newnode = new bitree();
        newnode->data = data;
        newnode->lchild = newnode->rchild = NULL;
        return newnode;
    }
    if (data < root->data) {
        root->lchild = inserttree(root->lchild, data);
    }
    else {
        root->rchild = inserttree(root->rchild, data);
    }
    return root;
}

// 添加内存释放函数
void freeTree(bitree* root) {
    if (root == NULL) return;
    freeTree(root->lchild);
    freeTree(root->rchild);
    delete root;
}
//输出叶子节点
void outleaves(bitree* root) {
    if (!root) return;
    if (!root->lchild && !root->rchild) {
        cout << root->data << " ";
    }
    outleaves(root->lchild);
    outleaves(root->rchild);
}
//查询高度
int height(bitree* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {   
        int left = height(root->lchild);
        int right = height(root->rchild);
        return(left > right) ? left + 1 : right + 1;
    }
}
// 改进冒泡排序实现
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
//中序遍历
int q = 0;
void check(int* b, int* c,int Datacount) 
{
    bool flag=true;
    for (int i = 0; i < Datacount; i++) 
    
    {
        if (b[i] != c[i]) 
        {
            flag = false;
        }
    }
    if (flag) 
    {
        cout << "\n中序遍历结果正确\n";
        
    }
    else 
    {
        cout << "\n中序遍历结果错误\n";
    }
}
void inOrderTraversal(bitree* root,int* c) {
    if (root) {
        inOrderTraversal(root->lchild,c);
        c[q] = root->data;
        cout << root->data << " ";
        q++;
        inOrderTraversal(root->rchild,c);
    }
}
int main() {
    srand(time(0));
    int DataCount, MaxData;
    do {
        cout << "请输入DataCount (10-20): ";
        cin >> DataCount;
    } while (DataCount < 10 || DataCount > 20);

    do {
        cout << "请输入MaxData (50-100): ";
        cin >> MaxData;
    } while (MaxData < 50 || MaxData > 100);

    //随机数
    int* a =(int *)malloc(sizeof(int)*DataCount);
    int* b = (int*)malloc(sizeof(int) * DataCount);

    for (int i = 0; i < DataCount; i++) {
        bool flag;
        do {
            flag = true;
            a[i] = rand() % (MaxData + 1);
            for (int j = 0; j < i; j++) {
                if (a[i] == a[j]) {
                    flag = false;
                    break;
                }
            }
        } while (!flag);
    }

    cout << "\n------ 原始数据 ------\n";
    for (int i = 0; i < DataCount; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

     //排序输出
    copy(a, a + DataCount, b);
    bubbleSort(b, DataCount);

    cout << "\n------ 排序后数据 ------\n";
    for (int i = 0; i < DataCount; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    // 构建二叉搜索树
    bitree* Btree = NULL;
    for (int i = 0; i < DataCount; i++) {
        Btree = inserttree(Btree, a[i]);
    }
    cout << "\n------ 高度"<<height(Btree)<<" ------\n";

    cout << "\n------ 叶子节点 ------\n";
    outleaves(Btree);

    cout << "\n\n------ 中序遍历结果 ------\n";
    int* c = (int*)malloc(sizeof(int) * DataCount);

    inOrderTraversal(Btree,c);
    check(b, c,DataCount);
    // 释放内存
    free(a);
    free(b);
    free(c);
    freeTree(Btree);
    cin.ignore();
    cin.get();
    return 0;
}