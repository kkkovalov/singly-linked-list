#include <iostream>

class List {
    public:
        int size(){
            ListNode *temp = head;
            if(temp == NULL){
                return 0;
            } else {
                int sizeVal = 0;
                while(temp != NULL){
                    temp = temp->next;
                    sizeVal++;
                };
                return sizeVal;
            };
        }

        void push_front(int newValue){

        };

        void push_back(int newValue){
            ListNode *newNode = (struct ListNode*) malloc(sizeof(ListNode));
            ListNode *temp = head;
            newNode->value = newValue;
            newNode->next = NULL;
            if(head){
                while(temp->next){
                    temp = temp->next;
                };
                temp->next = newNode;
            } else {
                head = newNode;
            };
        };

        void display(){
            ListNode *temp = head;
            while(temp){
                std::cout<<temp->value<<' '<<temp->next<<std::endl;
                temp = temp->next;
            };
            std::cout<<std::endl;
        };

    private:
        struct ListNode {
            int value;
            ListNode *next;
        };
        ListNode *head = NULL;
        
};


int main(void){

    List list;
    list.push_back(6);
    list.push_back(4);
    list.push_back(1);
    list.push_back(2);
    list.display();

};