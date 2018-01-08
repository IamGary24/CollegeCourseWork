import java.util.Scanner;


public class MortgageAccount_Fowler 
{
	private double accountNumber = 0, 	//holds account number
			principal = 0, 				//hold principal amount
			interestRate = 0, 			//holds interest rate
			numberPayments = 0, 		//holds number of payments made
			monthlyPayment = 0, 		//holds number of monthly payments left
			phone = 0;					//holds account phone number
	private String accountName = "", 	//holds account name (first name +  last name)
			address = "", 				//holds address
			firstName = "", 			//holds first name
			lastName ="";				//holds last name
	
	//create a scanner class to read keyboard input
			Scanner keyboard = new Scanner(System.in);
	
	public MortgageAccount_Fowler(double acc, double pri, double r, double num, String name) //parameter constructor
	{
		accountNumber = acc;
		principal = pri;
		interestRate = r;
		numberPayments = num;
		accountName = name;
	}
	
	private double calculateMonthlyPayment() //determine the monthly payment
	{
		monthlyPayment = (principal * Math.pow(1 + interestRate/12, numberPayments) *  interestRate /12) / (Math.pow(1 + interestRate /12, 360)-1);
		return monthlyPayment;
	}
	
	private double calculatePrincipal() //determine the current principal amount
	{
		principal = principal - (monthlyPayment - principal * interestRate/12);
		return principal;
	}
	
	public void setPrincipal() //construct method to construct principal amount
	{
		System.out.println("Input the current principal: "); //prompt user to provide current principal amount
		principal = keyboard.nextDouble();
	}
	
	public void setInterestRate() //construct method to construct interest Rate
	{
		System.out.println("Input the interest rate: "); //prompt user to provide interest rate
		interestRate = keyboard.nextDouble();
	}
	
	public void setNumberPayments() //construct method to construct number of payments
	{
		System.out.println("Input the number of payments: "); //prompt user to provide number of payments
		numberPayments = keyboard.nextDouble();
	}
	
	public void setAccountName() //constructor method to construct what account name is
	{
		System.out.println("Please input your last name: ");
		lastName = keyboard.nextLine();
		System.out.println("Please input your first name: ");
		firstName = keyboard.nextLine();
		accountName = firstName + " " + lastName;
	}
	
	public void setAccountNumber() // Constructor method to construct what account number is
	{
		System.out.println("Please input your account number: ");
		accountNumber = keyboard.nextDouble();
	}
	
	public void setAddress() //constructor method to construct address
	{
		System.out.println("Please input your address: ");
		address = keyboard.nextLine();
	}
	
	public void setPhone() //constructor method to construct phone number
	{
		System.out.println("Please input your phone number: ");
		phone = keyboard.nextDouble();
	}

	public void checkInterestRate() //shows interest rate to user
	{
		System.out.println("Name: " + accountName);
		System.out.println("Account Number: " + accountNumber);
		System.out.println("Current interest rate: " + interestRate);

	}
	
	public void checkMonthlyPayment()//shows the user the monthly payment
	{
		System.out.println("Name: " + accountName);
		System.out.println("Account Number: " + accountNumber);
		System.out.println("Monthly Payment: " + monthlyPayment);
	}
	
	public void checkPrincipal()//shows the user the current principal
	{
		System.out.println("Name: " + accountName);
		System.out.println("Account Number: " + accountNumber);
		System.out.println("Original Principal amount: " + principal);
		System.out.println("Number of payed payments: " + numberPayments);
		System.out.println("Current principal amount: " + calculatePrincipal());
	}
	
	public void getMonthlyPayment() //shows monthly payment to user
	{
		System.out.println("Principal Ammount: " + principal);
		System.out.println("Interest Rate: " + interestRate);
		System.out.println("Number Payments: " + numberPayments);
		System.out.println("Monthly Payment: " + calculateMonthlyPayment());
	}
	
	
}



