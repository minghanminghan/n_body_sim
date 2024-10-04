#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_structures.h"

//implement tree traversal for toString (try to avoid oop)


/*
// core physics: need to implement pairwise
a = F/m
v_new = v_old + dt
p_new = p_old + v_new*dt
*/

int main(void) {
    Point p[4] = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1}};
    /*
    Node_t n1, n2, n3, n4;
    n1.value = &p[0];
    n2.value = &p[1];
    n3.value = &p[2];
    n4.value = &p[3];
    */
    /*
    Node_t *n0 = init_node_t_outer(&p[0]);
    Node_t *n1 = init_node_t_outer(&p[1]);
    Node_t *n2 = init_node_t_outer(&p[2]);
    Node_t *n3 = init_node_t_outer(&p[3]);
    */
    Node_t *n0, *n1, *n2, *n3, *n4, *n5;
    Node_t *outer[4] = {n1, n2, n3, n4};
    n0 = init_node_t_inner(outer);

    print_node_t(n0);

/*
    Queue *q = init_q();
    q_enq(q, n0);

    Node_t *t1 = q_deq(q);
    //print_node_t(t1);
    print_queue(q);

    q_enq(q, n1);
    q_enq(q, n2);
    q_enq(q, n3);
    print_queue(q);
 */

    return 0;
}
/*
int main(void) {
    // srand(time(NULL));
    Point points[1] = {{(float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX, 1.0}};

    Point *p_rand = &points[0];

    Node_t children[4] = {NULL, NULL, NULL, NULL};

    Node_t *n = (Node_t*) malloc (sizeof(Node_t*));
    n->value = p_rand;
    print_node(n);
    return 0;
};
*/