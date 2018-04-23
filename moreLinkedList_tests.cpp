#include <cstddef>
#include <iostream>
#include <algorithm>

using namespace std;  

class Node{
	public:
		int data;
		Node * next;

		Node(int d){
			data = d;
            next = NULL;
		}
};

class LinkedList{
	public:
    
		Node * insert(Node * head, int data){
            Node * temp = new Node(data); //assign new memory for the new node
            if(head == NULL){
                head = temp;
            } 
            else if(head->next == NULL){
                head->next = temp;
            } else{
                Node * head2 = head;
                    while(head2->next != NULL){  //stepping to end of list
                    head2 = head2->next;
                }
                head2->next = temp;
            }
            return head;
		}

		void printLL(Node * head){
            Node * temp = head;
			while(temp != NULL){
				cout << temp->data << " ";
                temp = temp->next;
			}
		}
};

int main(){
    Node* head = NULL;
    LinkedList mylist;

    int T, data;
    cin >> T;

    while(T-->0){
        cin >> data;
        head = mylist.insert(head,data);
    }
    
    mylist.printLL(head);
}