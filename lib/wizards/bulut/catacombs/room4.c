int open;

inherit "room/room";

init() {
::init();
add_action("open","open");
add_action("close","close");
}

reset(arg) {

  add_exit("west","/wizards/bulut/catacombs/room5");
  add_exit("east","/wizards/bulut/catacombs/room6");
  add_exit("south","/wizards/bulut/catacombs/room3");

	if(open) {
		add_exit("gates","/wizards/bulut/catacombs/building");
	}

  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
	      "Only the wind blowing in the trees brakes the silence.\n" +
	      "The gloomy atmosphere tightens as you get closer to the gates.\n" +
              "A building with iron gates is here.\n";
  set_light(2);                 
  items = allocate(4);


  if (!present("crow")) {
     move_object(clone_object("/wizards/bulut/catacombs/crow"), this_object());
  }
                      
  items[0] = "building";
  items[1] = "A building made of stone";
  items[2] = "gates";
  items[3] = "Iron gates with a broken lock";


}

open(str){
if (str =="gates") {
	if (!open) {
	write("You open the gates.\n");
	add_exit("gates","/wizards/bulut/catacombs/building");
	open = 1;
	return 1;}
write("The gates are already open!\n");
	return 1;
	}
}

close(str){
if(str =="gates") {
	if(open) {
	write("You close the gates.\n");
	remove_exit("gates");
	open = 0;
	return 1;}
write("The gates are allready close!\n");
	return 1;
	}
}                                                          