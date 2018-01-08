/**
*	Patient.java
*	@author: Gary Fowler
*	this is the subclass to Person, holds information for the Patient
*
*/

public class Patient extends Person {
	
	private String ID;
	private int age;
	private String doctorInfo;
	private String admittedDate;
	private String dateOfBirth;
	private String dischargeDate;
	
	//default Constructor
	public Patient(){
		super(firstName, lastName);
		age = 0;
		ID = "123456"; //default ID, 6 digits
		doctorInfo = "default"; //pull from Doctor.java
	}
	
	//Constructor with parameters
	public Patient(String first, String last, int a, String id, String dname){
		super(firstName, lastName);
		setAge(a);
		setID(id);
		setDoctor(dname); //pull from Doctor.java
	}
	
	//method to output the Patient's information
	public String toString(){
		return (firstName + " " + lastName + " " + age + " " + ID + " " + doctorInfo);
	}
	
	/**
	*setters
	*/
	
	
	//set patients age
	public void setAge(int a){
		age = a;
	}
	
	//set patients id
	public void setID(String id){
		ID = id;
	}
	
	
	//set name of patient
	public void setName(String first, String last){
		firstName = first;
		lastName = last;
	}
	
	//set the doctorName
	public void setDoctor(String info){
		doctorInfo = info;
	}
	
	//set the admitted date
	public void setAdmitted(String ad){
		admittedDate = ad;
	}
	
	//set the date of birth
	public void setDOB(String dob){
		dateOfBirth = dob;
	}
	
	//set the discharge date
	public void setDischarge(String dd){
		dischargeDate = dd;
	}
	
	/**
	*getters
	*/

        //Method to return firstName.
        //Postcondition: The value of firstName is returned.
    public String getFirstName()
    {
        return firstName;
    }

        //Method to return lastName.
        //Postcondition: The value of lastName is returned.
    public String getLastName()
    {
        return lastName;
    }
	//get patients age
	public int getAge(){
		return age;
	}
	
	//get patients id
	public String getID(){
		return ID;
	}	
	
	//get doctor information
	public String getDoctor(){
		return doctorInfo;
	}
	
	//method to get full patient name
	public String getName(){
		String fullName = firstName + " " + lastName;
		return fullName;
	}
	
		//get the admitted date
	public String getAdmitted(){
		return admittedDate;
	}
	
	//get the date of birth
	public String getDOB(){
		return dateOfBirth;
	}
	
	//get the discharge date
	public String getDischarge(){
		return dischargeDate;
	}
}
