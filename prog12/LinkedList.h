//4.25.2025
//Diya Tomar
//This file contains a class to model a Linked List. The class is templated.                       

#pragma once //this tells the compiler to only include this file one time                         
#include <iostream> //for outputting the results to the screen
#include "NodeType.h" //including contents of "NodeType.h" file

//class to model a linked list (template to accept values of different types)
template <typename T>
class LinkedList {
    
    private://access specifier, contains private class members
        NodeType<T> *head; //pointer to point at beginning of linked list                       
    
    public://access specifier, contains public class members
        ~LinkedList();//destructor
        LinkedList();//default constructor
        
        void insert(T);//method to insert value to list
        void remove(T);//method to remove 1st occurrence of item from the list
        void print() const;//method to print list
        bool isEmpty() const { return head == nullptr; }//method that returns true if list is empty
        void clear();//method to remove all items in list

};//end class definition

//the LinkedList constructor creates a linked list
template <typename T>
LinkedList<T>::LinkedList() {
    //setting head pointer to null (no items in list)
    head = nullptr;
}//end constructor

//the LinkedList destructor deletes the linked list
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();//calling clear method to clear list
}//end destructor

//the print method prints the items in the linked list
template <typename T>
void LinkedList<T>::print() const{
    
    //current pointer pointing at what head is pointing at in the list
    //(beginning of list)
    NodeType<T> *current = head;
    
    if (isEmpty()) {//if the list is empty
        //print that list is empty (no items)
        std::cout << "There are no items in the list." << std::endl;
    }
    
    //while current pointer is not at the end of the list
    while (current != nullptr) {
        //print data in node pointed at by current
        std::cout << current->data << std::endl;
        //point current at next node
        current = current->next;
    }
}//end print

//the clear method clears the list (removes all items from the list)
template <typename T>
void LinkedList<T>::clear() {
    
    //temp pointer pointing at what head is pointing at in the list
    //(first node in the list)
    NodeType<T> *temp = head;
    
    while (!isEmpty()) {//while the list is not empty                                
        head = head->next;//point head pointer at next node
        delete temp;//delete the node pointed at by temp
        temp = head;//point temp at same node being pointed at by head
    }
}//end clear

//the insert method inserts a value (specified by the parameter) in the list
//values are inserted to the front of the list (building backwards)
//val means value to insert
template <typename T>
void LinkedList<T>::insert(T val) {
    
    NodeType<T> *newNode = new NodeType<T>;//newNode pointer pointing at a node                         
    newNode->next = nullptr;//setting next pointer of node to null                                     
    newNode->data = val;//storing value provided by parameter as the data of the node 
    
    if (isEmpty()) {//if the list is empty
        //point head to new node
        head = newNode;
    }
    //else if the list is not empty                                                                 
    else {
        newNode->next = head;//point next pointer of node at same position as head
        head = newNode;//point head at same position of newNode
        
        //the code above points the newNode to the front of the list                               
        //and then points the head at newNode so now both are 
        //pointing to the front of the list
    }
    
}//end insert

//the remove method removes the first occurence of a value 
//(specified by the parameter) from the list
//val means value to remove
template <typename T>
void LinkedList<T>::remove(T val) {
    
    NodeType<T> *current;//current pointer
    //setting current pointer to point at what head is pointing at in the list
    current = head;
    
    NodeType<T> *previous;//previous pointer
    //setting previous pointer to point at current position (which is also head)
    previous = current;
    
    
    if (isEmpty()) {//if the list is empty
        //print that no value can be removed since list is empty
        std::cerr << "List is empty, can't remove." << std::endl;
        return;//return to not execute rest of code in method
    }
    
    //while the data being pointed at is not equal to the value to remove
    //and current is not equal to null (not at the end of the list)
    while (current != nullptr and current->data != val) {
        //set the previous pointer to point at the node pointed at by
        //current
        previous = current;
        //point current at the next node
        current = current->next;
    }
    
    //if the current pointer is equal to null (is at the end of the list)
    if (current == nullptr) {
        //print that value was not found in the list
        std::cerr << "Value not found in the list." << std::endl;
    }
    //if the value being removed is the first value in the list
    else if (current == head) {
        //point head to the 2nd node in the list
        head = head->next;
        //delete value stored at node pointed at by current
        delete current;
    }
    else {//if value is in the list                                                                                    
        //making previous pointer point at node after the node that will
        //be removed from list
        previous->next = current->next;
        //delete value stored at node pointed at by current
        delete current;
    }

}//end remove



