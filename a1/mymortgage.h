/**
 * -------------------------------------
 * @file  file name
 * Assignment 1  Header File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version the date of creating this file in format like 2024-01-08
 *
 * ------------------------------------- */
#ifndef MYMORTGAGE_H
#define MYMORTGAGE_H

float monthly_payment(float principal_amount, float annual_interest_rate, int years);

float total_payment(float principal_amount, float annual_interest_rate, int years);

float total_interest(float principal_amount, float annual_interest_rate, int years);

#endif  // MYMORTGAGE_H
