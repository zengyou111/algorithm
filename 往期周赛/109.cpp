#include "iostream"
#include "stdio.h"
#include "vector"
#include "stdlib.h"
using namespace  std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
};
struct ListNode{
    int val;
    ListNode *next;
};

TreeNode* Partition(ListNode *head,ListNode *tail){

    ListNode *L=(ListNode *)malloc(sizeof(ListNode));
    ListNode *slow=L,*fast=L;
    L->next=head;
    while(fast->next!=tail){
        for(int i=0;i<2&&fast->next!=tail;i++){
            fast=fast->next;
        }
        slow=slow->next;
    }
    if(!slow)return NULL;
    TreeNode *root=(TreeNode *)malloc(sizeof(TreeNode));
    if(head==tail){
        root->val=head->val;
        root->left=root->right=NULL;
    }else{
        root->val=slow->val;
        root->left=Partition(head,slow);
        root->right=Partition(slow->next,tail);
    }

    return root;
}

int main(){
    ListNode *arr[5]={NULL};
    vector<int>num={-10,-3,0,5,9};
    for(int i=0;i<5;i++){
        arr[i]=(ListNode *) malloc(sizeof(ListNode));
        arr[i]->val=num[i];
    }
    for(int i=0;i<4;i++){
        arr[i]->next=arr[i+1];
    }
    arr[4]->next=NULL;
    Partition(arr[0],NULL);




    return 0;
}

