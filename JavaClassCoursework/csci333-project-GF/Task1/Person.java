/**
*	Person.java
*	stores information for a person, is the parent class of doctor and patient
*/
public class Person
{
    public static String firstName; //store the first name
    public static String lastName;  //store the last name

        //Default constructor
        //Initialize firstName and lastName to an empty string.
        //Postcondition: firstName = ""; lastName = "";
    public Person()
    {
        firstName = "";
        lastName = "";

    }

        //Constructor with parameters
        //Set firstName and lastName according to the parameters.
        //Postcondition: firstName = first; lastName = last;
    public Person(String first, String last)
    {
        setName(first, last);
    }

        //Method to output the first name and last name
        //in the form firstName lastName.
    public String toString()
    {
        return (firstName + " " + lastName);
    }

	/**
	*setters
	*/
	
        //Method to set firstName and lastName according to
        //the parameters.
        //Postcondition: firstName = first; lastName = last;
    public void setName(String first, String last)
    {
        firstName = first;
        lastName = last;
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
}
