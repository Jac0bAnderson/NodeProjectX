/*
 * CTECList.h
 *
 *  Created on: Feb 22, 2016
 *      Author: jand6944
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_
#include "ArrayNode.h"
#include <assert.h>
template <class Type>
class CTECList
{
private:
    int size;
    ArrayNode<Type> * head;
    ArrayNode<Type> * end;
    void calculateSize();
    void swap(int indexOne, int indexTwo);
public:
    CTECList();
    virtual ~CTECList();
    int getSize();
    Type getFront();
    Type getEnd();
    Type getAtIndex(int index);
    void set(int index, const Type& value);
    void addToFront(const Type& value);
    void addToEnd(const Type& value);
    void addAtIndex(int index, const Type& value);
    Type removeFront();
    Type removeEnd();
    Type removeAtIndex(int index);
    int indexOf(Type searchValue);
    Type getFromIndex(int index);
    void selectionSort();

};



#endif /* MODEL_CTECLIST_H_ */
