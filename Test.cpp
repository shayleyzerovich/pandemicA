 
 
	#include "doctest.h"
	#include <iostream>
	#include <stdexcept>
	

	#include "Board.hpp"
	#include "City.hpp"
	#include "Color.hpp"
	#include "Player.hpp"
	#include "Researcher.hpp"
	#include "Scientist.hpp"
	#include "FieldDoctor.hpp"
	#include "GeneSplicer.hpp"
	#include "OperationsExpert.hpp"
	#include "Dispatcher.hpp"
	#include "Medic.hpp"
	#include "Virologist.hpp"
	

	using namespace pandemic;
	using namespace std;
	

	Board board; // Initialize an empty board (with 0 disease cubes in any city).
	

	TEST_CASE("operator []")
	{
		CHECK(board.is_clean() == true);
	  
		board[London] = 1;
		board[Paris] = 2;
	  board[Milan] = 3;
	  board[Madrid] = 4;
		board[Bangkok] = 5;
		board[Beijing] = 0;
		board[BuenosAires] = 1;
		board[Delhi] = 2;
		board[HongKong] = 3;
		board[Istanbul] = 4;
	  board[LosAngeles] = 5;
	  board[SanFrancisco] = 0;
	  board[Chicago] = 1;
	  board[Atlanta] = 2;
	  board[Miami] = 3;
	

		// check the diseases level
	  
		CHECK(board[City::London] == 1);
		CHECK(board[City::Paris] == 2);
		CHECK(board[City::Milan] == 3);
		CHECK(board[City::Madrid] == 4);
		CHECK(board[City::Bangkok] == 5);
		CHECK(board[City::Beijing] == 0);
		CHECK(board[City::BuenosAires] == 1);
		CHECK(board[City::Delhi] == 2);
		CHECK(board[City::HongKong] == 3);
		CHECK(board[City::Istanbul] == 4);
		CHECK(board[City::LosAngeles] == 5);
		CHECK(board[City::SanFrancisco] == 0);
		CHECK(board[City::Chicago] == 1);
		CHECK(board[City::Atlanta] == 2);
		CHECK(board[City::Miami] == 3);
	  
	  
	//   CHECK_THROWS(board[City::London] != 1);
	// 	CHECK_THROWS(board[City::Paris] != 2);
	// 	CHECK_THROWS(board[City::Milan] != 3);
	// 	CHECK_THROWS(board[City::Madrid] != 4);
	// 	CHECK_THROWS(board[City::Bangkok] != 5);
	// 	CHECK_THROWS(board[City::Beijing] != 0);
	// 	CHECK_THROWS(board[City::BuenosAires] != 1);
	// 	CHECK_THROWS(board[City::Delhi] != 2);
	// 	CHECK_THROWS(board[City::HongKong] != 3);
	// 	CHECK_THROWS(board[City::Istanbul] != 4);
	// 	CHECK_THROWS(board[City::LosAngeles] != 5);
	// 	CHECK_THROWS(board[City::SanFrancisco] != 0);
	// 	CHECK_THROWS(board[City::Chicago] != 1);
	// 	CHECK_THROWS(board[City::Atlanta] != 2);
	// 	CHECK_THROWS(board[City::Miami] != 3);
	

		//Changes the diseases level
	  
		board[London] = 5;
		board[Paris] = 4;
	  board[Milan] = 0;
	  board[Madrid] = 2;
		board[Bangkok] = 1;
		board[Beijing] = 5;
		board[BuenosAires] = 4;
		board[Delhi] = 3;
		board[HongKong] = 2;
		board[Istanbul] = 1;
	  board[LosAngeles] = 0;
	  board[SanFrancisco] = 5;
	  board[Chicago] = 4;
	  board[Atlanta] = 3;
	  board[Miami] = 2;
	

	  
		// check the diseases level after the change
	  
		CHECK(board[City::London] == 5);
		CHECK(board[City::Paris] == 4);
		CHECK(board[City::Milan] == 0);
		CHECK(board[City::Madrid] == 2);
		CHECK(board[City::Bangkok] == 1);
		CHECK(board[City::Beijing] == 5);
		CHECK(board[City::BuenosAires] == 4);
		CHECK(board[City::Delhi] == 3);
		CHECK(board[City::HongKong] == 2);
		CHECK(board[City::Istanbul] == 1);
		CHECK(board[City::LosAngeles] == 0);
		CHECK(board[City::SanFrancisco] == 5);
		CHECK(board[City::Chicago] == 4);
		CHECK(board[City::Atlanta] == 3);
		CHECK(board[City::Miami] == 2);
	  
	  
	//   CHECK_THROWS(board[City::London] != 5);
	// 	CHECK_THROWS(board[City::Paris] != 4);
	// 	CHECK_THROWS(board[City::Milan] != 0);
	// 	CHECK_THROWS(board[City::Madrid] != 2);
	// 	CHECK_THROWS(board[City::Bangkok] != 1);
	// 	CHECK_THROWS(board[City::Beijing] != 5);
	// 	CHECK_THROWS(board[City::BuenosAires] != 4);
	// 	CHECK_THROWS(board[City::Delhi] != 3);
	// 	CHECK_THROWS(board[City::HongKong] != 2);
	// 	CHECK_THROWS(board[City::Istanbul] != 1);
	// 	CHECK_THROWS(board[City::LosAngeles] != 0);
	// 	CHECK_THROWS(board[City::SanFrancisco] != 5);
	// 	CHECK_THROWS(board[City::Chicago] != 4);
	// 	CHECK_THROWS(board[City::Atlanta] != 3);
	// 	CHECK_THROWS(board[City::Miami] != 2);
	

		CHECK(board.is_clean() == false);
	}
	

	TEST_CASE("Test all game functions")
	{
	  
	//drive and build functions
	  OperationsExpert player{board,  City::London};
	  CHECK_NOTHROW(player.drive(Paris));
		CHECK_NOTHROW(player.drive(Madrid));
		CHECK_NOTHROW(player.drive(NewYork));
		CHECK_NOTHROW(player.drive(Montreal));
		CHECK_NOTHROW(player.drive(Chicago));
		CHECK_NOTHROW(player.build());
	  
	//take card and fly direct functions
		player.take_card(City::Moscow);
		CHECK_NOTHROW(player.fly_direct(City::Moscow));
		CHECK_NOTHROW(player.drive(Tehran));
		CHECK_NOTHROW(player.build());
	 
	  //fly shuttle function
		CHECK_NOTHROW(player.fly_shuttle(City::Chicago));
		CHECK_NOTHROW(player.fly_shuttle(City::Tehran));
	

	  //discover cure function
		CHECK_NOTHROW(player.drive(Delhi));
		CHECK_THROWS(player.discover_cure(Color::Black));
	

	  //treat cure function
		player.take_card(City::Delhi);
		CHECK_NOTHROW(player.fly_charter(London));
		CHECK_NOTHROW(player.treat(London));
		CHECK(board[City::London] == 4);
	  //CHECK_THROWS(board[City::London] != 5);
	

	  //check role
	  CHECK_EQ(player.role(),"OperationsExpert");
	  
	

	}
