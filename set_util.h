#ifndef SET_UTIL_IMPL_H
#define SET_UTIL_IMPL_H

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

//print a set on screen
template<typename T>
void printSet(std::set<T> setToPrint) {
	std::cout << "{ ";
	for (const auto& element : setToPrint) {
		std::cout << element << " ";
	}
	std::cout << "}" << std::endl;
}

//print a set of sets on screen
template<typename T>
void printSetOfSets(const std::set<std::set<T>>& setOfSetsToPrint) {
	for (const auto& subset : setOfSetsToPrint) {
		printSet(subset);
	}
}

// arithmetic set union between two sets of any generic type
template<typename T>
std::set<T> unionSet(std::set<T> first, std::set<T> second) {
	std::set<T> result = {};
	std::set_union(first.begin(), first.end(), second.begin(),
	               second.end(), inserter(result, result.end()));
	return result;
}

// arithmetic set intersection between two sets of any generic type
template<typename T>
std::set<T> intersectionSet(std::set<T> first, std::set<T> second) {
	std::set<T> result = {};
	std::set_intersection(first.begin(), first.end(), second.begin(),
	               second.end(), inserter(result, result.end()));
	return result;
}

// arithmetic set subtraction between two sets of any generic type
template<typename T>
std::set<T> differenceSet(std::set<T> first, std::set<T> second) {
	std::set<T> result = {};
	std::set_difference(first.begin(), first.end(), second.begin(),
	                    second.end(), inserter(result, result.end()));
	return result;
}

// arithmetic symmetric difference between two sets of any generic type
template<typename T>
std::set<T> symmetricDifferenceSet(std::set<T> first, std::set<T> second) {
	std::set<T> result = {};
	std::set_symmetric_difference(first.begin(), first.end(), second.begin(),
	                    second.end(), inserter(result, result.end()));
	return result;
}

//all possible permutations of a set
template <typename T>
std::set<std::set<T>> powerSet(const std::set<T>& inputSet) {
	std::vector<T> inputVector(inputSet.begin(), inputSet.end());
	std::set<std::set<T>> result;
	int setSize = inputVector.size();
	for (int i = 0; i < (1 << setSize); i++) {
		std::set<T> subset;
		for (int j = 0; j < setSize; j++) {
			if (i & (1 << j)) {
				subset.insert(inputVector[j]);
			}
		}
		result.insert(subset);
	}
	return result;
}


#endif //SET_UTIL_IMPL_H