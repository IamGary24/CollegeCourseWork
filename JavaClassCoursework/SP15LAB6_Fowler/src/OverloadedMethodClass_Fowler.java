
public class OverloadedMethodClass_Fowler
{
	public void displayInformation(int num1, int num2)
	{
		System.out.println("Here are the numbers: " + num1 + " " + num2);
	}
	
	public void displayInformation(double num1, String s)
	{
		System.out.println("Here are the inputs: " + num1 + " " + s);
	}
	
	public void displayInformation(String s1, String s2)
	{
		System.out.println("Here are the inputs: " + s1 + " " + s2);
	}

}
