#include "main.hpp"
/*
	cout << "	 -------------------------------------------" << endl;
	cout << "	|	INDEX	|	FIRSTNAME	|	LASTNAME	|	 NICKNAME |" << endl;
	cout << " 	-------------------------------------------" << endl;
*/

string getIndex(int index)
{
	string rtn;


	rtn = "|";
	rtn.insert(1, 9, ' ');
	rtn.insert(rtn.length(), 1, (char)index + '0');
	return (rtn);
}

string getInfo(string info)
{
	string	rtn;
	string	temp;

	if (info.length() > 10)
	{
		rtn = info;
		rtn.resize(9);
		rtn.shrink_to_fit();
		rtn.insert(rtn.length(), 1, '.');
	}
	else
	{
		temp = info;
		rtn.insert(0, 10 - temp.length(), ' ');
		rtn += info;
	}
	return (rtn);

}

void printContact(Contact *info, int index)
{
	string buffer;
	string sep1;
	string sep2;

	sep1 = "|";
	sep2 = " ";
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			buffer += getIndex(index);
		}
		else if (i == 1)
		{
			buffer += getInfo(info->firstName_);
		}
		else if (i == 2)
		{
			buffer += getInfo(info->lastName_);
		}
		else if (i == 3)
		{
			buffer += getInfo(info->nickName_);
		}
		
		buffer += sep1;
	}
	cout << buffer << endl;
	/*
	cout << "first name:"		<<	info->firstName_ << endl;
	cout << "last name:"		<<	info->lastName_ << endl;
	cout << "nickname:"			<<	info->nickName_ << endl;
	cout << "phone numer:"		<<  info->phoneNumber_ << endl;
	cout << "darkest secret:"	<<	info->darkestSecret_ << endl;
	*/
}

Contact::Contact()
{
	cin.clear();
	cin.ignore();
	cout << "first name:\n";
	getline(cin, firstName_);
	cout << "last name:" << endl;
	getline(cin, lastName_);
	cout << "nickname:" << endl;
	getline(cin, nickName_);
	cout << "phone numer:" << endl;
	getline(cin, phoneNumber_);
	cout << "darkest secret:" << endl;
	getline(cin, darkestSecret_ );
}

void printAllInfo(class Contact *info)
{
	cout << "first name:	" << info->firstName_ << endl;
	cout << "last name:	" <<  info->lastName_ << endl;
	cout << "nickname:	" <<  info->nickName_ << endl;
	cout << "phone numer:	" <<  info->phoneNumber_ << endl;
	cout << "darkest secret:\n	" <<  info->darkestSecret_ << endl;
}
void selectContact(class Queue *record)
{
	int index;
	int i;
	QNode *actual;

	i = 1;
	cout << "Enter index of desired contact:" << endl;
	do
	{
   		while(!(cin >> index)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
		 }
		if (!(index > 0 && index <= record->size))
			cout << "No contact exist under such index!" << endl;
	}
	while (!(index > 0 && index <= record->size));
	actual = record->front;
	while (actual != NULL && index != i)
	{
		actual = actual->next;
		i++;
	}
	printAllInfo(actual->item);
}