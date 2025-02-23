#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treeStructure.h"
#include "writeTree.h"

// write out the (x,y) corners of the node
void printOut(FILE *fp, Node *node) {
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0, -level);

  fprintf(fp, " %g %g\n", x, y);
  fprintf(fp, " %g %g\n", x + h, y);
  fprintf(fp, " %g %g\n", x + h, y + h);
  fprintf(fp, " %g %g\n", x, y + h);
  fprintf(fp, " %g %g\n\n", x, y);

  return;
}

// recursively visit the leaf nodes
void writeNode(FILE *fp, Node *node) {
  int i;

  if (node->child[0] == NULL)
    printOut(fp, node);
  else {
    for (i = 0; i < 4; ++i) {
      writeNode(fp, node->child[i]);
    }
  }

  return;
}

// write out the tree to file 'quad.out'
void writeTree(Node *head) {
  FILE *fp = fopen("quad.out", "w");
  writeNode(fp, head);
  fclose(fp);

  return;
}

// free all of the memory allocated for the Nodes
void destroyTree(Node *node) {
  int i;

  // if the node does not have any children then the memory allocated for it is freed
  if (node->child[0] == NULL)
    free(node);
  else {
    for (i = 0; i < 4; ++i) {
      destroyTree(node->child[i]);
    }

    free(node);
  }

  return;
}
