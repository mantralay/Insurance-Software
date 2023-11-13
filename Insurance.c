#include <stdio.h>
#include <string.h>

struct Customer {
    char name[100];
    // Add other customer details as needed
};

struct Nominee {
    char name[100];
    // Add other nominee details as needed
};

struct LifeInsurancePolicy {
    struct Customer customer;
    struct Nominee nominee1;
    struct Nominee nominee2;
    int investmentAmount;
    int policyYears;
};

struct TermPolicy {
    struct Customer customer;
    struct Nominee nominee;
    int investmentAmount;
    int lockInYears;
};

struct VehicleInsurance {
    char vehicleType; // '2' for two-wheeler, '4' for four-wheeler
    int insuredAmount;
};

struct HealthInsurance {
    char insuranceType; // 'G' for Gold Pass, 'P' for Platinum Pass
    int annualPremium;
};

// Function prototypes
void addLifeInsurancePolicy(struct LifeInsurancePolicy *policy);
void calculateLifeInsuranceReturns(struct LifeInsurancePolicy policy);

void addTermPolicy(struct TermPolicy *policy);
void calculateTermPolicyReturns(struct TermPolicy policy);

void addVehicleInsurance(struct VehicleInsurance *insurance);
void calculateVehicleInsuranceReturns(struct VehicleInsurance insurance);

void addHealthInsurance(struct HealthInsurance *insurance);
void calculateHealthInsuranceReturns(struct HealthInsurance insurance);

int main() {
    struct LifeInsurancePolicy lifePolicy;
    struct TermPolicy termPolicy;
    struct VehicleInsurance vehicleInsurance;
    struct HealthInsurance healthInsurance;

    // Life insurance
    addLifeInsurancePolicy(&lifePolicy);
    calculateLifeInsuranceReturns(lifePolicy);

    // Term policy
    addTermPolicy(&termPolicy);
    calculateTermPolicyReturns(termPolicy);

    // Vehicle insurance
    addVehicleInsurance(&vehicleInsurance);
    calculateVehicleInsuranceReturns(vehicleInsurance);

    // Health insurance
    addHealthInsurance(&healthInsurance);
    calculateHealthInsuranceReturns(healthInsurance);

    return 0;
}

void addLifeInsurancePolicy(struct LifeInsurancePolicy *policy) {
    // Input customer details
    printf("Enter customer name: ");
    fgets(policy->customer.name, sizeof(policy->customer.name), stdin);
    strtok(policy->customer.name, "\n");

    // Input nominee details
    printf("Enter first nominee name: ");
    fgets(policy->nominee1.name, sizeof(policy->nominee1.name), stdin);
    strtok(policy->nominee1.name, "\n");

    printf("Enter second nominee name: ");
    fgets(policy->nominee2.name, sizeof(policy->nominee2.name), stdin);
    strtok(policy->nominee2.name, "\n");

    // Input investment amount and policy years
    printf("Enter investment amount per year: ");
    scanf("%d", &policy->investmentAmount);

    printf("Enter policy years: ");
    scanf("%d", &policy->policyYears);
}

void calculateLifeInsuranceReturns(struct LifeInsurancePolicy policy) {
    // Implement logic to calculate life insurance returns
    // For simplicity, let's assume a fixed return of 50% after the policy term
    int totalReturn = policy.investmentAmount * 1.5;

    // Display returns
    printf("\nLife insurance details:\n");
    printf("Customer: %s\n", policy.customer.name);
    printf("Nominee 1: %s\n", policy.nominee1.name);
    printf("Nominee 2: %s\n", policy.nominee2.name);
    printf("Investment amount per year: %d\n", policy.investmentAmount);
    printf("Policy years: %d\n", policy.policyYears);
    printf("Total return after policy term: %d\n", totalReturn);
}

void addTermPolicy(struct TermPolicy *policy) {
    // Input customer details
    printf("Enter customer name: ");
    fgets(policy->customer.name, sizeof(policy->customer.name), stdin);
    strtok(policy->customer.name, "\n");

    // Input nominee details
    printf("Enter nominee name: ");
    fgets(policy->nominee.name, sizeof(policy->nominee.name), stdin);
    strtok(policy->nominee.name, "\n");

    // Input investment amount and lock-in years
    printf("Enter investment amount: ");
    scanf("%d", &policy->investmentAmount);

    printf("Enter lock-in years: ");
    scanf("%d", &policy->lockInYears);
}

void calculateTermPolicyReturns(struct TermPolicy policy) {
    // Implement logic to calculate term policy returns
    // For simplicity, let's assume a fixed compound interest rate
    float interestRate;

    if (policy.lockInYears <= 5) {
        interestRate = 0.10;
    } else if (policy.lockInYears <= 10) {
        interestRate = 0.15;
    } else if (policy.lockInYears <= 20) {
        interestRate = 0.20;
    } else {
        interestRate = 0.25;
    }

    float totalReturn = policy.investmentAmount;

    for (int i = 0; i < policy.lockInYears; ++i) {
        totalReturn *= (1 + interestRate);
    }

    // Display returns
    printf("\nTerm policy details:\n");
    printf("Customer: %s\n", policy.customer.name);
    printf("Nominee: %s\n", policy.nominee.name);
    printf("Investment amount: %d\n", policy.investmentAmount);
    printf("Lock-in years: %d\n", policy.lockInYears);
    printf("Total return after policy term: %.2f\n", totalReturn);
}

void addVehicleInsurance(struct VehicleInsurance *insurance) {
    // Input vehicle details
    printf("Enter vehicle type (2 for two-wheeler, 4 for four-wheeler): ");
    scanf(" %c", &insurance->vehicleType);

    printf("Enter insured amount: ");
scanf("%d", &insurance->insuredAmount);
}

void calculateVehicleInsuranceReturns(struct VehicleInsurance insurance) {
// Implement logic to calculate vehicle insurance returns
// For simplicity, let's assume a fixed depreciation rate
float depreciationRate = 0.20;
float totalReturn = insurance.insuredAmount;
  for (int i = 0; i < 5; ++i) {
      totalReturn *= (1 - depreciationRate);
  }

  // Display returns
  printf("\nVehicle insurance details:\n");
  printf("Vehicle type: %c\n", insurance.vehicleType);
  printf("Insured amount: %d\n", insurance.insuredAmount);
  printf("Total return after 5 years: %.2f\n", totalReturn);
}

void addHealthInsurance(struct HealthInsurance *insurance) {
// Input health insurance details
printf("Enter insurance type (G for Gold Pass, P for Platinum Pass): ");
scanf(" %c", &insurance->insuranceType);
printf("Enter annual premium: ");
scanf("%d", &insurance->annualPremium);
printf("Enter annual premium: ");
scanf("%d", &insurance->annualPremium);
}

void calculateHealthInsuranceReturns(struct HealthInsurance insurance) {
// Implement logic to calculate health insurance returns
// For simplicity, let's assume a fixed coverage amount
int coverageAmount;
if (insurance.insuranceType == 'G') {
    coverageAmount = 100000; // Gold Pass coverage amount
} else if (insurance.insuranceType == 'P') {
    coverageAmount = 500000; // Platinum Pass coverage amount
} else {
    printf("Invalid insurance type\n");
    return;
}

// Display returns
printf("\nHealth insurance details:\n");
printf("Insurance type: %c\n", insurance.insuranceType);
printf("Annual premium: %d\n", insurance.annualPremium);
printf("Coverage amount: %d\n", coverageAmount);
}
