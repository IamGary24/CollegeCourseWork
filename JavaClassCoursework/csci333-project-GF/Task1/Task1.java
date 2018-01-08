/**
*	Task1.java
*	@author: Gary Fowler
* 
*	test all of the classes:
*   Bill.java, Person.java, Doctor.java, Patient.java, Date.java
*
*/

import java.io.*;
import java.util.*;

public class Task1 {
	
	public static void main(String[] args){
		
		/**
		*create patient A with billA and attendingA
		*
		*this patient will use default constructors
		*we will then use setters and add values in to change defaults
		*/
	
		Bill billA = new Bill();
		Patient patientA = new Patient();
		Doctor attendingA = new Doctor("Doctor","Strange","Surgery");
		Date datesA = new Date();
		
		/**
		*create patient B with billB and attendingB
		*
		*this patient will NOT use default constructors
		*we will then only use getters to output their information
		*/	
		
		Bill billB = new Bill("345543",750.00,349.99,1229.89);
		Doctor attendingB = new Doctor("Doctor","Octavian","Research");
		Patient patientB = new Patient("Jackie","Fowler",27,"345543",attendingB.getName());
		Date datesB = new Date("October 30, 1990","November 1, 2017", "November 3, 2017");
		
		/**
		*	Patient A setters
		*/
		//doctor setters
		attendingA.setName("Doctor","Strange");
		attendingA.setSpecialty("Surgery");
		
		//patient setters
		patientA.setAge(26);
		patientA.setID("223344");
		patientA.setDoctor(attendingA.getName()); //pull this from Doctor.java
		patientA.setName("Gary","Fowler");
		
		//bill setters
		billA.setID(patientA.getID());	//we actually want to get the ID from Patient.java
		billA.setCharges(850.00,450.25,1230.99);
		
		//date setters
		datesA.setDates("October 21, 1991","December 1, 2017","December 6, 2017");
		patientA.setDOB(datesA.getDOB());
		patientA.setAdmitted(datesA.getAdmitted());
		patientA.setDischarge(datesA.getDischarge());
		
		/**
		*	Patient A output
		*/
		System.out.println("The patient is: " + patientA.getName());
		System.out.println("Their age is: " + patientA.getAge());
		System.out.println("Their ID is: " + patientA.getID());
		System.out.println("Their Attending Physician is: " + patientA.getDoctor());
		System.out.println("Their bill is: ");
		System.out.print("Doctor Fee: " + billA.getDocFee() + " ");
		System.out.print("Medicine Fee: " + billA.getMedFee() + " ");		
		System.out.println("Room Fee: " + billA.getRoomFee());
		System.out.println("Their Date of Birth is: " + patientA.getDOB());
		System.out.println("Their Admitted Date is: " + patientA.getAdmitted());
		System.out.println("Their Discharge Date is: " + patientA.getDischarge());
		
		/**
		*	Patient B output
		*/
		patientB.setName("Jackie","Fowler");
		System.out.println("\nThe patient is: " + patientB.getName());
		System.out.println("Their age is: " + patientB.getAge());
		System.out.println("Their ID is: " + patientB.getID());
		System.out.println("Their Attending Physician is: " + patientB.getDoctor());
		System.out.println("Their bill is: ");
		System.out.print("Doctor Fee: " + billB.getDocFee() + " ");
		System.out.print("Medicine Fee: " + billB.getMedFee() + " ");		
		System.out.println("Room Fee: " + billB.getRoomFee());
		System.out.println("Their Date of Birth is: " + datesB.getDOB());
		System.out.println("Their Admitted Date is: " + datesB.getAdmitted());
		System.out.println("Their Discharge Date is: " + datesB.getDischarge());
		
		
	}
}