#include <random>
#include <iostream>
#include <chrono>
#include <sstream>

int read_int(const std::string question)
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
	unsigned mode;
		while(1){
			menu:
				std::cout<<"Игра в камушки"<<std::endl;
				mode = read_int("Выберите действие:\n1.Игра с компьютером\n2.Игра с другим человеком\n3.Выход\n");
				if (mode<1||mode>3){std::cout<<"Такого режима нет!"<<std::endl;goto menu;}
				if (mode == 3) break;
	unsigned kamni;
	using clk = std::chrono::system_clock;
	std::minstd_rand rnd{
		unsigned(clk::now().time_since_epoch().count())
	};
	std::uniform_int_distribution<> d {15, 25};
	unsigned stone_count = d(rnd);
	while (mode == 1){
	std::cout << "В куче " << stone_count << " камней." << std::endl;
	stonechooze:
		kamni=read_int("Сколько тянете камней? (введите число от 1 до "+std::to_string(std::min(3U,stone_count))+="): ");
		if (kamni>0&&kamni<=std::min(3U,stone_count))
			stone_count-=kamni;
		else {std::cout<<"Введено неверное количество камней.\n"; goto stonechooze;}
	if (stone_count==0){
		std::cout<<"Вы проигрывающий."<<std::endl; break;
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
		if (stone_count==0){ std::cout<<"Вы выиграли."<<std::endl; break;}
	}}
	bool is1 = true;
	while(mode == 2){
		if (is1) is1=false; else is1 = true;
		if (stone_count==0){
						std::cout<<"Игрок "<<is1+1<<" выйграл!"<<std::endl; break;}
		stonechooze2:
		std::cout << "В куче " << stone_count << " камней." << std::endl;
		std::cout<<"Ходит "<<is1+1<<" игрок"<<std::endl;
		kamni=read_int("Сколько тянете камней? (введите число от 1 до "+std::to_string(std::min(3U,stone_count))+="): ");
		if (kamni>0&&kamni<=std::min(3U,stone_count))
			stone_count-=kamni;
		else {std::cout<<"Введено неверное количество камней.\n"; goto stonechooze2;}
	}

}return 0;}
