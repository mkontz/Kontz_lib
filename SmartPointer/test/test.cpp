#include <iostream>
#include <string>
#include "../smartPointer.h"
#include "myKid.h"

#define private public
#define protected public

using namespace MEK;

void incrementAge(SmartPointer<myKid> kid)
{
	(*kid).getAge()++;

	kid->getAge()++;

	// kid.printPntrInfo();
	// kid->printInfo();
};




bool compareSmartPointer(SmartPointer<myKid> sp1, SmartPointer<myKid> sp2, unsigned expectCnt = 1)
{
	bool match = true;

	if (sp1->getAge() != sp2->getAge())
	{
		match = false;
		std::cout << "        Ages don't match: Age 1: " << sp1->getAge() << ", Age 2: " << sp2->getAge() << std::endl;
	}
	else
	{
		std::cout << "        Ages  match: Ages: " << sp1->getAge() << std::endl;
	}

	if (sp1->getName() != sp2->getName())
	{
		match = false;
		std::cout << "        Names don't match: Name 1: " << sp1->getName() << ", Name 2: " << sp2->getName() << std::endl;
	}
	else
	{
		std::cout << "        Names match: Name: " << sp1->getName() << std::endl;
	}

	if (sp1.getSmPntr() != sp2.getSmPntr())
	{
		match = false;
		std::cout << "        Smart pointer to objects don't match: smartPointer 1: " << (uint64_t) sp1.getSmPntr() << ", smartPointer 2: " << (uint64_t) sp2.getSmPntr() << std::endl;
	}
	else
	{
		std::cout << "        Smart pointer to objects match: smartPointer: " << (uint64_t) sp1.getSmPntr() << std::endl;
	}

	if ((sp1.getSmCnt() != sp2.getSmCnt()) || (sp1.getSmCnt() != expectCnt + 2))
	{
		match = false;
		std::cout << "        Smart pointer counts don't match: smartPointer 1: " << (uint64_t) sp1.getSmCnt() << ", smartPointer 2 = " << (uint64_t) sp2.getSmCnt() << ", expected: " << expectCnt << " + 2 = " << expectCnt + 2 << std::endl;
	}
	else
	{
		std::cout << "        Smart pointer counts match: smartPointer = " << expectCnt << " + 2 = " << expectCnt + 2 << std::endl;
	}

	return match;
}

bool compareSmartPointer(SmartPointer<myKid> sp1, myKid* kid2, unsigned expectCnt = 1)
{
	bool match = true;

	if (sp1->getAge() != kid2->getAge())
	{
		match = false;
		std::cout << "        Ages don't match: Age 1: " << sp1->getAge() << ", Age 2: " << kid2->getAge() << std::endl;
	}
	else
	{
		std::cout << "        Ages  match: Ages: " << sp1->getAge() << std::endl;
	}

	if (sp1->getName() != kid2->getName())
	{
		match = false;
		std::cout << "        Names don't match: Name 1: " << sp1->getName() << ", Name 2: " << kid2->getName() << std::endl;
	}
	else
	{
		std::cout << "        Names match: Name: " << sp1->getName() << std::endl;
	}

	if (sp1.getSmCnt() != expectCnt + 1)
	{
		match = false;
		std::cout << "        Smart pointer count don't match: smartPointer 1: " << (uint64_t) sp1.getSmCnt() << ", expected: " << expectCnt << " + 1 = " << expectCnt + 1 << std::endl;
	}
	else
	{
		std::cout << "        Smart pointer count match: smartPointer = " << expectCnt << " + 1 = " << expectCnt + 1 << std::endl;
	}

	return match;
}

int main()
{
	bool allTestsPassed = true;
	unsigned count_IDK = 0;
	unsigned count_AEK = 0;

	////////////////////////////////////////////////////////////////
	std::cout << "Create empty smart pointer using default constructor\n";
	////////////////////////////////////////////////////////////////

	SmartPointer<myKid> sp1;

	////////////////////////////////////////////////////////////////
	if ((NULL == sp1.getSmPntr()) && ( sp1.getSmCnt() == 0))
	{
		std::cout << "    Smart pointer is empty - Passed\n\n";
	}
	else
	{
		std::cout << "    Smart pointer is not empty - Failed\n\n";
		allTestsPassed = false;
	}

	////////////////////////////////////////////////////////////////
	std::cout << "Create new kid smart pointer using object pointer constructor\n";
	////////////////////////////////////////////////////////////////

	myKid* pIDK = new myKid("Isabella", 8);
	SmartPointer<myKid> sp2(pIDK);
	count_IDK++;

	////////////////////////////////////////////////////////////////
	std::cout << "    Test if smart pointer's and data match\n";
	if (compareSmartPointer(sp2, pIDK, count_IDK))
	{
		std::cout << "    SmartPointer and data match - Passed\n\n";
	}
	else
	{
		std::cout << "    SmartPointer and data don't match - Failed\n\n";
		allTestsPassed = false;
	}

	////////////////////////////////////////////////////////////////
	std::cout << "Use copy operator to update empty smart pointer." << std::endl;
	////////////////////////////////////////////////////////////////

	sp1 = sp2;
	count_IDK++;

	////////////////////////////////////////////////////////////////
	std::cout << "    Test if smart pointers and their data match.\n";
	if (compareSmartPointer(sp1, sp2, count_IDK))
	{
		std::cout << "    SmartPointers match - Passed\n\n";
	}
	else
	{
		std::cout << "    SmartPointers don't match - Failed\n\n";
		allTestsPassed = false;
	}

	{
		////////////////////////////////////////////////////////////////
		std::cout << "Create new kid smart pointer in new context" << std::endl;
		////////////////////////////////////////////////////////////////

		SmartPointer<myKid> sp3(new myKid("ALejandro", 6));
		count_AEK++;

		////////////////////////////////////////////////////////////////
		std::cout << "    Test if smart pointer's and data match\n";
		if (compareSmartPointer(sp3, &(*sp3), count_AEK))
		{
			std::cout << "    SmartPointer and data match - Passed\n\n";
		}
		else
		{
			std::cout << "    SmartPointer and data don't match - Failed\n\n";
			allTestsPassed = false;
		}

		////////////////////////////////////////////////////////////////
		std::cout << "Create new kid smart point using copy constructor" << std::endl;
		////////////////////////////////////////////////////////////////

		SmartPointer<myKid> sp4(sp3);
		count_AEK++;

		////////////////////////////////////////////////////////////////
		std::cout << "    Test if smart pointers and their data match.\n";
		if (compareSmartPointer(sp3, sp4, count_AEK))
		{
			std::cout << "    SmartPointers match - Passed\n\n";
		}
		else
		{
			std::cout << "    SmartPointers don't match - Failed\n\n";
			allTestsPassed = false;
		}

		////////////////////////////////////////////////////////////////
		std::cout << "Increment age new kid smart point in new context" << std::endl;
		////////////////////////////////////////////////////////////////

		incrementAge(sp1);
		incrementAge(sp2);
		incrementAge(sp3);

		////////////////////////////////////////////////////////////////

		std::cout << "    Test if smart pointers and their data match.\n";
		if (compareSmartPointer(sp1, sp2, count_IDK))
		{
			std::cout << "    SmartPointers match - Passed\n\n";
		}
		else
		{
			std::cout << "    SmartPointers don't match - Failed\n\n";
			allTestsPassed = false;
		}

		std::cout << "    Test if smart pointers and their data match.\n";
		if (compareSmartPointer(sp3, sp4, count_AEK))
		{
			std::cout << "    SmartPointers match - Passed\n\n";
		}
		else
		{
			std::cout << "    SmartPointers don't match - Failed\n\n";
			allTestsPassed = false;
		}

		////////////////////////////////////////////////////////////////
		std::cout << "Copy old smart pointer to new smart pointer" << std::endl;
		////////////////////////////////////////////////////////////////

		sp3 = sp2;
		count_AEK--;
		count_IDK++;

		////////////////////////////////////////////////////////////////

		std::cout << "    Test if smart pointers and their data match.\n";
		if (compareSmartPointer(sp1, sp2, count_IDK))
		{
			std::cout << "    SmartPointers match - Passed\n\n";
		}
		else
		{
			std::cout << "    SmartPointers don't match - Failed\n\n";
			allTestsPassed = false;
		}


		std::cout << "    Test if smart pointers and their data match.\n";
		if (compareSmartPointer(sp1, sp3, count_IDK))
		{
			std::cout << "    SmartPointers match - Passed\n\n";
		}
		else
		{
			std::cout << "    SmartPointers don't match - Failed\n\n";
			allTestsPassed = false;
		}

		std::cout << "    Test if smart pointers and their data match.\n";
		if (compareSmartPointer(sp3, sp4, count_AEK))
		{
			std::cout << "    SmartPointers match (not expected) - Failed\n\n";
			allTestsPassed = false;
		}
		else
		{
			std::cout << "    SmartPointers don't match (as expected) - Passed\n\n";
			
		}


		////////////////////////////////////////////////////////////////
		std::cout << "Clear a smart pointers\n" << std::endl;
		////////////////////////////////////////////////////////////////
		sp3.clear();
		count_IDK--;

		////////////////////////////////////////////////////////////////
		if ((NULL == sp3.getSmPntr()) && ( sp3.getSmCnt() == 0))
		{
			std::cout << "    Smart pointer is empty - Passed\n\n";
		}
		else
		{
			std::cout << "    Smart pointer is not empty - Failed\n\n";
			allTestsPassed = false;
		}

		std::cout << "    Test if remaining smart pointers decrement count.\n";
		if (compareSmartPointer(sp1, sp2, count_IDK))
		{
			std::cout << "    SmartPointers match - Passed\n\n";
		}
		else
		{
			std::cout << "    SmartPointers don't match - Failed\n\n";
			allTestsPassed = false;
		}

		////////////////////////////////////////////////////////////////
		std::cout << "Remove context of two of the smart pointers\n" << std::endl;
		////////////////////////////////////////////////////////////////
		sp3 = sp1;
		count_AEK--;
	}

	////////////////////////////////////////////////////////////////
	std::cout << "    Test if smart pointers and their data match.\n";
	if (compareSmartPointer(sp1, sp2, count_IDK))
	{
		std::cout << "    SmartPointers match - Passed\n\n";
	}
	else
	{
		std::cout << "    SmartPointers don't match - Failed\n\n";
		allTestsPassed = false;
	}

	////////////////////////////////////////////////////////////////
	// Summary of all tests.
	////////////////////////////////////////////////////////////////
	if (allTestsPassed)
	{
		std::cout << "All tests passed!!\n\n";
	}
	else
	{
		std::cout << "Not all tests passed!!\n\n";
	}
	////////////////////////////////////////////////////////////////

	return 0;
}




