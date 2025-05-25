#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string booktitle[100];               //library can store 100 books.
int totalbooks = 40; 
int issuedbooks[50];                 //stores book number issued
string issuedto[50];                 //stores the name of the student book is issued to
int totalissued = 0;
void bookfile() {
	ofstream file("books.txt");
	if (!file) {
		cout << "error opening file!" << endl;
	}
	for (int i = 0; i < totalbooks; i++) {
		file << booktitle[i] << endl;
	}
	file.close();
}
void issuedfile() {
	ofstream issuefile("issuedbooks.txt");
	if (!issuefile) {
		cout << "error opening file" << endl;
	}
	  for (int i = 0; i < totalissued; i++) {
        issuefile << issuedbooks[i] << " issued to " << issuedto[i] << endl;
    }
	issuefile.close();

}
void addbook() {
	if (totalbooks >= 100) {
		cout << "Library is full!";  //checking if the library is full or not.
		return;
	}
	cout << "Enter Book title: ";
	cin.ignore();
	getline(cin,booktitle[totalbooks]);            //using 'getline' instead of 'cin' to store a book with a title having more than one word.
	cout << "'"<<booktitle[totalbooks] << "'" << " added successfully" << endl; //book added to the library.
	totalbooks++;                                     //counting total number of books
	bookfile();
	cout << "****************************" << endl;
	cout << "****************************" << endl;
}
void viewbook() {     
	cout << totalbooks << " Books available in library right now."<<endl; 
	booktitle[0] = "Harry Potter Sorcerer's Stone";                 //books already available in the library
	booktitle[1] = "Harry Potter and the Chamber of Secrets";
	booktitle[2] = "Harry Potter and the Prisoner of Azkaban";
	booktitle[3] = "Harry Potter and the Goblet of fire";
	booktitle[4] = "Harry Potter and Order of Pheonix";
	booktitle[5] = "Harry Potter and the Half Blood Prince";
	booktitle[6] = "Harr Potter and the Deathly Hallows";
	booktitle[7] = "Harry Potter and the Cursed Child";
	booktitle[8] = "Wizard of Oz";
	booktitle[9] = "How to train your Dragon"; 
	booktitle[10] = "Roll of thunder hear my cry";
	booktitle[11] = "Alice in the wonderland";
	booktitle[12] = "Diary of a Wimpy kid";
	booktitle[13] = "Diary of a Wimpy kid: Rodrick Rules";
	booktitle[14] = "Diary of a Wimpy kid: The Last Straw";
	booktitle[15] = "Diary of a Wimpy kid: Dog Days";
	booktitle[16] = "Diary of a Wimpy kid: The Ugly Truth";
	booktitle[17] = "Diary of a Wimpy kid: Cabin fever";
	booktitle[18] = "Diary of a Wimpy kid: The Third Wheel";
	booktitle[19] = "Diary of a Wimpy kid: Hard Luck";
	booktitle[20] = "Diary of a Wimpy kid: The Long Haul";
	booktitle[21] = "Diary of a Wimpy kid: Old School";
	booktitle[22] = "Diary of a Wimpy kid: Double Down";
	booktitle[23] = "Diary of a Wimpy kid: The Getaway";
	booktitle[24] = "Diary of a Wimpy kid: The Melt Down";
	booktitle[25] = "Engine Summer";
	booktitle[26] = "The Hearing Trumpet";
	booktitle[27] = "Ice";
	booktitle[28] = "The Tartar Steppe";
	booktitle[29] = "The Invention of Morel";
	booktitle[30] = "Little,Big";
	booktitle[31] = "The Tenants of Moonbloom";
	booktitle[32] = "Melina";
	booktitle[33] = "A Void";
	booktitle[34] = "The Obscene Bird of Night";
	booktitle[35] = "Auto-da-Fé";
	booktitle[36] = "Riddley Walker";
	booktitle[37] = "The Third Policeman";
	booktitle[38] = "The Mezzanine";
	booktitle[39] = "Wittgenstein’s Mistress";
	if (totalbooks == 0) {
		cout << "No books found in the library!";
		return;
	}
	for (int i = 0; i < totalbooks; i++) {               //this loop prints all the books numbered one by one.
		cout << i + 1 << "." << booktitle[i] << endl;  
	}
	bookfile();
	cout << "****************************" << endl;
	cout << "****************************" << endl;
}
void deletebook() {
	int num;                                             
	cout << "Enter the number of Book to be deleted";
	cin.ignore();
	cin >> num;                                          // number book is listed at when added to the library
	if (num <1 || num > totalbooks) {
		cout << "invalid input. This number doesnot exist"<<endl;
		return;
	}
	for (int i = num - 1; i < totalbooks - 1; i++) {     //deleting the book from library
		booktitle[i] = booktitle[i + 1];
		totalbooks--;                                    //subtracting from totalbooks
	}
	cout << "*******************************" << endl;
	cout << "*******************************" << endl;
}
void searchbook() {
	string bookname;                                     //using string because it makes handling word and sentence easy
	cout << "Enter the name of the Book: ";
	cin.ignore();
	getline(cin, bookname);
	bool book = false;                                  
	for (int i = 0; i <= totalbooks; i++) {                     //loop searcing for the book in library
		if (bookname == booktitle[i]) {
			cout << bookname << " found on number " << i + 1 << endl;
			book = true;
			break;
		}
	}
		if(!book){
			cout << "Book not found!" << endl;
		}
	
	cout << "********************************" << endl;
	cout << "********************************" << endl;
}
void issuebook() {
	int num;
	string name;
	string enrolment;
	if (totalbooks == 0) {                                //if there are no books in library student can't issue one
		cout << "No Book available to issue.";
		return;
	}
	viewbook();                                         //shows available books
	cout << "Enter Book number to issue:";
	cin >> num;
	if (num < 1 || num > totalbooks) {
		cout << "Invalid Book Number!";
		return;
	}
	for (int i = 0; i < totalissued; i++) {
		if (issuedbooks[i] == num) {
			cout << "book already issued to" << issuedto[i] << endl;
		}
	}
	cout << "Enter Student Name:";
	cin.ignore();
	getline(cin, name);
	cout << "Enter Students Enrolment Number:";
	cin.ignore();
	getline(cin, enrolment);
	issuedbooks[totalissued] = num;
	issuedto[totalissued] = name;
	cout << booktitle[num - 1] << " issued to " << name << endl;
	totalissued++;
	issuedfile();
	cout << "********************************" << endl;
	cout << "********************************" << endl;
}
void returnbook() {
	if (totalissued==0) {
		cout << "No books currently issued!"<<endl;
	}
	cout << "Issued Books:";                         // Show issued books
	for (int i = 0; i < totalissued;i++) {
		cout << issuedbooks[i] << " . " << booktitle[issuedbooks[i] - 1] << " issued to: " << issuedto[i]<<endl;
	}
	cout << "Enter book number to return: ";
	int num;
	cin >> num;
	bool found = false;
	for (int i = 0; i < totalissued; i++) {
		if (issuedbooks[i] == num) {
			found = true;
			for (int j = i; j < totalissued-1; j++) {
				issuedbooks[j] = issuedbooks[j + 1];
				issuedto[j] = issuedto[j + 1];
			}
		}
		totalissued--;
		cout << "Book has been returned"<<endl;
		issuedfile();
	}
	if (!found) {
		cout << "Book was not issued." << endl;
	}

	cout << "**********************************" << endl;
	cout << "**********************************" << endl;
}

void studentmenu() {                       //students menu
	int choice;
	while (true) {                               // Students have limited access for e.g they can not add or delete a book
		cout << "1. View Books" << endl;
		cout << "2. Search Book" << endl;
		cout << "3. Issue Book" << endl;
		cout << "4. Return Book" << endl;
		cout << "5. Return to Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input! Please enter a number.\n";
			continue;
		}
		switch (choice) {
		case 1: viewbook();
			break;
		case 2: searchbook();
			break;
		case 3: issuebook();
			break;
		case 4: returnbook();
			break;
		case 5: cout << "goodbye";
			return;
		default:
			cout << "invalid choice!" << endl;
		}
	}
}
void librarianmenu() {
	int choice;
	while (true) {
		cout << "1.Add Book" << endl;
		cout << "2.View Book" << endl;
		cout << "3.Delete Book" << endl;
		cout << "4.Search Book" << endl;
		cout << "5.Return to Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input! Please enter a number.\n";
			continue;
		}
		switch (choice) {
		case 1: addbook(); break;
		case 2: viewbook(); break;
		case 3: deletebook(); break;
		case 4: searchbook(); break;
		case 5: cout << "goodbye!" << endl;
			return;
		default: cout << "inalid output!" << endl; break;
		}
	}
}

void display() {
	int choice;
	int librarian;
	int student;  
	while(true){                                               //using while loop so the program continues
	cout << "*********LIBRARY MANAGEMENT SYSTEM***********" << endl;
	cout << "Are you a: " << endl;                                      // user selects whether they are a student or librarian
	cout << "1.Student" << endl;
	cout << "2.Librarian" << endl;
	cout << "3.EXIT" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Please enter a number.\n";
		continue;
	}
		switch (choice) {
		case 1: studentmenu(); break;                               //calling student function
		case 2: librarianmenu(); break;                             //calling librarian function
		case 3: cout << "goodbye!" << endl;                         
			return;                                                 //return will end the display function
		default:cout << "invalid output!"; break;

		}
	}
}

int main() {                                                          //Main Function
	
	display();
	return 0;
}