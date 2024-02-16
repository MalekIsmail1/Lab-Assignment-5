#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

char* toCString(node* head) {
    int len = length(head);
    char* str = (char*)malloc(len + 1); // +1 for null terminator
    int i = 0;
    while (head != NULL) {
        str[i++] = head->letter;
        head = head->next;
    
    }
    str[i] = '\0'; // null terminator
    return str;
}

// Inserts character to the linkedlist.
// If the linked list is head -> |a|->|b|->|c|,
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|.
void insertChar(node** pHead, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = *pHead;
    *pHead = newNode;
}

// Deletes all nodes in the linkedList.
void deleteList(node** pHead) {
    while (*pHead != NULL) {
        node* temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
}

int main(void) {
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("/Users/mac/Downloads/input.txt", "r");

    if (inFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is: %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!\n");
            break;
        }
    }

    fclose(inFile);

    return 0;
}
