#include <iostream>

using namespace std;
 int tail = 0, head = 0;
 bool kyo_is_empty(int *q){
    if(head == tail)return true;
    else return false;

 }
 void print(int *q,int n){
    while(head != tail){
        cout<<q[head]<<" ";
        if(head == n)head = 0;
        else ++head;
    }cout<<endl;
 }
void enqueu(int *q,int x,int n){
    q[tail]=x;
    if(tail==n)tail=0;
    else tail += 1;
}int dequeu(int *q,int n){
    int x;
    if(!kyo_is_empty(q)){
         x = q[head];
        if(head==n)head = 0;
        else head += 1;
    }else cout<<"queue is empty"<<endl;
    return x;
}
int main()
{
    int n=6 ,x;
    int q[n];
    enqueu(q,4,n);
    enqueu(q,8,n);
    enqueu(q,4,n);
    enqueu(q,5,n);
    dequeu(q,n);
    dequeu(q,n);
    dequeu(q,n);
    dequeu(q,n);
    dequeu(q,n);
    print(q,n);
    cout<<"tail = "<<tail<<endl;
    cout<<"head = "<<head <<endl;
    enqueu(q,6,n);
    enqueu(q,55,n);
    enqueu(q,33,n);
    enqueu(q,23,n);
    enqueu(q,4,n);
    dequeu(q,n);
    dequeu(q,n);
    dequeu(q,n);
    dequeu(q,n);
    print(q,n);
    cout<<"tail = "<<tail<<endl;
    cout<<"head = "<<head <<endl;
    return 0;
}
