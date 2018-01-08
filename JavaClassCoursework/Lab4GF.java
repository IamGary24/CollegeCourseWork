/**
 * Lab4GF.java
 * 
 * @author Fowler, Gary III
 * @assignment CSCI 333 Lab 3 -Qn M
 * @date 9/22/2017
 *
 */
 
import java.io.*;
import java.util.*;

public class Lab4GF {

	public static void main(String[] args)
	{	
		//create a scanner to read user input
		Scanner input = new Scanner(System.in);
		
		//request user to input an integer
		System.out.print("Input an integer: ");
		
		//receive input from user as  a string
		String userInput = input.next();
		
		//variable for running total
		int total = 0;
		
		//loop over the string outputing each individual character
		for (int i = 0; i < userInput.length(); i++){
			System.out.print(userInput.charAt(i) + " ");
			total += Character.getNumericValue(userInput.charAt(i));
		}
		
		System.out.println("\nThe total is: " + total);
		
		
	}
}