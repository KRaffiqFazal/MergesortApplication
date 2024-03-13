#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "MergeSorter.h"
#include "RadixSort.h"

using namespace std;
using namespace chrono;

class AlgorithmTester
{
public:
  /// <summary>
  /// Creates an Algorithm tester which will test the Merge sort algorithm for a single list multiple times and return
  /// multiples values for the average lower, median and upper bound.
  /// </summary>
  /// <param name="testingValues">Vector of values to sort with merge sort.</param>
  /// <param name="numOfTrials">The number of trials the user wishes to test with.</param>
  /// <param name="sortingType">The type of sort that needs to be run.</param>
  AlgorithmTester(vector<int> testingValues, int numOfTrials, int sortingType)
  {
    // Efficiency will be divided into BigO, BigOmega and BigTheta, therefore must be divisible by 3 to work out bounds.
    if (numOfTrials % 3 != 0)
    {
      numOfTrials = numOfTrials + 3 - (numOfTrials % 3);
    }
    trialsNeeded = numOfTrials;
    unsortedValues = testingValues;
    if (sortingType == 1)
    {
      isMergeSort = true;
    }
  }

  /// <summary>
  /// Works out the lower, median and upper bound averages of the sorting algorithm on a given list.
  /// </summary>
  /// <returns>Returns a vector of 3 values: lower, median and upper bound.</returns>
  vector<double> averages()
  {
    vector<double> finalAverages;
    results.clear();

    // Below loop tests merge sort for a given number of tests that is divisible by 3 where the lower and upper bound sorts will be kept separate from.
    for (int i = 0; i < trialsNeeded - 2; i++)
    {
      results.push_back(individualTest());
    }
    unsortedValues = MergeSorter::mergeSortAsc(unsortedValues);

    // Lower bound (fully sorted).
    results.push_back(individualTest());

    // Upper bound (fully sorted then reversed).
    reverse(unsortedValues.begin(), unsortedValues.end());
    results.push_back(individualTest());

    sort(results.begin(), results.end());

    // Below code splits the now ordered averages into 3 sections to get averages.
    double averageSegment = 0;

    finalAverages.push_back(results[0]);
    for (int i = 1; i <= trialsNeeded; i++)
    {
      averageSegment += results[i - 1];
      if (i % (trialsNeeded / 3) == 0)
      {
        finalAverages.push_back((averageSegment) / (trialsNeeded / 3));
        averageSegment = 0;
      }
    }
    finalAverages.push_back(results[results.size() - 1]);
    return finalAverages;
  }
private:
  int trialsNeeded;
  vector<int> unsortedValues;
  vector<double> results;
  bool isMergeSort = false;

  /// <summary>
  /// Times the algorithm in milliseconds with a stopwatch.
  /// </summary>
  /// <returns>The time it took for the algorithm to sort values.</returns>
  double individualTest()
  {
    steady_clock::time_point start;
    steady_clock::time_point end;
    if (isMergeSort)
    {
      start = high_resolution_clock::now();
      MergeSorter::mergeSortAsc(unsortedValues);
      end = high_resolution_clock::now();
    }
    else
    {
      start = high_resolution_clock::now();
      RadixSort::Sort(unsortedValues);
      end = high_resolution_clock::now();
    }
    
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();
  }
};

