#include <iostream>

#include "algorithm.hpp"

using namespace std;
using namespace itis;

int main(int argc, char *argv[]) {
  FordFulkerson *fordFulkerson = new FordFulkerson();

  int graph[6][6] = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0},

                     {0, 4, 0, 0, 14, 0},  {0, 0, 9, 0, 0, 20},

                     {0, 0, 0, 7, 0, 4},   {0, 0, 0, 0, 0, 0}};

  //cout << fordFulkerson->fordFulkerson(graph, 6, 0, 5);

  return 0;
}