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
  print_matrix(test);
  add_edge(test, 1, 2, 3, 4, 5, 6);
  print_matrix(test);
  //edges = new_matrix(4, 4);
  //transform = new_matrix(4, 4);

  
  //free_matrix( transform );
  //free_matrix( edges );
}  
