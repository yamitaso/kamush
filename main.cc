#include <random>
#include <iostream>
#include <chrono>
#include <sstream>
int read_int(const char * question)
{
	int result;
	std::string inp;
re: std::cout << question;
	std::getline (std::cin, inp);
	{
		std::stringstream inps {inp};
		inps>>result;
		if(inps.fail()){
			if(std::cin.fail()){
				std::cerr<<"Ошибка ввода вывода!"<<std::endl;exit(1);
			}
			std::cout <<
				"Некоректный ввод!"<<
				std::endl;
			goto re;
		}
		else if(not inps.eof()){
			std::cout<<"Непонятный мусор в конце ввода!"<<std::endl;
			goto re;

		}
	}
	return result;
}
int main(){
	int kamni;
	using clk = std::chrono::system_clock;
	std::minstd_rand rnd{
		unsigned(clk::now().time_since_epoch().count())
	};
	std::uniform_int_distribution<> d {15, 25};
	unsigned stone_count = d(rnd);
	while (1){
	std::cout << "В куче " << stone_count << " камней." << std::endl;
	stonechooze:
		std::cout<<"Сколько тянете камней? (введите число от 1 до "<<std::min(3U,stone_count)<<"): ";
		kamni=read_int("");
		if (kamni>0&&kamni<=std::min(3U,stone_count))
			stone_count-=kamni;
		else {std::cout<<"Введено неверное количество камней.\n"; goto stonechooze;};
	if (stone_count==0){
		std::cout<<"Вы проигрывающий."<<std::endl; return 0;
	} else {
		unsigned comp;
		if (kamni==1)
		comp = std::min(3U,stone_count);
		else if (kamni==2)
		comp = std::min(2U,stone_count);
		else if (kamni==3)
		comp = std::min(1U,stone_count);
		std::cout << "Компьютер вытянул "<<comp<<" камней. ";
		stone_count-=comp;
		if (stone_count==0){ std::cout<<"Вы выиграли."<<std::endl; return 0;}
	}}
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

