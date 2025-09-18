#include <iostream>
#include<cstdlib>
#include <string>
#include<conio.h>
using namespace std;

	const int MAX_ITEMS = 100;
// Data storage
string tourPackageNames[MAX_ITEMS];
string tourPackageDescriptions[MAX_ITEMS];
string tourPackageItineraries[MAX_ITEMS][10];
int tourPackageCount = 0;

int bookingIds[MAX_ITEMS];
string bookingTourNames[MAX_ITEMS];
string bookingCustomerNames[MAX_ITEMS];
string bookingStatuses[MAX_ITEMS];
int bookingCount = 0;

string accommodationHotelNames[MAX_ITEMS];
string accommodationRoomTypes[MAX_ITEMS];
int accommodationAvailabilities[MAX_ITEMS];
int accommodationCount = 0;

string transportationTypes[MAX_ITEMS];
string transportationDetails[MAX_ITEMS];
int transportationCount = 0;

int reviewTicketIds[MAX_ITEMS];
string reviewCustomerNames[MAX_ITEMS];
string reviewMessages[MAX_ITEMS];
int reviewTicketCount = 0;

int bookingIdCounter = 1;
int reviewIdCounter = 1;


void Tour_Package()                            //Tour Package Function
{
	 int packageChoice;
            cout << "1. View Tour Packages"<<endl;
            cout << "2. Add Tour Package"<<endl;
            cout << "3. Customize Tour Package"<<endl;
            cout << "4. Delete Tour Package"<<endl;
            cout << "Enter your choice: ";
            cin >> packageChoice;

            if (packageChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < tourPackageCount; i++) 
				{
                    cout << "Name: " << tourPackageNames[i] << "\nDescription: " << tourPackageDescriptions[i] << "\nItinerary:\n";
                    for (int j = 0; j <10; j++) 
					{
                        cout << tourPackageItineraries[i][j] <<endl;
                    }
                    cout <<endl;
                }
                cout<<"Press Enter to go to main menu";
                getch();
            } 
			else if (packageChoice == 2) 
			{
				system("cls");
                if (tourPackageCount < MAX_ITEMS) 
				{
                    cout << "Enter tour name: ";
                    cin.ignore();
                    getline(cin, tourPackageNames[tourPackageCount]);
                    cout << "Enter tour description: ";
                    getline(cin, tourPackageDescriptions[tourPackageCount]);
                    cout << "Enter number of itinerary days(Maximum 10): ";
                    int days;
                    cin >> days;
                    while(cin.fail()|| days<1||days>10)
                    {
                    	cin.clear();
                    	cin.ignore(1000000,'\n');
                    	cout<<"Enter a valid number: ";
                    	cin>>days;
					}
					cin.ignore();
                    for (int i = 0; i < days; i++) 
					{
                        cout << "Enter itinerary for day " << i + 1 << ": ";
                        getline(cin, tourPackageItineraries[tourPackageCount][i]);
                    }
                    tourPackageCount++;
                    cout<<endl<<"Tour has been added succefully!"<<endl<<"Press Enter to go to main menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more tour packages. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to main menu";
                    getch();
                }
            }
            else if(packageChoice == 3)
            {
            	int customize;
            	cout<<"Enter the index of the tour you want to customize: ";
            	cin>>customize;
            	while(cin.fail()||customize>=tourPackageCount|| customize<0)
            	{
            		cin.clear();
            		cin.ignore(10000,'\n');
            		cout<<"Index Not found: ";
            		cin>>customize;
				}
            	cout<<"Enter new tour name: ";
            	cin.ignore();
            	getline(cin, tourPackageNames[customize]);
            	cout<<endl<<"Enter tour description: ";
            	getline(cin, tourPackageDescriptions[customize]);
            	cout<<"Enter number of itinerary days(Maximum 10): ";
            	int days;
            	cin>>days;
            	while(cin.fail()||days<1||days>10)
            	{
            		cin.clear();
            		cin.ignore(100000,'\n');
            		cout<<"Enter a valid number: ";
					cin>>days; 
				}
            	cin.ignore();
            	for(int i=0;i<10;i++)
            	{
            		tourPackageItineraries[customize][i]="";
				}
            	for(int i=0;i<days;i++)
            	{
            		cout<<"Enter itinerary for day "<<i+1<<": ";
            		getline(cin, tourPackageItineraries[customize][i]);
				}
				cout<<endl<<"Tour has been customized successfully!"<<endl<<"Press Enter to go to menu";
				getch();
			}
			else if(packageChoice == 4 )
			{
				cout<<"Enter the index of the tour you want to delete: ";
				int del;
				cin>>del;
				while(cin.fail()||del>=tourPackageCount|| del<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>del;
				}
				for(int i=del;i<tourPackageCount;i++)
				{
					tourPackageNames[i]=tourPackageNames[i+1];
				    tourPackageDescriptions[i]=tourPackageDescriptions[i+1];
				    for(int j=0;j<10;j++)
				   {
					tourPackageItineraries[i][j]=tourPackageItineraries[i+1][j];
				   }
				}
				
				
				tourPackageCount--;
				cout<<endl<<"Tour has been deleted successfully!"<<endl<<"Press Enter to go to menu";
				getch();}
}
			
void Bookings()                                  //Bookings Function
			{
				int bookingChoice;
            cout << "1. View Bookings"<<endl;
            cout << "2. Add Booking"<<endl;
            cout << "3. Customize Booking"<<endl;
            cout << "4. Delete Booking"<<endl;
            cout << "Enter your choice: ";
            cin >> bookingChoice;

            if (bookingChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < bookingCount; ++i) 
				{
                    cout << "Booking ID: " << bookingIds[i] << "\nTour: " << bookingTourNames[i] << "\nCustomer: " << bookingCustomerNames[i] << "\nStatus: " << bookingStatuses[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to main menu";
                getch();
            } 
			else if (bookingChoice == 2) 
			{
				system("cls");
                if (bookingCount < MAX_ITEMS) 
				{
                    bookingIds[bookingCount] = bookingIdCounter++;
                    cout << "Enter tour name: ";
                    cin.ignore();
                    getline(cin, bookingTourNames[bookingCount]);
                    cout << "Enter customer name: ";
                    getline(cin, bookingCustomerNames[bookingCount]);
                    bookingStatuses[bookingCount] = "Confirmed";
                    bookingCount++;
                    cout<<"Tour has been booked for the customer successfully!"<<endl<<"Press Enter to go to menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more bookings. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
            else if(bookingChoice==3)
            {
            	cout<<"Enter the Index of the booking You want to customize: ";
            	int customize;
            	cin>>customize;
            	while(cin.fail()||customize>=bookingCount||customize<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"ID Not Found: ";
					cin>>customize;
				}
            	cout<<"Enter the name of the new booking tour: ";
            	cin.ignore();
            	getline(cin, bookingTourNames[customize]);
            	cout<<"Enter the name of the customer: ";
            	getline(cin, bookingCustomerNames[customize]);
            	bookingStatuses[customize]="Confirmed";
            	cout<<"Booking has been customized successfully!"<<endl<<"Press Enter to go to menu";
            	getch();
			}
			else if(bookingChoice==4)
			{
				cout<<"Enter the ID of the booking You want to delete: ";
				int del;
				cin>>del;
				while(cin.fail()||del>=bookingCount||del<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>del;
				}
				for(int i=del;i<bookingCount;i++)
				{
					bookingIds[i]=bookingIds[i+1];
					bookingTourNames[i]=bookingTourNames[i+1];
					bookingCustomerNames[i]=bookingCustomerNames[i+1];
				}
					
				bookingCount--;
				cout<<"Booking has been deleted successfuly!"<<endl<<"Press Enter to go to menu";
				getch();
			}
			}
			
void Accommodation()                                //Accommodation Function
			{
				int accommodationChoice;
            cout << "1. View Accommodations"<<endl;
            cout << "2. Add Accommodation"<<endl;
            cout << "3. Customize Accomodation"<<endl;
            cout << "4. Delete Accomodation"<<endl;
            cout << "Enter your choice: ";
            cin >> accommodationChoice;

            if (accommodationChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < accommodationCount; ++i) 
				{
                    cout << "Hotel: " << accommodationHotelNames[i] << "\nRoom: " << accommodationRoomTypes[i] << "\nAvailability: " << accommodationAvailabilities[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to menu";
                getch();
            } 
			else if (accommodationChoice == 2) 
			{
				system("cls");
                if (accommodationCount < MAX_ITEMS) 
				{
                    cout << "Enter hotel name: ";
                    cin.ignore();
                    getline(cin, accommodationHotelNames[accommodationCount]);
                    cout << "Enter room type: ";
                    getline(cin, accommodationRoomTypes[accommodationCount]);
                    cout << "Enter availability: ";
                    cin >> accommodationAvailabilities[accommodationCount];
                    accommodationCount++;
                    cout<<endl<<"Accomodation has been added successfully!"<<endl<<"Press Enter to go to menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more accommodations. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
            else if(accommodationChoice==3)
            {
            	cout<<"Enter the Index of Accommodation you want to change: ";
            	int customize;
            	cin>>customize;
            	while(cin.fail()||customize>=accommodationCount||customize<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>customize;
				}
            	cout<<"Enter new hotel name: ";
            	cin.ignore();
            	getline(cin,accommodationHotelNames[customize]);
            	cout<<"Enter room type: ";
            	getline(cin,accommodationRoomTypes[customize]);
            	cout<<"Enter availability: ";
            	cin>>accommodationAvailabilities[customize];
            	cout<<"Accommodation has been customized successfully!"<<endl<<"Press Enter to go to menu";
            	getch(); 	
			}
			else if(accommodationChoice==4)
			{
				cout<<"Enter the Index of Accommodation you want to delete: ";
				int del;
				cin>>del;
				while(cin.fail()||del>=accommodationCount||del<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>del;
				}
				for(int i=del;i<accommodationCount;i++)
				{
					accommodationHotelNames[i]=accommodationHotelNames[i+1];
				    accommodationRoomTypes[i]=accommodationRoomTypes[i+1];
				    accommodationAvailabilities[i]=accommodationAvailabilities[i+1];
				}
				
				accommodationCount--;
				cout<<"Accommodation has been deleted successfully!"<<endl<<"Press Enter to go to menu";
				getch();
			}
			}
	
void Transport()                                   //Transport Function
			{
				int transportChoice;
            cout << "1. View Transportation"<<endl;
            cout << "2. Add Transportation"<<endl;
            cout << "3. Customize Transportation"<<endl;
            cout << "4. Delete Transportaion"<<endl;
            cout << "Enter your choice: ";
            cin >> transportChoice;

            if (transportChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < transportationCount; ++i) 
				{
                    cout << "Type: " << transportationTypes[i] << "\nDetails: " << transportationDetails[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to menu";
                getch();
            } 
			else if (transportChoice == 2) 
			{
				system("cls");
                if (transportationCount < MAX_ITEMS) 
				{
                    cout << "Enter transport type: ";
                    cin.ignore();
                    getline(cin, transportationTypes[transportationCount]);
                    cout << "Enter details: ";
                    getline(cin, transportationDetails[transportationCount]);
                    transportationCount++;
                    cout<<"Transport has been added successfully!";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more transportation options. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
            else if(transportChoice==3)
            {
            	cout<<"Enter the Index of transportaion you want to customize: ";
            	int customize;
            	cin>>customize;
            	while(cin.fail()||customize>=transportationCount||customize<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>customize;
				}
				    cout<<"Enter new transportation type: ";
					cin.ignore();
					getline(cin,transportationTypes[customize]);
					cout<<"Enter details: ";
					getline(cin,transportationDetails[customize]);
					cout<<"Transport has been customized successfully!"<<endl<<"Press Enter to go to menu";
					getch();
			}
			else if(transportChoice==4)
			{
				cout<<"Enter the Index of the transportation you want to delete: ";
				int del;
				cin>>del;
				while(cin.fail()||del>=transportationCount||del<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>del;
				}
				for(int i=del;i<transportationCount;i++)
				{
					transportationTypes[i]=transportationTypes[i+1];
				    transportationDetails[i]=transportationDetails[i+1];
				}
				transportationCount--;
				
				cout<<"Transport has been deleted successfully!"<<endl<<"Press Enter to go to menu";
				getch();
			}
			}
			
void Customers()                               //Customer review Function
			{
				int reviewChoice;
            cout << "1. View Reviews"<<endl;
            cout << "2. Add A Review"<<endl;
            cout << "3. Customize A Review"<<endl;
            cout << "4. Delete A Review"<<endl;
            cout << "Enter your choice: ";
            cin >> reviewChoice;

            if (reviewChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < reviewTicketCount; ++i) 
				{
                    cout << "Review ID: " << reviewTicketIds[i] << "\nCustomer: " << reviewCustomerNames[i] << "\nMessage: " << reviewMessages[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to menu";
                getch();
            } 
			else if (reviewChoice == 2) 
			{
				system("cls");
                if (reviewTicketCount < MAX_ITEMS) 
				{
                    reviewTicketIds[reviewTicketCount] = reviewIdCounter++;
                    cout << "Enter customer name: ";
                    cin.ignore();
                    getline(cin, reviewCustomerNames[reviewTicketCount]);
                    cout << "Enter message: ";
                    getline(cin, reviewMessages[reviewTicketCount]);
                    reviewTicketCount++;
                    cout<<"Customer Review has been added successfully!"<<endl<<"Press Enter to go to menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more support tickets. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
            else if(reviewChoice==3)
            {
            	cout<<"Enter the Index of the Review you want to customize: ";
            	int customize;
            	cin>>customize;
            	while(cin.fail()||customize>=reviewTicketCount||customize<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>customize;
				}
				cout<<"Enter new customer name: ";
				cin.ignore();
				getline(cin,reviewCustomerNames[customize]);
				cout<<"Enter the message: ";
				getline(cin,reviewMessages[customize]);
				cout<<"Customer review has been customized successfully!"<<endl<<"Press Enter to go to menu";
				getch();
			}
			else if(reviewChoice==4)
			{
				cout<<"Enter the index of the review you want to delete";
				int del;
				cin>>del;
				while(cin.fail()||del>=reviewTicketCount||del<0)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>del;
				}
				for(int i=del;i<reviewTicketCount;i++)
				{
					reviewTicketIds[i]=reviewTicketIds[i+1];
					reviewCustomerNames[i]=reviewCustomerNames[i+1];
				    reviewMessages[i]=reviewMessages[i+1];
				}
				
				reviewTicketCount--;
				cout<<"Customer Review has been deleted successfully"<<endl<<"Press Enter to Continue";
				getch();
			}
			}
			
			
int main()                                  //Main Function
{
    // Sample Data Initialization
    tourPackageNames[tourPackageCount] = "Beach Adventure";
    tourPackageDescriptions[tourPackageCount] = "A fun beach tour";
    tourPackageItineraries[tourPackageCount][0] = "Day 1: Arrival";
    tourPackageItineraries[tourPackageCount][1] = "Day 2: Beach Fun";
    tourPackageItineraries[tourPackageCount][2] = "Day 3: Departure";
    tourPackageCount++;
    
    bookingTourNames[bookingCount]="Beach Adventure";
    bookingCustomerNames[bookingCount]="Alex";
    bookingStatuses[bookingCount]="Confirmed";
    bookingCount++;

    accommodationHotelNames[accommodationCount] = "Seaside Hotel";
    accommodationRoomTypes[accommodationCount] = "Deluxe Room";
    accommodationAvailabilities[accommodationCount] = 10;
    accommodationCount++;

    transportationTypes[transportationCount] = "Car Rental";
    transportationDetails[transportationCount] = "Available for 3 days";
    transportationCount++;
    
    reviewCustomerNames[reviewTicketCount]="Alex";
    reviewMessages[reviewTicketCount]="Amazing Experience";
    reviewTicketCount++;

    bool running = true;
    while (running) 
	{
        int choice;
        system ("cls");
        system("color 0A");
        	 cout << "\t* We Welcome You To  Travel Tribe And Tours *\n" << endl;
    cout << "\t-------------------Main Menu----------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|                                           |" << endl;
    cout << "\t|Tours Management------------------------> 1|" << endl;
    cout << "\t|Bookings Management---------------------> 2|" << endl;
    cout << "\t|Accomodation Management-----------------> 3|" << endl;
    cout << "\t|Transportation--------------------------> 4|" << endl;
    cout << "\t|Customer Support------------------------> 5|" << endl;
    cout << "\t|Exit the Program------------------------> 0|" << endl;
    cout << "\t|                                           |" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
        cout <<endl<<"Enter your choice: ";
        cin >> choice;
        while(cin.fail()||choice<0||choice>5)
        {
        	cin.clear();
        	cin.ignore(100000,'\n');
        	cout<<"Ivalid Input   Enter Choice: ";
        	cin>>choice;
		}

        if (choice == 1) 
		{
           Tour_Package();
        } 
		else if (choice == 2) 
		{
            Bookings();  
        } 
		else if (choice == 3) 
		{
			Accommodation();
        } 
		else if (choice == 4) 
		{
			Transport();
        } 
		else if (choice == 5) 
		{
			Customers();
        } 
		else if (choice == 0) 
		{
			system("cls");
			cout<<"\n\n\n\n\n\t\t\t\tExiting the Program....";
            running = false;
        } 
    }

    return 0;
}

