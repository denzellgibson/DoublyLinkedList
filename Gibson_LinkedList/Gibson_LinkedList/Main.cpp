//Denzell Gibson
//CSC382 10:30am
//5/25/2017

#include "Header.h"
#include "LinkedList.h"
#include "Node.h"

int main()
{
	//Testing.

	LinkedList<int> list; //Creates a new LinkedList object.
	LinkedList<std::string> slist;
	LinkedList<bool> blist;

	std::cout << "Adding nodes." << std::endl;
	for (int i = 1; i <= 100; i++)
	{
		list.insert(i);
	}
	std::cout << std::endl; //Spacing purposes.

	list.displayData();
	std::cout << std::endl;

	std::cout << "Max: " << list.findMaximum() << std::endl;
	std::cout << "Min: " << list.findMinimum() << std::endl;
	std::cout << std::endl;

	std::cout << "Deleting Nodes" << std::endl;
	for (int i = 1; i <= 100; i++)
	{
		list.deleteNode(i);
	}
	std::cout << std::endl;

	list.displayData();
	std::cout << std::endl;

	std::cout << "Inserting Nodes" << std::endl;
	slist.insert("1");
	slist.insert("2");
	slist.insert("10");
	slist.insert("20");
	slist.insert("100");
	slist.insert("200");
	slist.insert("1000");
	slist.insert("2000");
	slist.insert("Bob");
	slist.insert("Jerry");
	std::cout << std::endl;

	slist.displayData();
	std::cout << std::endl;

	std::cout << "Largest String: " << slist.findMaximum() << std::endl;
	std::cout << "Smallest String: " << slist.findMinimum() << std::endl;
	std::cout << std::endl;
	
	blist.insert(true);
	blist.insert(false);
	blist.displayData();
	std::cout << std::endl;

	std::cout << blist.findMaximum() << std::endl;
	std::cout << blist.findMinimum() << std::endl;
	std::cout << std::endl;

	system("pause");
	return 0;
}