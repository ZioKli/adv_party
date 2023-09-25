/*
 * Adventuring party header file
 */

#define MAX_BAG_SIZE 500

/* This is the definition of a command */

enum bag_type{
  LEATHER,
  SILK,
  CANVAS,  
};

struct item {
  int count;
  char *i_name;
};

struct adv_bag {
  bag_type type;
  item contents[MAX_BAG_SIZE];
};

struct adv_p {
  char * name;
  struct adv_bag bag;
  struct adv_p *next;
};

struct party {
  char *leader_name;
  struct adv_p *adventurers;
};

/* externals */
extern int yydebug;
extern int debug;
extern int lines; // defined and updated by parser, used by bash.cc

/* you should use THIS routine instead of malloc */
void *MallocZ(int numbytes);

/* global routine decls */
int yyparse(void);
