#include <stdio.h>

// allows other source files to use the maxLevel variable
extern int maxLevel;

// function definitions
Node *makeNode(double x, double y, int level);
void makeChildren(Node *parent, int maxLevel);
void growQuadtree(Node *node);
