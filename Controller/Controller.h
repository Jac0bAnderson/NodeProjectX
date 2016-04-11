/*
 * Controller.h
 *
 *  Created on: Jan 27, 2016
 *      Author: jand6944
 */

#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_
//Import section
#include <iostream>
#include <string>

#include "../Model/Timer.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp" 
#include "../Model/CTECList.cpp"
#include "../Model/CTECList.h"


using namespace std;
class Controller
{
	//the private things of the controller.cpp
private:
	//Node<int> intNode;
	//ArrayNode<string>stringArrayNode;
 //  ArrayNo<string> otherArrayNode;
	//CTECArray<string> * myStringArray;
    
    int * mergeData;
	CTECList<int> * numbers;
	CTECArray<int> * notHipsterInts;
	Timer arrayTimer;
	void testLists();
    void checkSort();
    void doMergeSort();
    void doQuickSort();
    void mergeSort(int dataArray [] , int size);
    void merge(int data [], int sizeOne int sizeTwo);
    void quickSort(int data[], int size);
    void partition(int size, int last);
    int swap(int first, int second);
    

	//the public things of the controller.cpp
 public:
	Controller();
	virtual ~Controller();
	void start();
};

#endif /* CONTROLLER_CONTROLLER_H_ */
