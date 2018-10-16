# CS540-Lab-3
Read files and sort using pointers.
/*
Saw, Wailinn
CS540
Lab 3 ptr

*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>


using namespace std;
#define arraySize 50
struct RECORD
{
	string FirstName = "";
	string LastName = "";
	string Id = "";
	string Email = "";
	float GPA = 0;
};

//Reads the text file.
void readFile(RECORD unsorted[], RECORD *ptrSort[], int &num);

//Menu
void mainMenu(RECORD unsorted[], RECORD *ptrSort[], int size);

//Sort function
void sort(RECORD *ptrSort[],  int size, int choice);

void sortMenu(RECORD unsorted[], RECORD *ptrSort[], int size);

//Prints current records.
void printCurrentValues(RECORD *sorted[], RECORD unsorted[], const int size, int choice);

//Prints orignalfile.
//void printOrignalFile(RECORD unsorted[], int size);


int main()
{
	//Size of items in array.
	int size = 0;

	RECORD unsorted[arraySize]; //Will have unsorted oritonal values.
	RECORD *ptrSort[arraySize]; //Pointer array.

	readFile(unsorted, ptrSort, size);//function that reads the file and stores it into the arrays.
	mainMenu(unsorted, ptrSort, size);//Main menu funciton.

	cin.ignore();
	cin.get();


	return 0;
}
void readFile(RECORD unsorted[], RECORD *ptrSort[], int &num)
{

	ifstream file;
	string fileName = "C:\\Users\\student.CS\\Desktop\\File.txt";
	do {
		/*cout << "Enter the file path location with extentions:" << endl;
		cin >> fileName;*/
		file.open(fileName);
		if (!file)
		{
			cout << "Cannot open file, try again. \n";
		}
	} while (!file);
	cout << "Will only read up to " << arraySize << " student records.\n"
		<< "Reading file.." << endl;
	while (file && !file.eof() && num < arraySize)
	{
		file >> unsorted[num].FirstName >> unsorted[num].LastName >> unsorted[num].GPA >> unsorted[num].Id >> unsorted[num].Email;
		ptrSort[num] = &unsorted[num];
		num++;
	}
	num--;
	cout << "number: " <<num << endl;
	cout << "Done reading file contents, will close file." << endl;
	file.close(); //closes the file after being read.
}

void mainMenu(RECORD unsorted[], RECORD *ptrSort[], int size)
{
	int choice;
	do {

		cout << "\n\n\t\t\tMain Menu" << endl
			<< "\t\t-------------------------" << endl
			<< "\t\t1) Print Unsorted Records" << endl
			<< "\t\t2) SortBy Field" << endl
			<< "\t\t3) Quit" << endl;
		cout << "\nPlease select an option above: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			printCurrentValues(ptrSort, unsorted, size, 1);
			break;
		case 2:
			sortMenu(unsorted, ptrSort, size);
			break;
		case 3:
			cout << "exiting...";
			break;
		default:
			cout << "Please enter a vaild input.";
			break;
		}


	} while (choice != 3);

}
void sortMenu(RECORD unsorted[], RECORD *ptrSort[], int size)
{
	int choice;
	do {
		cout << "\n\n\t\t\tChoce options" << endl
			<< "\t\t-------------------------" << endl
			<< "\t\t1) Sort by First name" << endl
			<< "\t\t2) Sort by Last Name" << endl
			<< "\t\t3) sort by GPA" << endl
			<< "\t\t4) sort by ID" << endl
			<< "\t\t5) sort by Email" << endl
			<< "\t\t6) Print current values" << endl
			<< "\t\t7) Return to main menu" << endl;
		cout << "\nPlease select an option above: ";
		cin >> choice;
		if (choice < 1 || choice > 7)
		{
			cout << "Please input a valid input.";
		}
		else if (choice == 6)
		{
			printCurrentValues(ptrSort, unsorted, size, 2);
		}
		else
		{
			sort(ptrSort, size, choice);
			//mainMenu(unsorted, ptrSort, size);
		}
	} while (choice != 7);

}

void sort(RECORD *ptrSort[], int size, int choice)
{

	bool check = false;
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			RECORD *tempAccount = nullptr;
			switch (choice)
			{
			case 1:
				check = ptrSort[j]->FirstName > ptrSort[j+1]->FirstName;
				break;
			case 2:
				check = ptrSort[j]->LastName > ptrSort[j+1]->LastName;
				break;
			case 3:
				check = ptrSort[j]->GPA > ptrSort[j+1]->GPA;
				break;
			case 4:
				check = ptrSort[j]->Id > ptrSort[j+1]->Id;
				break;
			case 5:
				check = ptrSort[j]->Email > ptrSort[j+1]->Email;
				break;
			case 6:

				break;
			}
			if (check)
			{

				tempAccount = ptrSort[j];
				ptrSort[j] = ptrSort[j+1];
				ptrSort[j+1] = tempAccount;
				check = false;
			}
		}
	}
}

void printCurrentValues(RECORD *ptrSort[], RECORD unsorted[], const int size, int choice)
{
	if (choice == 2)
	{
		cout << "First name" << "\t" << "Last name" << "\t" << "GPA" << "\t\t" << "ID" << "\t\t" << "Email" << endl;
		cout << "------------------------------------------------------------------------------------\n";
		for (int i = 0; i < size; i++)
		{
			cout << ptrSort[i]->FirstName << "\t\t" << ptrSort[i]->LastName << setprecision(1) << fixed << "\t\t" << ptrSort[i]->GPA << "\t\t" << ptrSort[i]->Id << "\t" << ptrSort[i]->Email << endl;

		}
	}
	if (choice == 1)
	{
		cout << "First name" << "\t" << "Last name" << "\t" << "GPA" << "\t\t" << "ID" << "\t\t" << "Email" << endl;
		cout << "------------------------------------------------------------------------------------\n";
		for (int index = 0; index < size; index++)
		{
			cout << unsorted[index].FirstName << "\t\t" << unsorted[index].LastName << "\t\t" << setprecision(1) << fixed << unsorted[index].GPA << "\t\t" << unsorted[index].Id << "\t" << unsorted[index].Email << endl;
		}

	}
}


/***********************************************************/
/*						Program output					  */
/**********************************************************
Will only read up to 50 student records.
Reading file..
number: 12
Done reading file contents, will close file.


Main Menu
-------------------------
1) Print Unsorted Records
2) SortBy Field
3) Quit

Please select an option above: 1
First name      Last name       GPA             ID              Email
------------------------------------------------------------------------------------
john            Doe             1.0             112230203       jd@gmail.com
danny           oh              2.5             221440204       doh@yahoo.com
sam             smith           3.0             121345152       ssmith@gmail.com
kiara           james           4.0             532456225       kjames@yahoo.com
amy             wong            3.5             124253786       wong@gmail.com
vicky           wood            2.0             881145231       vwood@pierce.edu
gwen            reed            2.8             354125187       greed@pierce.edu
toby            weber           1.7             421548753       tweber@pierce.edu
alicia          kelley          2.2             521429651       akelley@pierce.edu
jose            webb            3.1             634567894       jwebb@pierce.edu
cory            castro          1.9             549854101       ccastro@pierce.edu
brian           klein           2.9             774556581       bklein@pierce.edu


Main Menu
-------------------------
1) Print Unsorted Records
2) SortBy Field
3) Quit

Please select an option above: 2


Choce options
-------------------------
1) Sort by First name
2) Sort by Last Name
3) sort by GPA
4) sort by ID
5) sort by Email
6) Print current values
7) Return to main menu

Please select an option above: 1


Choce options
-------------------------
1) Sort by First name
2) Sort by Last Name
3) sort by GPA
4) sort by ID
5) sort by Email
6) Print current values
7) Return to main menu

Please select an option above: 6
First name      Last name       GPA             ID              Email
------------------------------------------------------------------------------------
alicia          kelley          2.2             521429651       akelley@pierce.edu
amy             wong            3.5             124253786       wong@gmail.com
brian           klein           2.9             774556581       bklein@pierce.edu
cory            castro          1.9             549854101       ccastro@pierce.edu
danny           oh              2.5             221440204       doh@yahoo.com
gwen            reed            2.8             354125187       greed@pierce.edu
john            Doe             1.0             112230203       jd@gmail.com
jose            webb            3.1             634567894       jwebb@pierce.edu
kiara           james           4.0             532456225       kjames@yahoo.com
sam             smith           3.0             121345152       ssmith@gmail.com
toby            weber           1.7             421548753       tweber@pierce.edu
vicky           wood            2.0             881145231       vwood@pierce.edu


Choce options
-------------------------
1) Sort by First name
2) Sort by Last Name
3) sort by GPA
4) sort by ID
5) sort by Email
6) Print current values
7) Return to main menu

Please select an option above: 3


Choce options
-------------------------
1) Sort by First name
2) Sort by Last Name
3) sort by GPA
4) sort by ID
5) sort by Email
6) Print current values
7) Return to main menu

Please select an option above: 6
First name      Last name       GPA             ID              Email
------------------------------------------------------------------------------------
john            Doe             1.0             112230203       jd@gmail.com
toby            weber           1.7             421548753       tweber@pierce.edu
cory            castro          1.9             549854101       ccastro@pierce.edu
vicky           wood            2.0             881145231       vwood@pierce.edu
alicia          kelley          2.2             521429651       akelley@pierce.edu
danny           oh              2.5             221440204       doh@yahoo.com
gwen            reed            2.8             354125187       greed@pierce.edu
brian           klein           2.9             774556581       bklein@pierce.edu
sam             smith           3.0             121345152       ssmith@gmail.com
jose            webb            3.1             634567894       jwebb@pierce.edu
amy             wong            3.5             124253786       wong@gmail.com
kiara           james           4.0             532456225       kjames@yahoo.com


Choce options
-------------------------
1) Sort by First name
2) Sort by Last Name
3) sort by GPA
4) sort by ID
5) sort by Email
6) Print current values
7) Return to main menu

Please select an option above: 4


Choce options
-------------------------
1) Sort by First name
2) Sort by Last Name
3) sort by GPA
4) sort by ID
5) sort by Email
6) Print current values
7) Return to main menu

Please select an option above: 6
First name      Last name       GPA             ID              Email
------------------------------------------------------------------------------------
john            Doe             1.0             112230203       jd@gmail.com
sam             smith           3.0             121345152       ssmith@gmail.com
amy             wong            3.5             124253786       wong@gmail.com
danny           oh              2.5             221440204       doh@yahoo.com
gwen            reed            2.8             354125187       greed@pierce.edu
toby            weber           1.7             421548753       tweber@pierce.edu
alicia          kelley          2.2             521429651       akelley@pierce.edu
kiara           james           4.0             532456225       kjames@yahoo.com
cory            castro          1.9             549854101       ccastro@pierce.edu
jose            webb            3.1             634567894       jwebb@pierce.edu
brian           klein           2.9             774556581       bklein@pierce.edu
vicky           wood            2.0             881145231       vwood@pierce.edu


Choce options
-------------------------
1) Sort by First name
2) Sort by Last Name
3) sort by GPA
4) sort by ID
5) sort by Email
6) Print current values
7) Return to main menu

Please select an option above: 7


Main Menu
-------------------------
1) Print Unsorted Records
2) SortBy Field
3) Quit

Please select an option above: 3
exiting...
*/
