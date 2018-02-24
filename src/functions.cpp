/**********************************************************************
 * This program has two purposes:
 * 	(1) Takes a string and makes sure that every closing 
 * 	    parenthesis, square bracket, and curly bracket has a
 * 	    corresponding opening symbol.
 * 	(2) Take a valid infix expression and returns the corresponing
 * 	    postfix expression.
 *
 * This program uses the functions.h file (located in the includes
 * folder.
 *
 * @author Nicholas English
 * @version 1.0
 * @date 2/23/2018
 *********************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include "functions.h"


/**********************************************************************
 * Helper method for the iToP function to determine the order of
 * operations.
 *
 * @param top holds the character of the current top item in the stack.
 * @param current hold the current character to be compared to the top
 * 	  item in the stack.
 * @return bool return's if the top character has higher priority.
 *********************************************************************/
bool hasHigherPriority(char top, char current);

/* Main */
int main(int argc, char** argv) {
	
	/* Variable(s) */
	int choice;
	std::string userInput;

	/* Determines which method to run based on user input. */
	std::cout << "\n\n\n Would you like to check for balanced" <<
		"symbols or convert an infix expression to postfix?" << std::endl;
	std::cout << " Enter 1 or 2 respectively for the input: \t";
	std::cin >> choice;

	/* Loops until the user enters a valid input. */
	while (choice != 1 && choice != 2) {
		std::cout << "\n\n Invalid choice! Please enter 1 or 2: \t"; 
		std::cin >> choice; 
	}

	/* Check for balanced symbols. */
	if (choice == 1) {

		/* Gets user input for what they would like checked. */
		std::cout << "\n Please enter what you would like checked:" << std::endl;
		std::cin >> userInput;

		/* Sends string to the functions. */
		balancedSymbols(userInput);

		if(balancedSymbols(userInput))
			std::cout << "\n\n Input is balanced!" << std::endl;
		else
			std::cout << "\n\n Input is NOT balanced!" << std::endl;
	}


	/* Convert infix to postfix. */
	if(choice == 2) {
		
		/* Variable(s) */
		std::string userInput;

		/* Gets user input for what they would like converted. */
		std::cout << "\n Please enter what you would like converted:" << std::endl;
		std::cin >> userInput;

		/* Prints the converted expression. */
		std::cout << "\n\n The converted expression is:" << std::endl;
		std::cout << iToP(userInput) << std::endl;

	}

	/* End of code reached. */
	std::cout << "\n\n\n " << std::endl;
}

/**********************************************************************
 * Function takes a string from the user and checks if the sumbols are
 * balanced.
 *
 * @param input is a string that the user would like checked.
 *********************************************************************/
// Sources of help:
// (1) http://www.cplusplus.com/reference/stack/stack/
bool balancedSymbols(std::string input) {
	
	/* Variable(s) */
	std::stack<char> balanceStack;
	
	/* Loops through every character in the string. */
	for(int i = 0; i < input.length(); i++) {

		/* What to do if an opening character. */
		if(input[i] == '(' || input[i] == '[' || input[i] == '{')
			balanceStack.push( input[i] );

		/* What to do if a closing character. */
		if(input[i] == ')' || input[i] == ']' || input[i] == '}') {
			
			if(balanceStack.empty())
				return false;

			else if ( balanceStack.top() == '(' && input[i] == ')' )
				balanceStack.pop();

			else if ( balanceStack.top() == '[' && input[i] == ']' )
				balanceStack.pop();

			else if ( balanceStack.top() == '{' && input[i] == '}' )
				balanceStack.pop();  
		}
	}

	/* Returns if the line is balance or not. */
	if(balanceStack.size() == 0)
		return true;
	else
		return false;
}

/**********************************************************************
 * Function converts an infix expression to a postfix expression. The
 * expression being converted is provided by the user.
 *
 * @param input is a string that the user would like converted.
 *********************************************************************/
// Sources of help:
// (1) https://www.youtube.com/watch?v=vq-nUF0G4fI
std::string iToP(std::string input) {
	
	/* Variable(s) */
	std::string postfix = "";
	std::stack<char> Operators;

	/* Loops through the string looking for operators. */
	for(int i = 0; i < input.length(); i++) {

		/* Scans each character to see if it's an operator. */
		if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			
			while(!Operators.empty() && Operators.top() != '(' && hasHigherPriority(Operators.top(), input[i])) {
				postfix += Operators.top();
				Operators.pop();
			}
			Operators.push(input[i]);
		}
		
		/* Scans each character to see if it's a space. */
		else if(input[i] == ' ')
			continue;

		/* Scans for an open parenthesis. */
		else if(input[i] == '(')
			Operators.push(input[i]);

		/* Scans for a closed parenthesis. */
		else if(input[i] == ')') {
			while(!Operators.empty() && Operators.top() != '(') {
				postfix += Operators.top();
				Operators.pop();
			}
			Operators.pop();
		}

		/* Puts the remaining characters intp string. */
		else
			postfix += input[i];
		
		/* Puts the remaning operators into the string. */
		while(!Operators.empty()) {
			postfix += Operators.top();
			Operators.pop();
		}
	}

	return postfix;
}

/**********************************************************************
* Helper method for the iToP function to determine the order of
* operations.
*
* @param top holds the character of the current top item in the stack.
* @param current hold the current character to be compared to the top
*        item in the stack.
* @return bool return's if the top character has higher priority.
*********************************************************************/
bool hasHigherPriority(char top, char current) {
	
	/* Variable(s) */
	int topWeight;
	int currentWeight;

	/* Sets a weight system to the characters. */
	// Multiplication and Division will be assigned 2.
	// Addition and Subtration will be assigned 1.
	if(top == '*' || top == '/')
		topWeight = 2;
	else
		topWeight = 1;
	
	if(current == '*' || current == '/')
		currentWeight = 2;
	else
		currentWeight = 1;
	
	/* Compares the top to the current character. */
	if(topWeight == currentWeight) 
		return true;

	if(topWeight > currentWeight)
		return true;

	if(topWeight < currentWeight)
		return false; 
}

