#include "../hashtable.h"
// #include "../hashtable.c"
#include "../ex2.h"
// #include "../ex2.c"
#include "../../utils/utils.h"
#include "../../utils/minunit.h"

char *test_short_case()
{
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

  char *expected[] = {"PDX", "DCA", "NONE"};

  mu_assert(check_string_arrays(reconstruct_trip(tickets, 3), expected, 3, 3), "Your function did not return the expected output");

  return NULL;
}

char *test_long_case()
{
  Ticket **tickets = malloc(10 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "PIT";
  ticket_1->destination = "ORD";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "XNA";
  ticket_2->destination = "CID";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "SFO";
  ticket_3->destination = "BHM";
  tickets[2] = ticket_3;

  Ticket *ticket_4 = malloc(sizeof(Ticket));
  ticket_4->source = "FLG";
  ticket_4->destination = "XNA";
  tickets[3] = ticket_4;

  Ticket *ticket_5 = malloc(sizeof(Ticket));
  ticket_5->source = "NONE";
  ticket_5->destination = "LAX";
  tickets[4] = ticket_5;

  Ticket *ticket_6 = malloc(sizeof(Ticket));
  ticket_6->source = "LAX";
  ticket_6->destination = "SFO";
  tickets[5] = ticket_6;

  Ticket *ticket_7 = malloc(sizeof(Ticket));
  ticket_7->source = "CID";
  ticket_7->destination = "SLC";
  tickets[6] = ticket_7;

  Ticket *ticket_8 = malloc(sizeof(Ticket));
  ticket_8->source = "ORD";
  ticket_8->destination = "NONE";
  tickets[7] = ticket_8;

  Ticket *ticket_9 = malloc(sizeof(Ticket));
  ticket_9->source = "SLC";
  ticket_9->destination = "PIT";
  tickets[8] = ticket_9;

  Ticket *ticket_10 = malloc(sizeof(Ticket));
  ticket_10->source = "BHM";
  ticket_10->destination = "FLG";
  tickets[9] = ticket_10;

  char *expected[] = {"LAX", "SFO", "BHM", "FLG", "XNA", "CID", "SLC", "PIT", "ORD", "NONE"};

  mu_assert(check_string_arrays(reconstruct_trip(tickets, 10), expected, 10, 10), "Your function did not return the expected output");

  return NULL;
}

char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_short_case);
  mu_run_test(test_long_case);

  return NULL;
}

RUN_TESTS(all_tests);