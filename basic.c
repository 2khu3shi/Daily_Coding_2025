#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* create(int k){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=k;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
node* insertFront(node* head,int k){
    node* newnode=create(k);
    if(head==NULL){
        head=newnode;
        return head;
    }
    node*temp=head;
    temp->prev=newnode;
    newnode->next=temp;
    return newnode;
}
node* insertEnd(node*head,int k){
    node* newnode=create(k);
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    return head;
}
node*Intermediate(node*head,int k,int pos){
    node* newnode=create(k);
    if(pos<=0){
        insertFront(head,k);
    }
    node*temp=head;
    int i;
    for(i=0;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    return head;
}
void deleteFront(node** head){
    node*temp=*head;
    if(*head==NULL){
        printf("Empty list");
    }
    (*head)=(*head)->next;
    free(temp);
}
void deleteEnd(node** head){
    node*temp=*head;
    if(*head==NULL){
        printf("Empty list");
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node* del=temp->next;
    temp->next=NULL;
    free(del);
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
// node* middle(node*head){
//     node*slow=head;
//     node*fast=head;
//     while(fast!=NULL&&fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }
node* reverse(node*head){
    
}
int main(){
    node* head=NULL;
    head=insertEnd(head,11);
    head=insertEnd(head,22);
    head=insertEnd(head,33);
    head=insertEnd(head,44);
    head=insertEnd(head,55);
    //node* mid=middle(head);
    //head=Intermediate(head,99,2);
    //deleteEnd(&head);
    //printf("middle element is-%d\n",mid->data);
    display(head);
    return 0;
}
