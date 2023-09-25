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
#include "parser.tab.h"
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

void doline(struct party *party) {
  printf("The leader of the party is %s")

}
