import java.util.Scanner;
import java.text.DecimalFormat;

//This is the main program for the Lab 4 Project and will use the methods from Vendor_Fowler to manipulate
//information provided by the user and display it in a clean output.

public class SP15LAB4_Fowler_VendorSalaryApplication 
{
	public static void main(String[] args)
	{
		double sale, //to hold amount of sales
			salary; //to hold base salary amount
		String vendorName, //to hold the Vendor's name
			vendorId; //to hold the Vendor's ID
		
		// Create DecimalFormat objects for dollar amounts and percentages.
		DecimalFormat dollar = new DecimalFormat("#,##0.00");
		DecimalFormat percent = new DecimalFormat("#0%");
		
		//Create a scanner object to read input.
		Scanner keyboard = new Scanner(System.in);
		
		//prompt user for the information needed
		System.out.println("This program will display a pay report for a vendor");
		System.out.println("Please input the following information: ");
		
		//ask the user for name, id, base salary, sales
		System.out.println("Your Name: "); //name
		vendorName = keyboard.nextLine(); //read input into vendorName
		System.out.println("Your Vendor ID: "); //id
		vendorId = keyboard.nextLine(); //read input into vendorId
		System.out.println("Base Salary Amount: $"); //base salary
		salary = keyboard.nextDouble(); //read input into salary
		System.out.println("Sales Amount: $"); //sales
		sale = keyboard.nextDouble(); //read input into sale
		
		//create an instance of the Vendor_Fowler class and pass the data to the constructor
		Vendor_Fowler payInfo = new Vendor_Fowler(sale, salary, vendorName, vendorId);
		
		//display the report
		System.out.println(payInfo.toString());
		
	}

}
