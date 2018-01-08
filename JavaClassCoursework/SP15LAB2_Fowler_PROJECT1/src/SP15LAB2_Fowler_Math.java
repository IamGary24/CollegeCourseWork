//SP15LAB2_Fowler_Math.java
import java.util.*; //This library is included

public class SP15LAB2_Fowler_Math 
{
	public static void main(String[] args)
	{//the body of the program
		
		//Declare the variables used in this program and set them equal to 0
		double number1 = 0;
		double number2 = 0;
		double sum = 0;
		double difference = 0;
		double product = 0;
		double quotient = 0;
		
		//Name the keyboard as the object to read input form the keyboard
		Scanner keyboard = new Scanner(System.in);
		
		//Display information on the screen
		System.out.println("In this program you will input two numbers and receive some mathematical operations for those two numbers");
		
		//Ask the user for the first number
		System.out.println("Please input the first number: ");
		
		//Receive input from the user and place the input into integer 1
		number1 = keyboard.nextDouble();
		
		//Ask the user for the second number
		System.out.println("Please input the second number: ");
		number2 = keyboard.nextDouble();
		
		//Calculate the sum
		sum = number1 + number2;
		
		//Calculate the difference
		difference = number1 - number2;
		
		//Calculate the product
		product = number1 * number2;
		
		//Calculate the quotient
		quotient = number1 / number2;
		
		//Display the results as an output
		System.out.println("Input: " + number1 + ", " + number2);
		System.out.println("Sum: " + sum);
		System.out.println("Difference: " + difference);
		System.out.println("Product: " + product);
		System.out.println("Quotient: " + quotient);
		
	}

}
