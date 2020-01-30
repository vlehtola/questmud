inherit "room/room";

string arg1;
string arg2;
int i;

init() {
::init();
add_action("look","look");
}

reset(arg) {

  add_exit("west","/wizards/bulut/catacombs/room9");
  add_exit("east","/wizards/bulut/catacombs/room11");
  add_exit("north","/wizards/bulut/catacombs/room12");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
              "Huge monument stands here. This part of graveyard is in better\n" + 
              "condition. Grass has been cut here awhile ago. Maybe the Caretaker\n" +
	      "is a bit selective on his duties. The gloomy atmosphere is still here though.\n";
  set_light(2);                 

  items = allocate(4);

  items[0] = "monument";
  items[1] = "A HUGE monument standing for the King Aldebar\n" +
	     "the old ruler of Deleria. A crown is attached on the\n" +
	     "head of the statue";       

  items[2] = "crown";
  items[3] = "Something glitters in the crown, You can't make out\n" +
	     "what it is from down here, and the statue looks\n" +
	     "impossible to climb";

}

look(str) {
if(present("crow",environment(this_player()))) {
	if (!str) { return 0; }

	if(sscanf(str,"%s %s", arg1,arg2)) {
		if(arg1=="at") {
			if(arg2=="crown") {
			if(!i) {
			i = 1;
			write("The crow takes on its wings!\n");
			write("The crown lands, and drops something to your hand.\n");
			move_object(clone_object("/wizards/bulut/catacombs/diamond"), this_player());
			return 1; }
				}
			}
		}
	}
    }                                                    