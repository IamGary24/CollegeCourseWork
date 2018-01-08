/**
*	Task2.java
*	@author: Gary Fowler
* 
*	GUI program that converts seconds to years, weeks, days, hours, and minutes
*	example: 789975432seconds would be returned as:
*	25 years, 11 weeks, 4 days, 5 hours, 37 minutes, 12 seconds
*
*/
import java.awt.EventQueue;
import java.awt.BorderLayout;

import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;
import javax.swing.border.EmptyBorder;
import javax.swing.JFrame;

public class Task2 extends JFrame implements ActionListener {
	
	private JPanel contentPane;
	private JTextField secondsTextF;
	private JTextField yearsTextF;
	private JTextField weeksTextF;
	private JTextField daysTextF;
	private JTextField hoursTextF;
	private JTextField minutesTextF;	
	
	private JLabel secondsLabel, yearsLabel, weeksLabel,
					daysLabel, hoursLabel, minutesLabel;
	
		//the chosen layout
	GridLayout converterLayout = new GridLayout(0,2);

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Task2 frame = new Task2();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public Task2(){
		/**
		*outer container
		*/
		setTitle("Seconds Converter");
		setBounds(100,100,320,400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		//set our layout
		contentPane.setLayout(converterLayout);

		/**
		*add elements to the gridlayout
		*/
		contentPane.add(new JLabel("Seconds"));
		secondsTextF = new JTextField();
		secondsTextF.addActionListener(this);
	    contentPane.add(secondsTextF);
		
		contentPane.add(new JLabel("Years"));
		yearsTextF = new JTextField();
	    contentPane.add(yearsTextF);
		yearsTextF.setEditable(false);
		
		contentPane.add(new JLabel("Weeks"));
		weeksTextF = new JTextField();
	    contentPane.add(weeksTextF);
		weeksTextF.setEditable(false);
		
		contentPane.add(new JLabel("Days"));
		daysTextF = new JTextField();
	    contentPane.add(daysTextF);
		daysTextF.setEditable(false);
		
		contentPane.add(new JLabel("Hours"));
		hoursTextF = new JTextField();
	    contentPane.add(hoursTextF);
		hoursTextF.setEditable(false);
		
		contentPane.add(new JLabel("Minutes"));
		minutesTextF = new JTextField();
	    contentPane.add(minutesTextF);
		minutesTextF.setEditable(false);
				
	}
	
	//our conversion function and listener function
	public void actionPerformed(ActionEvent arg0){
		if(arg0.getSource()==secondsTextF){
			String text = secondsTextF.getText();
			int seconds = Integer.parseInt(text);
			
			//convert to the corresponding values
			int years = seconds / 31557600;
			int weeks = (seconds % 31557600) / 86400;
			int days = ((seconds % 31557600) % 604800) / 86400;
			int hours = (((seconds % 31557600) % 604800) % 86400) / 3600;
			int minutes = ((((seconds % 31557600) % 604800) % 86400) % 3600) / 60;
			seconds = ((((seconds % 31557600) % 604800) % 86400) % 3600) % 60;

			//set the text in the text boxes
			secondsTextF.setText(Integer.toString(seconds));
			yearsTextF.setText(Integer.toString(years));
			weeksTextF.setText(Integer.toString(weeks));
			daysTextF.setText(Integer.toString(days));
			hoursTextF.setText(Integer.toString(hours));
			minutesTextF.setText(Integer.toString(minutes));			
		}
	}
}

