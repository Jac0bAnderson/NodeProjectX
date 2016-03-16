/*
 * CTECList.h
 *
 *  Created on: Feb 22, 2016
 *      Author: jand6944
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_
#include "ArrayNode.h"
template <class Type>
class CTECList
{
private:
int size;
ArrayNode<Type> *Head;
ArrayNode<Type> *end;
void calculatedSize();
public:
CTECList();
~CTECList();
int getSize();
void  addToFront(const Type& value);
void addToEnd(const Type& value);
void addAtIndex(int index, Type value);
Type getFront();
Type getEnd();
Type getFromIndex(int index);
Type removeFromFront();
Type removeFromEnd();
Type removeFromIndex(int index, Type value);
Type set(int index, Type value);
};



#endif /* MODEL_CTECLIST_H_ */
