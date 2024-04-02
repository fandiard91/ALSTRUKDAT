#include <stdio.h>
#include <stdlib.h>

struct LetterNode {
    char letter; 
    struct LetterNode* next; 
};

int main() {
    
    struct LetterNode node1 = {'I', NULL};
    struct LetterNode node2 = {'N', NULL};
    struct LetterNode node3 = {'F', NULL};
    struct LetterNode node4 = {'O', NULL};
    struct LetterNode node5 = {'R', NULL};
    struct LetterNode node6 = {'M', NULL};
    struct LetterNode node7 = {'A', NULL};
    struct LetterNode node8 = {'T', NULL};
    struct LetterNode node9 = {'I', NULL};
    struct LetterNode node10 = {'K', NULL};
    struct LetterNode node11 = {'A', NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = &node9;
    node9.next = &node10;
    node10.next = &node11;
    node11.next = NULL;

    printf("Output: ");
    struct LetterNode* currentNode = &node1;
    while (currentNode != NULL) {
        printf("%c", currentNode->letter);
        currentNode = currentNode->next;
    }
    printf("\n");

    return 0;
}
