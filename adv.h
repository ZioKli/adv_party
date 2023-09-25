/*
 * Adventuring party header file
 */

enum bag_type {
  LEATHER,
  SILK,
  CANVAS,
};

struct item {
  int count;
  char *i_name;
  struct item *next;
};

struct adv_bag {
  enum bag_type type;
  struct item* first_item;
};

struct adventurer {
  char *name;
  char *portrait;
  struct adv_bag bag;
  struct adventurer *next;
};

struct party {
  char *leader_name;
  char *leader_portrait;
  struct adventurer *adventurers;
};


void print_bag_type(enum bag_type t);
void print_bag(struct adv_bag bag);
void print_party_member(struct adventurer *member);
void print_party(struct party a_party);

/* externals */
extern int yydebug;
extern int debug;
extern int lines; // defined and updated by parser, used by bash.cc

/* you should use THIS routine instead of malloc */
void *MallocZ(int numbytes);

/* global routine decls */
int yyparse(void);
