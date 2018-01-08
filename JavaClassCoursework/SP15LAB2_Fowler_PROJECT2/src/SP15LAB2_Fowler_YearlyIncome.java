//SP15LAB2_Fowler_YearlyIncome.java
import java.util.*; //this library is included

public class SP15LAB2_Fowler_YearlyIncome 
{
	public static void main(String[] args)
	{//main body of the program
		
		//Declare variables used in this program
		String name; //employee name
		String department; // the department the employee works in
		double payRate; // the pay rate per hour of the employee
		double yearlyIncome; // the yearly income of the employee
		
		//name the keyboard as an object to read input from the keyboard
		Scanner keyboard = new Scanner(System.in);
		
		//Display message to the user
		System.out.println("This program will ask for your name, department, and pay rate per hour, then it will display the information as well as your yearly income.");
		
		//Ask user for name and receive input
		System.out.println("Please input your name: "); //display to the user
		name = keyboard.nextLine(); // read the next line of the keyboard and input into the string name
		
		//Ask user for department
		System.out.println("Please input your department: ");
		department = keyboard.nextLine();
		
		//Ask user for payRate
		System.out.println("Please input your pay rate per hour: ");
		payRate = keyboard.nextDouble();
		
		//Calculate the yearly income
		yearlyIncome = payRate * 40 * 52; // 40 hours per week, 52 weeks per year
		
		//Display the information to the user
		System.out.println("Employee Name: " + name);
		System.out.println("Department: " + department);
		System.out.println("Pay rate per hour: " + payRate);
		System.out.println("Yearly Income: " + yearlyIncome);
		System.out.println("Where yearly income = pay rate per hour * 40 (hours per week) * 52 (weeks per year)");
		
		
		
	}

}
