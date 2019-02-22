#ifndef _ex_1_h_
#define _ex_1_h_

typedef struct Answer
{
  int index_1;
  int index_2;
} Answer;

Answer *get_indices_of_item_weights(int *weights, int n, int limit);
void print_answer(Answer *answer);

#endif