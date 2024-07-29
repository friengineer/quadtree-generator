//#include <stdio.h>
#include <stdbool.h>
//#include "treeStructure.h"

// allows other source files to use the childrenAdded variable
extern int childrenAdded;
extern int falseResults;
extern double tolerance;
extern int choice;

double dataFunction(double x, double y, int choice);
bool indicator(Node *node, double tolerance, int choice);
void addChildren(Node *node);
void monitorChildren(Node *node);
