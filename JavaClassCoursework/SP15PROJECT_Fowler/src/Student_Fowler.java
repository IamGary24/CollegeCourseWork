//Student class
import java.util.Scanner;
public class Student_Fowler
{
	
	private String name;
	private String studentId;
	private double project;
	private double discussionTopic;
	
	Scanner keyboard = new Scanner(System.in); //create an object to read keyboard input
	
	public void setName(String n) //setter that allows code from gradingApplication to store a value in name
	{
		name = n;
	}
	
	public void setStudentId(String Id) //setter that allows code from gradingApplication to store a value in studentId
	{
		studentId = Id;
	}
	
	
	public void setProject(double p) //setter that allows code from gradingApplication to store a value in project
	{
		project = p;
	}
	
	public void setDiscussionTopic(double dt)//setter that allows code from gradingApplication to store a value in discussionTopic
	{
		discussionTopic = dt;
	}
	
	public String getName()//getter to return name
	{
		return name;
	}
	
	public String getStudentId()//getter to return studentId
	{
		return studentId;
	}
	
	//method getQuizzes asks for input from the user and then populates the quizzesArray with the results
	public double[] getQuizzes(double[] quizzes)
	{
		for (int index = 0; index < quizzes.length; index++)
		{
			System.out.println("Input a grade for quiz " + index + ": ");
			quizzes[index] = keyboard.nextDouble();
		}
		
		return quizzes;
	}
	
	//method getHomework asks for input from the user and then populates the homeworkArray with the results
	public double[] getHomework(double[] homework)
	{
		for (int index = 0; index < homework.length; index++)
		{
			System.out.println("Input a grade for homework " + index + ": ");
			homework[index] = keyboard.nextDouble();
		}
		
		return homework;
	}
	
	//method getLab asks for the input from the user and then populates the labArray with the results
	public double[] getLab(double[] lab)
	{
		for(int index = 0; index < lab.length; index++)
		{
			System.out.println("Input a grade for lab " + index + ": ");
			lab[index] = keyboard.nextDouble();
		}
		
		return lab;
	}
	
	//method getTest asks for the input from the user and then populates the testArray with the results
	public double[] getTest(double[] tests)
	{
		for(int index = 0; index < tests.length; index++)
		{
			System.out.println("Input a grade for test " + index + ": ");
			tests[index] = keyboard.nextDouble();
		}
		
		return tests;
	}
	
	//method getQuizzesTotal totals up the quizzesArray
	public double getQuizzesTotal(double[] quizzes)
	{
		double total = 0; //to hold the quizzes grade total
		
		for (double grade : quizzes) //calculate the total of the quiz grades
			{
			total += grade;	
			}
		
		return total; //return the total grade
	}
	
	//method getHomeworkTotal totals up the homeworkArray
	public double getHomeworkTotal(double[] homework)
	{
		double total = 0; //to hold the homework grade total
		
		for(double grade : homework) //calculate the total of the homework grades
			total += grade;
		
		return total; //return the total homework grade
	}
	
	//method getLabTotal totals up the labArray
	public double getLabTotal(double[] lab)
	{
		double total = 0; //to hold the lab grade total
		
		for (double grade : lab) //calculate the total of the lab grades
			total += grade;
		
		return total; //return the total lab grade
	}
	
	//method getTestTotal totals up the testArray
	public double getTestTotal(double[] test)
	{
		double total = 0; //to hold the lab grade total
		
		for(double grade : test) //calculate the total of the test grades
			total += grade;
		
		return total; //return the total test grade
	}
	
	//the toString method to display requested information
	public String toString()
	{
		String str = " ";
		str = "\nStudent ID: " + studentId +
		"\n Quizzes: " +  
		
	}
	
	
	
	
	
	
	
	
	
	
}
