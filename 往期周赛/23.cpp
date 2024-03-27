#include "stdio.h"
#include <iostream>
#include "stdlib.h"
using namespace  std;

struct ListNode{
    int val;
    struct ListNode*next;
};

void swap(struct ListNode**lists,int left,int right){
    struct ListNode *flag=lists[right];
    lists[right]=lists[left];
    lists[left]=flag;
}

void heapify(struct ListNode **lists,int listsSize,int i){
    int leftSon=2*i+1,rightSon=2*(i+1),minmal=i;
    if(leftSon<listsSize&&lists[leftSon]->val<lists[minmal]->val){
        minmal=leftSon;
    }
    if(rightSon<listsSize&&lists[rightSon]->val<lists[minmal]->val){
        minmal=rightSon;
    }
    if(minmal!=i){
        swap(lists,i,minmal);
        heapify(lists,listsSize,minmal);
    }
}
void buildHeap(struct ListNode**lists,int listsSize){
    for(int i=listsSize/2-1;i>=0;i--){
        heapify(lists,listsSize,i);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    buildHeap(lists,listsSize);
    struct ListNode*res=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *t=res;
    while(lists[0]){
        struct ListNode*flag=(struct ListNode*)malloc(sizeof(struct ListNode));
        flag->val=lists[0]->val;
        t->next=flag;
        t=flag;
        t->next=NULL;
        lists[0]=lists[0]->next;
        if(!lists[0]){
            swap(lists,0,listsSize-1);
            listsSize--;
        }
        heapify(lists,listsSize,0);
    }
    return res->next;
}

int main() {
    /* [[1,4,5],[1,3,4],[2,6]]*/
    struct ListNode*a1=(struct ListNode*) malloc(sizeof(ListNode))
            ,*a2=(struct ListNode*) malloc(sizeof(ListNode))
            ,*a3=(struct ListNode*) malloc(sizeof(ListNode))
            ,*a4=(struct ListNode*) malloc(sizeof(ListNode))
            ,*a5=(struct ListNode*) malloc(sizeof(ListNode))
            ,*a6=(struct ListNode*) malloc(sizeof(ListNode))
            ,*a7=(struct ListNode*) malloc(sizeof(ListNode))
            ,*a8=(struct ListNode*) malloc(sizeof(ListNode));
    a1->val=1,a2->val=4,a3->val=5,a4->val=1,a5->val=3,a6->val=4,a7->val=2,a8->val=6;
    a1->next=a2,a2->next=a3;a3->next=NULL;
    a4->next=a5,a5->next=a6;a6->next=NULL;
    a7->next=a8;a8->next=NULL;
    struct  ListNode **lists=(struct ListNode**) malloc(sizeof(ListNode*)*3);
    lists[0]=a1,lists[1]=a4,lists[2]=a7;
    mergeKLists(lists,3);
    return 0;
}
/*
 lists[0][0]->val
 lists[1][0]->val
 lists[2][0]->val

 * */