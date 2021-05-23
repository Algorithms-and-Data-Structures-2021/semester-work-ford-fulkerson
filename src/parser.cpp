#include <utility>
#include "ctime"
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>
#include <parser.hpp>

#include "algorithm.hpp"

using namespace std;
using namespace itis;

vector<int> split(const std::string &s, char delimiter) {
  vector<int> tokens;

  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}

void Parser::process_data(const string &pathToInputFile, const string &pathToResult, int iterations) {
  string line;
  vector<float> timeResult;
  std::ofstream out;
  out.open(pathToResult);

  for (int j = 0; j < iterations; ++j) {

    ifstream file(pathToInputFile);

    auto *fordFulkerson = new FordFulkerson();

    getline(file, line);
    vector<int> intValues = split(line, ',');
    int size = intValues.size();
    int **matrix = new int *[size];
    for (int i = 0; i < size; ++i) {
      matrix[i] = new int[size];
    }
    for (int p = 0; p < size; ++p) {
      matrix[0][p] = intValues.at(p);
    }

    for (int i = 0; i < size - 1; ++i) {
      getline(file, line);
      vector<int> intValues = split(line, ',');

      for (int p = 0; p < intValues.size(); ++p) {
        matrix[i][p] = intValues.at(p);
      }
    }

    file.close();

    double startTime = clock();
    fordFulkerson->fordFulkerson(matrix, size, 0, size - 1);
    double endTime = clock();

    delete[](matrix);
    timeResult.emplace_back(endTime - startTime);
    if (out.is_open()) {
      out << to_string(endTime - startTime) << " ";
    }
    out << std::endl;
  }

  float average = 0;
  for (float f : timeResult) {
    average += f;
  }
  average /= static_cast<float>(timeResult.size());
  if (out.is_open()) {
    out << "average time: " << to_string(average) << " ms\n";
  }

  out.close();
}
