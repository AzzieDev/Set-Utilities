#include "main.h"
#include "set_util.h"
#include <iostream>

//globally defined sets for full scope access
std::set<int> gamma = {2, 3, 5, 8};
std::set<int> delta = {2, 3, 4, 5};

int main() {
	printDemo();
	unionDemo();
	intersectionDemo();
	subtractDemo();
	symmetricDifferenceDemo();
	powerSetDemo();

	return 0;
}

//prints out the values of the two sets
void printDemo() {
	std::cout << "Gamma = ";
	printSet(gamma);
	std::cout << "Delta = ";
	printSet(delta);
}

//demonstrates the union of two sets
void unionDemo() {
	std::set<int> epsilon = unionSet(gamma, delta);
	std::cout << "Gamma ∪ Delta = ";
	printSet(epsilon);
}

//demonstrates the union of two sets
void intersectionDemo() {
	std::set<int> epsilon = intersectionSet(gamma, delta);
	std::cout << "Gamma ∩ Delta = ";
	printSet(epsilon);
}

//demonstrates subtraction of each set from the other
void subtractDemo() {
	std::set<int> eta = differenceSet(gamma, delta);
	std::cout << "Gamma - Delta = ";
	printSet(eta);

	std::set<int> theta = differenceSet(delta, gamma);
	std::cout << "Delta - Gamma = ";
	printSet(theta);
}

//demonstrates the symmetric difference of two sets
void symmetricDifferenceDemo() {
	std::set<int> epsilon = symmetricDifferenceSet(gamma, delta);
	std::cout << "Gamma ⊖ Delta = ";
	printSet(epsilon);
}

//demonstrates all permutations of sets
void powerSetDemo() {
	std::cout << "P(Gamma): { " << std::endl;
	std::set<std::set<int>> kappa = powerSet(gamma);
	printSetOfSets(kappa);
	std::cout << " }" << std::endl;
	std::cout << "P(Delta): { " << std::endl;
	std::set<std::set<int>> iota = powerSet(gamma);
	printSetOfSets(iota);
	std::cout << " }" << std::endl;
}