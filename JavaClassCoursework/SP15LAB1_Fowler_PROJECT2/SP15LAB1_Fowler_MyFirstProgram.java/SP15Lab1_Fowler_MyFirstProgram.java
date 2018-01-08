//SP15_LAB1_Fowler_MyFirstProgram.java
import java.util.*; //This Library is added

public class SP15Lab1_Fowler_MyFirstProgram
{
	
	public static void main(String[] args)
	{//the body of the program
		
		//declare variables including my name
		String firstName = "Gary";
		String lastName = "Fowler";
		
		//declare variables denoting test scores
		double test1 = 89.7;
		double test2 = 98.25;
		double test3 = 76.3;
		double test4 = 92.5;
		
		//declare a variable to hold the average of the scores
		double average;
		
		//display information stating what school at richland
		System.out.println("Richland College - The school of Engineer Business and Technology");
		//display information stating what semester
		System.out.println("Spring 2015");
		//display information welcoming to the class
		System.out.println("Welcome to java class");
		
		//display information on the screen stating my name
		System.out.println("Student: " + firstName + " " + lastName);
		
		//display test scores
		System.out.println("Test scores: " + test1 + ", " + test2 + ", " + test3 + ", " + test4);
		
		//compute the average
		average = (test1 + test2 + test3 + test4) / 4.0;
		
		//display the average
		System.out.println("Average: " + average);
		
	}//end of program

}//end of the class
