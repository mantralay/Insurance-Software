#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer information
struct Customer {
    char name[50];
    char nominee1[50];
    char nominee2[50];
    char username[20];
    char password[20];
};

// Global variable to store the current customer
struct Customer currentCustomer;
// Boolean variable to track login status
int isLoggedIn = 0;

// Function to display customer details
void displayCustomerDetails() {
    if (isLoggedIn) {
        printf("\nCustomer Details:\n");
        printf("Name: %s\n", currentCustomer.name);
        printf("Nominee 1: %s\n", currentCustomer.nominee1);
        printf("Nominee 2: %s\n", currentCustomer.nominee2);
        printf("Username: %s\n", currentCustomer.username);
    } else {
        printf("\nPlease log in first.\n");
    }
}

// Function to handle policy purchase
void purchasePolicy() {
    if (isLoggedIn) {
        int policyChoice;

        printf("\nChoose a policy option:\n");
        printf("1. Term Plans\n");
        printf("2. Life Insurance\n");
        printf("3. Health Insurance\n");
        printf("4. Vehicle Insurance\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &policyChoice);

        switch (policyChoice) {
            case 1:
            int age, term, coverageAmount;
            float premium;

    // Get user input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter the term length (in years): ");
    scanf("%d", &term);

    printf("Enter the coverage amount: ");
    scanf("%d", &coverageAmount);

    // Basic premium calculation (simplified for demonstration purposes)
    // You may want to consult with an insurance professional for a more accurate formula
    if (age < 18 || age > 60) {
        printf("Invalid age for term insurance. Exiting program.\n");
         // Exit with an error code
    }

    if (term < 1) {
        printf("Invalid term length. Exiting program.\n");
         // Exit with an error code
    }

    // Simplified premium calculation: Age-based and term-based adjustments
    // Adjustments are made based on age and term length
    if (age >= 18 && age <= 30) {
        premium = term * 10.0 * coverageAmount / 80000.0; // Adjusted premium for younger age
    } else {
        premium = term * 15.0 * coverageAmount / 80000.0; // Adjusted premium for older age
    }

    // Display the calculated premium
    printf("Your term insurance premium is: Rs.%.2f\n", premium);
                printf("\nTerm Plans policy purchased successfully!\n");
                // Add logic for Term Plans policy purchase here
                break;
            case 2:
            {
                    // Declare variables
                    float premium;
                    float insuranceCoverage;
                    int coveragePeriod;
                    float deathBenefit;
                    float maturityBenefit;

                    // Get user input
                    printf("Enter the annual premium amount: ");
                    scanf("%f", &premium);

                    printf("Enter the coverage period in years: ");
                    scanf("%d", &coveragePeriod);

                    // Calculate insurance coverage
                    insuranceCoverage = premium * coveragePeriod * 3;

                    // Calculate death benefit
                    deathBenefit = insuranceCoverage;

                    // Calculate maturity benefit
                    if (coveragePeriod == 30) {
                        maturityBenefit = insuranceCoverage / 2;
                    } else {
                        maturityBenefit = 0; // No maturity benefit for other coverage periods
                    }
                    
                    // Display results
                    printf("\nInsurance Coverage: Rs %.2f\n", insuranceCoverage);
                    printf("Death Benefit: Rs %.2f\n", deathBenefit);
                    printf("Maturity Benefit: Rs %.2f\n", maturityBenefit);
                }

                printf("\nLife Insurance policy purchased successfully!\n");
                // Add logic for Life Insurance policy purchase here
                break;
            case 3:
             int age_2;
              char coverageType;
              float premium_2;

    // Get user input
    printf("Enter your age: ");
    scanf("%d", &age_2);

    printf("Enter the coverage type (I for Individual, F for Family): ");
    scanf(" %c", &coverageType);

    // Basic premium calculation (simplified for demonstration purposes)
    // You may want to consult with an insurance professional for a more accurate formula
    if (age_2 < 0 || age_2 > 100) {
        printf("Invalid age for health insurance. Exiting program.\n");
         // Exit with an error code
    }

    // Adjust premium based on age and coverage type
    if (coverageType == 'I' || coverageType == 'i') {
        premium_2 = age_2 * 5.0; // Basic premium for individual coverage
    } else if (coverageType == 'F' || coverageType == 'f') {
        premium_2 = age_2 * 8.0; // Basic premium for family coverage
    } else {
        printf("Invalid coverage type. Exiting program.\n");
         // Exit with an error code
    }

    // Display the calculated premium
    printf("Your health insurance premium is: %.2f\n", premium_2);
                printf("\nHealth Insurance policy purchased successfully!\n");
                // Add logic for Health Insurance policy purchase here
                break;
            case 4:
            char vehicleType;
    int age3, basePremium;
    float totalPremium;

    // Get user input
    printf("Enter the type of vehicle (C for Car, B for Bike): ");
    scanf(" %c", &vehicleType);

    printf("Enter your age: ");
    scanf("%d", &age3);

    // Calculate base premium based on vehicle type
    if (vehicleType == 'C' || vehicleType == 'c') {
        basePremium = 80000; // Base premium for car
    } else if (vehicleType == 'B' || vehicleType == 'b') {
        basePremium = 40000; // Base premium for bike
    } else {
        printf("Invalid vehicle type. Exiting program.\n");
         // Exit with an error code
    }

    // Adjust premium based on age
    if (age < 25) {
        totalPremium = basePremium * 1.2; // 20% increase for age under 25
    } else {
        totalPremium = basePremium; // No additional charge for age 25 and above
    }

    // Display the calculated premium
    printf("Your insurance premium is: Rs%.2f\n", totalPremium);

                printf("\nVehicle Insurance policy purchased successfully!\n");
                // Add logic for Vehicle Insurance policy purchase here
                break;
            default:
                printf("\nInvalid policy choice. Please enter a number between 1 and 4.\n");
        }
    } else {
        printf("\nPlease log in first.\n");
    }

}
void purchased_policy() {
    int choice2;
    
    void login();
    
    printf("1. Logout\n");
    printf("2. Buy a new Policy\n");
     printf("Enter your choice (1-2): ");
    
        scanf("%d", &choice2);

        switch (choice2) {
            case 1:
                login();
                break;
            case 2:
                purchasePolicy();
                break;

            default :
            printf("Invalid choice !");    
        }
}
// Function to handle login
void login() {
    char username[20];
    char password[20];

    printf("\nEnter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    // Check if the entered credentials match the stored credentials
    if (strcmp(username, currentCustomer.username) == 0 &&
        strcmp(password, currentCustomer.password) == 0) {
        isLoggedIn = 1;
        printf("\nLogin successful!\n");
        displayCustomerDetails();
        purchasePolicy();
        purchased_policy();
    } else {
        printf("\nInvalid credentials. Login failed.\n");
    }
}
void signup() {
    printf("\nEnter Customer Name: ");
    scanf("%s", currentCustomer.name);

    printf("Enter Nominee 1: ");
    scanf("%s", currentCustomer.nominee1);

    printf("Enter Nominee 2: ");
    scanf("%s", currentCustomer.nominee2);

    printf("Enter Username: ");
    scanf("%s", currentCustomer.username);

    printf("Enter Password: ");
    scanf("%s", currentCustomer.password);

    printf("\nSignup successful!\n");
}

int main() {
    int choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Login\n");
        printf("2. Signup\n");
        printf("3. Exit\n");

        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                
                break;
            case 2:
                signup();
                break;
            
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }

    } while (choice != 3);

    return 0;
}
