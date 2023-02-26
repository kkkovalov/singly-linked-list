#include <iostream>

struct ListNode {
    int value;
    ListNode *next;
};

ListNode *head = NULL;

int main(void){
    std::cout<<"Enter number of integers in the list"<<std::endl;
    int numVal;
    std::cin>>numVal;

    int i = 0;
    ListNode *temp;
    while(i < numVal){
        int newVal = 0;
        std::cout<<"Enter your value: ";
        std::cin>>newVal;
        temp = head;
        ListNode *newNode = (struct ListNode*) malloc(sizeof(ListNode));
        newNode->value = newVal;
        newNode->next = NULL;

        if(head) {
            while(temp->next != NULL){
                temp = temp->next;
            };
            temp->next = newNode;
        } else {
            head = newNode;
        }
        i++;
    };

    std::cout<<"Display created list: "<<std::endl;
    temp = head;
    while(temp != NULL){
        std::cout<<temp->value<<' ';
        temp = temp->next;
    };
    std::cout<<' '<<std::endl;
};