import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Scanner;


public class SP15LAB6_Fowler_AreaOfShapeCalculation {

	public static void main(String[] args) 
	{
		//declare variable selection to use with user's inputted selection
		int selection = 0; 
		
		//create a scanner class to read keyboard input
		Scanner keyboard = new Scanner(System.in);
		
		//declare a decimal format to hold 2 decimal places
		NumberFormat formatter = new DecimalFormat("#0.00"); //format 2 decimal digits

		do
		{
			//display menu to user
			System.out.println("This program will calculate some Geometry!");
			System.out.println("1. Calculate the Area of a Circle");
			System.out.println("2. Calculate the Area of a Rectangle");
			System.out.println("3. Calculate the Area of a Square");
			System.out.println("4. Calculate the Area of a Triangle");
			System.out.println("5. Quit");
			System.out.println("Enter your choice(1-5): "); //prompt user to input a choice
			
			//read user's selection
			selection = keyboard.nextInt();
			
			//switch statement to handle the menu
			switch(selection)
			{
			case 1:
			{
				System.out.println("Input the circle's radius: ");
				double radius = keyboard.nextDouble(); //declare and initialize a variable to use with radius, the value is from the keyboard
				System.out.println("-------------------");
				System.out.println("CIRCLE");
				System.out.println("Radius = " + radius);
				System.out.println("The area is: " + formatter.format(StaticMethodClass_Fowler.areaOfCircle_Fowler(radius)));
				System.out.println("-------------------");
				break;
			}
			case 2:
			{
				System.out.println("Input the rectangle's length: ");
				double length = keyboard.nextDouble(); //declare and initialize a variable to use with length, the value is from the keyboard
				System.out.println("Input the rectangle's width: ");
				double width = keyboard.nextDouble(); //declare and initialize a variable to use with width, from keyboard
				//output requested information to user
				System.out.println("-------------------");
				System.out.println("RECTANGLE");
				System.out.println("Length = " + length);
				System.out.println("Width = " + width);
				System.out.println("The area is: " + formatter.format(StaticMethodClass_Fowler.areaOfRectangle_Fowler(length, width)));
				System.out.println("-------------------");
				break;
			}
			case 3:
			{
				System.out.println("Input the square's side length: ");
				double side = keyboard.nextDouble(); //declare and initialize a variable to use with side, from keyboard
				//output to user the information requested
				System.out.println("-------------------");
				System.out.println("SQUARE");
				System.out.println("Side = " + side);
				System.out.println("The area is: " + formatter.format(StaticMethodClass_Fowler.areaOfSquare_Fowler(side)));
				System.out.println("-------------------");
				break;
			}
			case 4:
			{
				System.out.println("Input the triangle's base: ");
				double base = keyboard.nextDouble(); //declare and initialize a variable to use with length, the value is from the keyboard
				System.out.println("Input the triangle's height: ");
				double height = keyboard.nextDouble(); //declare and initialize a variable to use with height, from keyboard
				//output to user the information requested
				System.out.println("-------------------");
				System.out.println("TRIANGLE");
				System.out.println("Base = " + base);
				System.out.println("Height = " + height);
				System.out.println("The area is: " + formatter.format(StaticMethodClass_Fowler.areaOfTriangle_Fowler(base, height)));
				System.out.println("-------------------");
				break;
			}
			case 5:
				break; //break from choice 5 to exit loop
			}
		}while(selection != 5);

	}

}
