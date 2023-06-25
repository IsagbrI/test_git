#ifndef _24_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _24_


typedef struct NodeTree {
    char value;
    struct NodeTree* parent;
    struct NodeTree* left;
    struct NodeTree* right;
} NodeTree;


// Создание нового узла
NodeTree* createNodeTree(char value);


// Описание структуры вектора
typedef struct Tree {
    struct NodeTree* root;
} Tree;


// Создание вектора
Tree* createTree();


// Вывод дерева с отступами
void printTree(NodeTree* root, int indent);


// Описание структуры узла
typedef struct Node {
    struct NodeTree* node;
    struct Node* left;
    struct Node* right;
} Node;

// Создание нового узла
Node* createNode(char value);

// Описание структуры вектора
typedef struct Vector {
    int count_of_elem;
    struct Node* left_node;
} Vector;


// Создание вектора
Vector* createVector();

// Функция проврки наличия элементов в векторе
bool isEmpty(Vector* vector);


// Функция вставки элементов в конец вектора
void push_back(Vector* vector, Node* new_node);

// Функция удаления элемента из конца дека
void pop_back(Vector* vector);


// Функция удаления вектора
void deleteVector(Vector* vector);


// Функция вывода вектора
void print(Vector* vector);


// Функция преобразования вектора в дерево
void test(Vector* vector, char symbol);


// Описание структуры узла
typedef struct NodeList {
    char value;
    struct NodeList* left;
    struct NodeList* right;
} NodeList;

// Создание нового узла
NodeList* createNodeList(char value);

// Описание структуры вектора
typedef struct List {
    int count_of_elem;
    struct NodeList* left_node;
} List;


// Создание вектора
List* createList();

// Функция проврки наличия элементов в векторе
bool isEmptyList(List* list);


void pop_back_list(List* list);


// Функция удаления листа
void deleteList(List* list);


// Функция вставки элементов в конец вектора
void push_back_list(List* list, NodeList* new_node);

// Функция удаления элемента из листа
void del(List* list, char symbol);


// Функция вывода листа
void print_list(List* list);


void find_multipliers(NodeTree* node_tree, List* multipliers);


void intersection_list(List* list_1, List* list_2);


void find_take_out_multipliers(NodeTree* node_tree, List* multipliers, bool first_start);


void del_node(NodeTree* node_tree, char multiplier);


void take_out_multiplier(NodeTree* node_tree, char multiplier);

void take_out_multipliers(NodeTree* node_tree, List* multipliers);


void take_out_multipliers_2(Tree* tree, List* multipliers);

void print_multi(NodeTree* node_tree, List* elements);


void print_tree_to_expression(Tree* tree);


#endif