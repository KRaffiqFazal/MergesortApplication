#pragma once
#include<iostream>
#include <vector>
#include<cstdlib>

using namespace std;

class RandomIntegerList
{
public:
  /// <summary>
  /// Generates a random vector of integers of a given size.
  /// </summary>
  /// <param name="size">Size of vector with random values to sort.</param>
  /// <returns>A vector of unsorted random values of a given size that the user has specified.</returns>
  static vector<int> GenerateRandomList(int size)
  {
    vector<int> randomVector;
    srand((unsigned)time(NULL));

    for (int i = 1; i <= size; i++)
    {
      randomVector.push_back(rand() % size);
    }

    return randomVector;

  }
};

