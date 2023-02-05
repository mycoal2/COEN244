#include <iostream>
#include "Reference.h"
#include "Article.h"
#include "Book.h"
#include "TextBook.h"
#include "ReferenceManager.h"

using namespace std;

int main() {
    cout << "lol" << endl;

    ReferenceManager Admin(7);  //size of 7
    Article* article1 = new Article("life of Elon", "Elon M.", 2015, "Technology", 16, 69);
    Article* article2 = new Article("life of Zuck", "Mark Z.", 2013, "Technology", 70, 83);
    Book* novel1 = new Book("pizza bread", "jon", 1998, "penguin publisher", 190);
    TextBook* texbook1 = new TextBook("math is hard", "einstein", 1898, "science publisher", 398, "einstein.ca");
    
    article1->print();
    article2->print();
    novel1->print();
    texbook1->print();
    
    Admin.AddReference(article1);
    Admin.AddReference(article2);
    Admin.AddReference(novel1);
    Admin.AddReference(texbook1);

    cout << endl << endl << "Calling Print funtion of ReferenceManager class" << endl;
    Admin.print();                          // ID will not be in order

    cout << endl << "----------------------------------" << endl; 
    cout << "ID of reference in position 2: " << Admin.get(2) << endl;      // position 2 in array is the third reference added

    cout << endl << "----------------------------------" << endl;
    cout << "Calling Delete function for reference at position 1 " << endl;
    if (Admin.Delete(1)) {
        cout << "Reference deleted " << endl;
    }
    else {
        cout << "Reference could not be deleted" << endl;
    }

    cout << endl << endl << "Calling Print function of ReferenceManager class" << endl;
    Admin.print();

    cout << endl << "----------------------------------" << endl;

    cout << "Calling Search function for reference with ID 3 " << endl;
    if (Admin.Search(3)) {                      // Reference with ID 3
        cout << "Reference with this ID exists" << endl;
    }
    else {
        cout << "Reference with this ID does not exists " << endl;
    }

    cout << endl << "----------------------------------" << endl;

    cout << "Calling Search function for reference with ID 2 " << endl;
    if (Admin.Search(2)) {                      // Reference with ID 2 have been deleted
        cout << "Reference with this ID exists" << endl;
    }
    else {
        cout << "Reference with this ID does not exists " << endl;
    }

    delete article1;
    delete article2;
    delete novel1;
    delete texbook1;
    
    return 0;
}
