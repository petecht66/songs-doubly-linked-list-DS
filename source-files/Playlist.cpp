#include "DLL.hpp"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Playlist.hpp"
using namespace std;

Playlist::Playlist() {
	list = new DLL();
	readList("MyListOfSongs.txt");
	list->printList();
	cout << endl;
	interface();
}

Playlist::Playlist(string s) {
	list = new DLL();

//	//To test, save and run your code.  If you get a message saying, Done Reading File,  it's
//	//possible your push method works, but you won't know for sure until you complete Step 2
//	//(Below)
//
	readList(s);  // uncomment this line to test the push method you wrote in the DLL.cpp file.
//
//
//
///*****************************************************************************************/
	list->printList();

	list->printList();  // uncomment out this line to test your printlist method.
	cout << endl;

	list->pop();
	list->printList();
	list->pop();
	list->printList();



	cout << endl;

	list->remove("Don't Be Cruel");  // removes from middle of list
	cout << endl;
	list->printList();
	list->remove("Black Magic Woman");  // removes last
	cout << endl;
	list->printList();
	list->remove("Let it Be");  // removes first.
	cout << endl;
	list->printList();

	list->push("Don't Be Cruel", "Elvis Presley", 4,43);
	list->push("Black Magic Woman", "Santana", 3,16);
	list->push("Let it Be", "Beatles", 3, 11);
	list->printList();

	cout << "Moving Great Balls of Fire  up one" << endl << endl;
	list->moveUp("Great Balls of Fire");
	list->printList();
	cout << "Moving Great Balls of Fire  up one" << endl << endl;
	list->moveUp("Great Balls of Fire");
	list->printList();
	cout << "Moving Great Balls of Fire up one" << endl<< endl;
	list->moveUp("Great Balls of Fire");
	list->printList();


	cout << "Moving Black Magic Woman down one" << endl << endl;
	list->moveDown("Black Magic Woman");
	list->printList();
	cout << "Moving Black Magic Woman  down one" << endl << endl;
	list->moveDown("Black Magic Woman");
	list->printList();
	cout << "Moving Black Magic Woman  down one" << endl<< endl;
	list->moveDown("Black Magic Woman");
	list->printList();

	list->printList();
	int mintot = 0;
	int sectot = 0;
	list->listDuration(&mintot, &sectot);
	mintot += sectot/60;
	sectot = sectot%60;
	int hr = 0;
	if (mintot>=60) {
		hr = mintot/60;
		mintot %= 60;
	}
	cout << "The total playlist time is ";
	hr>0?cout<<hr<<":":cout<<" ";
	cout<< mintot<<":";
	sectot<10?cout<<"0"<<sectot:cout<<sectot;
	cout << endl<<flush;

	list->makeRandom();
	list->printList();
	cout << "***************" << endl;
	list->makeRandom();
	list->printList();

	delete(list);
	cout << "Yep, deleted" << endl;

	list = new DLL();
	readList("MyListOfSongs.txt");
	list->printList();
	cout << endl;

//	/* (15 pts) Step 10:  Uncomment out the code below to play with the interface.
//	 * Make sure you:
	// NOTE: My outputs did not print out for some reason, but I put what the outputs should be below
//	 * 1) add at least 2 songs (and print the list after each add)
	list->push("1979", "The Smashing Pumpkins", 4,26);
	list->printList();
	cout << endl;
	list->push("Black Hole Sun", "Soundgarden", 5,18);
	list->printList();
	cout << endl;
//	 * 2) remove at least 2 songs (and print the list after each remove)
	list->remove("Blueberry Hill");
	list->printList();
	cout << endl;
	list->remove("99");
	list->printList();
	cout << endl;
//	 * 3) Move up at least twice (and print)
	list->moveUp("1979");
	list->printList();
	cout << endl;
	list->moveUp("Send Me on My Way");
	list->printList();
	cout << endl;
//	 * 4) Move down at least twice (and print)
	list->moveDown("Let It Be");
	list->printList();
	cout << endl;
	list->moveDown("Be Fine");
	list->printList();
	cout << endl;
//	 * 5) Randomize twice (and print)
	list->makeRandom();
	list->printList();
	cout << endl;
	list->makeRandom();
	list->printList();
	cout << endl;
//	 * 6) find the lists duration
	list->listDuration(&mintot, &sectot);
	mintot += sectot/60;
	sectot = sectot%60;
	int secondHr = 0;
	if (mintot>=60) {
		secondHr = mintot/60;
		mintot %= 60;
	}
	cout << "The total playlist time is ";
	secondHr>0?cout<<secondHr<<":":cout<<" ";
	cout<< mintot<<":";
	sectot<10?cout<<"0"<<sectot:cout<<sectot;
	cout << endl<<flush;
//	 * 7) play around, if you want :-)
//	 *
//	 *
//	*/
//
//
	interface();
//
//
//	/* Your output should go here */
	// Output 1, first print
//	   Let it Be, Beatles................3:11
//     Rock Around The Clock, Bill Haley................3:59
//     Don't Be Cruel, Elvis Presley................4:43
//     Blueberry Hill, Fats Domino................4:58
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Be Fine, Madeon................3:28
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     99, Barns Courtney................3:19
//     Born To Be Yours, Vibe2Vibe................3:14
//     Send Me on My Way, Rusted Root................4:23
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     Love is Alive, Louis The Child and Elohim................2:50
//	   1979, The Smashing Pumpkins................4:26
	// Output 1, second print
	// Let it Be, Beatles................3:11
//     Rock Around The Clock, Bill Haley................3:59
//     Don't Be Cruel, Elvis Presley................4:43
//     Blueberry Hill, Fats Domino................4:58
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Be Fine, Madeon................3:28
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     99, Barns Courtney................3:19
//     Born To Be Yours, Vibe2Vibe................3:14
//     Send Me on My Way, Rusted Root................4:23
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     Love is Alive, Louis The Child and Elohim................2:50
//	   1979, The Smashing Pumpkins................4:26
//	   Black Hole Sun, Soundgarden................5:18
	// Output 2, first print
//     Let it Be, Beatles................3:11
//     Rock Around The Clock, Bill Haley................3:59
//     Don't Be Cruel, Elvis Presley................4:43
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Be Fine, Madeon................3:28
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     99, Barns Courtney................3:19
//     Born To Be Yours, Vibe2Vibe................3:14
//     Send Me on My Way, Rusted Root................4:23
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     Love is Alive, Louis The Child and Elohim................2:50
//	   1979, The Smashing Pumpkins................4:26
//	   Black Hole Sun, Soundgarden................5:18
	// Output 2, second print
//	   Let it Be, Beatles................3:11
//     Rock Around The Clock, Bill Haley................3:59
//     Don't Be Cruel, Elvis Presley................4:43
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Be Fine, Madeon................3:28
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     Born To Be Yours, Vibe2Vibe................3:14
//     Send Me on My Way, Rusted Root................4:23
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     Love is Alive, Louis The Child and Elohim................2:50
//	   1979, The Smashing Pumpkins................4:26
//	   Black Hole Sun, Soundgarden................5:18
	// Output 3, first print
//     Let it Be, Beatles................3:11
//     Rock Around The Clock, Bill Haley................3:59
//     Don't Be Cruel, Elvis Presley................4:43
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Be Fine, Madeon................3:28
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     Born To Be Yours, Vibe2Vibe................3:14
//     Send Me on My Way, Rusted Root................4:23
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     1979, The Smashing Pumpkins................4:26
//     Love is Alive, Louis The Child and Elohim................2:50
//	   Black Hole Sun, Soundgarden................5:18
	// Output 3, second print
//     Let it Be, Beatles................3:11
//     Rock Around The Clock, Bill Haley................3:59
//     Don't Be Cruel, Elvis Presley................4:43
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Be Fine, Madeon................3:28
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     Send Me on My Way, Rusted Root................4:23
//     Born To Be Yours, Vibe2Vibe................3:14
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     1979, The Smashing Pumpkins................4:26
//     Love is Alive, Louis The Child and Elohim................2:50
//	   Black Hole Sun, Soundgarden................5:18
	// Output 4, first print
//     Rock Around The Clock, Bill Haley................3:59
//     Let it Be, Beatles................3:11
//     Don't Be Cruel, Elvis Presley................4:43
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Be Fine, Madeon................3:28
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     Send Me on My Way, Rusted Root................4:23
//     Born To Be Yours, Vibe2Vibe................3:14
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     1979, The Smashing Pumpkins................4:26
//     Love is Alive, Louis The Child and Elohim................2:50
//	   Black Hole Sun, Soundgarden................5:18
	// Output 4, second print
//     Rock Around The Clock, Bill Haley................3:59
//     Let it Be, Beatles................3:11
//     Don't Be Cruel, Elvis Presley................4:43
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Jonny B Good, Chuck Berry................3:14
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     Black Magic Woman, Santana................3:16
//     La Bamba, Richie Valens................3:29
//     Margaritaville, Jimmy Buffett................2:55
//     Reaper, Sia................3:39
//     Good Life, OneRepublic................4:13
//     I Can't Wait, Nu Shooz................5:26
//     The King of Wishful Thinking, Go West................4:O1
//     i, Kendrick Lamar................3:52
//     I Wanna Get Better, Bleachers................3:24
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     Be Fine, Madeon................3:28
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Purple Hat, Sofi Tukker................2:58
//     Send Me on My Way, Rusted Root................4:23
//     Born To Be Yours, Vibe2Vibe................3:14
//     Dreams, The Cranberries................4:31
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Sing It Out Loud, OMI................3:41
//     Punching in a Dream, The Naked And Famous................3:58
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Still Not a Player, Big Pun Joe................3:56
//     Train, Brick+Mortar................3:O5
//     17, Zhavia Ward................2:46
//     Critical Mistakes, 888................3:20
//     Good News, K.Flay................3:31
//     1979, The Smashing Pumpkins................4:26
//     Love is Alive, Louis The Child and Elohim................2:50
//	   Black Hole Sun, Soundgarden................5:18
	// Output 5, first print
//	   Rock Around The Clock, Bill Haley................3:59
//	   Reaper, Sia................3:39
//	   Punching in a Dream, The Naked And Famous................3:58
//	   I Wanna Get Better, Bleachers................3:24
//	   Dreams, The Cranberries................4:31
//	   Good News, K.Flay................3:31
//	   Born To Be Yours, Vibe2Vibe................3:14
//	   I Can't Wait, Nu Shooz................5:26
//	   Purple Hat, Sofi Tukker................2:58
//	   Black Hole Sun, Soundgarden................5:18
//	   Where the Rivers Flow, Sons of Maria................3:O3
//	   i, Kendrick Lamar................3:52
//	   Let it Be, Beatles................3:11
//	   Great Balls of Fire, Jerry Lee Lewis................1:O7
//	   Love is Alive, Louis The Child and Elohim................2:50
//	   Sing It Out Loud, OMI................3:41
//	   Bad Moon Rising, Credence Clearwater Revival................6:O9
//	   Still Not a Player, Big Pun Joe................3:56
//	   Margaritaville, Jimmy Buffett................2:55
//	   Gossip Folks, Missy Elliot and Ludacris................3:54
//	   Jonny B Good, Chuck Berry................3:14
//	   Harder To Breather, Maroon 5................2:52
//	   17, Zhavia Ward................2:46\
//	   Train, Brick+Mortar................3:O5
//	   Antisocial, Ed Sheeran and Travis Scott................2:41
//	   Don't Be Cruel, Elvis Presley................4:43
//	   Black Magic Woman, Santana................3:16
//	   Good Life, OneRepublic................4:13
//	   Critical Mistakes, 888................3:20
//	   Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//	   The King of Wishful Thinking, Go West................4:O1
//	   Be Fine, Madeon................3:28
//	   Send Me on My Way, Rusted Root................4:23
//	   This Old Heart of Mine, The Isley Brothers................2:55
//	   La Bamba, Richie Valens................3:29
//	   1979, The Smashing Pumpkins................4:26
	// Output 5, second print
//     Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//     I Can't Wait, Nu Shooz................5:26
//     17, Zhavia Ward................2:46
//     Purple Hat, Sofi Tukker................2:58
//     Good Life, OneRepublic................4:13
//     Reaper, Sia................3:39
//     Margaritaville, Jimmy Buffett................2:55
//     Train, Brick+Mortar................3:O5
//     This Old Heart of Mine, The Isley Brothers................2:55
//     Love is Alive, Louis The Child and Elohim................2:50
//     Gossip Folks, Missy Elliot and Ludacris................3:54
//     Don't Be Cruel, Elvis Presley................4:43
//     Send Me on My Way, Rusted Root................4:23
//     I Wanna Get Better, Bleachers................3:24
//     Great Balls of Fire, Jerry Lee Lewis................1:O7
//     Still Not a Player, Big Pun Joe................3:56
//     Harder To Breather, Maroon 5................2:52
//     Where the Rivers Flow, Sons of Maria................3:O3
//     Punching in a Dream, The Naked And Famous................3:58
//     Rock Around The Clock, Bill Haley................3:59
//     Be Fine, Madeon................3:28
//     Good News, K.Flay................3:31
//     Dreams, The Cranberries................4:31
//     Black Magic Woman, Santana................3:16
//     The King of Wishful Thinking, Go West................4:O1
//     Sing It Out Loud, OMI................3:41
//     Bad Moon Rising, Credence Clearwater Revival................6:O9
//     1979, The Smashing Pumpkins................4:26
//     Black Hole Sun, Soundgarden................5:18
//     La Bamba, Richie Valens................3:29
//     Let it Be, Beatles................3:11
//     Born To Be Yours, Vibe2Vibe................3:14
//     Antisocial, Ed Sheeran and Travis Scott................2:41
//     i, Kendrick Lamar................3:52
//     Critical Mistakes, 888................3:20
//     Jonny B Good, Chuck Berry................3:14
	// Output 6
	// The total playlist time is 2:10:04
//
}

void Playlist::interface() {
	int choice=0;
	while (choice != 8) {
		cout << "What do you want to do?" <<endl<< flush;
		cout <<"Enter:" << endl<< flush;
		cout <<"\t1 for adding song"<<endl<< flush;
		cout <<"\t2 for removing a song" << endl<< flush;
		cout <<"\t3 for moving a song up in the list" << endl<< flush;
		cout <<"\t4 for moving a song down in the list" << endl<< flush;
		cout <<"\t5 for randomly shuffling the list" << endl<< flush;
		cout <<"\t6 for creating a brand new list" <<endl<< flush;
		cout <<"\t7 for getting the playlist's time duration"<< endl<<flush;
		cout <<"\t8 for exit" <<endl<< flush;

		cin >> choice;
		if (choice ==1) {
			addSong();
		}
		else if (choice == 2) {
			removeSong();
		}
		else if (choice == 3) {
			moveUp();
		}
		else if (choice == 4) {
			moveDown();
		}
		else if (choice ==5) {
			list->makeRandom();
			list->printList();
		}

		else if (choice ==6){
			makeNewList();
		}

		else if (choice ==7){
			getDuration();
		}
		else if (choice == 8) {
			ByeNow();
		}
	}
}

void Playlist::makeNewList() {
	cout << "Enter the name of the list you wish to enter:" <<endl << flush;
	string newlist = getTitle();
	delete list;
	list = new DLL();
	readList(newlist);
	list->printList();
}

void Playlist::getDuration() {
	int mintot = 0;
	int sectot = 0;
	list->listDuration(&mintot, &sectot);
	mintot += sectot/60;
	sectot = sectot%60;
	int hr = 0;
	if (mintot>=60) {
		hr = mintot/60;
		mintot %= 60;
	}
	cout << "The total playlist time is ";
	hr>0?cout<<hr<<":":cout<<" ";
	cout<< mintot<<":";
	sectot<10?cout<<"0"<<sectot:cout<<sectot;
	cout << endl<<flush;
	return;
}


void Playlist::moveUp() {
	cout<<"Moving a Song Up:" <<endl;
	cout << "Enter the title of the song you wish to move up in the list:" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->moveUp(title);
		list->printList();
	}
}
string Playlist::getTitle() {
	string song = "";
	while (song == "") {
	    getline(cin, song);
	}
	string title;
	title = strip(song);
	return title;

}
void Playlist::moveDown() {
	cout<<"Moving a Song Down:" <<endl;
	cout << "Enter the title of the song you wish to move down in the list:" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->moveDown(title);
		list->printList();
	}
}
void Playlist::removeSong() {
	cout<<"Removing a song:" <<endl;
	cout << "Enter the title of the song you wish to remove" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->remove(title);
		list->printList();
	}
}

void Playlist::addSong() {
	cout<<"Adding a song:" <<endl;
	cout << "Enter the song's info as follows: title, artist(s), min:sec" <<endl << flush;
	string song = "";
    while (song == "") {
    	getline(cin, song);
    }
	string artist;
	string title;
	string mins;
	string secs;
	title = strip(song);
	artist = strip(song);
	mins = strip(song);
	stringstream tmp(mins);
	int min = 0;
	tmp>>min;
	secs = song;
	stringstream tmp2(secs);
	int sec = 0;
	tmp2>>sec;
		//cout << title<<":::"<<artist<<":::"<<mins<<":::"<<secs<<":::"<<endl;
	if (title.length() >0) {
		list->push(title, artist, min, sec);
		list->printList();
	}

}
void Playlist::ByeNow() {
	cout << "Bye Now!" << endl;
	return;
}

string Playlist::strip(string &s) {
	const char* WhiteSpace = " \t\v\r\n";
	size_t start = s.find_first_not_of(WhiteSpace);
	const char* EndChar = ":,\n";
	size_t end = s.find_first_of(EndChar);
	string s2;
	int len = s.length();
	if (start<end){
		s2=s.substr(start,end-start);
		s = s.substr(end+1,len-end+1);
	}
	return s2;

}
void Playlist::readList(string f) {
	ifstream file(f.c_str());
	string songstr;
	string artist;
	string title;
	string mins;
	string secs;
	while (!file.eof()) {
		getline(file,songstr);
		//cout << songstr<<endl;
		title = strip(songstr);
		artist = strip(songstr);
		mins = strip(songstr);
		stringstream tmp(mins);
		int min = 0;
		tmp>>min;
		secs = songstr;
		stringstream tmp2(secs);
		int sec = 0;
		tmp2>>sec;
		//cout << title<<":::"<<artist<<":::"<<mins<<":::"<<secs<<":::"<<endl;
		if (title.length() >0) {
			list->push(title, artist, min, sec);
		}
	}
	cout <<"*********DONE READING**************************"<<endl<<endl;
	return;
}



