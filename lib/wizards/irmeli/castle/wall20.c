inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/watchman2.c");
move_object(monster, this_object());

}

if(arg) return;

add_exit("stairs","/wizards/irmeli/castle/wall19.c");
add_exit("east","/wizards/irmeli/castle/wall21.c");

short_desc = "Crossing of south and west wall of the castle of Asgroth";
long_desc = "A small guardhouse made of bricks and boards has been built in here, in the\n"+
            "crossing of the east and the south wall. The small guardhouse was built as a\n"+
            "shelter, shelter from the wind, attackers and cold for the watchmen. It even\n"+
            "has a roof which gives shelter for the rainy days. The guardhouse consist of\n"+
            "two exits to the south wall and to the west wall, four walls, roof and one\n"+
            "window which gives a view to the outworld. A telescope is pointing through the\n"+
            "window to the outworld. You can hear the wind raping the walls and the roof\n"+ 
            "of the guardhouse. If the wind was a little bit stronger, it could take the\n"+
            "guardhouse along and shatter it down to the ground. There are stairs leading\n"+
            "down to the west wall. There are two big towers rising up to the sky from the\n"+
            "north wall.\n";

  

  items = allocate(2);
  items[0] = "telescope";
  items[1] = "A rusty telescope is pointing through the window to the ourworld. It might be possible look through it, if the class inside the telescope is not broken.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
init() {
  ::init();
  add_action("look", "look");
}

look(str) {
  if(str != "through telescope") return;
  write("You step closer to the telescope and take a look through it.\n");
  write("You can see some animals eating, running, playing and sleeping in the valley.\n");
  write("Everything looks normal in there and you start to feel a bit bored. You decide\n");
  write("to stop looking through telescope and you step away from it.\n");
  return 1;
}

