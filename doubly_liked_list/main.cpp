#include <iostream>

using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
};

void delete_d(Node** head,int key){
    if((*head)==nullptr){
        cout<<"do not do this shit again"<<endl;
        return;
    }
    Node* temp = (*head);
    while(temp!=nullptr&&temp->data != key){
       temp = temp -> next;
    }
    if(temp == nullptr) return;
    if(temp==(*head)) (*head)=temp->next;
    if(temp->next!=nullptr)
        temp->next->prev = temp->prev;
    if(temp->prev!=nullptr)
        temp->prev->next=temp->next;
    delete(temp);
    return;
}
/*void delete_d(Node** head,int key){
    if((*head)==nullptr){
        cout<<"do not do this shit again"<<endl;
        return;
    }
    Node* temp = (*head);
    while(temp->data!=key){
        temp = temp->next;
    }
    if(temp->prev != nullptr&&temp->next!=nullptr){
        temp->prev->next=temp->next;
    }else if(temp->prev==nullptr){
        (*head)=temp->next;
    }else{
        temp->prev->next=nullptr;
    }


}*/
void search_d(Node** head,int key){
    while((*head)!=nullptr&&(*head)->data!=key){
        (*head)=(*head)->next;
    }
     cout<<endl<<"the location of "<<key<<" = "<<(*head)<<endl;
}
void insert_before(Node** head,Node* A,int val){
    Node* new_ele = new Node();
    if(A==nullptr){
        cout<<"wrong addition"<<endl;
        return;
    }
    new_ele -> data = val;
     new_ele -> prev = A -> prev;
     A -> prev = new_ele;
    new_ele -> next = A;
    if(new_ele -> prev != nullptr){
        new_ele ->prev->next=new_ele;
    }else{
        (*head)=new_ele;
    }
}
void insert_first(Node** head,int val){
    Node* temp = new Node();
    temp ->data = val;
    temp ->next = (*head);
    temp ->prev = nullptr;
    if((*head)!=nullptr)
        (*head) -> prev = temp;
    (*head) = temp;
    cout<<"make sure of the address for "<<val<<" and it is = "<<temp<<endl;
}
void insert_after(Node* prev_block,int val){
    Node* new_ele = new Node();
    if (prev_block == nullptr) {
        cout << "the given previous node cannot be NULL";
        return;
    }
    new_ele ->data = val;
    new_ele -> next = prev_block -> next;
    new_ele -> prev = prev_block;
    prev_block -> next = new_ele;
   if(new_ele ->next != nullptr)
    new_ele ->next->prev = new_ele;
}
void print(Node** p){
    Node* mp = (*p);
    while(mp!=nullptr){
        cout<<mp ->data<<" ";
        mp = mp ->next;
    }
}
void printList(Node* node)
{
    Node* last;
    cout << "\nTraversal in forward direction \n";
    while (node != NULL) {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction \n";
    while (last != NULL) {
        cout << " " << last->data << " ";
        last = last->prev;
    }
}
int main()
{
    Node* head = nullptr;
    insert_first(&head,4);
    insert_first(&head,5);
    insert_first(&head,6);
    insert_first(&head,7);
    insert_after(head,100);
    insert_before(&head,head  ,100);
    print(&head);
    search_d(&head,5);
    delete_d(&head,100);
    printList(head);
    return 0;
}
