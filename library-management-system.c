#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_CART 50

// Book structure
struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
    int quantity;
};

// Global data
struct Book books[100];
int bookCount = 0;

int cart[50];
int cartCount = 0;

// Admin credentials
char adminUser[] = "admin";
char adminPass[] = "1234";

// Function prototypes
void visitorPanel();
void adminPanel();

void viewBooks();
void searchBook();
void addToCart();
void removeFromCart();
void viewCart();
void confirmPurchase();

void addBook();
void deleteBook();

int main() {
    int choice;

    // Sample books
    books[0] = (struct Book){1, "Harry_Potter", "Rowling", 1200, 5};
    books[1] = (struct Book){2, "1984", "Orwell", 700, 4};
    books[2] = (struct Book){3, "Alchemist", "Coelho", 500, 6};
    bookCount = 3;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Visitor\n");
        printf("2. Admin\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            visitorPanel();
        else if (choice == 2)
            adminPanel();
        else if (choice == 0)
            break;
        else
            printf("----Invalid input!----\n");
    }
    return 0;
}

// VISITOR

void visitorPanel() {
    int choice;

    while (1) {
        printf("\n==== Visitor Panel ====\n");
        printf("1. View books\n");
        printf("2. Search book\n");
        printf("3. Add to cart\n");
        printf("4. Remove from cart\n");
        printf("5. View cart\n");
        printf("6. Confirm purchase\n");
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
        	viewBooks();	
		}
        else if (choice == 2) {
        	searchBook();	
		}
        else if (choice == 3) {
        	addToCart();	
		}
        else if (choice == 4) {
        	removeFromCart();	
		}
        else if (choice == 5) {
        	viewCart();	
		}
        else if (choice == 6) {
        	confirmPurchase();	
		}
        else if (choice == 0) {
        	break;	
		}
        else {
        	printf("Invalid choice!\n");	
		}
    }
}

void viewBooks() {
    int i;
    printf("\nID\tTitle\tAuthor\tPrice\tQuantity\n");
    for (i = 0; i < bookCount; i++) {
        printf("%d   %s   %s   %.2f   %d\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].price,
               books[i].quantity);
    }
}

void searchBook() {
    char name[50];
    int i, found = 0;

    printf("Enter title or author: ");
    scanf("%s", name);

    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, name) == 0 ||
            strcmp(books[i].author, name) == 0) {

            printf("Found: %s by %s (%.2f, Qty: %d)\n",
                   books[i].title,
                   books[i].author,
                   books[i].price,
                   books[i].quantity);
            found = 1;
        }
    }

    if (!found)
        printf("Book not found.\n");
}

void addToCart() {
    int id, i;

    if (cartCount >= 50) {
        printf("Cart is full.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].quantity > 0) {
                cart[cartCount++] = id;
                books[i].quantity--;
                printf("Added to cart.\n");
            } else {
                printf("Out of stock.\n");
            }
            return;
        }
    }
    printf("Book ID not found.\n");
}

void removeFromCart() {
    int id, i, j;

    if (cartCount == 0) {
        printf("Cart is empty.\n");
        return;
    }

    printf("Enter book ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < cartCount; i++) {
        if (cart[i] == id) {

            for (j = 0; j < bookCount; j++) {
                if (books[j].id == id) {
                    books[j].quantity++;
                    break;
                }
            }

            for (j = i; j < cartCount - 1; j++)
                cart[j] = cart[j + 1];

            cartCount--;
            printf("Removed from cart.\n");
            return;
        }
    }

    printf("Book not in cart.\n");
}

void viewCart() {
    int i, j;
    float total = 0;

    if (cartCount == 0) {
        printf("Cart is empty.\n");
        return;
    }

    printf("\nCart items:\n");
    for (i = 0; i < cartCount; i++) {
        for (j = 0; j < bookCount; j++) {
            if (books[j].id == cart[i]) {
                printf("%s - %.2f\n",
                       books[j].title,
                       books[j].price);
                total += books[j].price;
            }
        }
    }
    printf("Total: %.2f\n", total);
}

void confirmPurchase() {
    if (cartCount == 0) {
        printf("Cart is empty.\n");
        return;
    }

    viewCart();
    cartCount = 0;
    printf("Purchase confirmed. Thank you!\n");
}

/* ================= ADMIN ================= */

void adminPanel() {
    char user[20], pass[20];
    int choice;

    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, adminUser) != 0 ||
        strcmp(pass, adminPass) != 0) {
        printf("Wrong credentials.\n");
        return;
    }

    while (1) {
        printf("\n--- Admin Panel ---\n");
        printf("1. Add book\n");
        printf("2. Delete book\n");
        printf("3. View books\n");
        printf("0. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addBook();
        else if (choice == 2) deleteBook();
        else if (choice == 3) viewBooks();
        else if (choice == 0) break;
        else printf("Invalid choice!\n");
    }
}

void addBook() {
    struct Book b;

    if (bookCount >= 100) {
        printf("Library full.\n");
        return;
    }

    b.id = bookCount + 1;
    printf("Title: ");
    scanf("%s", b.title);
    printf("Author: ");
    scanf("%s", b.author);
    printf("Price: ");
    scanf("%f", &b.price);
    printf("Quantity: ");
    scanf("%d", &b.quantity);

    books[bookCount++] = b;
    printf("Book added.\n");
}

void deleteBook() {
    int id, i, j;

    printf("Enter book ID: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (j = i; j < bookCount - 1; j++)
                books[j] = books[j + 1];
            bookCount--;
            printf("Book deleted.\n");
            return;
        }
    }
    printf("Book not found.\n");
}
