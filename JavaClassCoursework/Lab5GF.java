 /**
 * Lab5GF.java
 * 
 * @author Fowler, Gary III
 * @assignment CSCI 333 Lab 5 -Qn M
 * @date 10/16/2017
 *
 */
 
import java.io.*;
import java.util.*;

public class Lab5GF{

	public static void main(String[] args)
	{	
		//create a scanner to read user input
		Scanner input = new Scanner(System.in);
		
		//request user to input the loan amount, the interest rate and the monthy playment
		//these values are stored in variables
		System.out.print("Input the loan amount: ");
		double loanAmount = input.nextDouble();
		
		System.out.print("Input the interest rate per year: ");
		double interestRate = input.nextDouble();
		
		System.out.print("Input the monthly payment: ");
		double monthlyPayment = input.nextDouble();
		
		//now calculate the monthly interest rate
		double monthlyInterest = interestRate / 1200.00; //the interest rate is a percentage, need to convert
		//flag for while loop
		boolean tooLow = false;
		
		//check to see if the payment is too low
		do{
			//if the payment is below the interest payment the loan will never be paid
			if (monthlyPayment < (loanAmount * monthlyInterest)){
				System.out.println("The monthly payment is too low.");
				tooLow = true;
							
			//get a new monthlyPayment
			System.out.print("Input the monthly payment: ");
			monthlyPayment = input.nextDouble();
			}
		
			tooLow = false;
		}while(tooLow);
			
		
		int monthCounter = 0; //month counter to determine how many months it took
		double adjustedPayment = 0; //the payment towards principal after subtracting interest payment
		
		//we do not know how many iterations, loanAmount controls the loop
		while(loanAmount > 0){
			//the loanAmount is always changing, so this equation must be called each time
			//the equation takes the original payment and subtracts the interest payment
			//this helps determine how much is paid towards principal
			adjustedPayment = monthlyPayment - (loanAmount * monthlyInterest); //need to format to dollars
			loanAmount = loanAmount - adjustedPayment; //subtract the loanAmount
			monthCounter++;
		}
		
		System.out.println("The loan will take " + monthCounter + " months to finish payment.");
	}
}