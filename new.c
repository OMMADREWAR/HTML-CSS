#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Structure for an item which holds weight & profit of the Item
struct Item {
	int profit, weight;	
	// Constructor- creation of object having profit and weight
	Item(int profit, int weight)
		: profit(profit), weight(weight)
	{
	}
};
// Comparison function to sort Item according to profit/weight ratio
int cmp(struct Item a, struct Item b)
{
	float r1 = (float)a.profit / a.weight;
	float r2 = (float)b.profit / b.weight;
	return r1 > r2;
}
int cmp1(struct Item a, struct Item b)
{
	 /*int result = compareOperation(a.profit, b.profit);
	 return result;*/
	float r1 = (float)a.profit;
	float r2 = (float)b.profit;
	return r1 > r2;
}
int cmp2(struct Item a, struct Item b)
{
	float r1 = (float)a.weight;
	float r2 = (float)b.weight;
	return r1 < r2;
}
// Main greedy function of case 1- maximum profit to solve problem
double fractionalKnapsack_1(struct Item arr[],int knapsack_capacity, int size)
{
	sort(arr, arr + size, cmp1); // Sort Item on basis of maximum profit
	int curWeight = 0; // Current weight in knapsack
	float Total_profit= 0.0;  // Total Profit Variable
	// Going through all Items
	for (int i = 0; i < size; i++) {
		// Add item if weight of given item is < knapsack capacity , add it completely
		if (curWeight + arr[i].weight <= knapsack_capacity) {
			curWeight += arr[i].weight;
			Total_profit += arr[i].profit;
		}
		// If we can't add current Item add fractional part of it
		else {
			float remain = knapsack_capacity - curWeight;
			Total_profit += arr[i].profit* (remain/ arr[i].weight);
			break;
		}
	}
	return Total_profit;  // final profit
}
// Main greedy function of case 2-minimum weight to solve problem
double fractionalKnapsack_2(struct Item arr[],int knapsack_capacity, int size)
{
	sort(arr, arr + size, cmp2); // Sort Item on basis of ratio
	int curWeight = 0; // Current weight in knapsack
	float Total_profit= 0.0;  // Total Profit Variable
	// Going through all Items
	for (int i = 0; i < size; i++) {
		// Add item if weight of given item is < knapsack capacity , add it 		completely
		if (curWeight + arr[i].weight <= knapsack_capacity) {
			curWeight += arr[i].weight;
			Total_profit += arr[i].profit;
		}
		// If we can't add current Item add fractional part of it
		else {
			float remain = knapsack_capacity - curWeight;
			Total_profit += arr[i].profit
						* (remain/ arr[i].weight);
			break;
		}
	}
	return Total_profit;  // final profit
}
// Main greedy function of case 3-P/W ration to solve problem
double fractionalKnapsack(struct Item arr[],
						int knapsack_capacity, int size)
{
	
	sort(arr, arr + size, cmp); // Sort Item on basis of ratio	
	/*for (int i = 0; i < size; i++) 
	{
	cout<< arr[i].profit<< arr[i].weight;
	}*/
	int curWeight = 0; // Current weight in knapsack	
	float Total_profit= 0.0;  // Total Profit Variable
	// Going through all Items
	for (int i = 0; i < size; i++) 
	{
		// Add item if weight of given item is < knapsack capacity , add it completely
		if (curWeight + arr[i].weight <= knapsack_capacity) {
			curWeight += arr[i].weight;
			Total_profit += arr[i].profit;
		}
		// If we can't add current Item add fractional part of it
		else {
			float remain = knapsack_capacity - curWeight;
			Total_profit += arr[i].profit
						* (remain
							/ arr[i].weight);

			break;
		}
	}
	return Total_profit;  // final profit
}
int main()
{
	// Weight of knapsack
	int knapsack_capacity=25;
		// Given weights and profits as a pairs
	Item arr[] = { { 24, 24},
				{ 18, 10 }, 
				{ 18, 10 },{ 10, 7} };

	int size = sizeof(arr) / sizeof(arr[0]);    //to find the size of array

	// Function Call
    cout <<"Maximum profit earned in case 1 (Maximum profit)="
         << fractionalKnapsack_1(arr, knapsack_capacity, size); // calling a fractional knapsack function for case 1
		 cout<<"\n";
    cout << "Maximum profit earned in case 2 (Minimum Weight)= "
		<< fractionalKnapsack_2(arr, knapsack_capacity, size);  // calling a fractional knapsack function for case 2 
		cout<<"\n";   
	cout << "Maximum profit earned in case 3 (Profit/weight ratio)= "
		<< fractionalKnapsack(arr, knapsack_capacity, size);  // calling a fractional knapsack function for case 3
		cout<<"\n";
	return 0;}

