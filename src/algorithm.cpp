#include "algorithm.hpp"
#include <iostream>
#include <climits>
#include <queue>

using namespace std;
namespace itis {

  // Количество вершин в графе
  static int vertexes;

  bool FordFulkerson::hasPath(int** graphPh, int s, int t, int* parent) {
    bool* checked = new bool[vertexes];

    queue<int> queue;

    queue.push(s);

    checked[s] = true;

    parent[s] = -1;

    while (!queue.empty()) {

      int i = queue.front();

      queue.pop();

      for (int j = 0; j < vertexes; j++) {

        if (!checked[j] && graphPh[i][j] > 0) {

          if (j == t) {

            parent[j] = i;

            return true;
          }

          queue.push(j);

          parent[j] = i;

          checked[j] = true;
        }
      }
    }

    return false;
  }

  int FordFulkerson::fordFulkerson(int** graph, int size, int s, int t) {
    vertexes = size;
    int i = 0;
    int j = 0;

    int** graphPh = new int*[size];
    for (int k = 0; k < size; ++k) {
      graphPh[k] = new int[size];
    }

    for (i = 0; i < vertexes; i++) {
      for (j = 0; j < vertexes; j++) {
        graphPh[i][j] = graph[j][i];
      }
    }

    int* parent = new int[vertexes];
    int maxFlow = 0;
    while (hasPath(graphPh, s, t, parent)) {
      int pathFlow = INT_MAX;
      for (i = t; i != s; i = parent[i]) {
        j = parent[i];
        pathFlow = min(pathFlow, graphPh[j][i]);
      }

      for (i = t; i != s; i = parent[i]) {
        j = parent[i];
        graphPh[i][j] -= pathFlow;
        graphPh[j][i] += pathFlow;
      }

      maxFlow += pathFlow;
    }
    return maxFlow;
  }

}  // namespace itis