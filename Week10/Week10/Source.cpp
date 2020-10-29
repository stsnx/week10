#include<iostream>
#include<time.h>
#include<vector>
#include<string.h>
struct card {
	int head;
	int sym;
	int point;
};
bool checkDuplicate[52];
std::vector<card> Deck;
char Head[14] = "A234567890JQK";
char Sym[4][10] = { "Spade","Hearth","Diamond","Clover" };
void shuffle() {
	for (int i = 0; i < 52; i++) {
		int temp = rand() % 52;
		
		while (checkDuplicate[temp] == true) {
			temp = rand() % 52;
		}checkDuplicate[temp] = true;
		card Card;
		int t = temp % 13;
		switch (t) {
		case 0: {Card.head = 12; Card.point = 0; break; }
		case 1: {Card.head = 0; Card.point = 1; break; }
		case 2: {Card.head = 1; Card.point = 2; break; }
		case 3: {Card.head = 2; Card.point = 3; break; }
		case 4: {Card.head = 3; Card.point = 4; break; }
		case 5: {Card.head = 4; Card.point = 5; break; }
		case 6: {Card.head = 5; Card.point = 6; break; }
		case 7: {Card.head = 6; Card.point = 7; break; }
		case 8: {Card.head = 7; Card.point = 8; break; }
		case 9: {Card.head = 8; Card.point = 9; break; }
		case 10: {Card.head = 9; Card.point = 0; break; }
		case 11: {Card.head = 10; Card.point = 0; break; }
		case 12: {Card.head = 11; Card.point = 0; break;}
		}
		t = temp / 13;
		switch (t) {
		case 0: Card.sym = 0; break;
		case 1: Card.sym = 1; break;
		case 2: Card.sym = 2; break;
		case 3: Card.sym = 3; break;
		}
		Deck.push_back(Card);
	}
	
}
int main() {
	srand(time(NULL));
	shuffle();
	std::cout << "Your Hand Have ";
	for (int i = 0; i < 2; i++) {
		if (Deck[i].head == 9){
			std::cout << "10" << ' ';
			
		} 
		else std::cout << Head[Deck[i].head] << ' ';
		std::cout << Sym[Deck[i].sym];
		if(i==0) std::cout << " and ";
		else std::cout << std::endl;
	}
	int S = Deck[0].point + Deck[1].point;
	S %= 10;
	std::cout << "You have "<<S<<" point"<<std::endl;
	if (S < 8)
	{
		char d;
		std::cout << "Do you want Hit or Stand? (h/s) ";
		std::cin >> d;
		if (d == 'h') {
			std::cout << "Your Hand Have ";
			for (int i = 0; i < 3; i++) {
				if (Deck[i].head == 9) {
					std::cout << "10" << ' ';

				}
				else std::cout << Head[Deck[i].head] << ' ';
				std::cout << Sym[Deck[i].sym];
				if (i == 0) std::cout << " , ";
				else if (i == 1) std::cout << " and ";
				else std::cout << std::endl;
			}
			S+= Deck[2].point;
			S %= 10;
			std::cout << "You have " << S << " point ,Game Over" << std::endl;
		}
		else if (d == 's') {
			std::cout << "You have " << S << " point ,Game Over" << std::endl;
		}
	}
	else std::cout <<" ,Game Over" << std::endl;
}