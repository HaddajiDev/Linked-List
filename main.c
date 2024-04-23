// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

void insert_new_value(struct node** head_ref, int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode -> value = value;
    newNode -> next = (*head_ref);
    (*head_ref) = newNode;
}

int Search_Node(struct node** head_ref, int key){
    struct node *current = *head_ref;
    
    while(current != NULL){
        if(current -> value == key) return 1;
        {
            current = current -> next;
        }
    }
    
    return 0;
}

void Delete_Node(struct node** head_ref, int key){
    struct node *temp = *head_ref, *prev;
    
    if(temp != NULL && temp -> value == key){
        *head_ref = temp -> next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp -> value != key){
        prev = temp;
        temp = temp -> next;
    }
    
    if(temp == NULL) return;
    
    prev -> next = temp -> next;
    free(temp);
}

void Sort_list(struct node** head_ref){
    struct node *current = *head_ref, *index = NULL;
    int temp;
    
    if(head_ref == NULL) return;
    {
        while(current != NULL){
            index = current -> next;
            while(index != NULL){
                if(current -> value > index -> value){
                    temp = current -> value;
                    current -> value = index -> value;
                    index -> value = temp;
                }
                index = index -> next;
            }
            current = current -> next;
        }
    }
}

void Print_List(struct node* p){
    
    while(p != NULL){
        printf("%d \n", p -> value);
        p = p -> next;
    }
}

int Get_Length(struct node* head_ref){
    int count = 0;
    while(head_ref != NULL){
        count++;
        head_ref = head_ref -> next;
    }

    return count;
}

int Get_Tail(struct node* head_ref){
    for(int i = 0; i < Get_Length(head_ref); i++){
        if(head_ref == NULL){
            return head_ref -> value;
        }
    }
    return 0;
}

int main() {
    struct node *head = NULL;
    
    for(int i = 0; i < 10; i++){
        insert_new_value(&head ,i);
    }    
    //Delete_Node(&head, 2);
    //Sort_list(&head);
    Print_List(head);
    printf("%s", Search_Node(&head, 0) ? "true" : "false");

    printf("%d lenght \n", Get_Length(head));
    printf("head : %d \n", head -> value);
    printf("tail : %d", Get_Tail(head));
    return 0;
}