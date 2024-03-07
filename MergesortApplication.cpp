#include <iostream>
#include <vector>
#include "MergeSorter.h"
#include "AlgorithmTester.h"
#include "RandomIntegerList.h"

using namespace std;

int main()
{
  AlgorithmTester* newTest = new AlgorithmTester(RandomIntegerList::GenerateRandomList(100000), 20);

  vector<double> averages = newTest->averages();

  cout << "Merge Sort Statistics" << endl;
  cout << "The lower bound is: " << averages[0] << endl;
  cout << "The lower-average is: " << averages[1] << endl;
  cout << "The overall mean is: " << averages[2] << endl;
  cout << "The upper-average is: " << averages[3] << endl;
  cout << "The upper bound is: " << averages[4] << endl;
}