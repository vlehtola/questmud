inherit "room/room";

int jep;


init() {
::init();
add_action("get","get");
}

reset(arg) {
  add_exit("out","/wizards/bulut/catacombs/room4");
 
  short_desc = "A building";
  long_desc = "You are standing inside of a small building made of rocks.\n" +
	      "This place looks like a tomb, a bit ghastly one though.\n" +
	      "Looks like there is not much to do here.\n" +
              "There is a golden sign hanging on the wall.\n";
  set_light(1);                 
  items = allocate(2);                    
  items[0] = "sign";
  items[1] = "It states: Rudolf the Rich.\nIt's made of pure gold!";

  

}

get(str) {
if (str=="sign") {
	write("Your eyes gleem with greed as you try to pull the sign out from the wall.\n");
	if (!jep) {
	write("That really was a bad idea.\n");
       move_object(clone_object("/wizards/bulut/catacombs/rudolf"), this_object());
	jep=1;
	return 1;
	}
write("..  but it won't budge.\n");
return 0;
	}
}                  
