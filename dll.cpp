#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

using namespace std;

struct dll{
	int data;
	struct dll *diff; 
};

// struct dll *head = NULL;
struct dll* XOR (struct dll *a, struct dll *b){
    return (struct dll*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

// Print elements of double linked list 
void display(struct dll *head){
	struct dll *curr = head;
    struct dll *prev = NULL;
    struct dll *next;
	if(!curr) {
		cout<<"\nNo elements in the list to display\n";
		return;
	}
    cout<<"\nElements in linked list from front:\n";
	while (curr->diff) {
			cout<<curr->data<<"<->";
			next = XOR(curr->diff,prev);
			prev = curr;
			curr = next;
	}
	 cout<<curr->data<<endl;
}

// Remove elements of double linked list from front 
void removeElementFromFront(struct dll **head){
	struct dll *curr = *head;
	struct dll *next,*prev = NULL,*nextTonext;
	if(!curr) {
		cout<<"No elements in the list to remove\n";
		return;
	}
	if(curr->diff == NULL) {
		cout<<"element removed:"<<curr->data<<endl;
		free(curr);
		*head = NULL;
        display(*head);
		return;
	}
	next = XOR(prev,curr->diff);
	
	if(next->diff != NULL){
		nextTonext = XOR(curr,next->diff);
		next->diff = XOR(prev,nextTonext);
	}else{
		next->diff = NULL;
	}
	*head = next;
	
	cout<<"element removed:"<<curr->data<<endl;
	free(curr);
    display(*head);
}

// Add elements to double linked list from last 
void insertElemetAtLast(int element,struct dll **head){
	struct dll *newnode = (dll *)malloc(sizeof(struct dll));
	if(!newnode) {
		cout<<"memory Error"<<endl;
		return;
	}
	newnode->data = element;
	newnode->diff = NULL;
	struct dll *last = *head;
	struct dll *prev = NULL;
	struct dll *next;
	if(*head == NULL) {
		*head = newnode;
		return;
	}
	while (last->diff != NULL) {
		next = XOR(last->diff,prev);
		prev = last;
		last = next;
	}
	last->diff = XOR(newnode,prev);	
	return;
}

int main(){
	struct dll *head = NULL;
	int n,x,choice,i;
	cout<<"Double Linked List Implementation Using Single Pointer\n";
	while(1){
		cout<<"\n1.Add element to ddl at last\n2.Display dll\n3.remove first element of dll\n4.exit\n\nplease enter your choice:";
		cin>>choice;
		switch(choice){
			case 1: cout<<"enter the number of elements to add:";
					cin>>n;
					for(i=0;i<n;i++){
						cout<<"enter element "<<i+1<<":";
						cin>>x;
						insertElemetAtLast(x,&head);
					}
                    display(head);
					break;

			case 2: display(head);
					break;
			
			case 3: removeElementFromFront(&head);
					break;

			case 4: exit(0);
					break;
					
			default: cout<<"please enter valid option\n";
		}
	}
	return 0;
}