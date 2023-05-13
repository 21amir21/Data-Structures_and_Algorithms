#include <iostream>
#include "Queue.h"
#include <stack>
#include <queue>
#include <string>
using namespace std;

// Question 1) (Q1)
// int main() {
//
//
//	stack<int> stoka;
//	Queue tabor(10);
//
//	cout << "Please enter some numbers " << endl;
//	for (int i = 0; i < 10; i++) {
//		stoka.push(i);
//		tabor.enqueue(i);
//	}
//
//	cout << "The number before reversing " << endl;
//	for (int i = 0; i < 10; i++) {
//		cout << tabor.dequeue() << endl;
//	}
//
//	cout << "The number after reversing " << endl;
//	for (int i = 0; i < 10; i++) {
//		cout << stoka.top() << endl;
//		 stoka.pop();
//	}
//
//	return 0;
//}

// Question 2) (Q2)
// int main() {
//
//	Queue tabor(10);
//
//	int choice = 0;
//	int counter = 0;
//	int waitingCounter = -1;
//
//	do {
//		cout << "0 - EXIT" << endl;
//		cout << "1 - ADD Customer" << endl;
//		cout << "2 - REMOVE Customer" << endl;
//		cout << "3 - DISPLAY ALL Customers" << endl;
//		cout << "Please enter your Choice" << endl;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 0:
//			break;
//		case 1:
//			counter++;
//			waitingCounter++;
//			tabor.enqueue(counter);
//			cout << "WELCOME you are Customer number " << counter << endl;
//			cout << "Waiting Customer: " << waitingCounter << endl;
//			break;
//		case 2:
//			counter--;
//			tabor.dequeue();
//			cout << "THANK YOU Customer number " << counter++ << endl;
//			break;
//		case 3:
//			tabor.display();
//		}
//
//		cout << endl;
//		cout << endl;
//
//
//	} while (choice != 0);
//
//	return 0;
//}

// Question 3) (Q3)
// int main() {
//
//	Queue q1(4);
//	Queue q2(2);
//	string klma;
//
//	do
//	{
//		cout << "Please enter a word of length 4" << endl;
//		cin >> klma;
//
//	} while (klma.size() != 4);
//
//	for (int i = 0; i < klma.size(); i++) {
//		q1.enqueue(klma[i]);
//	}
//
//	for (int i = 0; i < 4; i++) {
//		if (i == 0 || i == 3) {
//			cout << (char)q1.dequeue() << " ";
//		}
//		else {
//			q2.enqueue(q1.dequeue());
//		}
//	}
//	// awl ma hatb2a empty hybtl y3ml pop lel elements w sa3etha el program hy-terminate
//	while (!q2.isEmpty()) {
//		cout << (char)q2.dequeue() << " ";
//	}
//
//	return 0;
//}

// Question 4) (Q4)
int main()
{

    int size, input;
    cout << "How many elements you want to enter? \n";
    cin >> size;
    Queue q1(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element number " << i + 1 << endl;
        cin >> input;
        q1.enqueue(input);
        cout << "The size of the queue is: " << q1.getSize() << endl;
    }
    q1.Display();
    cout << "Enter the number you want to dequeue " << endl;
    cin >> input;

    if (q1.Search(input))
    {
        while (!q1.isEmpty())
        {
            int val = q1.dequeue();
            if (input == val)
            {
                q1.Display();
                break;
            }
        }
    }
    else
    {
        cout << "The element can not be found in the queue \n";
    }

    return 0;
}

// Question 5) (Q5)
