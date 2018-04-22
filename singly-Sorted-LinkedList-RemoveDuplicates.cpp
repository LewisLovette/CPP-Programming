#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;  
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:  

            //MY CODE      
            Node* removeDuplicates(Node *head)
            {   
                //Write your code here
                Node * nextPos = head;
                while(nextPos->next != NULL){
                    if(nextPos->data == nextPos->next->data){
                        Node * temp = nextPos->next;    //So we can delete allocated memory
                        nextPos->next = nextPos->next->next;    //skips over next node onto the node after the next.
                        delete temp;                    //Deleting the node from memory
                    }else{
                        nextPos = nextPos->next;    //No duplicates = step through list.
                    }
                }
                return head;
            }


          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};
      
int main()
{
  Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    } 
    head=mylist.removeDuplicates(head);

  mylist.display(head);
    
}