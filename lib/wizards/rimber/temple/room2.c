inherit "room/room";
object monk;

reset(arg) {
 if(!monk) {
 monk = clone_object("/wizards/rimber/temple/monk.c");
 move_object(monk, this_object());
 }
 if(arg) return;
 set_light(3);
 short_desc = "Inside the temple";
  long_desc = "The basement of the temple is full of different kind of statues and potraits\n"+
                       "of the ancients who once built the city. Strange music is filling the corridor\n"+
                       "and the torches are illuminating the whole room. The priests of ancients are\n"+
                       "here to pray. This place is the largest sanctuary in the city of Asgroth.\n";
 add_exit("north", "/wizards/rimber/temple/room12.c");
 add_exit("west", "/wizards/rimber/temple/room1.c");
 add_exit("east", "/wizards/rimber/temple/room3.c");
 add_exit("south", "/wizards/rimber/temple/room6.c");
}