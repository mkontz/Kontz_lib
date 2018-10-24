#include <iostream>
#include <string>
#include "../smartPointer.h"
#include "myKid.h"

#define private public
#define protected public


void incrementAge(SmartPointer<myKid> kid)
{
	(*kid).getAge()++;

	kid->getAge()++;

	kid.printPntrInfo();
	kid->printInfo();
};

int main()
{
	std::cout << "Create empty smart pointer" << std::endl;
	SmartPointer<myKid> sp1;
	sp1.printPntrInfo();

	{
		// myKid* pIDK = new myKid("Isabella", 8);
		std::cout << "Create new kid smart point in new context" << std::endl;
		SmartPointer<myKid> sp2(new myKid("Isabella", 8));
		sp1.printPntrInfo();
		sp2.printPntrInfo();
		(*sp2).printInfo();

		std::cout << "Copy to empty pointer" << std::endl;
		sp1 = sp2;
		sp1.printPntrInfo();
		(*sp1).printInfo();
		sp2.printPntrInfo();
		(*sp2).printInfo();
		{
			std::cout << "Create new kid smart point in new context" << std::endl;
			SmartPointer<myKid> sp3(new myKid("ALejandro", 6));
			sp1.printPntrInfo();
			(*sp1).printInfo();
			sp2.printPntrInfo();
			(*sp2).printInfo();
			sp3.printPntrInfo();
			(*sp3).printInfo();

			std::cout << "Create new kid smart point in new context" << std::endl;
			SmartPointer<myKid> sp4(sp3);
			sp1.printPntrInfo();
			(*sp1).printInfo();
			sp2.printPntrInfo();
			(*sp2).printInfo();
			sp3.printPntrInfo();
			(*sp3).printInfo();
			sp4.printPntrInfo();
			(*sp4).printInfo();

			std::cout << "Increment age new kid smart point in new context" << std::endl;
			incrementAge(sp1);
			incrementAge(sp2);
			incrementAge(sp3);
			sp1.printPntrInfo();
			(*sp1).printInfo();
			sp2.printPntrInfo();
			(*sp2).printInfo();
			sp3.printPntrInfo();
			(*sp3).printInfo();
			sp4.printPntrInfo();
			(*sp4).printInfo();

			std::cout << "Copy old smart pointer to new smart pointer" << std::endl;
			sp3 = sp2;
			sp1.printPntrInfo();
			(*sp1).printInfo();
			sp2.printPntrInfo();
			(*sp2).printInfo();
			sp3.printPntrInfo();
			(*sp3).printInfo();
			sp4.printPntrInfo();
			(*sp4).printInfo();
			
		}
		std::cout << "Remove context of one of the smart pointers" << std::endl;
		sp1.printPntrInfo();
		(*sp1).printInfo();
		sp2.printPntrInfo();
		(*sp2).printInfo();
	}
	std::cout << "Remove context of one of the smart pointers" << std::endl;
	sp1.printPntrInfo();
	(*sp1).printInfo();
   
	// sp1.printPntrInfo();
	return 0;
}




