#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *test;
  struct matrix *edges;
  struct matrix *transform;

  test = new_matrix(4,4);
  printf("New Matrix\n");
  print_matrix(test);
  add_edge(test, 1, 2, 3, 4, 5, 6);
  printf("Adding (1, 2, 3) and (4, 5, 6)\n");
  print_matrix(test);
  add_edge(test, 7, 8, 9, 10, 11, 12);
  printf("Adding (7, 8, 9) and (10, 11, 12)\n");
  print_matrix(test);
  add_edge(test, 13, 14, 15, 16, 17, 18);
  printf("Identity Matrix\n");
  ident(test);
  print_matrix(test);
  printf("Scalar Multiplication by 2\n");
  scalar_mult(2, test);
  print_matrix(test);
  //edges = new_matrix(4, 4);
  //transform = new_matrix(4, 4);

  
  //free_matrix( transform );
  //free_matrix( edges );
}  
