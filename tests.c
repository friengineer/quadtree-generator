#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "valueTree.h"
#include "tests.h"

void task1(Node *node) {
  maxLevel = 5;
  writeTree(node);
  destroyTree(node);
}

void task2(Node *node) {
  maxLevel = 5;
  growQuadtree(node);
  writeTree(node);
  destroyTree(node);
}

void task3(Node *node) {
  maxLevel = 3;
  growQuadtree(node);
  writeTree(node);
  destroyTree(node);
}

void task4(Node *node) {
  maxLevel = 10;
  childrenAdded = 0;
  falseResults = 0;
  tolerance = 0.2;
  choice = 1;

  monitorChildren(node);
  writeTree(node);
  destroyTree(node);
}
