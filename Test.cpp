 
 
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
		for(int i=0;i<20;i++)
		{
	          CHECK(board.is_clean() == true);
		}
 		CHECK(board.is_clean() == true);
	  
		board[City::London] = 1;
	        board[City::Paris] = 2;
	        board[City::Milan] = 3;
	        board[City::Madrid] = 4;
		board[City::Bangkok] = 5;
		board[City::Beijing] = 0;
		board[City::BuenosAires] = 1;
		board[City::Delhi] = 2;
		board[City::HongKong] = 3;
		board[City::Istanbul] = 4;
	        board[City::LosAngeles] = 5;
	        board[City::SanFrancisco] = 0;
	        board[City::Chicago] = 1;
	        board[City::Atlanta] = 2;
         	board[City::Miami] = 3;
	

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
	  
	  
	        CHECK_THROWS_AS((board[City::London] == 5),std::exception);
		CHECK_THROWS_AS((board[City::Paris] == 5),std::exception);
		CHECK_THROWS_AS((board[City::Milan] == 5),std::exception);
		CHECK_THROWS_AS((board[City::Madrid] == 5),std::exception);
		CHECK_THROWS_AS((board[City::Bangkok] == 3),std::exception);
		CHECK_THROWS_AS((board[City::Beijing] == 3),std::exception);
		CHECK_THROWS_AS((board[City::BuenosAires] == 3),std::exception);
		CHECK_THROWS_AS((board[City::Delhi] == 3),std::exception);
		CHECK_THROWS_AS((board[City::HongKong] == 2),std::exception);
		CHECK_THROWS_AS((board[City::Istanbul] == 2),std::exception);
		CHECK_THROWS_AS((board[City::LosAngeles] == 2),std::exception);
		CHECK_THROWS_AS((board[City::SanFrancisco] == 2),std::exception);
		CHECK_THROWS_AS((board[City::Chicago] == 2),std::exception);
		CHECK_THROWS_AS((board[City::Atlanta] == 4),std::exception);
		CHECK_THROWS_AS((board[City::Miami] == 4),std::exception);
		
	

		//Changes the diseases level
	  
		board[City::London] = 5;
		board[City::Paris] = 4;
	        board[City::Milan] = 0;
	        board[City::Madrid] = 2;
		board[City::Bangkok] = 1;
		board[City::Beijing] = 5;
		board[City::BuenosAires] = 4;
		board[City::Delhi] = 3;
		board[City::HongKong] = 2;
		board[City::Istanbul] = 1;
	        board[City::LosAngeles] = 0;
	        board[City::SanFrancisco] = 5;
	        board[City::Chicago] = 4;
	        board[City::Atlanta] = 3;
	        board[City::Miami] = 2;
	

	  
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
	  
	  
	  CHECK_THROWS_AS((board[City::London] == 3),std::exception);
		CHECK_THROWS_AS((board[City::Paris] == 3),std::exception);
		CHECK_THROWS_AS((board[City::Milan] == 3),std::exception);
		CHECK_THROWS_AS((board[City::Madrid] == 3),std::exception);
		CHECK_THROWS_AS((board[City::Bangkok] == 3),std::exception);
		CHECK_THROWS_AS((board[City::Beijing] == 3),std::exception);
		CHECK_THROWS_AS((board[City::BuenosAires] == 5),std::exception);
		CHECK_THROWS_AS((board[City::Delhi] == 5),std::exception);
		CHECK_THROWS_AS((board[City::HongKong] == 5),std::exception);
		CHECK_THROWS_AS((board[City::Istanbul] == 5),std::exception);
		CHECK_THROWS_AS((board[City::LosAngeles] == 1),std::exception);
		CHECK_THROWS_AS((board[City::SanFrancisco] == 1),std::exception);
		CHECK_THROWS_AS((board[City::Chicago] == 1),std::exception);
		CHECK_THROWS_AS((board[City::Atlanta] == 1),std::exception);
		CHECK_THROWS_AS((board[City::Miami] == 1),std::exception);
		
		CHECK_THROWS_AS((board[City::Miami] == 4),std::exception);
	

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
	        CHECK_THROWS_AS((board[City::London] == 0),std::exception);
	

	  //check role
	       CHECK_EQ(player.role(),"OperationsExpert");
	  
	
	}
