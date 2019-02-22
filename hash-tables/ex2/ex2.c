#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
// #include "hashtable.c"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  //loop through number of tickets
  for (int i = 0; i < length; i++)
  {
    //add each ticket to ht source as key, destination as value
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  //Set initial route where source == NONE
  //printf("Trip starts: %s\n", hash_table_retrieve(ht, "NONE"));
  route[0] = hash_table_retrieve(ht, "NONE");
  for (int i = 1; i < length; i++)
  {
    //Add all stops by retrieving the destination from previous stop
    //printf("Next stop: %s\n", hash_table_retrieve(ht, route[i - 1]));
    route[i] = hash_table_retrieve(ht, route[i - 1]);
  }

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
