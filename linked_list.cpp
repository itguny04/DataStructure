#include <iostream>
#include <stdlib.h>

// push(O), pop(O), remove(O), insert(O), get(O) / getSize(O), isEmpty(O), printAll(O)

typedef struct List {
    struct List* next;
    int data;
} List;

List* init();

List* push(List* head, int data);
int pop(List* head);
int get(List* head, int index);
void insert(List* head, int index, int data);
void remove(List* head, int index);

void printAllList(List* head);
bool isEmpty(List* head);
int getListSize(List* head);


int main(void){
    bool list_status;
    int data, index;
    std::string msg;
  
    List* List = init();

    /*
    insert(List, 0, 20);
    push(List, 100);
    push(List, 50);
    insert(List, 3, 20);
    insert(List, 4, 50);
    printAllList(List);
    */
  
    /*
    push(List, 100);
    push(List, 10);
    push(List, 1);
    insert(List, 1, 1000);
    printAllList(List);
    */

    /*
    push(List, 100);
    get(List, 0);
    */
  
    return 0;
}

// List 생성
List* init() {
    List* head = (List*)malloc(sizeof(List));
    head->next = NULL;
    return head;
}

// List 기본 입출력
List* push(List* head, int data) {
    List* cur = head;

    while(true) {
        if(cur->next == NULL) {
            List* node = (List*)malloc(sizeof(List));
            cur->next = node;
            node->data = data;
            node->next = NULL;
            break;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int pop(List* head) {
    int data;
    List* cur_H = head->next;
    List* cur_L = head;

    if(isEmpty(head)) {
        return 0;
    }
  
    while(cur_H->next != NULL) {
        cur_H = cur_H->next;
        cur_L = cur_L->next;
    }
    
    data=cur_H->data;
    cur_L->next = NULL;
  
    return data;
}

int get(List* head, int index) {
    if(getListSize(head)<=index) {
        std::cout << "index error(index is same or big than List Size): " << std::endl;
        return 0;
    }
  
    List* cur = head->next;
    for(int i=0;i<index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

void remove(List* head, int index) {
    List* cur_H = head->next;
    List* cur_L = head;

    if(getListSize(head)<=index) {
        std::cout << "index error(index is same or big than List Size): " << std::endl;
        return ;
    }
  
    for(int i=0;i<index;i++) {
        cur_H = cur_H->next;
        cur_L = cur_L->next;
    }

    cur_L->next = cur_H->next;
}

void insert(List* head, int index, int data) {
    List* cur_H = head->next;
    List* cur_L = head;

    if(getListSize(head)<index) {
        std::cout << "index error(index is same or big than List Size): " << getListSize(head) << std::endl;
        return ;
    }
  
    for(int i=0;i<index;i++) {
        cur_H = cur_H->next;
        cur_L = cur_L->next;
    }

    List* node = (List*)malloc(sizeof(List));
    node->data = data;
    node->next = cur_H;
    cur_L->next = node;
}

// List 그 외 기능
void printAllList(List* head) {
    List* cur = head->next;

    while(true) {
        if(cur->next == NULL) {
            std::cout << cur->data << std::endl;  
            break;
        }else{
            std::cout << cur->data << std::endl;  
            cur = cur->next;
        } 
    }
}

bool isEmpty(List* head) {
    if(head->next == NULL) {
        return true;
    } else {
        return false;
    }
}

int getListSize(List* head){
    int count = 1;
    List* cur = head->next;
    if(isEmpty(head)) {
        return 0;
    } else {
        while(cur->next != NULL) {
            count++;
            cur = cur->next;
        }
    }

    return count;
}
