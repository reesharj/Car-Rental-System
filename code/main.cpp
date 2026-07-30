#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;


//variable declaration
int option, option2, option3, option4, option5, option6, option7, option8, option9, option10, option11;
int m, j, c;
int checkemail, checkpass, confirmationpass, length, carcompare, pickupcompare, delivercompare;
int month, date, hours, seater_car;
int i = 0, carcount = 4, z = 0, numdriver = 2;
int arrySeat[50] = { 4,4,6,6 };

char email[99][99], password[99][99], firstname[99][99], lastname[99][99], phone[99][99];
char email1[99], password1[99], tempemail[99], temppassword[99], confirmpass[99], cartype[99], pickupdelivery[99], deliverypoint[99], starttime[99], ic_car[99], typecar_car[99], platenumber_car[99], colour_car[99];
char arryCar[50][50] = { "MYVI", "HONDA", "BMW", "STAREX" }, arryDrivername[99][99] = { "Ahmad bin Ali", "Fatimah binti Rahman" }, arryDrivernumber[99][99] = { "0123456789","0198765432" };
char driverchoice;

float arryPriceNoDriver[50] = { 6,10,18,30 };
float arryPriceDriver[50] = { 14,18,26,38 };
float total;

//function
int optionpage2();
void cartable();
float payment(char);
int paymentoption(float);
int datecheck(int);
char appdetails();
void seaterpricerange();

int main()
{
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
	cout << "x\t\t\t\t\t\t\t\tx" << endl;
	cout << "x\t\t\t\tGOCAR\t\t\t\tx" << endl;
	cout << "x\t\tCar Booking & Rental Application\t\tx" << endl;
	cout << "x\t\t\t\t\t\t\t\tx" << endl;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
	cout << endl << endl << "\tOption : " << endl;
	cout << "\t\t1. Login" << endl << "\t\t2. Sign up" << endl << "\t\t3. Quit" << endl;
	option = optionpage2(); //call function optionpage2 (to check the input either valid or not)
	if (option == 1) //login
	{
		bool emailFound = false; //emailFound == 0 (email from input same with one of the email in array)

		cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl << endl << endl;
		cout << "Email: ";
		cin >> email1;
		for (m = 0; m < i; m++) //loop to check input email with all registered email
		{
			checkemail = strcmp(email[m], email1); //compare input with array
			if (checkemail == 0) //input same with one of the array
			{
				do
				{
					cout << "Password: ";
					cin >> password1;
					checkpass = strcmp(password[m], password1); //check password
					if (checkpass == 0) //password is correct
					{
						cout << endl << "Login succesful!" << endl;
						do //page option2
						{
							cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
							cout << endl << endl << "\tOption : " << endl;
							cout << "\t\t1. Customer" << endl << "\t\t2. Staff/Driver" << endl << "\t\t3. Back" << endl;
							option2 = optionpage2(); //check option either valid or not 
							if (option2 == 1) //customer
							{
								cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
								cout << endl << endl << "Welcome to GoCar where you can rent and booking a various type of car from us with affordable price." << endl << endl;
								cartable(); //car choice display
								cout << endl << "\tOption : " << endl;
								cout << "\t\t1. Order for now" << endl << "\t\t2. Order for later" << endl << "\t\t3. Back" << endl;
								option3 = optionpage2(); //check option either valid or not
								if (option3 == 1) //rent
								{
									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
									cout << endl << endl;
									driverchoice = appdetails(); //function call rent&book information details
									total = payment(driverchoice); //function call to calculate total
									option5 = paymentoption(total); //function call to choose payment method
									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
									cout << endl << endl << "Name\t\t: " << firstname[m] << " " << lastname[m] << endl; //name from the array
									cout << "Phone number\t: " << phone[m] << endl;
									cout << "Car type\t: " << cartype << endl;
									cout << "Time\t\t: " << hours << " hour(s) " << endl;
									switch (option5) //option5 = payment method
									{
									case 1:
										cout << "Credit Card\n";
										break;
									case 2:
										cout << "Debit Card\n";
										break;
									case 3:
										cout << "Online Banking\n";
										break;
									case 4:
										cout << "Cash\n";
										break;
									default:
										cout << "Invalid choice. Please select a valid payment method";
									}
									if (driverchoice == 'y') //display driver details if user choose to have a driver
									{
										cout << endl << "Driver name: " << arryDrivername[z] << endl;
										cout << "Driver contact: " << arryDrivernumber[z] << endl;
										++z; //current driver not available, next user will get diff driver
									}
									if (delivercompare == 0) //user choose deliver
										cout << endl << "Your car will be arrived at " << deliverypoint << " less than 1 hour!" << endl;
									if (pickupcompare == 0) //user choose pickup
										cout << endl << "Pickup your car at GoCar Melaka now!" << endl;
									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
									do
									{
										cout << endl << endl << "Enter (0) to go to the main menu >> ";
										cin >> option6;
										if (option6 == 0)
										{
											cout << endl << endl;
											main();
										}
										else
											cout << "Invalid input. Please re-enter again.";
									} while (option6 != 0);
								}

								else if (option3 == 2) //book
								{
									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
									cout << endl << endl << "Booking date" << endl;
									do
									{
										cout << endl << "Month (1-12): ";
										cin >> month;
										if (month >= 1 && month <= 12)
											date = datecheck(month); //callfunction datecheck to check numbers of days for every months.
										else
											cout << "Invalid input. Please re-enter again." << endl;
									} while (month < 1 || month > 12); //loop if input months not in range 1-12
									cout << "Start time (xx.xxam/pm): ";
									cin >> starttime;
									driverchoice = appdetails(); //rent&book information details
									total = payment(driverchoice); //calculate total
									option7 = paymentoption(total); //choose payment method
									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
									cout << endl << endl << "Name\t\t: " << firstname[m] << " " << lastname[m] << endl; //name from the array
									cout << "Phone number\t: " << phone[m] << endl;
									cout << "Car type\t: " << cartype << endl;
									cout << "Time\t\t: " << starttime << " (" << hours << " hour(s)) " << endl;
									cout << "Booking date\t: " << date << "/" << month << "/2024" << endl;
									switch (option7) //payment method
									{
									case 1:
										cout << "Credit Card\n";
										break;
									case 2:
										cout << "Debit Card\n";
										break;
									case 3:
										cout << "Online Banking\n";
										break;
									case 4:
										cout << "Cash\n";
										break;
									default:
										cout << "Invalid choice. Please select a valid payment method";
									}
									if (delivercompare == 0) // user choose deliver
										cout << endl << "Your car will be arrived at " << deliverypoint << " on " << date << "/" << month << "/ 2024, 15 minutes before " << starttime << "." << endl;
									if (pickupcompare == 0) //user choose pickup
										cout << endl << "Pickup your car at GoCar Melaka on " << date << "/" << month << "/2024." << endl;
									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl << endl;
									do
									{
										cout << endl << "Enter (0) to go to the main menu >> ";
										cin >> option8;
										if (option8 == 0)
										{
											cout << endl << endl;
											main();
										}
										else
											cout << "Invalid input. Please re-enter again." << endl;
									} while (option8 != 0);
								}
								else //back (option3 == 3)
									continue;
							}

							else if (option2 == 2) //staff
							{
								cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
								cout << endl << endl << "\tOption : " << endl;
								cout << "\t\t1. Car registration" << endl << "\t\t2. Driver registration" << endl << "\t\t3. Back" << endl;
								option9 = optionpage2(); //check option either valid or not
								if (option9 == 1)//car registration
								{
									ofstream outputFile("carregistration.txt", ios::app);

									if (!outputFile)
									{
										cerr << "File could not be opened \n";
										exit(1);
									}

									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
									cout << endl << endl << "Name: " << firstname[m] << " " << lastname[m] << endl; //name from the array
									cout << "NRIC: ";
									cin >> ic_car;
									cout << "Type car: ";
									cin >> typecar_car;
									_strupr_s(typecar_car); //convert to uppercase
									strcpy_s(arryCar[carcount], typecar_car); //copy to array
									cout << "Plate number: ";
									cin >> platenumber_car;
									cout << "Colour: ";
									cin >> colour_car;

									outputFile << firstname[m] << " " << lastname[m] << setw(10) << typecar_car << setw(10) << platenumber_car << setw(10) << colour_car << endl;

									do
									{
										cout << "4 seater/6 seater: ";
										cin >> seater_car;
										if (seater_car == 4 || seater_car == 6)
										{
											arrySeat[carcount] = seater_car; //copy to array
											seaterpricerange(); //price suggestion depends on number of seat
											cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl << endl;
											cout << "\t\tDETAILS OF CAR REGISTRATION\t" << endl << endl;

											ifstream inputFile("carregistration.txt", ios::app);

											if (!inputFile)
											{
												cerr << "File could not be opened \n";
												exit(1);
											}

											cout << "Name\t\t: " << firstname[m] << " " << lastname[m] << endl << "Car type\t: " << typecar_car << endl << "Plate number\t: " << platenumber_car << endl << "Colour\t\t: " << colour_car << endl;


											cout << endl << "Updated! " << endl << endl;
											cartable(); //display updated table
										}
										else
											"Invalid input. Please re-enter again.";
									} while (seater_car != 4 && seater_car != 6);

									do
									{
										cout << endl << "Enter (0) to go to the main menu >> ";
										cin >> option10;
										if (option10 == 0)
										{
											cout << endl << endl;
											main();
										}
										else
											cout << "Invalid input. Please re-enter again." << endl;
									} while (option10 != 0);
								}
								else if (option9 == 2)//driver registration
								{
									struct StaffDetail {
										string LicensePeriod;
										string NRIC;
									};//struct

									struct StaffDetail staff;

									ofstream outputFile("driverinfo.txt", ios::app); //inputfile

									if (!outputFile)
									{
										cerr << "File could not be opened \n";
										exit(1);
									}

									cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
									cout << endl << endl << "ENTER YOUR DETAILS TO BE A DRIVER FOR A CAR RENT" << endl << "----------------------------------------------------";
									cout << endl << "\nName: " << firstname[m] << " " << lastname[m] << endl; //name from the array
									cout << "Phone number: " << phone[m] << endl;
									cout << "License period: " << "(eg: 14/12/2012-13/05/2013)" << endl;
									cin >> staff.LicensePeriod;
									cout << "NRIC: ";
									cin >> staff.NRIC;

									outputFile << firstname[m] << " " << lastname[m] << "\t" << phone[m] << "\t" << staff.LicensePeriod << setw(10) << staff.NRIC << endl;

									ifstream inputFile("driverinfo.txt", ios::in); //output file

									if (!inputFile)
									{
										cerr << "File could not be opened \n";
										exit(1);
									}

									cout << "\n----------------------------------------------------" << endl;
									cout << endl << "\tDETAILS INFORMATION OF THE DRIVER\n" << endl;

									cout << "Name\t\t: " << firstname[m] << " " << lastname[m] << endl << "Phone number\t: " << phone[m] << endl << "License period: " << staff.LicensePeriod << endl << "IC number\t: " << staff.NRIC << endl << endl;

									cout << endl << "     ---YOUR DATA WILL BE SAVED, THANK YOU---" << endl;
									++numdriver; //number of driver increased.
									cout << "\n----------------------------------------------------" << endl;
									do
									{
										cout << endl << "Enter (0) to go to the main menu >> ";
										cin >> option11;
										if (option11 == 0)
										{
											cout << endl << endl;
											main();
										}
										else
											cout << "Invalid input. Please re-enter again." << endl;
									} while (option11 != 0);
								}
								else //back (option9 == 3)
									continue;
							}
							else //back (option == 3)
							{
								cout << endl << endl;
								main();
							}
						} while (option3 == 3 || option9 == 3);
					}
					else
						cout << "Incorrect password. Please check your password and try again." << endl;
				} while (checkpass != 0); //wrong pass, re-enter again.
				emailFound = true;
				break; //break looping bcs email already found.
			}
		}
		if (!emailFound) //email entered not registered yet
		{
			cout << "The email you entered doesn't belong to an account." << endl;
			do
			{
				cout << endl << "Press (0) to go to the main page >> ";
				cin >> option4;
				if (option4 == 0)
				{
					cout << endl << endl;
					main();
				}
				else
					cout << "Invalid input. Please re-enter again." << endl;
			} while (option4 != 0);
		}
	}

	else if (option == 2) //signup
	{
		ofstream outputFile("userinfo.txt", ios::app);

		if (!outputFile)
		{
			cerr << "File could not be opened \n";
			exit(1);
		}

		cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
		cout << endl << endl << "First name: ";
		cin >> firstname[i];
		cout << "Last name: ";
		cin >> lastname[i];
		cout << "Phone number: ";
		cin >> phone[i];
		do
		{
			//option3 = 0;
			cout << "Email: ";
			cin >> tempemail;
			for (int c = 0; c < i; c++)
			{
				checkemail = strcmp(email[c], tempemail); //compare input email with array to check if it has registered or not 
				if (checkemail == 0) //email found in array. already registeres
				{
					cout << "This email address is already registered." << endl;
					do
					{
						cout << endl << "Press (0) to go to the main page or press (1) to re-enter the email >> ";
						cin >> option3;
						if (option3 == 0)
						{
							cout << endl << endl;
							main();
						}
						else if (option3 == 1)
						{
							cout << endl;
							break;
						}
						else
							cout << "Invalid input. Please re-enter again." << endl;
					} while (option3 != 0 && option3 != 1);
				}
			}
		} while (option3 == 1);
		cout << "Password: ";
		cin >> temppassword;
		do
		{
			cout << "Confirm password: ";
			cin >> confirmpass;
			confirmationpass = strcmp(temppassword, confirmpass); //check either confirm password same wirh password entered above
			if (confirmationpass == 0) //if same
			{
				strcpy_s(email[i], tempemail); //copt to array
				strcpy_s(password[i], temppassword); //copt to array
				outputFile << firstname[i] << " " << lastname[i] << "\t" << phone[i] << "\t" << email[i] << endl;
				++i; //number of user registered increase
				cout << endl << "Registration successful!" << endl;
				cout << endl << endl;
				main();
			}
			else
				cout << "Password does not match. Please re-enter again." << endl;
		} while (confirmationpass != 0);
	}

	else // exit (option == 3)
	{
		cout << endl << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
		cout << endl << endl << "Exit" << endl;
	}

	return 0;
}

int optionpage2() //check input valid or not
{
	int x;

	do
	{
		cout << endl << "Enter your option >> ";
		cin >> x;
		if (x != 1 && x != 2 && x != 3)
			cout << "Invalid input. Please re-enter again." << endl;
	} while (x != 1 && x != 2 && x != 3);

	return x;
}

void cartable()
{
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "|\tCar type\t|\tSeat\t |\tPrice/hour\t|\tPrice/hour\t|" << endl;
	cout << "|\t\t\t|\t\t |   (without driver)   |    (Include driver)   |" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	for (j = 0; j < carcount; j++) //to print out all element in the array
	{
		length = strlen(arryCar[j]); //count the letter to arrange the size of table
		if (length < 10)
		{
			cout << "| " << j + 1 << ". " << arryCar[j] << " \t\t|    " << arrySeat[j];
			if (arryPriceNoDriver[j] < 10)
				cout << fixed << showpoint << setprecision(2) << " seater\t | \tRM  " << arryPriceNoDriver[j] << "\t| \t RM" << arryPriceDriver[j] << "\t| " << endl;
			else
				cout << fixed << showpoint << setprecision(2) << " seater\t | \tRM " << arryPriceNoDriver[j] << "\t| \t RM" << arryPriceDriver[j] << "\t| " << endl;
		}
		else
		{
			cout << "| " << j + 1 << ". " << arryCar[j] << " \t|    " << arrySeat[j];
			if (arryPriceNoDriver[j] < 10)
				cout << fixed << showpoint << setprecision(2) << " seater\t | \tRM  " << arryPriceNoDriver[j] << "\t\t| \t RM" << arryPriceDriver[j] << "\t| " << endl;
			else
				cout << fixed << showpoint << setprecision(2) << " seater\t | \tRM " << arryPriceNoDriver[j] << "\t\t| \t RM" << arryPriceDriver[j] << "\t| " << endl;
		}
		cout << "-----------------------------------------------------------------------------------------" << endl;
	}
}

float payment(char driver)
{
	float y = 0;

	if (driver == 'y')
		y = hours * arryPriceDriver[c]; //c is the number of the element choosen (car type)
	if (driver == 'n')
		y = hours * arryPriceNoDriver[c];

	return y;
}

int paymentoption(float z)
{
	int paymentOption;

	cout << endl << fixed << showpoint << setprecision(2) << "The total payment is RM " << z << endl;
	cout << endl << "\tSelect a payment method : " << endl;
	cout << "\t\t1. Credit Card\n";
	cout << "\t\t2. Debit Card\n";
	cout << "\t\t3. Online Banking\n";
	cout << "\t\t4. Cash\n";
	do
	{
		cout << endl << "Enter your option >> ";
		cin >> paymentOption;
		switch (paymentOption)
		{
		case 1:
			cout << "You chose Credit Card.\n";
			break;
		case 2:
			cout << "You chose Debit Card.\n";
			break;
		case 3:
			cout << "You chose Online Banking.\n";
			break;
		case 4:
			cout << "You chose Cash.\n";
			break;
		default:
			cout << "Invalid choice. Please select a valid payment method." << endl;
		}
	} while (paymentOption != 1 && paymentOption != 2 && paymentOption != 3 && paymentOption != 4);

	return paymentOption;
}

int datecheck(int month)
{
	int d = 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		do
		{
			cout << "Date (1-31): ";
			cin >> d;
			if (d < 1 || d > 31)
				cout << "Invalid input. Please re-enter again." << endl << endl;
		} while (d < 1 || d > 31);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		do
		{
			cout << "Date (1-30): ";
			cin >> d;
			if (d < 1 || d > 30)
				cout << "Invalid input. Please re-enter again." << endl << endl;
		} while (d < 1 || d > 30);
	}
	if (month == 2)
	{
		do
		{
			cout << "D (1-29): ";
			cin >> d;
			if (d < 1 || d > 29)
				cout << "Invalid input. Please re-enter again." << endl << endl;
		} while (d < 1 || d > 29);
	}

	return d;
}

char appdetails()
{
	struct data
	{
		char typeCar[99];
		char choice;
	};

	data customer;

	do
	{
		cout << "Enter car type: ";
		cin >> customer.typeCar;
		_strupr_s(customer.typeCar); //convert to uppercase
		strcpy_s(cartype, customer.typeCar); //copy to array (1D array)
		for (c = 0; c < carcount; c++) //check if the input car type is available in the array
		{
			carcompare = strcmp(arryCar[c], customer.typeCar);
			if (carcompare == 0) //available
			{
				do
				{
					cout << "Enter rent hours: ";
					cin >> hours;
					if (hours >= 0)
					{
						do
						{
							cout << "Pickup/Deliver: ";
							cin >> pickupdelivery;
							_strlwr_s(pickupdelivery); //convert to lowercase
							pickupcompare = strcmp(pickupdelivery, "pickup");
							delivercompare = strcmp(pickupdelivery, "deliver");
							if (pickupcompare == 0 || delivercompare == 0)
							{
								if (delivercompare == 0)
								{
									cout << "Enter deliver point: ";
									cin >> deliverypoint;
								}
								do
								{
									cout << "Do you want a driver? (y/n): ";
									cin >> customer.choice;
									if (customer.choice != 'y' && customer.choice != 'n')
										cout << "Invalid input. Please re-enter again." << endl << endl;
								} while (customer.choice != 'y' && customer.choice != 'n');
							}
							else
								cout << "Invaid input. Please re-enter again." << endl << endl;
						} while (pickupcompare != 0 && delivercompare != 0);
					}
					else
						cout << "Time must be in positive number. Please re-enter again." << endl << endl;
				} while (hours < 0);
				break; // break the loop to check the availabality car
			}
		}
		if (carcompare != 0)
			cout << "Invalid car type. Please re-enter again." << endl << endl;
	} while (carcompare != 0);

	return customer.choice;
}

void seaterpricerange()
{
	if (seater_car == 4)
		cout << "Price range (RM5-RM10): ";
	else if (seater_car == 6)
		cout << "Price range (RM12-RM18): ";
	cin >> arryPriceNoDriver[carcount];
	arryPriceDriver[carcount] = arryPriceNoDriver[carcount] + 5;
	carcount++; //car in company increased
}
