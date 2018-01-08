/**
*	Bill.java
*	@author: Gary Fowler
*	this class determines the patients bill and outputs that information
*/

public class Bill {
	
	private String ID;
	private double totalCharges;
	private double docFee;
	private double medFee;
	private double roomFee;
	
	//Default constructor
	//Initialize all values to 0, except the default 6 digit ID
	public Bill(){
		ID = "123456"; //ID is 6 digit
		docFee = 0;
		medFee = 0;
		roomFee = 0;
		totalCharges = docFee + medFee + roomFee;
	}
	
	//Constructor with parameters
	//we take the three fees and set them and total charges
	public Bill(String ID, double docFee, double medFee, double roomFee){
		setID(ID);
		setCharges(docFee, medFee, roomFee);
	}
	
	/**
	*setters
	*/
	
	//first set the ID
	public void setID(String i){
		ID = i;
	}
	
	//now we set not only the total charges but also all the individuals
	public void setCharges(double doc, double med, double room){
		totalCharges = doc + med + room;
		docFee = doc;
		medFee = med;
		roomFee = room;
	}
	
	/**
	*getters
	*/
	
	//return the ID
	public String getID(){
		return ID;
	}
	
	//return the totalCharges
	public double getTotalCharges(){
		return totalCharges;
	}
	
	//return each individual fee
	
	//doc
	public double getDocFee(){
		return docFee;
	}
	
	//med
	public double getMedFee(){
		return medFee;
	}
	
	//room
	public double getRoomFee(){
		return roomFee;
	}
	
}