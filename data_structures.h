#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_q Node_q;
typedef struct { float x, y, m; } Point;

struct Node_t {
    Node_t *children[4];
    Point *value;
};

struct Node_q {
    Node_t *value;
    Node_q *next;
};

typedef struct {int size; Node_q *head;} Queue;


void print_point(Point *p) {
    printf("{x:%f, y:%f, m:%f}", p->x, p->y, p->m);
}


void print_node_t(Node_t *n) {
    printf("children: [%p, %p, %p, %p], value: ", n->children[0], n->children[1], n->children[2], n->children[3]);
    print_point(n->value);
}


void print_queue(Queue *q) {
    Node_q* cur = q->head;
    for(int i = 0; i < q->size; i++) {
        printf("%d {", i);
        print_node_t(cur->value);
        printf("}\n");
        cur = cur->next;
    }
}


Node_t* init_node_t_outer(Point *p) { // some memory access issue here, probably with the array indexing
    Node_t* out = (Node_t*) malloc(sizeof(Node_t*));
    out->value = p;
    out->children[0] = NULL;
    return out;
}

Node_t* init_node_t_inner(Node_t* arr[4]){
    Node_t* out = (Node_t*) malloc(sizeof(Node_t*));
    out->value = NULL;
    for(int i = 0; i < 4; i++) {
        out->children[i] = arr[i];
    }
    return out;
}


Queue* init_q() { // assume pointer is coming in empty, malloc it and assign size = 0
    Queue *q = (Queue*) malloc(sizeof(Queue*));
    q->size = 0;
    q->head = NULL;
    return q;
}


void q_enq(Queue *q, Node_t *n) {
    Node_q *new_head = (Node_q*) malloc(sizeof(Node_q*));
    
    new_head->value = n;
    new_head->next = q->head;
    q->head = new_head;
    q->size++;
}


Node_t* q_deq(Queue *q) {
    Node_q *cur = q->head;
    Node_q *prev = (Node_q*) malloc(sizeof(Node_q*));
    for(int i = 0; i < (q->size)-1; i++) {
        prev = cur;
        cur = cur->next;
    }
    Node_t *out = cur->value;
    prev->next = NULL;
    q->size--;
    return out;
}


Node_t* q_get(Queue *q, int index) {
    if(index > q->size) {
        index = q->size;
    }
    else if(index < 0 ) {
        if(index < -q->size){
            index = 0;
        }
    }
    Node_q *cur = (Node_q*) malloc(sizeof(Node_q*));
    cur = q->head;
    for(int i = 0; i < index; i++){
        cur = cur->next;
    }

    Node_t* out = cur->value;
    free(cur);
    return out;
}


void preorder_traversal(Node_t *n) { // currently returns pointer of pointers; consider add function pointer param
    if(n != NULL) {

    }
}