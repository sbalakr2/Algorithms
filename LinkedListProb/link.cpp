/*
 * link.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <set>
#include <stack>
using namespace std;

struct node{
	int key;
	node *next;
};

node* head = NULL;

node* createNode(int k){
	node* newNode = new node;
	newNode->key = k;
	newNode->next = NULL;
	return newNode;
}

void print(node* n){
	while(n != NULL){
		cout << n->key << endl;
		n = n-> next;
	}
}

// method to remove duplicate keys in an unsorted linked list
void removeDuplicates(node* n){
	set<int> keys;
	set<int>::iterator it;
	node* prev = NULL;
	while(n != NULL){
		int cur = n->key;
		it = keys.find(cur);
		if(it == keys.end()){ // element not already in set
			keys.insert(cur);
		} else{
			prev->next = n->next;
		}
		prev = n;
		n = n->next;
	}
}

//method to remove duplicate keys in an unsorted linked list - without using additional space
// use two pointers
void removeDuplicatesWithoutStorage(node* n){
	node* cur; node* run;
	cur = n;
	while(cur != NULL){
		run = cur;
		while(run->next != NULL){
			if(cur->key == run->next->key){
				run->next = run->next->next;
			} else{
				run = run->next;
			}
		}
		cur = cur->next;
	}
}

void printKthtoLast(node* n, int k){ // Iterative Approach
	node* ptr1; node* ptr2;
	ptr1 = ptr2 = n;
	int cnt = 1;
	while(ptr2 != NULL && cnt <= k){
		ptr2 = ptr2->next;
		cnt +=1;
	}
	if(cnt == k+1){ // case when the list is shorter than k
		while(ptr2 != NULL){
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		cout << "K-nth node from the last: " << ptr1->key;
	} else{
		cout << "List is too short";
	}
}

int printKthtoLastRecursive(node* n, int k){
	if(n == NULL)
		return 0;
	int index = printKthtoLastRecursive(n->next, k) + 1;
	if(index == k)
		cout << "K-nth to last element: " << n->key;
	return index;
}

void getKthtoLastElement(node* n){
	int k;
	cout << "Enter k: " <<endl;
	cin>>k;
	//printKthtoLast(n, k);
	printKthtoLastRecursive(n, k);
}

node* partitionListAroundX(node* n, int x){ // Stable
	node *start = NULL; node* end = NULL;
	node *sp = NULL; node* ep = NULL;
	if(n == NULL)
		return NULL;
	while(n != NULL){
		node *nextNode = n->next; // saving the next pointer as it will be lost
		if(n->key < x){
			if(start == NULL){
				start = n;
				start->next = NULL;
				sp = start;
			}
			else{
				sp->next = n;
				sp = n;
			}
		} else{
			if(end == NULL){
				end = n;
				end->next = NULL;
				ep = end;
			}
			else{
				if(n->key == x){
					node* t = end;
					end = n;
					end->next = t;
				} else{
					ep->next = n;
					ep = n;
				}
			}
		}
		n = nextNode;
	}

	if(start == NULL){
		ep->next = NULL;
		return end;
	}
	if(end == NULL){
		sp->next = NULL;
		return start;
	}
	sp->next = end;
	ep->next = NULL;

	return start;
}

node* partitionUnStableListAroundX(node* n, int x){
	node* head = n;
	node* tail = n;
	while(n != NULL){
		node* next = n->next;
		if(n->key < x){
			n->next = head;
			head = n;
		} else{
			tail->next = n;
			tail = n;
		}
		n = next;
	}
	tail->next = NULL;
	return head;
}

void partitionLinkedList(node* n){
	int x;
	cout << "Enter the value around which the list should be partitioned: "<<endl;
	cin>>x;
	//node* head = partitionListAroundX(n, x);
	node* head = partitionUnStableListAroundX(n, x);
	print(head);
}

node* addLists(node *list1, node* list2, int carry){
	if(list1 == NULL && list2 == NULL && carry == 0)
		return NULL;
	node *resultHead = new node;
	int sum = carry;
	if(list1 != NULL)
		sum += list1->key;
	if(list2 != NULL)
		sum += list2->key;
	resultHead->key = (sum%10);
	if(list1->next != NULL || list2->next != NULL)
		resultHead->next = addLists(list1->next, list2->next, sum/10);
	return resultHead;
}

void addTwoLinkedLists(node* head1, node* head2){
	node* resultHead = addLists(head1, head2, 0);
	print(resultHead);
}

node* reversedLinkedList(node* copy){
	node* prev = NULL;
	node* cur = copy;
	node* next;
	while(cur != NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	copy = prev;
	return copy;
}

node* copyLinkedList(node* head){
	// only read the existing linked list and make a copy
	node* copy = createNode(head->key);
	node* temp = copy;
	node* cur = head->next;
	while(cur != NULL){
		temp->next = createNode(cur->key);
		temp = temp->next;
		cur = cur->next;
	}
	//print(head);
	return copy;
}

bool checkIsPalindrome(node* head, node* reversed){
	node* n1 = head;
	node* n2 = reversed;
	while(n1 != NULL && n2 != NULL){
		if(n1->key != n2-> key)
			return false;
		n1 = n1->next;
		n2 = n2->next;
	}
	if(n1 == NULL && n2 == NULL)
		return true;
	return false;
}

void checkPalindrome(node* head){
	// reverse and compare
	node* copy = copyLinkedList(head);
	//print(copy);
	node* reversed = reversedLinkedList(copy);
	print(head);
	print(reversed);
	bool isPalindrome = checkIsPalindrome(head, reversed);
	if(isPalindrome)cout<<"The linked list is a palindrome";
	else cout << "The linked list is not a palindrome";
}

bool checkIsPalindromeUsingStack(node* head){
	stack<int> st;
	node* slow = head;
	node* fast = head;
	while(slow && fast && fast->next){
		st.push(slow->key);
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast != NULL)
		slow = slow->next;
	while(slow && !st.empty()){
		if(st.top() != slow->key)
			return false;
		slow = slow->next;
		st.pop();
	}
	return true;
}
void checkPalindromeUsingStack(node* head){
	bool isPalindrome = checkIsPalindromeUsingStack(head);
	if(isPalindrome)cout<<"The linked list is a palindrome";
		else cout << "The linked list is not a palindrome";
}

int getLinkedListLength(node* head){
	node* temp = head;
	int len = 0;
	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}

/*bool checkIsPalindromeRecursive(node* head, int length, node** next){
	if(length < 2)
		return true;
	bool flag = checkIsPalindromeRecursive(head->next, length - 2, &(head->next));
	if(!flag){
		return flag;
	}

}*/

void checkPalindromeRecursive(node* head){
	/*int len = getLinkedListLength(head);
	cout<<"len: "<<len<<endl;
	bool isPalindrome = checkIsPalindromeRecursive(head, len, &head);
		if(isPalindrome)cout<<"The linked list is a palindrome";
			else cout << "The linked list is not a palindrome";*/
}

bool checkIntersectionOfLinkedLists(node* list1, node* list2, int* intNode){
	if(list1 == NULL || list2 == NULL)
		return false;
	int l1=1, l2=1;
	node* lp1 = list1;
	node* lp2 = list2;
	while(lp1->next){
		l1++;
		lp1 = lp1->next;
	}
	while(lp2->next){
		l2++;
		lp2 = lp2->next;
	}
	if(lp1 != lp2)	// If the last node "reference" are not same, then there is no intersection
		return false;

	int diff = (l1 > l2) ? (l1-l2) : (l2-l1);
	lp1 = list1;
	lp2 = list2;
	while(diff > 0){	// moving the long list pointer to adjust the difference
		if(l1 > l2){
			lp1 = lp1->next;
		} else{
			lp2 = lp2->next;
		}
		diff--;
	}
	while(lp1 && lp2){
		if(lp1 == lp2){
			*intNode = lp1->key;
			return true;
		}
		lp1 = lp1->next;
		lp2 = lp2->next;
	}
	return false;
}

void checkIfIntersectingLinkedLists(node* n1, node* n2){
	int* intNode = new int;
	int isIntersecting = checkIntersectionOfLinkedLists(n1, n2, intNode);
	if(isIntersecting)cout<<"The linked lists are intersecting at " << *intNode;
			else cout << "The linked lists are not intersecting";
}

int findStartAndRemove(node* head, node* loop_node){
	   struct node *ptr1;
	   struct node *ptr2;
	   ptr1 = head;
	   while (1)
	   {
	     ptr2 = loop_node;
	     while (ptr2->next != loop_node && ptr2->next != ptr1)
	         ptr2 = ptr2->next;
	     if (ptr2->next == ptr1){
	        return ptr1->key;
	     }
	     ptr1 = ptr1->next;
	   }
	   ptr2->next = NULL;
	return 0;
}

int findStartOfLoopAndRemove(node* head, node* cp){
	node* ptr1 = head;
	ptr1 = ptr1->next;
	while(ptr1 && cp){
		if(ptr1 == cp->next){
			cp->next = NULL;
			return ptr1->key;
		}
		ptr1 = ptr1->next;
		cp = cp->next;
	}
	return 0;
}

void detectAndRemoveLoop(node* head){
	node* slow = head;
	node* fast = head;

	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast){
			//int loopStart = findStartAndRemove(head, slow);
			int loopStart = findStartOfLoopAndRemove(head, slow);
			cout<< "Loop starts at node " << loopStart << endl;
			print(head);
			break;
		}
	}
}

int main(){
	/*node *head = createNode(3);
	head->next = createNode(5);
	head->next->next = createNode(8);
	head->next->next->next = createNode(5);
	head->next->next->next->next = createNode(10);
	head->next->next->next->next->next = createNode(2);
	head->next->next->next->next->next->next = createNode(1);*/
	//removeDuplicates(head);
	//removeDuplicatesWithoutStorage(head);
	//print(head);
	//getKthtoLastElement(head);
	//partitionLinkedList(head);

	/***********Block 2**********/

	/*node* head1 = createNode(7);
	head1->next = createNode(1);
	head1->next->next = createNode(6);

	node* head2 = createNode(5);
	head2->next = createNode(9);
	head2->next->next = createNode(2);

	addTwoLinkedLists(head1, head2);*/

	/***********Block 3**********/

	/*node* head = createNode(0);
	head->next = createNode(1);
	head->next->next = createNode(2);
	head->next->next->next = createNode(1);
	head->next->next->next->next = createNode(0);*/

	//checkPalindrome(head);
	//checkPalindromeUsingStack(head);
	//checkPalindromeRecursive(head);

	/********Intersection of Linked Lists********/
	/*node* common = createNode(7);
	common->next = createNode(2);
	common->next->next = createNode(1);

	node* head1 = createNode(3);
	head1->next = createNode(1);
	head1->next->next = createNode(5);
	head1->next->next->next = createNode(9);
	head1->next->next->next->next = common;

	node* head2 = createNode(4);
	head2->next = createNode(6);
	head2->next->next = common;

	checkIfIntersectingLinkedLists(head1, head2);*/

	/*********Loop Detection and Removal***********/
	node* common = createNode(5);
	common->next = createNode(9);
	common->next->next = createNode(6);
	common->next->next->next = createNode(4);
	common->next->next->next->next = common;

	node* head = createNode(3);
	head->next = createNode(1);
	head->next->next = common;

	detectAndRemoveLoop(head);
	return 0;
}



