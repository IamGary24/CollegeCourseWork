import java.util.Scanner;

//This is the main program for the Lab 5 Project 

public class SP15LAB5_Fowler_MortgageService {

	public static void main(String[] args) 
	{
		double accountNumber = 0, //for account number
			principal = 0, //for principal amount
			interestRate = 0, //for interest rate
			numberPayments = 0; //for number of payments
		String accountName = ""; //for account name
		
		//create an object and associate it with the variable mortgage
		MortgageAccount_Fowler mortgage = new MortgageAccount_Fowler(accountNumber, principal, interestRate, numberPayments, accountName);
		
		//create a scanner class to read keyboard input
		Scanner keyboard = new Scanner(System.in);
		int selection; // variable to be used with the menu selection

		//create a do...while loop for use with this program so that it will execute at least once and then continue until the user exits
			do
			{
		//Display the menu to the user
				System.out.println("This program will list some options to choose from, type 1-6 to select an option.");
				System.out.println("1. Estimate the monthly mortgage payment.");
				System.out.println("2. Open new mortgage account.");
				System.out.println("3. Check interest rate.");
				System.out.println("4. Monthly payment.");
				System.out.println("5. Check current principal.");
				System.out.println("6. Exit.");
		
		//declare variable to be used with the users selection
				selection = keyboard.nextInt();
				switch(selection) //use a switch structure to determine the choice the user picked and provide the correct information
				{
				case 1: 
					{
					mortgage.getMonthlyPayment(); //call function to retrieve the monthly payment
					break;
					}
				case 2: //open a new mortgage account with user
					{
					mortgage.setPrincipal();
					mortgage.setInterestRate();
					mortgage.setNumberPayments();
					mortgage.setAccountName();
					mortgage.setAccountNumber();
					mortgage.setAddress();
					mortgage.setPhone();
					break;
					}
				case 3: //check the interest rate
					mortgage.checkInterestRate();
					break;
				case 4: //check the monthly payment
					{
					mortgage.checkMonthlyPayment();
					break;	
					}
				case 5: //check the principal
					{
					mortgage.checkPrincipal();
					break;
					}
				case 6:
					break;
				}
			}while (selection != 6);
	}

}
