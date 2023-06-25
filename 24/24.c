#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "24.h"



// Создание нового узла
NodeTree* createNodeTree(char value) {
    NodeTree* newNodeTree = (NodeTree*)malloc(sizeof(NodeTree));
    newNodeTree->value = value;
    newNodeTree->parent = NULL;
    newNodeTree->left = NULL;
    newNodeTree->right = NULL;
    return newNodeTree;
}


// Создание вектора
Tree* createTree() {
    Tree* newTree = (Tree*)malloc(sizeof(Tree));
    newTree->root = NULL;
}



// Вывод дерева с отступами
void printTree(NodeTree* root, int indent) {
    if (root == NULL) {
        return;
    }
    printTree(root->right, indent + 4);
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("%c\n", root->value);
    printTree(root->left, indent + 4);
}



// Создание нового узла
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->node = createNodeTree(value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



// Создание вектора
Vector* createVector() {
    Vector* newVector = (Vector*)malloc(sizeof(Vector));
    newVector->count_of_elem = 0;
    newVector->left_node = NULL;
}

// Функция проврки наличия элементов в векторе
bool isEmpty(Vector* vector) {
    return (vector->count_of_elem == 0);
}


// Функция вставки элементов в конец вектора
void push_back(Vector* vector, Node* new_node) {
    vector->count_of_elem++;
    if (vector->left_node == NULL) 
        vector->left_node = new_node;
    else {
        Node* node = vector->left_node;
        while (node->right != NULL) {
            node = node->right;
        }
        node->right = new_node;
        new_node->left = node;
    }
}

// Функция удаления элемента из конца дека
void pop_back(Vector* vector) {
    if (!isEmpty(vector)) {
        vector->count_of_elem--;
        Node* node = vector->left_node;
        if (vector->count_of_elem != 0) {
            while (node->right != NULL) {
                node = node->right;
            }
            Node* node_left = node->left;
            free(node);
            node_left->right = NULL;
        } else {
            free(node);
            vector->left_node = NULL;
        }
    }
}


// Функция удаления вектора
void deleteVector(Vector* vector) {
    while (!isEmpty(vector)) {
        pop_back(vector);
    } 
    free(vector);
}


// Функция вывода вектора
void print(Vector* vector) {
    if (!isEmpty(vector)) {
        Node* temp_node = vector->left_node;
        while (temp_node->right != NULL) {
            printf("%c ", temp_node->node->value);
            temp_node = temp_node->right;
        }
        printf("%c\n", temp_node->node->value);
    }
    printf("----------------------\n");
}


// Функция преобразования вектора в дерево
void test(Vector* vector, char symbol) {
    if (!isEmpty(vector)) {
        Node* temp_node_vector = vector->left_node;
        Node* temp = NULL;
        NodeTree* temp_node_tree = NULL;
        while (temp_node_vector != NULL) {
            temp_node_tree = temp_node_vector->node;
            if (temp_node_tree->value == symbol) {
                // формируем связи узлов дерева
                temp_node_tree->left = temp_node_vector->left->node;
                temp_node_tree->right = temp_node_vector->right->node;
                temp_node_vector->left->node->parent = temp_node_tree;
                temp_node_vector->right->node->parent = temp_node_tree;
                // удаляем узлы вектора
                // левый
                temp = temp_node_vector->left;
                if (temp->left == NULL) {
                    vector->left_node = temp_node_vector;
                } else {
                    temp->left->right = temp_node_vector;
                }
                temp_node_vector->left = temp->left;
                free(temp);              
                vector->count_of_elem--;
                // правый
                temp = temp_node_vector->right;
                if (temp->right != NULL) {
                    temp->right->left = temp_node_vector;
                } 
                temp_node_vector->right = temp->right;
                free(temp);
                vector->count_of_elem--;
            }
            temp_node_vector = temp_node_vector->right;
            // print(vector);
        }
    }
    printf("Done\n");
}


// Создание нового узла
NodeList* createNodeList(char value) {
    NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


// Создание вектора
List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    newList->count_of_elem = 0;
    newList->left_node = NULL;
}

// Функция проврки наличия элементов в векторе
bool isEmptyList(List* list) {
    return (list->count_of_elem == 0);
}


void pop_back_list(List* list) {
    if (!isEmptyList(list)) {
        list->count_of_elem--;
        NodeList* node = list->left_node;
        if (list->count_of_elem != 0) {
            while (node->right != NULL) {
                node = node->right;
            }
            NodeList* node_left = node->left;
            free(node);
            node_left->right = NULL;
        } else {
            free(node);
            list->left_node = NULL;
        }
    }
}


// Функция удаления листа
void deleteList(List* list) {
    while (!isEmptyList(list)) {
        pop_back_list(list);
    } 
    free(list);
}


// Функция вставки элементов в конец вектора
void push_back_list(List* list, NodeList* new_node) {
    list->count_of_elem++;
    if (list->left_node == NULL) 
        list->left_node = new_node;
    else {
        NodeList* node = list->left_node;
        while (node->right != NULL) {
            node = node->right;
        }
        node->right = new_node;
        new_node->left = node;
    }
}

// Функция удаления элемента из листа
void del(List* list, char symbol) {
    if (!isEmptyList(list)) {
        list->count_of_elem--;
        NodeList* node = list->left_node;
        if (node->value == symbol) {
            list->left_node = node->right;
            node->right->left = node->left;
            free(node);
        } else {
            node = node->right;
            while (node->value != symbol) {
                node = node->right;
            }
            if (node->right != NULL) {
                node->right->left = node->left;
            }
            node->left->right = node->right;
            free(node);
        }
    }
}


// Функция вывода листа
void print_list(List* list) {
    if (!isEmptyList(list)) {
        NodeList* temp_node = list->left_node;
        while (temp_node->right != NULL) {
            printf("%c ", temp_node->value);
            temp_node = temp_node->right;
        }
        printf("%c\n", temp_node->value);
    }
    printf("----------------------\n");
}


void find_multipliers(NodeTree* node_tree, List* multipliers) {
    if (node_tree->left == NULL && node_tree->right == NULL) {
        push_back_list(multipliers, createNodeList(node_tree->value));
        return;
    }
    find_multipliers(node_tree->left, multipliers);
    find_multipliers(node_tree->right, multipliers);
}


void intersection_list(List* list_1, List* list_2) {
    NodeList* node_list_1 = list_1->left_node;
    NodeList* node_list_2 = list_2->left_node;
    NodeList* temp = NULL;
    bool is_find;
    while (node_list_1 != NULL) {
        is_find = false;
        node_list_2 = list_2->left_node;
        while (node_list_2 != NULL) {
            if (node_list_1->value == node_list_2->value) {
                is_find = true;
                break;
            }
            node_list_2 = node_list_2->right;
        }
        temp = node_list_1;
        node_list_1 = node_list_1->right;
        if (!is_find) {
            del(list_1, temp->value);
        }
    }
}


void find_take_out_multipliers(NodeTree* node_tree, List* multipliers, bool first_start) {
    List* multipliers_2 = createList();
    if (first_start) {
        find_multipliers(node_tree->right, multipliers);
    } else {
        find_multipliers(node_tree->right, multipliers_2);
        intersection_list(multipliers, multipliers_2);
    }
    List* multipliers_3 = createList();
    if (node_tree->left->value == '*') {
        find_multipliers(node_tree->left, multipliers_3);
        intersection_list(multipliers, multipliers_3);
    } else {
        find_take_out_multipliers(node_tree->left, multipliers, false);
    }
}


void del_node(NodeTree* node_tree, char multiplier) {
    if (node_tree->left == NULL && node_tree->right == NULL) {
        if (node_tree->value == multiplier) {
            NodeTree* temp_node = node_tree->parent;
            if (temp_node->value == '+') {
                node_tree->value = '1';
            } else if (temp_node->parent->value == '+') {
                // if (temp_node->parent->left->right->value == multiplier) {
                //     temp_node->parent->left = temp_node->left;
                //     temp_node->left->parent = temp_node->parent;
                //     free(temp_node->right);
                //     free(temp_node);
                if (temp_node->right->value == multiplier) {
                    temp_node->parent->right = temp_node->left;
                    temp_node->left->parent = temp_node->parent;
                    free(temp_node->right);
                    free(temp_node);
                } else {
                    temp_node->parent->right = temp_node->right;
                    temp_node->right->parent = temp_node->parent;
                    free(temp_node->left);
                    free(temp_node);
                }
            } else {
                if (temp_node->right->value == multiplier) {
                    temp_node->parent->left = temp_node->left;
                    temp_node->left->parent = temp_node->parent;
                    free(temp_node->right);
                    free(temp_node);
                } else {
                    temp_node->parent->left = temp_node->right;
                    temp_node->right->parent = temp_node->parent;
                    free(temp_node->left);
                    free(temp_node);
                }
            }
            //node_tree->value = '1';
        }
        return;
    }
    del_node(node_tree->left, multiplier);
    del_node(node_tree->right, multiplier);
}


void take_out_multiplier(NodeTree* node_tree, char multiplier) {
    del_node(node_tree->right, multiplier);
    if (node_tree->left->value == '*') {
        del_node(node_tree->left, multiplier);
    } else {
        take_out_multiplier(node_tree->left, multiplier);
    }
}

void take_out_multipliers(NodeTree* node_tree, List* multipliers) {
    NodeList* multiplier = multipliers->left_node;
    while (multiplier != NULL) {
        take_out_multiplier(node_tree, multiplier->value);
        multiplier = multiplier->right;
        printTree(node_tree, 2);
        printf("-----------------\n");
    }
}


void take_out_multipliers_2(Tree* tree, List* multipliers) {
    NodeList* multiplier = multipliers->left_node;
    NodeTree* node_tree = NULL;
    while (multiplier != NULL) {
        node_tree = createNodeTree('x');
        node_tree->left = tree->root;
        tree->root = node_tree; 
        node_tree = createNodeTree(multiplier->value);
        tree->root->right = node_tree;
        node_tree->parent = tree->root;
        multiplier = multiplier->right;
        printTree(tree->root, 2);
        printf("-----------------\n");
    }
}

void print_multi(NodeTree* node_tree, List* elements) {
    if (node_tree->left == NULL && node_tree->right == NULL) {
        push_back_list(elements, createNodeList(node_tree->value));
        return;
    }
    print_multi(node_tree->left, elements);
    print_multi(node_tree->right, elements);
}


void print_tree_to_expression(Tree* tree) {
    List* elements;
    NodeList* node_list = NULL;
    NodeTree* node_tree = tree->root;
    int count_of_brackets = 0;
    while (node_tree->left != NULL) {
        if (node_tree->right->value != '*') {
            printf("%c ", node_tree->right->value);
        } else {
            elements = createList();
            print_multi(node_tree->right, elements);
            node_list = elements->left_node;
            while (node_list->right != NULL) {
                printf("%c * ", node_list->value);
                node_list = node_list->right;
            }
            printf("%c ", node_list->value);
            deleteList(elements);
        }
        if (node_tree->value == 'x') {
            printf("* (");
            ++count_of_brackets;
        } else {
            printf("%c ", node_tree->value);
        }
        node_tree = node_tree->left;
    }
    printf("%c", node_tree->value);
    for (int i = 0; i < count_of_brackets; ++i) {
        printf(")");
    }

}