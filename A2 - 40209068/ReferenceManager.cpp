#include "ReferenceManager.h"

//default to size of 10
ReferenceManager::ReferenceManager() {
    Max = 10;
    list_Reference = new Reference* [Max];
  
  for (int i = 0; i < Max; i++) {         //dont need double pointer
        list_Reference[i] = nullptr;
   }
 
    num_Reference = 0;
}

ReferenceManager::ReferenceManager(int capacity) {
    Max = capacity;
    list_Reference = new Reference* [Max];
    for (int i = 0; i < Max; i++) {
        list_Reference[i] = nullptr;
    }
    num_Reference = 0;
}
ReferenceManager::ReferenceManager(const ReferenceManager& a) {
    Max = a.Max;
    list_Reference = new Reference* [Max];
    for (int i = 0; i < a.Max; i++) {
        list_Reference[i] = a.list_Reference[i];
    }
    num_Reference = a.num_Reference;
}

ReferenceManager::~ReferenceManager() {     //destructor
    delete[] list_Reference;
}

bool ReferenceManager::AddReference(Reference* r) {
    if (num_Reference < Max) {
        list_Reference[num_Reference] = r;
        num_Reference++;
        return true;
    }
    else {
        cout << "Reference cannot be added because the limit has been reached" << endl;
        return false;
    }
}
int ReferenceManager::get(int pos) {
    if (pos < 0) {
        cout << "Invalid position" << endl;
        return -1;
    }
    if (pos > Max) {
        cout << "No reference at this position" << endl;
        return -1;
    }
    else {
        //list_Reference[pos].print();          //not asking for info of this position
        return list_Reference[pos]->getID();
    }
}
bool ReferenceManager::Delete(int pos) {
    if (pos < 0) {
        cout << "Invalid position" << endl;
        return false;
    }
    if (pos > Max) {
        cout << "No reference at this position" << endl;
        return false;
    }
    else {
        for (int i = pos; i < num_Reference - 1; i++) {
            list_Reference[i] = list_Reference[i + 1];
        }
        num_Reference--;
        return true;
    }
}
bool ReferenceManager::Search(int id) {
    for (int i = 0; i < num_Reference; i++) {
        if (list_Reference[i]->getID() == id) {
            return true;
        }
    }
    return false;
}
int ReferenceManager::getnum_Reference() const{
    return num_Reference;
}
void ReferenceManager::print() {
    cout << "The number of reference: " << getnum_Reference() << endl;
    for (int i = 0; i < num_Reference; i++) {       //this will list all references
        list_Reference[i]->print();
        cout << endl;
    }
}