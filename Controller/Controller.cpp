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
//called when started
void Controller :: start()
{
    testLists();
arrayTimer.startTimer();

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
    mergeSort(mergeData, 5000);
}
void Controller :: mergeSort(int dataArray [] , int size)
{
    
}
void Controller :: merge(int data [], int sizeOne int sizeTwo)
{
    
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
