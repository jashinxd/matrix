#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  
  screen s;
  color c;


  c.red = 0;
  c.green = 0;
  c.blue = 255;

  clear_screen(s);
 
  struct matrix *test;
  struct matrix *test2;
  struct matrix *edges;
  struct matrix *transform;

  /*
  test = new_matrix(4,4);
  test2 = new_matrix(4,1);
  printf("New Matrix\n");
  print_matrix(test);
  add_edge(test, 1, 2, 3, 4, 5, 6);
  printf("Adding (1, 2, 3) and (4, 5, 6)\n");
  print_matrix(test);
  add_edge(test, 7, 8, 9, 10, 11, 12);
  printf("Adding (7, 8, 9) and (10, 11, 12)\n");
  print_matrix(test);
  printf("Identity Matrix\n");
  ident(test);
  print_matrix(test);
  printf("Scalar Multiplication by 2\n");
  scalar_mult(2, test);
  print_matrix(test);
  printf("2nd Matrix\n");
  add_point(test2, 7, 8, 9);
  print_matrix(test2);
  //printf("Multiplying 1st matrix and second matrix\n");
  //matrix_mult(test, test2);
  //print_matrix(test2);
  printf("Translate 2nd matrix by 2, 2, 2\n");
  struct matrix * trans = make_translate(2, 2, 2);
  matrix_mult(trans, test2);
  print_matrix(test2);
  printf("Scale 2nd matrix by 2, 2, 2\n");
  struct matrix * scale = make_scale(2, 2, 2);
  matrix_mult(scale, test2);
  print_matrix(test2);
  printf("Rotating 2nd matrix by 30 degrees about x axis\n");
  struct matrix * rotX = make_rotX(30);
  matrix_mult(rotX, test2);
  print_matrix(test2);
  printf("Rotating 2nd matrix by 30 degrees about y axis\n");
  struct matrix * rotY = make_rotY(30);
  matrix_mult(rotY, test2);
  print_matrix(test2);
  printf("Rotating 2nd matrix by 30 degrees about z axis\n");
  struct matrix * rotZ = make_rotZ(30);
  matrix_mult(rotZ, test2);
  print_matrix(test2);
  */
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  //print_matrix(edges);
  /*
  add_edge(edges, -1 * 100, -1 * 100, 0, -1 * 100, 100, 0);
  add_edge(edges, -1 * 100, 100, 0, 100, 100, 0);
  add_edge(edges, 100, 100, 0, 100, -1 * 100, 0);
  printf("cols = %d\n", edges->cols);
  add_edge(edges, 100, -1 * 100, 0, -1 * 100, -1 * 100, 0);
  print_matrix(edges);
  */

  add_edge(edges,0,0,0,0,30,0);
  print_matrix(edges);
  printf("cols = %d\n", edges->cols);
  printf("lastcol = %d\n", edges->lastcol);
  add_edge(edges,0,30,0,30,30,0);
  print_matrix(edges);
  printf("cols = %d\n", edges->cols);
  printf("lastcol = %d\n", edges->lastcol);
  add_edge(edges,30,30,0,30,0,0);
  print_matrix(edges);
  printf("cols = %d\n", edges->cols);
  printf("lastcol = %d\n", edges->lastcol);
  add_edge(edges,30,0,0,0,0,0);
  print_matrix(edges);
  printf("cols = %d\n", edges->cols);
  printf("lastcol = %d\n", edges->lastcol);
  draw_lines(edges, s, c);

  int i;
  for (i = 0; i < 20; i++) {                                            
    transform = make_translate(2, 2, 0);
    matrix_mult( transform, edges );
    print_matrix(edges);
    draw_lines(edges, s, c);
    //printf("trans");
    transform = make_rotX(10);
    matrix_mult( transform, edges );
    draw_lines(edges, s, c);
    printf("rotX");
    transform = make_rotY(10);                                          
    matrix_mult( transform, edges );                                    
    draw_lines(edges, s, c);                                            
    printf("rotY");                                                     
    transform = make_rotZ(10);                                          
    matrix_mult( transform, edges );                                    
    draw_lines(edges, s, c);                                            
    printf("rotZz");                                                    
    transform = make_scale(1.1, 1.1, 1.1);                              
    matrix_mult( transform, edges );                                    
    draw_lines(edges, s, c);                                            
    printf("scale");                                                    
    transform = make_translate(10, 10, 0);                              
    matrix_mult( transform, edges );                                    
    draw_lines(edges, s, c);                                            
    printf("trans");
    c.red=(c.red + 21) % 256;
    c.green=(c.red + 12) % 256;
    c.blue=(c.red + 16) % 256;
    
  }           
  
  display(s);
  save_extension(s, "matrix.png");
  
  free_matrix( transform );
  free_matrix( edges );
}  
