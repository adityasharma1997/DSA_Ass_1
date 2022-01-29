#include<iostream>
#include <map>
using namespace std;

class Node{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int key,int value){
        this->key=key;
        this->value=value;
        this->prev=NULL;
        this->next=NULL;
    }
};

class LRUCache {
public:
    Node *head, *tail;
    unordered_map<int, Node *> hmap;
    int capacity,cursize;

    void addatlast(Node *temp){
        if(head==NULL){
            head=temp;
            tail=temp;
            //only node
        }else{
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        return;
    }

    void removefromstart(Node *temp){
         // Node *temp1=temp;
        if(temp->prev==NULL){
            head=temp->next;
        }
        else{
            temp->prev->next=temp->next;
        }
        if(temp->next==NULL){
            tail=temp->prev;
        }
        else{
            temp->next->prev=temp->prev;
        }
        temp->next=NULL;
        temp->prev=NULL;
         // delete(temp1);
    }

    LRUCache(int capacity) {
        this->capacity=capacity;
        cursize=0;
        head=NULL;
        tail=NULL;
    }
    
    int get(int key) {
         if(hmap.find(key)!=hmap.end()){
            int ans=hmap[key]->value;
            removefromstart(hmap[key]);
            addatlast(hmap[key]);

            return ans;
        }

        return -1;
    }
    
    void set(int key, int value) {
        if(hmap.find(key)!=hmap.end()){
            hmap[key]->value=value;

            removefromstart(hmap[key]);
            addatlast(hmap[key]);
        }
        else{
            if(capacity==cursize){
                hmap.erase(head->key);
                removefromstart(head);
                cursize--;
            }
            Node *new1= new Node(key,value);
            hmap[key]=new1;
            cursize++;
            addatlast(new1);
            }
    }
};

int main(){

    //driver code
    return 0;
}

