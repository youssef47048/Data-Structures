#include <iostream>

using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node* search_(Node** head,int key){
    if((*head)==nullptr){
        cout<<"not exist"<<endl;
        return nullptr;
    }while((*head)->data != key){
        (*head) = (*head)->next;
    }
    return (*head);
}
void delete_position(Node*& head,int key){
    if(head == nullptr){
        cout<<"I will come for you!"<<endl;
        return;
    }
   if(head!=nullptr&&head->data==key){
    Node* temp = head;
    head= head->next;
    delete(temp);
    return;
   }
    delete_position(head ->next,key);
}
void delete_first(Node** head){
    Node* temp = (*head);
    (*head) = (*head) -> next;
    delete(temp);
}void delete_last(Node** head){
    Node* en = (*head);
    Node* prev = nullptr;
    while(en -> next){
        prev = en;
        en = en -> next;
    }
     prev -> next=nullptr;
    delete(en);
}
void push_first(Node **head_ref,int new_data){
    Node* new_node = new Node();
    new_node -> data = new_data;

    new_node -> next = (*head_ref);
    *head_ref = new_node;
     //cout<<"push first fun "<< new_node<<endl;
}
void push_after(Node* prev , int new_data){
    if(prev == nullptr){
        cout<<"get the way out"<<endl;
        return;
    }
    Node *new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = prev -> next;
    prev -> next = new_node;
}

 void push_end(Node** head_ref , int new_data){
    Node* new_node = new Node();
    new_node ->data = new_data;
    new_node ->next = nullptr;
    Node *last = *head_ref;
    if(*head_ref == nullptr){
        (*head_ref) -> next = new_node;
        return;
    }
    while(last ->next != nullptr){
        last = last ->next;
    }
    last ->next = new_node;
    return;
 }
 void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
int main()
{
    Node *head = nullptr;
    Node* after = new Node();

    push_first(&head,10);
    push_first(&head,4);
    push_end(&head,55);
    push_first(&head,8);
    after =head ->next;
   after = after ->next;
    push_after(after,1);
    push_end( &head , 22);
    printList(head);
    cout<<endl;
    delete_first(&head);
    delete_last(&head);
    delete_position(head,5);
    cout << search_(&head,4)<<endl;
    printList(head);
    return 0;
}
