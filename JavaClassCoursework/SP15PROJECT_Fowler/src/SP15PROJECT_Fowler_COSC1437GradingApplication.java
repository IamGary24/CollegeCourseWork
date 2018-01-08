//controlling class of the program. uses methods from Student_Fowler class
import java.util.Scanner;

public class SP15PROJECT_Fowler_COSC1437GradingApplication
{
	public static void main(String[] args)
	{
		Student_Fowler grading = new Student_Fowler(); //creates a Student_Fowler class object and associates it with the variable grading
		Scanner keyboard = new Scanner(System.in); //create a scanner object for keyboard input
		
		//declare constants to be used in the program
		final int NUM_QUIZZES = 15;
		final int NUM_HOMEWORK = 10;
		final int NUM_LAB = 7;
		final int NUM_TEST = 3;
		final double NUM_MAX = 800;
		
		//create an array for quizzes, homework, labs, tests
		double[] quizzesArray = new double[NUM_QUIZZES];
		double[] homeworkArray = new double[NUM_HOMEWORK];
		double[] labArray = new double[NUM_LAB];
		double[] testArray = new double[NUM_TEST];
		
		char repeat; //the char to determine if the user would like to stop the program or not
		
		do //create a do...while loop to execute the "menu" of the program
		{
			//ask the user for their name
			System.out.println("What is your name? ");
			grading.setName(keyboard.next());
			
			//ask the user for their id
			System.out.println("What is your Student ID? ");
			grading.setStudentId(keyboard.next());
		
		//pass the arrays to the get methods
		grading.getQuizzes(quizzesArray);
		grading.getHomework(homeworkArray);
		grading.getLab(labArray);
		grading.getTest(testArray);
		
		//ask the user for their project grade
		System.out.println("What is your project grade? ");
		grading.setProject(keyboard.nextDouble());
		
		//ask the user for their discussion grade
		System.out.println("What is your discussion grade? ");
		grading.setDiscussionTopic(keyboard.nextDouble());
		
		//compute the total grade by defining variable totalGrade and then adding the total grades of each individual item
		double totalGrade = grading.getQuizzesTotal(quizzesArray) + grading.getHomeworkTotal(homeworkArray) + grading.getLabTotal(labArray) + grading.getTestTotal(testArray);
		
		//display max score possible
		double maxGrade = NUM_MAX;
		
		//calculate the percentage
		double percentage = (100*totalGrade)/maxGrade;
		
		//call the toString method to output the information
		System.out.println(grading.toString());
		
		
		
		
		//Does the user want to continue?
		System.out.println("Would you like to go back to the menu?");
		System.out.println("Enter Y for yes or N for no: ");
		String input = " "; //declare variable input for the user's input
		input = keyboard.next(); //read a string
		repeat = input.charAt(0); //get the first char
		
		}while (repeat == 'Y' || repeat == 'y');
		
		
		
		
		
	}
	
	

}
