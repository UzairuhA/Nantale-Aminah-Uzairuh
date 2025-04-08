#include <stdio.h>

// Define a structure to represent a menu item
struct MenuItem {
    int item_code;   // Unique code for each item
    char name[50];   // Name of the item (e.g., "Cheeseburger")
    float price;     // Price of the item
};

// Function to display the menu
void display_menu(struct MenuItem menu[], int menu_size) {
    printf("Welcome to the Restaurant!\n");
    printf("Here is our menu:\n");
    printf("----------------------------------------\n");

    // Loop through each menu item and display its details
    for (int i = 0; i < menu_size; i++) {
        printf("Code: %d, Item: %-20s Price: $%.2f\n", menu[i].item_code, menu[i].name, menu[i].price);
    }
    printf("----------------------------------------\n");
}

// Function to calculate the total (subtotal, tax, grand total)
void calculateTotal(struct MenuItem menu[], int menu_size, int order[], int quantities[], int num_items) {
    float subtotal = 0.0;
    
    // Calculate the subtotal by adding the price of each ordered item
    for (int i = 0; i < num_items; i++) {
        int item_code = order[i];
        int quantity = quantities[i];

        // Find the item in the menu and add its price to the subtotal
        for (int j = 0; j < menu_size; j++) {
            if (menu[j].item_code == item_code) {
                subtotal += menu[j].price * quantity;
                break;
            }
        }
    }

    // Calculate tax (7% of subtotal)
    float tax = subtotal * 0.07;
    
    // Calculate the grand total (subtotal + tax)
    float grand_total = subtotal + tax;

    // Print the itemized receipt
    printf("\nItemized Receipt:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        int item_code = order[i];
        int quantity = quantities[i];

        // Find and display each item ordered, with quantity and price
        for (int j = 0; j < menu_size; j++) {
            if (menu[j].item_code == item_code) {
                printf("%-20s x%d - $%.2f\n", menu[j].name, quantity, menu[j].price * quantity);
                break;
            }
        }
    }

    // Print the subtotal, tax, and grand total
    printf("----------------------------------------\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax (7%%): $%.2f\n", tax);
    printf("Grand Total: $%.2f\n", grand_total);
    printf("----------------------------------------\n");
}

// Function to take the user's order
void take_order(struct MenuItem menu[], int menu_size) {
    int order[100];         // Array to store item codes of ordered items
    int quantities[100];    // Array to store the quantities of ordered items
    int num_items = 0;      // Number of items the user orders
    char continue_ordering = 'y';

    // Continue asking for items until the user enters 0
    while (continue_ordering == 'y' || continue_ordering == 'Y') {
        int item_code, quantity;

        // Ask the user to enter an item code
        printf("\nEnter the item code to order (or 0 to finish): ");
        scanf("%d", &item_code);

        if (item_code == 0) {
            break;  // Exit if the user enters 0
        }

        // Search for the item in the menu and prompt for quantity
        int found = 0;
        for (int i = 0; i < menu_size; i++) {
            if (menu[i].item_code == item_code) {
                printf("How many of %s would you like to order? ", menu[i].name);
                scanf("%d", &quantity);
                
                // Store the item code and quantity
                order[num_items] = item_code;
                quantities[num_items] = quantity;
                num_items++;  // Increase the number of ordered items
                found = 1;
                break;
            }
        }

        // If the item code is invalid, show an error message
        if (!found) {
            printf("Invalid item code. Please try again.\n");
        }

        // Ask the user if they want to continue ordering
        printf("Do you want to continue ordering? (y/n): ");
        scanf(" %c", &continue_ordering);
    }

    // Calculate and display the total (subtotal, tax, grand total)
    calculateTotal(menu, menu_size, order, quantities, num_items);
}

int main() {
    // Define the menu items
    struct MenuItem menu[] = {
        {101, "Cheeseburger", 5.99},
        {102, "Veggie Pizza", 7.49},
        {103, "Chicken Wings", 8.99},
        {104, "Fries", 2.49},
        {105, "Caesar Salad", 4.99},
        {107, "Chocolate Cake", 3.99},
        {108, "Soda", 1.49},
        {109, "Ice Cream", 2.99}
    };

    // Determine the number of menu items
    int menu_size = sizeof(menu) / sizeof(menu[0]);

    // Display the menu and take the order
    display_menu(menu, menu_size);
    take_order(menu, menu_size);

    printf("Thank you for your order! Have a great day!\n");
    return 0;
}
