/**
*	Doctor.java
*	@author: Gary Fowler
*	this is a subclass to Person, holds info for Doctor and his specialty
*
*/

public class Doctor extends Person {

	//adds one field holding specialty
	private String specialty = "";
	
	//default Constructor
	public Doctor(){
		super(firstName, lastName);
		specialty = "";
	}
	
	//Constructor with parameters
	public Doctor(String first, String last, String spec){
		super(first, last);
		specialty = spec;
	}
	
	/**
	*setters
	*/
	
	//set name of doctor
	public void setName(String first, String last){
		firstName = first;
		lastName = last;
	}
	
	//method to set the Doctor's specialty
	public void setSpecialty(String spec){
		specialty = spec;
	}
	
	/**
	*getters
	*/	
	
	//method to return Doctor's specialty
	public String getSpecialty(){
		return specialty;
	}
	
	//method to get full doctor name
	public String getName(){
		String fullName = firstName + " " + lastName + " " + specialty;
		return fullName;
	}
}