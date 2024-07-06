#include <stdlib.h>
#include <math.h>
#include "treeStructure.h"
#include "buildTree.h"

// sets the value for the maximum tree level so that the tree cannot grow bigger than this
int maxLevel = 5;

// make a node at given location (x,y) and level

Node *makeNode(double x, double y, int level){

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for(i = 0; i<4; ++i)
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren(Node *parent, int maxLevel){

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  // if the parent node is not in the maximum level of the quadtree children will be made for it
  if (level < maxLevel){
    double hChild = pow(2.0,-(level+1));

    parent->child[0] = makeNode(x, y, level+1);
    parent->child[1] = makeNode(x+hChild, y, level+1);
    parent->child[2] = makeNode(x+hChild, y+hChild, level+1);
    parent->child[3] = makeNode(x, y+hChild, level+1);
  }

  return;
}

// grow the quadtree uniformly by one level

void growQuadtree(Node *node){

  int i;

  // if the node does not have any children then children are created for it
  if (node->child[0] == NULL){
    makeChildren(node, maxLevel);
  }
  else{
    for (i = 0; i < 4; ++i){
      growQuadtree(node->child[i]);
    }
  }

  return;
}
