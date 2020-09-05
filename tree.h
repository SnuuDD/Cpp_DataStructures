/*
 * tree.h
 *
 *  Created on: 31/03/2019
 *      Author: Luis Jesus Morales Juarez - A01703455
 */
 
#ifndef TREE_H_
#define TREE_H_

#include <string>
#include <sstream>
#include "exception.h"

class SimpleTree;

class TreeNode {
private:
	int value;
	TreeNode *left, *right;
	
	int depth() const;
	void removeChilds();
	bool isLeaf() const;
	
public:
	TreeNode(int);
	TreeNode(int, TreeNode*, TreeNode*);
	
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
	
	friend class SimpleTree;
};

TreeNode::TreeNode(int val) : value(val), left(0), right(0) {}

TreeNode::TreeNode(int val, TreeNode* le, TreeNode* ri)
	: value(val), left(le), right(ri) {}

void TreeNode::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

bool TreeNode::isFull() const {	
	
	//Checa si el nodo es solo una hoja
	if(isLeaf()){return true;}
	
	//Si no lo es checa si ambos ampuntadores lo son de manera recursiva
	if (left !=0 && right != 0){
		return (left->isFull() && right->isFull());
	}
	//Si alguno de los dos no es una hoja, regresa faslo
	return false;
}

int TreeNode::internalNodes() const {
	int index = 0;
	// Si es solo un nodo no tiene internos y regresa 0
	if(isLeaf()){return 0;}
	//Si alguna de las ramas no estan vacias cuenta los nodos de las mismas hasta que sean hojas
	else if(right!=0 && left != 0){
		index = index + (left->internalNodes() + right->internalNodes());
	}
	//Si el lado derecho esta vacio, solo cuenta el izquierdo
	else if(right==0){
		index = index + left->internalNodes();
	}
	//Si el lado izquierdo, esta vacio solo cuenta el derecho
	else if(left==0){
		index = index + right->internalNodes();
	}
	//Se regresa +1 pues el padre tambien es un nodo
	return index + 1;
}

int TreeNode::depth() const {
	int le = -1;
	int ri = -1;
	int de = -1;

	if (left != 0) {
		le = left->depth();
	}
	if (right != 0) {
		ri = right->depth();
	}
	de = (le > ri)? le : ri;
	return (de + 1);
}

bool TreeNode::isPerfect() const {
	//Si es un unico nodo es perfecto
	if(isLeaf()){return true;}
	//Si esta lleno, checa la profundidad de ambos nodos, si son iguales regresa true
	if(isFull()){
		int d=0,i=0;
		d=right->depth();
		i=left->depth();
			
		if(d==i){
			return true;
			
		}
	return false;
	}
	

}

bool TreeNode::isLeaf() const {
	return (left == 0 && right == 0);
}


bool TreeNode::isDegenerate() const {
	//Si uno de los nodos no esta vacio, no es un arbol degenerado xd
	if((left!=0 && right!=0)){return false;}
	//Si el lado izquierdo esta vacio, checamos el derecho
	else if(left==0 && right!=0){
			//Continuamos hasta que un nodo sea hoja
			if(right->isLeaf()) {return true;}
			else
			//Si no es una hoja llamos de nuevo la funcion para que evalue el siguinte nodo
				return(right->isDegenerate());
	}
	//Sino entro al primer if, checamos ellado izquierdo
	else if(left!=0 && right==0)
		{
			//Continuamos hasta que un nodo sea hoja
			if(left->isLeaf()) {return true;}
			else
			//Si no es una hoja llamos de nuevo la funcion para que evalue el siguinte nodo
				return(left->isDegenerate());

	}
}

class SimpleTree {
private:
	TreeNode *root;
	void caseOne();
	void caseTwo();
	void caseThree();
	void caseFour();

public:
	SimpleTree(int);
	~SimpleTree();
	bool empty() const;
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
};

SimpleTree::SimpleTree(int option) {
	switch (option) {
		case  1: caseOne(); break;
		case  2: caseTwo(); break;
		case  3: caseThree(); break;
		default: caseFour(); break;
	}
}

void SimpleTree::caseOne() {
	TreeNode *a, *b, *c, *d;
	
	a = new TreeNode(4);
	b = new TreeNode(5);
	c = new TreeNode(2, a, b);
	
	a = new TreeNode(6);
	b = new TreeNode(7);
	d = new TreeNode(3, a, b);
	
	root = new TreeNode(1, c, d);
}

void SimpleTree::caseTwo() {
	TreeNode *a, *b, *c, *d, *e;
	
	a = new TreeNode(8);
	b = new TreeNode(9);
	c = new TreeNode(4, a, b);
	
	a = new TreeNode(10);
	b = new TreeNode(11);
	d = new TreeNode(5, a, b);
	
	e = new TreeNode(2, c, d);
	
	a = new TreeNode(6);
	b = new TreeNode(7);
	c = new TreeNode(3, a, b);
	
	root = new TreeNode(1, e, c);
}	

void SimpleTree::caseThree() {
	TreeNode *a, *b, *c;
	
	a = new TreeNode(6);
	
	b = new TreeNode(5, a, 0);
	
	c = new TreeNode(4, 0, b);
	
	a = new TreeNode(3, c, 0);
	
	b = new TreeNode(2, 0, a);
	
	root = new TreeNode(1, b, 0);
}

void SimpleTree::caseFour() {
	root = new TreeNode(1);
}

SimpleTree::~SimpleTree() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

bool SimpleTree::empty() const {
	return (root == 0);
}

bool SimpleTree::isFull() const {
	if (!empty()) {
		return root->isFull();
	}
	return false;
}

int SimpleTree::internalNodes() const {
	if (!empty()) {
		return root->internalNodes();
	}
	return 0;
}

bool SimpleTree::isPerfect() const {
	if (!empty()) {
		return root->isPerfect();
	}
	return false;
}

bool SimpleTree::isDegenerate() const {
	if (!empty()) {
		return root->isDegenerate();
	}
	return false;
}

#endif /* EVALTREE_H_ */
