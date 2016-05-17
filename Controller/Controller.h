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
#include "../Model/CTECBinaryTree.cpp"

using namespace std;
class Controller
{
	//the private things of the controller.cpp
private:
	//Node<int> intNode;
	//ArrayNode<string>stringArrayNode;
 //  ArrayNo<string> otherArrayNode;
	//CTECArray<string> * myStringArray;
    CTECArray<int> * myIntArray;
    CTECList<int> * numbers;
    Timer arrayTimer;
    int * mergeData;
    void testLists();
    void checkSorts();
    void doMergeSort();
    void mergeSort(int dataArray[], int size);
    void merge(int data[], int sizeOne, int sizeTwo);
    void doBogo();
    void quickSort(int first, int last);
    int partition(int first, int last);
    void swap(int first, int second);
    void doQuick();
    void testTable();
public:
    Controller();
    virtual ~Controller();
    void start();
    void doGraphs();
    void tryTree();
};

#endif /* CONTROLLER_CONTROLLER_H_ */
