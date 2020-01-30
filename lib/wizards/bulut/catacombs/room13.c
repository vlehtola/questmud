int open;

int i;
string who;
string arg1,arg2;

inherit "room/room";

init() {
::init();
add_action("spit","spit");
add_action("read","read");
add_action("look","look");
}

reset(arg) {
  add_exit("south","/wizards/bulut/catacombs/room12");
  short_desc = "Ancient graveyard";


  set_light(2);                 

  if (!present("crow")) {
     move_object(clone_object("/wizards/bulut/catacombs/crow"), this_object());
	  }

}

look(str) {
if(!str) { return 0; }
	if(!sscanf(str,"%s %s",arg1,arg2)) return 0;
		 if(arg1=="at") {
		if(arg2 == "statue" ) {
			if (!i) {
	write("A statue of some man who's name has been scraped off.\n" +
	     "You bet that this man was up to no good.\n" +
	     "Someone has spitted on the statue\n");
	 	return 1;
				}
			}
		if ( arg2 == "rock" ) {
			if (i) {
	write("Pieces of rock are all over the ground.\n");
	return 1;
	
		}
return 0;
		}
return 0;
		}
	
}
spit(str) {
if (i) { return 0;}
if ( str =="statue" ) {
 write("Some strange darc voice says : 'Thou shall not disgrace!'\n");
 write("The ground collapses beneath your feet!!\n");
this_player()->move_player("XX#/wizards/bulut/catacombs/cata1");
	return 1;
	}
return 0;
}    

read(str) {
if (str=="parchment") {
if (i) { write("Nothing happens.\n"); return 1;}
if(present("parchment",this_player())) { 
destruct(present("parchment",this_player()));
write("As you describe the parchment, it vanishes!\n");
	write("The statue explodes!\n"); i = 1;
	write("You feel like something evil just materialized.\n");	
     move_object(clone_object("/wizards/bulut/catacombs/gaul"), this_object());
	this_player()->set_quest("Release Gaul from his prison"); 
	return 1;
		}
	}
}


long() {
if (i) {
write("You are standing on a peaceful grass field.\n" +
	      "Looks like some battle has taken place here shortly.\n" +
	      "Pieces of rock are all over the ground.\n" +
              "The ground looks a bit soft here.\n" +
              "   There is one obvious exit: south\n");
}


	
if(!i) {
write("You are standing on a peaceful grass field.\n" +
	      "A statue stands here, it somehow looks evil.\n" +
              "The sight of the statue makes you feel threaten.\n" +
	      "The ground looks a bit soft here.\n" +
              "   There is one obvious exit: south\n");
}
}                      
