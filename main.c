#include <stdlib.h>
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "tests.h"

// main

int main(int argc, char **argv){
  Node *head;

  // make the head node
  head = makeNode(0.0, 0.0, 0);

  int input = 0;

  printf("\nType the number of the task you want to test: ");
  scanf("%i", &input);

  switch (input){
    case 1:
      // make a non-uniform level 3 tree
      makeChildren(head, maxLevel);
      makeChildren(head->child[0], maxLevel);
      makeChildren(head->child[1], maxLevel);
      makeChildren(head->child[2], maxLevel);
      makeChildren(head->child[3], maxLevel);
      makeChildren(head->child[0]->child[0], maxLevel);

      task1(head);
      printf("\nFinished testing.\n");

      break;
    case 2:
      // make a non-uniform level 3 tree
      makeChildren(head, maxLevel);
      makeChildren(head->child[0], maxLevel);
      makeChildren(head->child[1], maxLevel);
      makeChildren(head->child[2], maxLevel);
      makeChildren(head->child[3], maxLevel);
      makeChildren(head->child[0]->child[0], maxLevel);

      task2(head);
      printf("\nFinished testing.\n");

      break;
    case 3:
      // make a non-uniform level 3 tree
      makeChildren(head, maxLevel);
      makeChildren(head->child[0], maxLevel);
      makeChildren(head->child[1], maxLevel);
      makeChildren(head->child[2], maxLevel);
      makeChildren(head->child[3], maxLevel);
      makeChildren(head->child[0]->child[0], maxLevel);

      task3(head);
      printf("\nFinished testing.\n");

      break;
    case 4:
      // make a full level 2 tree
      makeChildren(head, maxLevel);
      makeChildren(head->child[0], maxLevel);
      makeChildren(head->child[1], maxLevel);
      makeChildren(head->child[2], maxLevel);
      makeChildren(head->child[3], maxLevel);

      task4(head);
      printf("\nFinished testing.\n");

      break;
    default:
      printf("\nEnter a number between 1 and 4.\n");

      // writes the Quadtree to Gnuplot
      writeTree(head);

      // frees all of the memory allocated for the Quadtree
      destroyTree(head);
  }

  return 0;
}
