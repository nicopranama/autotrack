## AutoTrack

AutoTrack is a console-based application written in C that helps manage and analyze car sales data stored in a text file.  
This project was developed as a final project for the Algorithm and Programming course at Bina Nusantara University.

## Overview

The AutoTrack application allows users to:

- Display all car sales transactions stored in a file
- Add new transactions to the dataset
- Search transactions by customer name, car brand, or car type
- Sort transactions based on total price or transaction date
- Save modified data back to the `sales.txt` file

The application reads from and writes to a text file (`sales.txt`) where each line represents a transaction with the following structure:

DDMMYYYY,Name,Type,Brand,Year,Model,Fuel,CC,Transmission,Qty,UnitPrice,TotalPrice


🚀 Features

1. View Transactions  
Display all recorded transactions in a readable table format. Each row displays complete details about the car sold and buyer.

2. Add Transactions  
Input a new transaction with complete information including:
- Customer name
- Car type and brand
- Fuel type, transmission, engine size, year
- Quantity and price

3. Search Transactions  
Search for specific records based on:
- Buyer name
- Car brand (e.g., Toyota, Honda)
- Car type (e.g., SUV, Hatchback)

4. Sort Transactions  
Users can sort sales data by:
- Total price (highest to lowest or vice versa)
- Transaction date (oldest to newest or vice versa)

5. Save Data  
After any modification (add, sort, etc.), data can be saved back to `sales.txt` ensuring permanent storage.


🛠️ Technologies Used

- C programming language
- File input/output: `fopen`, `fprintf`, `fscanf`
- String processing: `strtok`, `strcmp`, etc.
- Sorting with `qsort`
- Console-based UI with formatted output


📂 How to Run

1. Ensure you have a valid `sales.txt` file in the same folder as the source code.
2. Open terminal or command prompt in the project directory.
3. Compile the program using:
   ```bash
   gcc FinPro2.c -o autotrack




