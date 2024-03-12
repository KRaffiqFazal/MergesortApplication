#include <iostream>
#include <vector>
#include "MergeSorter.h"
#include "AlgorithmTester.h"
#include "RandomIntegerList.h"

using namespace std;

bool isNumber(string input)
{
  bool toReturn = true;
  for (char val : input)
  {
    if (!isdigit(val))
    {
      toReturn = false;
    }
  }
  return toReturn;
}
int main(int argc, char* argv[])
{
  // First argument is program name, other checks ensure number of items and number of trials is correct.
  if (argc != 4)
  {
    cout << "Please provide 3 commandline arguments: number of items to sort, number of trials and type of sort" << endl;
    return 0;
  }
  if (!isNumber(argv[1]))
  {
    cout << "Please provide an integer number of items to sort." << endl;
    return 0;
  }
  if (!isNumber(argv[2]))
  {
    cout << "Please provide an integer number of trials." << endl;
    return 0;
  }

  int sortType;

  if (!isNumber(argv[3]))
  {
    sortType = atoi(argv[3]);
    if (!(sortType == 0 || sortType == 1))
    {
      cout << "Please provide a valid sorting type: '0' is radix sort, '1' is merge sort.";
      return 0;
    }
  }
  int numOfItems = atoi(argv[1]);
  int numOfTrials = atoi(argv[2]);
  AlgorithmTester* newTest = new AlgorithmTester(RandomIntegerList::GenerateRandomList(numOfItems), numOfTrials, sortType);

  vector<double> averages = newTest->averages();
  if (sortType == 0)
  {
    cout << "Radix Sort Statistics" << endl;
  }
  else
  {
    cout << "Merge Sort Statistics" << endl;
  }
  cout << "The lower bound is: " << (averages[0] / 1000000) << endl;
  cout << "The lower-average is: " << (averages[1] / 1000000) << endl;
  cout << "The overall mean is: " << (averages[2] / 1000000) << endl;
  cout << "The upper-average is: " << (averages[3] / 1000000) << endl;
  cout << "The upper bound is: " << (averages[4] / 1000000) << endl;
}