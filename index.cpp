#include <iostream>



int main(void){

    int *list1 = (int*) malloc(3 * sizeof(int));
    int *list2 = (int*) malloc(3 * sizeof(int));
    list1[0] = 8;
    list1[1] = 4;
    list1[2] = 3;
    list2[0] = 5;
    list2[1] = 1;
    list2[2] = 9;
    for(int i = 0; i < 3; i++){
        std::cout<<list1[i]<<" "<<&list1[i]<<std::endl;
    }
    for(int i = 0; i < 3; i++){
        std::cout<<list2[i]<<" "<<&list2[i]<<std::endl;
    }
    list1[3] = 7;
    for(int i = 0; i < 3; i++){
        std::cout<<list1[i]<<" "<<&list1[i]<<std::endl;
    }
    for(int i = 0; i < 3; i++){
        std::cout<<list2[i]<<" "<<&list2[i]<<std::endl;
    }
    free(list1);
    free(list2);
    
};