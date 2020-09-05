/*
 * queues.h
 *
 *  Created on: 03/03/2019
 *      Author: Luis Jesus Morales Juarez
 */
#ifndef STACKSANDQUEUES_H_
#define STACKSANDQUEUES_H_

#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

class StacksAndQueues {
private:
	queue<string> tokenize(string);
	bool hasHigherPrecedence(const string&, const string&);

public:
	bool balancedBrackets(const string&);
	queue<int> merge(const queue<int>&, const queue<int>&);
	string convertInfixToPostfix(const string&);
};

queue<string> StacksAndQueues::tokenize(string str) {
	int i = 0;
	int length = str.size();
	string aux;
	queue<string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}


bool StacksAndQueues::hasHigherPrecedence(const string &stackTop, const string &op) {
	return !((stackTop == string("+") || stackTop == string("-")) &&
			 (op == string("*")       || op == string("/")));
}

bool StacksAndQueues::balancedBrackets(const string &expr) {
	
	string aux = expr;
    stack<string> pila;
	
	for(int i=0; i>=aux.length();i++){


        if( aux[i] == '('   ||     aux[i] == '['    ||      aux[i] == '{'){
            pila.push(aux[i]);
        }

        if( aux[i] == ')'   ||     aux[i] == ']'    ||      aux[i] == '}'){
            try
            {
                 char temp = pila.pop();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << 'Pila Vacia';
                return false;
            }        
                if(temp == '('){ if(aux[i]!=')'){return false;}}
                if(temp == '['){ if(aux[i]!=']'){return false;}}
                if(temp == '{'){ if(aux[i]!='}'){return false;}}
        }
    }
	
	
	return true;
}

queue<int> StacksAndQueues::merge(const queue<int> &queue1, const queue<int> &queue2) {
	queue<int> result;
	
	return result;
}

string StacksAndQueues::convertInfixToPostfix(const string &expr) {
	return string("");
}

#endif /* STACKSANDQUEUES_H_ */
