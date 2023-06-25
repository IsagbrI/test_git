#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "24.h"


int main() {
    List* list = createList();
    NodeList* node_list = NULL; 


    Tree* tree = createTree();
    NodeTree* node_tree = NULL;
    Vector* vector = createVector();
    Node* node = NULL;

    char* data = "a * b + a * b * c + a * b * e * f" ;
    for (int i = 0; data[i] != '\0'; ++i) {

        if (data[i] != ' ') {
            push_back(vector, createNode(data[i]));

        }
    }
    print(vector);
    test(vector, '*');
    test(vector, '+');
    print(vector);
    node_tree = vector->left_node->node;
    deleteVector(vector);
    tree->root = node_tree;
    printTree(tree->root, 2);
    printf("FIND multipliers\n");
    find_take_out_multipliers(tree->root, list, true);
    print_list(list);
    take_out_multipliers(tree->root, list);
    take_out_multipliers_2(tree, list);

    print_tree_to_expression(tree);


    return 0;
}