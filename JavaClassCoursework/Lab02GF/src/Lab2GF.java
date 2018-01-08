/**
 * Lab2GF.java
 * 
 * @author Fowler, Gary III
 * @assignment CSCI 333 Lab 2 -Qn M
 * @date 9/17/2017
 *
 */

import javax.swing.JOptionPane;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Lab2GF {
	
	//each milk carton holds 3.78 liters of milk
	private static double milkCartonSize = 3.78;
	//the cost to produce a carton and the profit earned
	private static double costProduceMilk = .38;
	private static double profitMilkCarton = .27;
	
	public static void main(String[] args)
	{
		//declare input scanner
		Scanner cartonInput = new Scanner(System.in);
		//set the format of 2 decimal places for the program
		DecimalFormat df = new DecimalFormat("#.00");
		
		//prompt the user for how much milk and store as a double
		System.out.println("Input the amount of milk produced this morning: ");
		double userInput = cartonInput.nextDouble();
		
		//output the amount of milk cartons needed rounded to the nearest int, 
		//store the num in a variable - numCartons
		System.out.print("The number of milk cartons needed is: ");
		long numCartons = Math.round(userInput / milkCartonSize);
		System.out.println(df.format(numCartons));
		
		//output the cost of producing milk
		System.out.print("The cost to produce the milk is: $");
		System.out.println(df.format(numCartons*costProduceMilk));
		
		//output the profit of producing milk
		System.out.print("The profit of the milk is: $");
		System.out.println(df.format(numCartons*profitMilkCarton));
		
		//no longer need the stream of i/o
		cartonInput.close();
		
		//display all outputs in dialog box
		JOptionPane.showMessageDialog(null, "The number of milk cartons needed is: " + df.format(numCartons) 
		+ "\nThe cost to produce the milk is: $" + df.format(numCartons*costProduceMilk) + 
		"\nThe profit of the milk is: $" + df.format(numCartons*profitMilkCarton));
	}

}
