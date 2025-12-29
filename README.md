# Library Management System

A lightweight, console-based **Library Management System** written in C. This application allows users to browse and purchase books while providing administrative tools to manage the library inventory.



---

## 🚀 Features

### **Visitor Panel**
* **Browse Inventory:** View all available books with details (ID, Title, Author, Price, Quantity).
* **Smart Search:** Search for books by Title or Author name.
* **Shopping Cart System:**
    * Add books to a personal cart.
    * Remove items from the cart.
    * Automatic stock adjustment (decrements quantity when added to cart).
* **Checkout:** Confirm purchase and see the total bill.

### **Admin Panel**
* **Secure Access:** Password-protected login (Default credentials provided below).
* **Inventory Management:** * Add new books to the system.
    * Delete books by ID.
    * View full library status.

---

## 🛠️ Technical Details

* **Language:** C
* **Data Structure:** Uses `struct` to manage book objects and arrays for runtime data storage.
* **Capacity:** Supports up to 100 books and a 50-item user cart.

---

## 💻 Getting Started

### **Requirements**
You need a C compiler (like `gcc`, `clang`, or the one included in Code::Blocks/Dev-C++) installed on your system.

### **Installation & Running**
1.  **Clone or Download:** Save the source code as `library_system.c`.
2.  **Compile the code:**
    ```bash
    gcc library_system.c -o library_system
    ```
3.  **Execute the program:**
    ```bash
    ./library_system
    ```

---

## 📖 Usage Guide

### **1. Admin Access**
To manage the library inventory, select the **Admin** option and use the following credentials:
* **Username:** `admin`
* **Password:** `1234`

### **2. Input Tips**
When adding books, please use **underscores** instead of spaces for titles (e.g., `The_Great_Gatsby`) to ensure the console reads the input correctly.

### **3. Data Persistence**
> **Note:** This version stores data in **RAM**. If you close the program, any new books added or changes made to the inventory will reset to the default sample books.

---

## 🗺️ Logic Flow



1.  **Main Menu:** Choose between Visitor and Admin modes.
2.  **Visitor Logic:** When a user adds a book to the cart, the system checks `books[i].quantity`. If available, it transfers the ID to the `cart` array and decrements the stock.
3.  **Admin Logic:** Admins can modify the global `books` array directly to update the "Master List."

---

## 🤝 Contributing
Feel free to fork this project and add features like:
* File handling for permanent data storage.
* User account registration.
* Improved UI with colored text.