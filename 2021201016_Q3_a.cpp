#include<iostream>
using namespace std;


class Node{
    public:
    int row;
    int col;
    double data;
    Node *next;
};

void convert_to_linklist(Node **head,int r,int j,double x){
    Node *temp= *head;
    Node *newly;
    

    if(temp==NULL){
        temp = new Node();
        temp->row = r;
        temp->col = j;
        temp->data = x;
        temp->next = NULL;
        *head = temp;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newly = new Node();
        newly->row = r;
        newly->col = j;
        newly->data = x;
        newly->next = NULL;
        temp->next = newly;
    }
}

Node* sort(Node **head){
    Node *first=*head;
    Node *cur;
    Node *second;
    bool unsorted=true;
    while(unsorted){
        unsorted=false;
        cur=*head;
        while(cur->next!=NULL){
            second=cur->next;
            if((cur->row)>(second->row)){
                int r=cur->row;
                cur->row=second->row;
                second->row=r;

                int c=cur->col;
                cur->col=second->col;
                second->col=c;

                double v=cur->data;
                cur->data=second->data;
                second->data=v;

                unsorted=true;
            }
            cur=cur->next;
        }
    }
    cur=*head;

     unsorted=true;
    while(unsorted){
        unsorted=false;
        cur=*head;
        while(cur->next!=NULL){
            second=cur->next;
            if(((cur->row)==(second->row))&&((cur->col)>(second->col))){
               
                int c=cur->col;
                cur->col=second->col;
                second->col=c;

                double v=cur->data;
                cur->data=second->data;
                second->data=v;

                unsorted=true;
            }
            cur=cur->next;
        }
    }
    
   return first;

}

Node* addition(Node **head){
    Node *milgya=*head;
    Node *temp=*head;
   
    while(temp->next!=NULL){
        if(((temp->row)==(temp->next->row))&&((temp->col)==(temp->next->col))){
            temp->data=temp->data+temp->next->data;
            temp->next=temp->next->next;
            
        }else{
            temp=temp->next;
        }
    }
    return milgya;
}

Node* multiplication(Node **list1,Node **list2){
Node *first=*list1;
Node *product=NULL;
    while(first!=NULL){
        Node *second=*list2;
        while(second->next!=NULL){
            if((first->col)==(second->row)){
                convert_to_linklist(&product,first->row,second->col,(first->data)*(second->data));
            }
            second=second->next;
        }
        if(second->next==NULL){
            if((first->col)==(second->row)){
                convert_to_linklist(&product,first->row,second->col,(first->data)*(second->data));
            }
        }
        first=first->next;
    }

    Node *product_sorted=sort(&product);
    Node *fin_ans=addition(&product_sorted);
    return fin_ans;
}


Node* transpose(Node **list){
    Node *head=*list;
    while(head!=NULL){
        int a = head->row;
        head->row=head->col;
        head->col=a;
        head=head->next;
    }
    Node *temp = *list;
    Node *answer=sort(&temp);
    return answer;
}

Node* sum_of_two(Node **list1,Node **list2){
    Node *answer=NULL;
    Node *p=*list1;
    Node *q=*list2;
    while(p!=NULL && q!=NULL){
        if(p->row==q->row){
            if(p->col==q->col){
                convert_to_linklist(&answer,p->row,p->col,(p->data+q->data));
                p=p->next;
                q=q->next;
            }else if((p->col)<(q->col)){
                convert_to_linklist(&answer,p->row,p->col,p->data);
                p=p->next;
            }else{
                convert_to_linklist(&answer,q->row,q->col,q->data);
                q=q->next;
            }
        }else if((p->row)<(q->row)){
            convert_to_linklist(&answer,p->row,p->col,p->data);
            p=p->next;
        }else{
            convert_to_linklist(&answer,q->row,q->col,q->data);
                q=q->next;
        }
    }
     while(p!=NULL){
        convert_to_linklist(&answer,p->row,p->col,p->data);
             p=p->next; 
     }
     while(q!=NULL){
         convert_to_linklist(&answer,q->row,q->col,q->data);
                 q=q->next;
     }
    return answer;
}

void print(Node *head){
    Node *temp=head;
    cout<<"rowIndex: ";
    while(temp!=NULL){
        cout<<temp->row<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=head;
    cout<<"colIndex: ";
    while(temp!=NULL){
        cout<<temp->col<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=head;
    cout<<"value: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

int main(){
    int row,col;
    cin>>row>>col;
    double matrix1[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix1[i][j];
        }
    }
    double matrix2[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix2[i][j];
        }
    }
    Node *list1=NULL;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix1[i][j]!=0){
                convert_to_linklist(&list1,i,j,matrix1[i][j]);
            }
        }
    }
    Node *list2=NULL;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix2[i][j]!=0){
                convert_to_linklist(&list2,i,j,matrix2[i][j]);
            }
        }
    }
    Node *y=transpose(&list1);
    Node *z=multiplication(&list1,&list2);
    Node *x = sum_of_two(&list1,&list2);
    print(x);
    return 0;

}