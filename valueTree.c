#include "math.h"
#include "treeStructure.h"
#include "valueTree.h"
#include "buildTree.h"

#define MAX(a, b) ( ((a) > (b)) ? (a) : (b) )
#define MIN(a, b) ( ((a) < (b)) ? (a) : (b) )

int childrenAdded;
int falseResults;
double tolerance;
int choice;

// Define a function that is computed
// on the quadtree grid
//
// Given a location (x,y) return a value
//
// Choice allows different functions
// to be selected
double dataFunction(double x, double y, int choice) {
  double value;

  if (choice == 0)
    value = exp(-(y - x) * (y - x) / 0.01) + exp(-(x - y) * (x - y) / 0.01);

  else if (choice == 1)
    value = exp(-(x - 0.5) * (x - 0.5) / 0.01) + exp(-(y - 0.5) * (y - 0.5) / 0.01);

  else if (choice == 2)
    value = exp(-((x - 0.72) * (x - 0.72) + (y - 0.23) * (y - 0.23)) / 0.01);

  // default uniform data
  else
    value = 1.0;

  return value;
}

// Compute the max and min values
// of the data on the quadtree node
//
// If the difference is too big request
// the node is split into children
bool indicator(Node *node, double tolerance, int choice) {
  double v[4], vmin, vmax;
  double h = pow(2, -node->level);

  v[0] = dataFunction(node->xy[0], node->xy[1], choice);
  v[1] = dataFunction(h + node->xy[0], node->xy[1], choice);
  v[2] = dataFunction(node->xy[0], h + node->xy[1], choice);
  v[3] = dataFunction(h + node->xy[0], h + node->xy[1], choice);

  vmin = MIN( MIN( MIN(v[0], v[1]), v[2]), v[3]);
  vmax = MAX( MAX( MAX(v[0], v[1]), v[2]), v[3]);

  if ((vmax - vmin) < tolerance)
    return true;
  else
    return false;
}

// creates children for leaf nodes if the indicator function returns false
void addChildren(Node *node) {
  int i;

  // if the node does not have any children then the indicator function is executed
  if (node->child[0] == NULL) {
    if (indicator(node, tolerance, choice) == false) {
      makeChildren(node, maxLevel);
      childrenAdded += 4;
      falseResults += 1;
    }
  }
  else {
    for (i = 0; i < 4; ++i) {
      addChildren(node->child[i]);
    }
  }

  return;
}

// counts how many times the indicator function returns false when the addChildren funciton is called
// and re-runs the addChildren function if the number of false results is not 0
void monitorChildren(Node *node) {
 falseResults = 0;
 addChildren(node);

 if (falseResults != 0) {
   monitorChildren(node);
 }

 return;
}
