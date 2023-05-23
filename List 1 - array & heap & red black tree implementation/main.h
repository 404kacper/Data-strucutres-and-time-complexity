#include "CustomArray.h"
#include "CustomList.h"
#include "MaxHeap.h"
#include "RedBlackTree.h"
#include "fstream"
#include <vector>
#include <random>
#include <chrono>
#include <ratio>
#include <ctime>

using namespace std::chrono;

vector<string> fileContents;
vector<int> numbers;

void readInputData();
void extractInputData(string &contentString, vector<int> &delimiterArray);
void readInputTime();
void openInterface();
int chooseStructure();
void proceedManual(int structChoice);
void proceedAuto(int structChoice);
int doArray(CustomArray& array);
int doList(CustomList& list);
int doHeap(MaxHeap& heap);
int doTree(RedBlackTree& tree);
int main();

