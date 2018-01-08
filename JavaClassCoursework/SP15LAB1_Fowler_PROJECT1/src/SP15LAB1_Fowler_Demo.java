//SP15LAB1_Fowler_Demo.java
import java.util.*; //This library is added

public class SP15LAB1_Fowler_Demo 
{
	public static void main(String[] args)
	{//the body of program
		
	//Display information on the screen by using "System.out.println( )"
	System.out.println("This is my first Java Program!");	
	
	//Syntax to declare variable is:
	// dataType variableName;
	//For example, declare variable named semester of String type
	String semester; //String is data type
	
	//Use "=" to assign value "Spring 2015" to variable named semester
	semester = "Spring 2015";
	
	//if displaying the value stored in a variable, just write the variable inside (...)
	System.out.println(semester);
	
	//declare variable myName of String and assign value to it on the same line
	String myName = "Liem Le";
	
	//display the value stored in variable myName. You can combine two pieces of // information by using +
	System.out.println("My name is: " + myName );
	
	//declare variable anInt1 and anInt2 of int type
	int anInt1;
	int anInt2;
	
	//assign values to int variables
	anInt1 = 10;
	anInt2 = 15;
	
	//display the sum of the two above numbers
	System.out.print("The sum is: "); //System.out.print do not go to next line
	
	//display the values that are stored in the variables, anInt1, anInt2
	//also, display the result of the sum of anInt1 and anInt2
	System.out.println(anInt1 + " + " + anInt2 + " = " + (anInt1 + anInt2));
	
	}//end of main
	
}//end of the class
