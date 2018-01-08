/**
 * Lab3GF.java
 * 
 * @author Fowler, Gary III
 * @assignment CSCI 333 Lab 3 -Qn M
 * @date 9/22/2017
 *
 */

import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Lab3GF {

	public static void main(String[] args)
	{
		File file = new File("C:\\Users\\Gary\\eclipse-workspace\\HW2GF_fileio\\GFData.txt");
		Scanner inFile = new Scanner(file);
		PrintWriter outFile = new PrintWriter("GFOutput.txt");

		//set the format of 2 decimal places for the program
		DecimalFormat df = new DecimalFormat("#.00");
		
		//while(inFile.hasNextLine())
		{
			//read from file
			String lastName = inFile.next();	//read the last name which is first	
			String firstName = inFile.next();	//read the first name which follows
			double currentSalary = inFile.nextDouble();	//the salary is next and is a double
			double percentIncrease = inFile.nextDouble();	//the percent increase is last and is a double
		
			double updatedSalary = (currentSalary * percentIncrease) + currentSalary;	//calculate updated salary
			
			outFile.println(lastName + " " + firstName + " " + df.format(updatedSalary));
			inFile.nextLine();	//move to the next line and progress the while loop
		}
		//close i/o streams
		inFile.close();
		outFile.close();
		
	}
}
