 /**
 * Lab7GF.java
 * 
 * @author Fowler, Gary III
 * @assignment CSCI 333 Lab 7 -Qn M
 * @date 11/3/2017
 *
 */
 
import java.io.*;
import java.util.*;

public class Lab7GF{

	public static void main(String[] args)
	{	
		//declare array
		int[] theArray = new int[]{2,5,5,3,1,2,4,3,2,2,2,2,3,6,5,5,6,3,1};
		int count = 0;
		int oldCount = 0;
		int similarValue = 0;
		int similarIndex = 0;
		
		//loop through array
		for (int i = 0; i < theArray.length-1; i++){
			if (theArray[i] == theArray[i+1]){//if current value == next value
				count++;	//increase the count of similar
			}
			else if (count > 0){	//if we have more than one that was similar
				if (oldCount > count){ //this will only trigger if we have entered the below block
					continue;	//ignore the rest of the loop, the new count of similars is not greater than old
				}
				oldCount = count;	//now we need to track the count of similars
				count = 0; //reset the count
				similarValue = theArray[i];	//and store the value that is equivalent to the count
				similarIndex = i;
			}	
		}
		
		//loop through array again, this time stopping at the similar
		for (int i = 0; i < theArray.length; i++){
			if (similarIndex == i){ //similarIndex works funny and so it stores the last instance of the similar
				System.out.print(theArray[i]);
				System.out.print(") ");
			} else if (similarIndex - oldCount == i){//becase of this interaction we do the () seemingly backwards
				System.out.print("(");
				System.out.print(theArray[i] + " ");
			} else {
				System.out.print(theArray[i] + " ");
			}
		}
	}
}