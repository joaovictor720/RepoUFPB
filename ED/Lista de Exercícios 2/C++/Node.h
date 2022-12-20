/*
 * No.h
 *
 *  Created on: 20 de out. de 2022
 *      Author: tiagomaritan
 */

#ifndef NO_H_
#define NO_H_

class Node {

private:
	int conteudo;
	Node *ant;
	Node *prox;

public:
	Node();
	virtual ~Node();

	int getConteudo();
	Node *getProx();
	Node *getAnt();

	void setConteudo(int conteudo);
	void setProx(Node *prox);
	void setAnt(Node *ant);

};

#endif /* NO_H_ */
