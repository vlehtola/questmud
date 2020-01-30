inherit "room/room";

object monk;

reset(arg) {
 if(!monk) {
 monk = clone_object("/wizards/rimber/temple/monk.c");
 move_object(monk, this_object());
 }
 set_light(3);
 short_desc = "Inside the temple";
  long_desc = "The basement of the temple is full of different kind of statues and potraits\n"+
                       "of the ancients who once built the city. Strange music is filling the corridor\n"+
                       "and the torches are illuminating the whole room. The priests of ancients are\n"+
                       "here to pray. This place is the largest sanctuary in the city of Asgroth.\n";
 add_exit("east", "/wizards/rimber/temple/room14.c");
 add_exit("south", "/wizards/rimber/temple/room4.c");
}
