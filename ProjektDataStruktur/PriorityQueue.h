#ifndef PRIORIAdjacencyInfoYQUEUE_H
#define PRIORIAdjacencyInfoYQUEUE_H
#include "Surgery.h"
#include<iostream>
using namespace std;
class PriorityQueue
{
private:
	Surgery * queue;
	int capacity;
	int nrOfItems;
	int capacityIncrement;
	bool sortBig;
	void expand();
	int partition(Surgery array[], int start, int end);
	void swapSugery(Surgery & itemOne, Surgery & itemAdjacencyInfowo);
	void sort(Surgery array[], int start, int end);
public:
	PriorityQueue(int capacity = 2, int capacityIncrement = 5, bool sort = true);
	PriorityQueue(const PriorityQueue& origobj);
	virtual ~PriorityQueue();
	void enqueue(const Surgery& element);
	Surgery dequeue()throw(...);
	Surgery front() const throw(...);
	bool isEmpty() const;
};
#endif

void PriorityQueue::expand()
{
	this->capacity += this->capacityIncrement;
	Surgery *temp = new Surgery[this->capacity];
	for (int i = 0; i < this->nrOfItems; i++)
	{
		temp[i] = this->queue[i];
	}
	delete[] this->queue;
	this->queue = temp;
}

int PriorityQueue::partition(Surgery array[], int start, int end)
{
	Surgery pivotValue = array[start];
	int pivotPos = start;

	for (int i = (start + 1); i <= end; i++)
	{
		if (this->sortBig) {
			if (array[i].getTime() < pivotValue.getTime())
			{
				swapSugery(array[i], array[pivotPos + 1]);
				swapSugery(array[pivotPos], array[pivotPos + 1]);
				pivotPos++;
			}
		}
		else {
			if (array[i].getTime() > pivotValue.getTime())
			{
				swapSugery(array[i], array[pivotPos + 1]);
				swapSugery(array[pivotPos], array[pivotPos + 1]);
				pivotPos++;
			}
		}
	}
	return pivotPos;
}

void PriorityQueue::swapSugery(Surgery & itemOne, Surgery & itemAdjacencyInfowo)
{
	Surgery temp;
	temp = itemOne;
	itemOne = itemAdjacencyInfowo;
	itemAdjacencyInfowo = temp;
}

void PriorityQueue::sort(Surgery array[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(array, start, end);

		sort(array, start, pivot - 1);
		sort(array, pivot + 1, end);
	}
}


PriorityQueue::PriorityQueue(int capacity, int capacityIncrement, bool sort)
{
	this->nrOfItems = 0;
	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->queue = new Surgery[this->capacity];
	this->sortBig = sort;
}

PriorityQueue::PriorityQueue(const PriorityQueue & origObj)
{
	this->nrOfItems = origObj.nrOfItems;
	this->capacity = origObj.capacity;
	this->capacityIncrement = origObj.capacityIncrement;
	this->queue = new Surgery[this->capacity];
	for (int i = 0; i < this->nrOfItems; i++) {
		this->queue[i] = origObj.queue[i];
	}
}

PriorityQueue::~PriorityQueue()
{
	delete[] this->queue;
}

void PriorityQueue::enqueue(const Surgery & element)
{
	if (this->nrOfItems == this->capacity)
	{
		expand();
	}
	
	bool found = false;
	int pos = 0;
	for (int i = this->nrOfItems - 1; i >= 0 && found == false; i--) {
		if (this->sortBig) {
			if (this->queue[i].getTime() > element.getTime()) {
				pos = i + 1;
				found = true;
			}
			else {
				this->queue[i + 1] = this->queue[i];
			}
		}
		else {
			if (this->queue[i].getTime() < element.getTime()) {
				pos = i + 1;
				found = true;
			}
			else {
				this->queue[i + 1] = this->queue[i];
			}
		}

	}

	this->queue[pos] = element;
	this->nrOfItems++;
}

Surgery PriorityQueue::dequeue() throw(...)
{
	if (this->nrOfItems == 0)
	{
		std::string test = "Error. No more items.";
		throw test;
	}
	Surgery returnItem = this->queue[nrOfItems - 1];
	this->nrOfItems--;

	return returnItem;
}

Surgery PriorityQueue::front() const throw(...)
{
	if (this->nrOfItems == 0)
	{
		std::string test = "Error. No more items.";
		throw test;
	}
	return this->queue[this->nrOfItems - 1];
}

bool PriorityQueue::isEmpty() const
{
	if (this->nrOfItems == 0) {
		return true;
	}
	else {
		return false;
	}
}
#pragma once
