#include <stdio.h>
#include <string>
#include <iostream>
#include "connectorof.h"



parking::Car::Car(const char* num) {
	//this->inside = inside;
	strcpy_s(car_num, num);
}
void parking::NodeList::car_in(Car* data) {
	Node* node = new Node(data);
	Node* iter = head;
	if (head == nullptr) { head = node; tail = node; }
	else {
		while (true) {
			if (!strcmp(node->data->car_num, iter->data->car_num)) {
				std::cout << "Car with the same num is already in the parking " << std::endl;
				return;
			}
			if (iter == tail) {
				break;
			}
			iter = iter->next;

		}
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
	std::cout << "Car with a num: " << node->data->car_num << " is in" << std::endl;
}
void parking::NodeList::car_out(const char* num) {
	Node* node = head;
	Node* iter;
	while (node!=nullptr) {
		
		if (!strcmp(node->data->car_num,num)){
			std::cout << "Car with a num: " << node->data->car_num << " is leaving. It was out to let other cars go out " << node->data->times_out << " times." << std::endl;
			if (head == tail) {
				head = nullptr;
				tail = nullptr;
				delete node;
				return;
			}
			if (node == head) {
				iter = head->next;
				while (true) {
					iter->data->times_out += 1;
					if (iter == tail)
						break;
					iter = iter->next;
				}
				head = node->next;
				
			}
			else if (node == tail) {
				(node->prev)->next = nullptr;
				tail = node->prev;
				
			}
			else {
				iter = node;
				
				while (true) {
					iter->data->times_out += 1;
					if (iter == tail)
						break;
					iter = iter->next;
				}
				(node->prev)->next = node->next;
				(node->next)->prev = node->prev;

			}	
			
			
			delete node;
			return;
		}
		if (node == tail) {
			std::cout<<"There is no car with a num: "<<num<<" in the parking! "<<std::endl;
			return;
		}
		node = node->next;
	}

	
}

void parking::NodeList::print()
{
	if ((tail==nullptr)&&(head == nullptr)) {
		std::cout << "No cars in the parking" << std::endl;
		return;
	}
	Node* iter = head;
	while (true) {

		std::cout <<"Car num: " <<iter->data->car_num <<"    ";
		std::cout <<"Times out: " <<iter->data->times_out<< std::endl;
	
		if (iter == tail)
			break;
		iter = iter->next;
	}
}

parking::NodeList::Node::Node(Car* data)
{
	this->data = data;
}

void Startprog() {
	char x[20];
	char t[20];
	std::cout << "Enter   1    if you want to park in your car " << std::endl;
	std::cout << "Enter   0    if you want to pick up your car " << std::endl;
	std::cout << "Enter   c    if you want to close the menu" << std::endl;
	std::cout << "Enter   p    if you want to see the full list of the cars in the parking" << std::endl;
	parking::NodeList list = parking::NodeList();
	while (true) {
		std::cin >> x;
		if (x[0] == '1') {
			std::cout << "Enter number of your car:   ";
			std::cin >> t;
			if (strlen(t) > 8) {
				std::cout << "Wrong car number! " << std::endl;
				continue;
			}
			list.car_in(new parking::Car(t));
			std::cout << "Something else?  " << std::endl;
			continue;
		}
		else if (x[0] == '0') {
			std::cout << "Enter number of your car:   ";
			std::cin >> t;
			if (strlen(t) > 8) {
				std::cout << "Wrong car number! " << std::endl;
				continue;
			}
			list.car_out(t);
			std::cout << "Something else?  " << std::endl;
			continue;
		}
		else if(x[0]=='p'){

			list.print();
			std::cout << "Something else?  " << std::endl;
			continue;
		}
		else if (x[0] == 'c')
			break;

		else {
			std::cout << "Enter appropriate char " << std::endl;
			continue;
		}
	}
}