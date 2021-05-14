#pragma once

namespace itis {
  class FordFulkerson {

    // Количество вершин в графе
    static int vertexes;

    //Проверка, если ли путь от источника к стоку в переданном графе.
    // Также заполняет parent[] для хранения пути
   private:
    bool hasPath(int** rGraph, int s, int t, int* parent);

   public:
    // Считает максимальный поток из источника в сток в данном графе
    int fordFulkerson(int** graph, int size, int s, int t);
  };
}  // namespace itis