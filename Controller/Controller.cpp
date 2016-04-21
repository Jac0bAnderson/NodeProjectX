/*
 * Controller.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jand6944
 */

//Import section
#include "Controller.h"//imports the controllers header file
#include <stdlib.h>
#include<string>


using namespace std;
Controller::Controller()
{
//this->	intNode.setValue(5);
//this -> stringArrayNode.setValue("words are fun");
//this->otherArrayNode.setValue("linked node");
//stringArrayNode.setNt(&otherArrayNode);
	//myStringArray = new CTECArray<string>(5);



	notHipsterInts = new CTECArray<int>(5);
	numbers = new CTECList<int>();
}

Controller::~Controller()
{

}
void Controller :: tryTree()
{
    CTECBinaryTree<int> testTree;
    testTree.insert(7);
    testTree.insert(10);
    testTree.insert(-5);
}
//called when started
void Controller :: start()
{
    doMergeSort();

	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (23* index));
	}
	for(int index= 0; index < notHipsterInts->getSize(); index++)
	{
		cout << "notHipsterInts at index " << index << notHipsterInts->get(index) << endl;
	}
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
	//cout<< intNode.getValue()<<endl;
	//cout<< stringArrayNode.getvalue()<<endl;

	//sets values
	//string first = "first comment of the day";
	//string second = "Tru ";
	//string third = "rekt";
	//string fourth = "phat Jonny";
	//string fifth = "cool kat";

	//sets values to the array
	//myStringArray->set(0, first);
	//cout << myStringArray->get(0) << endl;
	//myStringArray->set(1, second);
	//myStringArray->set(2, third);
	//myStringArray->set(3, fourth);
	//myStringArray->set(4, fifth);
	//for(int index =0; index < myStringArray->getSize(); index++)
	//{
	//	cout << "the content at index " << index << "are " << myStringArray->get(index) << endl;
	//}
}
void Controller:: swap(int first, int second)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last];
}
int Controller:: partition(int size, int last)
{
    int pivot;
    int index, smallIndex;
    swap(first, (first+last)/2);
    pivot = mergeData[first];
    for(index = first +1; index <= last, index++);
    {
        if(mergeData[index]< pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    return smallIndex;
}
void Controller :: doQuick()
{
    mergeData = new int [5000];
    for(int spot =0; spot< 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer.mergeTimer;
    merTimer.startTimer();
    quickSort(mergeData, 49999);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    delete [] mergeData;

}
void Controller:: quickSort(int data[], int size)
{
    int pivotIndex;
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quickSort(data, pivotIndex-1);
        quickSort(pivotIndex + 1, last);
        
    }
}
void Controller :: sortData()
{
 
}
void Controller :: doMergeSort()
{
    mergeData = new int [5000];
    for(int spot =0; spot< 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer.mergeTimer;
    merTimer.startTimer();
    quickSort(mergeData, 49999);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    delete [] mergeData;
}
void Controller :: mergeSort(int dataArray [] , int size)
{
    
    int sizeOne;
    int sizeTwo;
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        mergeSort(data, sizeOne);
        mergeSort((data+sizeOne), sizeTwo);
        merge(data, sizeOne, sizeTwo);
    }
}
void Controller :: merge(int data [], int sizeOne int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 =0;
    int copied2 = 0;
    int index;
    temp new int [sizeOne + sizeTwo];
    while ((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < data + sizeOne) [copied2] )
        {
            temp[copied++] = data [copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne) [copied2++];
        }
    }
    while(copied < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeTwo) [copied2++];
    }
    for(index =0; index < sizeOne + sizeTwo; indexx++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}
void Controller :: checkSort()
{
    //Create an array and list
    //fill with random data
    //sort and time
    //repeat with ordered data
    //print results
    CTECArray<int> numbersInArray(5000);
    CTECList<int> numberInList;
    int cPlusPlusArray[5000];
    for(int spot= 0; spot <5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToFront(randomValue);
        cPlusPlusArray[spot] = randomValue;
    }
    
    Timer listTime;
    listTimer.startTimer();
    numbersInList.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    sortTimer.resetTimer();
    sortTimer.startTimer();
}
//Tests
void Controller :: testLists()
{
    CTECList<int> CList;
    
    numbers->addToFront(3);
    cout << "the front should return 3" << CList.getFront() << endl;
    
    numbers->addToEnd(6);
    cout << "the end should return 6" << CList.getEnd() << endl;
}
