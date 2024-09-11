/**
 * -------------------------------------
 * @file  file name
 * Assignment 1  Main File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version the date of creating this file in format like 2024-01-08
 *
 * ------------------------------------- */
#include <math.h>
#include <stdio.h>
#include "mymortgage.h"
/**
 * Compute the monthly payment of given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - monthly payment, float type.
 */
float monthly_payment(float principal_amount, float annual_interest_rate, int years) {
    // Convert annual interest rate to a decimal
    float monthly_interest_rate = annual_interest_rate / 12 / 100;

    // Calculate the total number of payments
    int total_payments = years * 12;

    // Calculate the monthly payment using the loan amortization formula
    float monthly_payment = principal_amount * (monthly_interest_rate * pow(1 + monthly_interest_rate, total_payments))
                                    / (pow(1 + monthly_interest_rate, total_payments) - 1);

    return monthly_payment;
}

/**
 * Determine the total payment of loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total payment of the loan, float type.
 */
float total_payment(float principal_amount, float annual_interest_rate, int years) {
	float monthly_interest_rate = annual_interest_rate / 12 / 100;

	    // Calculate the total number of payments
	    int total_payments = years * 12;
	    float monthly_payment = principal_amount * (monthly_interest_rate * pow(1 + monthly_interest_rate, total_payments))
	                                    / (pow(1 + monthly_interest_rate, total_payments) - 1);

    float total_payment = monthly_payment * 12 * years;

    return total_payment;
}

/**
 * Determine the total interested payed for the loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total interest payed by the end of paying off the loan, float type.
 */
float total_interest(float principal_amount, float annual_interest_rate, int years) {
    // Call the monthly_payment function to get the monthly payment
    float monthly_payment_value = monthly_payment(principal_amount, annual_interest_rate, years);
    float total_payment_value = total_payment(principal_amount, annual_interest_rate, years);
    float total_interest = total_payment_value - principal_amount;

    return total_interest;
}
