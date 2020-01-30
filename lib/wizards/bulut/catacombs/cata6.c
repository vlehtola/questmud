inherit "room/room";

int i;

init() {
::init();
add_action("push","push");
}

reset(arg) {

  add_exit("east","/wizards/bulut/catacombs/cata4");
  short_desc = "Catacombs";
  long_desc = "You are wandering somewhere under the graveyard.\n" +
	      "The smell of rotten flesh is coming from the graves near by.\n" +	
	      "The ground is hard, but moisty. You wonder why do these catacombs exist.\n" +     
              "This place makes you feel distressed.\n" +
	      "Some light blinks from the cave's ceiling.\n";
  set_light(2);                 
  set_not_out(1);
items = allocate(4);
  items[0] = "ceiling";
  items[1] = "Some light blinks between two large rocks on the ceiling";
  items[2] = "rocks";
  items[3] = "Perhaps you could push them aside";

}

push(str) {
if (!i) {
if(str=="rocks") {
write("You push the rocks aside.\n");
add_exit("climb","wizards/bulut/catacombs/room8");
return 1;}
write("You cant push the rocks any further.\n");
return 1;}
}           
