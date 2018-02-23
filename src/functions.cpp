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
#include <"functions.h">

int main(int argc, char** argv) {
	/* Variable(s) */
	int choice;	// Holds the user's choice of operation.

	/* Determines which method to run based on user input. */
	std::cout << "\n Would you like to check for balanced" <<
		"symbols or convert an infix expression to postfix?" << std::endl;

	std::cout << "Enter 1 or 2 respectively for the input: \t";
	std::cin >> choice;

	/* Loops until the user enters a valid input. */
	while (choice != 1 && choice != 2) {
		std::cout << "\n\n Invalid choice!" <<
			<< "Please enter 1 or 2: \t"
			<< std::endl;
		std::cin >> choice; 
	}

	/* Check for balanced symbols. */
	if (choice == 1) {
	
		/* Variable(s) */
		std::string userInput;

		/* Gets user input for what they would like checked. */
		std::cout << "\n Please enter what you would like checked:" << std::endl;
		std::cin >> userInput;

		/* Sends string to the functions. */
		balancedSymbols(userInput);
	}


	/* Convert infix to postfix. */
	if(choice == 2)
		
		/* Variable(s) */
		std::string userInput;

		/* Gets user input for what they would like converted. */
		std::cout << "\n Please enter what you would like converted:" << std::endl;
		std::cin >> userInput;

		/* Sends string to the function. */
		convertExpression(userInput);
	}

	/* End of code reached. */
	std::cout << "\n\n\n" << std::endl;
}

/**********************************************************************
 * Function takes a string from the user and checks if the sumbols are
 * balanced.
 *
 * @param input is a string that the user would like checked.
 *********************************************************************/
bool balancedSymbols(std::string input) {
	/* Variable(s) */
	stack balanceStack;
	
	/* Loops through every character in the string. */
	for(int i = 0; i < input.length(); i++) {

		/* What to do if an opening character. */
		if(input[i] == '(' || input[i] == '[' || input[i] == '{')
			balanceStack.push( input[i] );

		/* What to do if a closing character. */
		if((input[i] == ')' || input[i] == ']' || input[i] == '}')
			if ( balanceStack.top() == input [i] )
				balanceStack.pop();
	}
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


}







































