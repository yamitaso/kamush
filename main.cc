#include <random>
#include <iostream>
#include <chrono>

int main(){
	/*std::random_device rd;
	std::minstd_rand rnd(rd());*/
	using clk = std::chrono::system_clock;
	std::minstd_rand rnd{
		unsigned(clk::now().time_since_epoch().count())
	};
	std::uniform_int_distribution<> d {15, 25};
	unsigned stone_count = d(rnd);
	std::cout << "В куче " << stone_count << " камней." << std::endl;
	std::cout << "Сколько тянете камней? (введите число от 1 до 3) ";

	for(unsigned i=0; i<10; i++)
			std::cout << d(rnd) << ' ';

	return 0;
}
/*доделать программу, игра камушки
 * спрашивает, сколько тянет юзер
 * уменьшает кучу
 * если 0 камней, то юзер проиграл
 * иначе ход компа
 * использовать:
 * цикл do while, либо for(;;)
 * break - выход из текущего блока внутри цикла или switch
 * countinue - вернуться на проверку условия
 * goto - метка, можно использовать в пределах блока или для выхода из блока
 * но, по возможности избегать его
 * метка:
 * 		тут оператор;
 * */

