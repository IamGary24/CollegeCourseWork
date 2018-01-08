/**
*	Date.java
*	@author: Gary Fowler
*	this class holds information on important patient dates
*/

public class Date {
	
	private String dateOfBirth;
	private String admittedDate;
	private String dischargeDate;
	
	//Default constructor
	//Initialize all values to 0, except the default 6 digit ID
	public Date(){
		dateOfBirth = "default";
		admittedDate = "default";
		dischargeDate = "default";
	}
	
	//Constructor with parameters
	//we take the three fees and set them and total charges
	public Date(String dob, String ad, String dd){
		setDOB(dob);
		setAdmitted(ad);
		setDischarge(dd);
	}
	
	/**
	*setters
	*/
	
	//set the necessary dates
	public void setDates(String dob, String ad, String dd){
		dateOfBirth = dob;
		admittedDate = ad;
		dischargeDate = dd;
	}
	
	//set the date of birth
	public void setDOB(String dob){
		dateOfBirth = dob;
	}
	
	//set the admitted date
	public void setAdmitted(String ad){
		admittedDate = ad;
	}
	
	//set the discharge date
	public void setDischarge(String dd){
		dischargeDate = dd;
	}
	
	/**
	*getters
	*/
	
	//return the date of birth
	public String getDOB(){
		return dateOfBirth;
	}
	
	//return the admitted date
	public String getAdmitted(){
		return admittedDate;
	}
	
	//return the discharge date
	public String getDischarge(){
		return dischargeDate;
	}
	
}