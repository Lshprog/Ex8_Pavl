#pragma once
namespace parking {
	struct Car {
		//bool inside;
		int times_out=0;
		char car_num[10];
		Car(char const* num);
		void print();
	};
	
	struct NodeList {
	private:
		struct Node {
			Car* data;
			Node* next;
			Node* prev;
			Node(Car* data);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		void car_in(Car* data);
		void car_out(char const* num);
		void print();
	};

}

void startprog();