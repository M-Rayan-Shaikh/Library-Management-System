# Library-Management-System
Introduction:
The Library Management System is a C++ console-based application designed to manage basic library operations such as:
•	Viewing available books
•	Adding or deleting books
•	Issuing and returning books
•	Displaying issued book details
The system supports file handling for logging issued books to a text file and offers separate menu sections for students and librarians.
Objectives:
•	To apply fundamental C++ programming concepts in a real-world scenario.
•	To use arrays, functions, file streams, and basic I/O handling.
•	To create an interactive console application with simple menu navigation.
•	To differentiate functionalities based on user roles (student vs librarian).
Key Feature
1.	bookfile() – Persist all book titles
Purpose:
Writes the current contents of the booktitle array to books.txt, one line per book, ensuring the on disk list matches the in memory list.
Key steps:
1.	ofstream file("books.txt"); – Opens (or creates) the text file in truncate mode, so previous contents are overwritten.
2.	if (!file) – Basic error check; prints a message if the file stream fails to open.
3.	for loop – Iterates from 0 to totalbooks – 1, writing each title followed by \n.
4.	file.close(); – Explicitly closes the stream (automatic at scope exit, but explicit is clearer).
2.	issuedfile() - Persist Issued Book Records
Purpose:
Saves every currently issued book (by number) along with the recipient’s name to issuedbooks.txt.
Highlights:
•	The file is recreated each call, guaranteeing the list is up to date.
•	Combines array values (issuedbooks[i]) and strings (issuedto[i]) into a single human readable line.
3.	addbook() – Add a New Book Title
Purpose:
Appends a new title to the library if space remains.
•	Capacity check – Disallows adding beyond the 100 book array limit.
•	cin.ignore() clears the trailing newline left by previous cin >> operations.
•	getline captures multi word titles.
•	totalbooks++ grows the effective list size after storing the title.
•	Calls bookfile() to sync the change to disk.
4.	viewbook() – View All Book Titles
Purpose:
Lists every title with a human friendly 1 based index.
5.	deletebook() – Remove a Book by Index
Explanation:
•	Validates the user’s 1 based index.
•	Shifts all elements above the removed slot left by one.
•	Decrements totalbooks after the shift, shrinking the logical size.
•	Calls bookfile() to reflect the change persistently.
6.	searchbook() – Find a Book Title by Exact Match
How it works:
Performs a linear search comparing the user string to each stored title until it succeeds or exhausts the list.
7.	issuebook() – Issue a Book to a Student
Logic:
•	Validate that books exist, and the requested index is legal.
•	Confirm the book is not already issued.
•	Collect student details.
•	Record the loan in issuedbooks/issuedto arrays and persist via issuedfile().
8.	returnbook() – Accept a Returned Book
Highlights:
•	Lists all current loans for easy reference.
•	Removes the matching entry via a left shift and decrements totalissued.
•	Updates the text file to reflect the reduced loan list.
9.	studentmenu() – Limited Student Interface
Notes:
•	Runs an infinite loop until the student selects option 5.
•	Provides only the operations appropriate for students (no add/delete).
10.	 librarianmenu() – Full Librarian Interface
Difference from student menu: Librarian can add and delete books, reflecting higher privileges.
11.	 display() – Main Role Selection
Role: Top level navigator that repeatedly asks the user to identify as student / librarian / exit, then calls the relevant submenu.
12.	 main() – Program Entry Point
Highlights:
•	Optional call to initializeBooks() suggested for one time setup.
•	Delegates everything else to display().
Summary
•	Each function is self contained and communicates through global arrays and counters. For future maintenance, consider refactoring into classes and replacing global state with encapsulated objects.
Improvements We Can Make
•	Add user authentication for both librarians and students.
•	Replace arrays with classes (Book, User) and use vector for dynamic storage.
•	Implement permanent book storage using file I/O for books and students.
•	Create a GUI version using a graphics library (e.g., Qt or WinAPI).
•	Add search and sort functionality for easier book browsing.
Conclusion
This project demonstrates a practical implementation of C++ programming concepts in building a simple, functional library management system. While basic in scope, it lays the foundation for future enhancements and provides a hands-on understanding of file handling, modular programming, and user interaction.

