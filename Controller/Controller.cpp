/*
 * Controller.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jand6944
 */

//Import section
#include "Controller.h"//imports the controllers header file

#include<string>


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
void Controller :: testLists()
{
	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "end should be 8" << numbers->getEnd() << endl;
}
//called when started
void Controller :: start()
{
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
