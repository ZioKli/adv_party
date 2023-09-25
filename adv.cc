/*
 * Headstart for Ostermann's shell project
 *
 * Shawn Ostermann -- Sept 11, 2022
 */

#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

// types and definitions live in "C land" and must be flagged
extern "C" {
#include "adv.h"
//#include "parser.tab.h"
extern "C" void yyset_debug(int d);
}

// global debugging flag
int debug = 0;

int main(int argc, char *argv[]) {
  if (debug)
    yydebug = 1; /* turn on ugly YACC debugging */
  /* parse the input file */
  yyparse();

  exit(0);
}

void print_bag_type(bag_type t) {
  switch (t) {
  case LEATHER:
    printf(" leather ");
    break;
  case SILK:
    printf(" silk ");
    break;
  case CANVAS:
    printf(" canvas ");
    break;
  }
}

void print_bag(struct adv_bag bag) {
  if (bag.first_item == NULL) {
    printf("an empty");
    print_bag_type(bag.type);
    printf("bag\n");
    return;
  }


  printf("a");
  print_bag_type(bag.type);
  printf("bag with ");
  printf("%d %s", bag.first_item->count, bag.first_item->i_name);

  struct item *i = bag.first_item->next;
  while (i != NULL) {
    if (i->next != NULL) {
      printf(", %d %s", i->count, i->i_name);
    }
    else {
      printf(", and %d %s", i->count, i->i_name);
    }
    i = i->next;
  }
}

void print_party_member(struct adventurer *member) {
  printf("%s %s, ", member->portrait, member->name);
  printf("%s has ", member->name);
  print_bag(member->bag);
  printf("\n");
}

void print_party(struct party a_party) {
  printf("Party Leader: %s %s\n", a_party.leader_portrait, a_party.leader_name);
  printf("Party:\n");
  struct adventurer *member = a_party.adventurers;
  while (member != NULL) {
    print_party_member(member);
    member = member->next;
  }
}
