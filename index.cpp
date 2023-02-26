#include <iostream>

class List {
    public:
        List(){
            head = NULL;
        }
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
            ListNode *newNode = (struct ListNode*) malloc(sizeof(ListNode));
            newNode->value = newValue;
            newNode->next = head;
            head = newNode;
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

        int pop_front(){
            if(isEmpty()) return -1;
            ListNode *temp = head;
            head = head->next;
            int deleteValue = temp->value;
            free(temp);
            return deleteValue;
        };

        int pop_back(){
            if(isEmpty()) return -1;
            ListNode *temp = head;
            while(temp->next->next){
                temp = temp->next;
            }
            int deleteValue = temp->next->value;
            free(temp->next);
            temp->next = NULL;
            return deleteValue;
        };

        void insert(int index, int value){
            if(index >= size()) {
                std::cout<<"Index is out of range, added at the back \n";
                push_back(value);
            } else {
                ListNode *newNode = (struct ListNode*) malloc(sizeof(ListNode));
                newNode->value = value;
                int i = 0;
                ListNode *temp = head;
                while( i != index - 1 ){
                    temp = temp->next;
                    i++;
                };
                newNode->next = temp->next;
                temp->next = newNode;
            }
        };

        int erase(int index){
            if(index >= size()) {
                std::cout<<"Index is out of range, removed from the back";
                pop_back();
            } else {
                ListNode *temp = head;
                int i = 0;
                while(i != index - 1){
                    temp = temp->next;
                    i++;
                }
                ListNode *erasedNode = temp->next;
                int erasedValue = temp->next->value;
                if(temp->next->next != NULL) temp->next = temp->next->next;
                free(erasedNode);
                return erasedValue;
            }
            return -1;
        };

        void display(){
            ListNode *temp = head;
            std::cout<<"Head: "<<head<<std::endl;
            while(temp){
                std::cout<<temp->value<<' '<<temp->next<<std::endl;
                temp = temp->next;
            };
            std::cout<<std::endl;
        };

        bool isEmpty(){
            if(head) return 0;
            else return 1;
        };

        int valueAt(int index){
            if(isEmpty()) return -1;
            if(index >= size()) return -1;
            int i = 0;
            ListNode *temp = head;
            while( i != index){
                i++;
                temp = temp->next;
            }
            return temp->value;
        };

        int front(){
            if(isEmpty()) return -1;
            else return head->value;
        };
        
        int back(){
            if(isEmpty()) return -1;
            else {
                ListNode *temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                return temp->value;
            }
        };

    private:
        struct ListNode {
            int value;
            ListNode *next;
        };
        ListNode *head;
        
};


int main(void){

    List list;
    list.push_front(2);
    list.push_back(6);
    list.push_front(3);
    list.push_back(4);
    list.push_back(1);
    list.push_back(2);
    list.push_front(9);
    list.insert(1,5);
    list.display();
    std::cout<<"Erased value at index '4': "<<list.erase(4)<<std::endl;
    list.display();
    std::cout<<"Value at index '0': "<<list.valueAt(0)<<std::endl;
    std::cout<<"isEmpty: "<<list.isEmpty()<<std::endl;
    std::cout<<"Size: "<<list.size()<<std::endl;
    std::cout<<"Value at the front: "<<list.front()<<std::endl;
    std::cout<<"Value at the back: "<<list.back()<<std::endl;
};