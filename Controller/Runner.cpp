/*
 * Runner.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jand6944
 */

#include "Controller.h"
/**
 * stars the program
 */
int main()
{
	Controller * baseController = new Controller();
	baseController -> start();
	return 0;
}


