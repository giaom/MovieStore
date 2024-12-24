# Movie Store Management System #
# CSS 343 2024 #

## Overview ##
The Movie Store Management System is a software application designed to manage customer information and inventory for a movie rental store.
It allows users to perform various operations such as adding customers, adding movies to the inventory, and processing transactions like borrowing and returning movies.

### Components ###
#### 1. Store #### 
Manages customer information and inventory.
Utilizes instances of Customer and Inventory classes.
Implements methods for building the store, processing transactions, and displaying information.
#### 2. Inventory #### 
Represents the inventory of movies.
Utilizes a hash table for efficient lookup.
Implements methods for adding movies, borrowing/returning movies, and displaying the inventory.
#### 3. HashTable #### 
Generic hash table template class implemented using arrays and pointers.
Provides functions for adding, removing, and displaying items.
#### 4. Customer #### 
Represents customer information.
Includes data members for name and ID.
Implements a method to display borrowing and return history.
#### 5. Movie #### 
Represents a movie entity with various attributes.
Includes data members to store information about the movie, such as stock, director, title, release year, and availability status.
Includes methods to add and remove stock, display movie information, and check availability.
#### 6. Transactions #### 
Provides classes for different types of transactions, such as Borrow and Return.
Each transaction type contains information about the customer and the movie involved in the transaction.
#### 7. Movie Subtypes: ####
Includes Classic, Comedy, and Drama. 
Inherits from the Movie class and provides specific functionality and comparison methods tailored to their genre of movies.

### Technicals ###
The Store class uses the Inventory and MyHashTable classes to manage movies and customers.
The Inventory class uses sets to store movies, sorted by specific criteria for each movie type.
The MyHashTable class uses an array of pointers to store customers, with a hash function to determine the index.
The Customer class maintains a linked list of transactions for each customer.
The Movie class and its subclasses (Classic, Comedy, Drama) provide methods for comparing and displaying movie information.
The Transaction class and its subclasses (Borrow, Return) handle the details of borrowing and returning movies.

### Usage ###
Compile the source files using a C++ compiler (e.g., g++).
Run the executable with the appropriate input files containing customer information, movie information, and transaction information.
Follow the prompts to perform operations such as adding customers, adding movies to the inventory, and processing transactions.
