
/*write the program to process data of customer and save it to binary file customer class should have properties ID, name, credit card no. implement approriate exception handling and validation like 
 credit card number. Creedit card number should be of 16 digit length. Display data on console */


#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<iomanip>
using namespace std;


class Customer 
{
	public:
    	int ID;
    	string name;
    	string creditCardNo;

    	void inputData() 
	{
        	cout<<"Enter Customer ID: ";
        	cin>>ID;
		
        	cout<<"Enter Name: ";
       		cin.ignore(); 
        	getline(cin, name);

        	cout<<"Enter credit card number: ";
        	cin>>creditCardNo;
        	validateCreditCard(creditCardNo);
    	}
	
/*
	void compare(Customer a, Customer b)
	{
		if(a.ID==b.ID)
		{
			cout<<"Customer ID should be a Unique number"<<endl;
		}
		else
		{
			cin>>ID
		}
	}
*/	 
    	void validateCreditCard(const string& cardNo)
       	{
       		 if (cardNo.length() != 16 ) 
		 {

            		throw invalid_argument("Insert the 16 digit Credit card number.");
       		 }
   	 }

    	void displayData() const 
    	{
        	cout<<ID<<", "<<name<<", "<<creditCardNo<<endl;
    	}
};


void saveToBinaryFile(const Customer& customer, const string& filename) 
{
    ofstream ofs(filename, ios::binary | ios::app);
    if (!ofs) 
    {
        throw runtime_error("File is not open file for writing.");
    }
    ofs.write(reinterpret_cast<const char*>(&customer), sizeof(Customer));
    ofs.close();
}


int main() 
{
    try 
    {
        int totalCust;
        cout << "Enter the total number of customers: ";
        cin >> totalCust;

	Customer C[totalCust];
	for (int i = 0; i < totalCust; i++)
        {
            C[i];
            C[i].inputData();

            saveToBinaryFile(C[i], "customersList.dat");
        }
/*	
	C[i].compare(

*/
	for (int i=0; i<totalCust; i++)
	{
		C[i].displayData();
	}


    } catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
