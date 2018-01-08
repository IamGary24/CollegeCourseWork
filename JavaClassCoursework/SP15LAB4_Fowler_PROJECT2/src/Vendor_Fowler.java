
public class Vendor_Fowler 
{
	private double salary, //base salary
			sale, //sale amount
			commission, //commission amount
			pay, //total bonus pay the employee receives
			bonus; //bonus amount
	private String vendorName, //vendor name
			vendorId; //vendor id
	
	/*The class constructor that accepts 4 parameters to accept arguments: s, b, n,and ni. s is assigned to sales
	b is assigned to base salary, n is assigned to vendorName, ni is assigned to vendorID*/
	public Vendor_Fowler(double s, double b, String n, String ni)
	{
		sale = s;
		salary = b;
		vendorName = n;
		vendorId = ni;
		calculateSalary();
	}
	
	/* setCommission method sets the amount of commission the employee will make based
	 * off of the sale amount */
	private void setCommission()
	{
		 if (sale > 25000)
			 commission = 0.05 * (sale - 25000);
		 else
			 commission = 0;
			
	}
	
	/* setBonus method sets the amount of bonus the employee gets based off of the sale amount */
	private void setBonus()
	{
		if (sale > 40000)
			bonus = 0.03 * (sale - 40000);
		else
			bonus = 0;
	}
	
	/* calculateSalary method calculates the total salary amount the employee gets based off of the sale amount
	 * + commission + bonus */
	private void calculateSalary()
	{
		setCommission();
		setBonus();
		pay = salary + commission + bonus;
	}
	
	//the toString method to output the information
	public String toString()
	{
		String str = "";
		str = "----------------------------" +
		"\nVendor Name: " + vendorName +
		"\nVendor ID: " + vendorId + 
		"\nTotal sale: $" + sale + 
		"\nBase Salary: $" + salary +
		"\nCommission: $" + commission + 
		"\nBonus: $" + bonus + 
		"\nTotal Amount made: $" + pay +
		"\n----------------------------";
		return str;
	}
}
