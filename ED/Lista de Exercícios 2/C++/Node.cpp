/*
 * No.cpp
 *
 *  Created on: 20 de out. de 2022
 *      Author: tiagomaritan
 */

#include "Node.h"
#include <stdlib.h>

Node::Node() {
	setAnt(NULL);
	setProx(NULL);
}

Node::~Node() {
}

int Node::getConteudo() {
	return conteudo;
}

void Node::setConteudo(int conteudo) {
	this->conteudo = conteudo;
}

Node *Node::getProx() {
	return prox;
}

void Node::setProx(Node *prox) {
	this->prox = prox;
}

Node *Node::getAnt() {
	return ant;
}

void Node::setAnt(Node *ant) {
	this->ant = ant;
}


