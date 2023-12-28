#include <string>
#include <iostream>
using namespace std;

class Tovar
{

private:
	string name;
	double price;
public:
	//-------------Setteru--------------//
	void setName()
	{
		
		getline(cin, name);
	}
	void setPrice()
	{
		double n_price;
		cin >> n_price;
		price = n_price;
	}
	//-----------Getteru----------------//
	string getName()
	{
		return name;
	}
	double getPrice()
	{
		return price;
	}
	//-----------------------------------//
};

class Zamovnuk
{
private:
	string zam_name;
	string adress;
	string number;
	int size = 0;
	Tovar* items = new Tovar[size];

public:

	

	Zamovnuk(string zam_name_, string adress_, string number_): zam_name{ zam_name_ }, adress{ adress_ }, number{ number_ }
	{

	}
	~Zamovnuk()
	{

	}

	void fill_item(int& i, Tovar*& items)
	{
		cout << "\nEnter name: ";
		cin.ignore(256, '\n');
		items[i].setName();
		cout << "\nEnter price: ";
		items[i].setPrice();
	}

	void add_item()
	{

		int new_size = size + 1;
		Tovar* tmp = new Tovar[new_size];

		for (int i = 0; i < new_size; i++)
		{
			if (i + 1 != new_size)
			{
				tmp[i] = items[i];
			}
			else
			{
				fill_item(i, tmp);
			}
		}

		delete[]items;
		items = tmp;
		size = new_size;
	}

	void show_items()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\n------------ Item " << i+1 << " ------------";
			cout << "\nThe item name: "<< items[i].getName();
			cout << "\nThe item price: "<< items[i].getPrice();
			cout << "\n---------------------------------"<<endl;
			
		}
		if (KILKIST() == 1)
		{
			cout << "\nIn general-- " << KILKIST() << " --item" << endl;
		}
		else if (KILKIST() == 0)
		{
			cout <<  "\nIn general-- " << KILKIST() << " --items" << endl;
		}
		else 
		{
			cout << "\nIn general-- " << KILKIST() << " --items" << endl;
		}
	}

	int KILKIST()
	{
		int kilkist;
		kilkist = size;

		return kilkist;
	}

	void delete_item()
	{
		if (size == 0)
		{
			cout << "\nThere are no items in your basket";
		}
		else
		{
			int item_num;
			int new_size = size - 1;
			Tovar* tmp = new Tovar[new_size];
			cout << "\nEnter the item number you want to delete: ";
			cin >> item_num;
			item_num--;

			int j = 0;

			for (int i = 0; i < new_size; i++)
			{
				if (item_num == i) 
				{
					
					tmp[i] = items[i + j];\
						j++;
				}
				else
				{
					
					tmp[i] = items[j];
				}
				j++;
			}

			delete[]items;
			items = tmp;
			size = new_size;
			

		}
	}

	void fill_client()
	{
		Zamovnuk first("Sasha","Dovzhenka","+380573546721");
	}

	void vartist()
	{
		int summa = 0;
		for (int i = 0; i < size; i++)
		{
			summa += items[i].getPrice();
		}
		cout << "\n General sum is: " << summa<<endl;
	}

	void see_all_info()
	{
		cin.ignore(1,'\n');
		cout << "\nZamovnuk's name is: "<< zam_name;
		cout << "\nZamovnuk's adress is: " << adress;
		cout << "\nZamovnuk's number is: " << number << endl;

		show_items();
		vartist();
	}
};


int main()
{
	Zamovnuk first("Sergiy","Mazepu","+3807456434");
	bool k = true;//для меню - точка виходу
	int num;//для меню

	while (k)
	{
		cout << "\nEnter 0 to leave\nEnter 1 to add item\nEnter 2 to show items\nEnter 3 to delete item\nEnter 4 to count full sum\nEnter 5 to see all the information"<<endl;
		cin >> num;
		if (num == 0)
		{
			k = false;
		}
		else if (num == 1)
		{
			first.add_item();
		}
		else if (num == 2)
		{
			first.show_items();
		}
		else if (num == 3)
		{
			first.delete_item();
		}
		else if (num == 4)
		{
			first.vartist();
		}
		else if (num == 5)
		{
			first.see_all_info();
		}
	}
	
}