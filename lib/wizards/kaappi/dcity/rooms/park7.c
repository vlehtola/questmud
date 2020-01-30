inherit "room/room";
object mob;

reset(arg) {

if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/kids.c");
  move_object(mob, this_object()); }
  if(arg) return;

  add_exit("south", "park5.c");
  add_exit("north", "park8.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. There is an old\n"+
            "looking oak on the left side of you. Some most commonly\n"+
            "used paths can clearly be seen on the ground.\n";
  set_light(3);

items = allocate(2);
  items[0] = "oak";
  items[1] = "An old looking oak. There are many big branches on it and seems like\n"+ 
             "it could be easy to climb up.\n";
}
init() {
  ::init();
  add_action("climb", "climb"); }

climb(str) {
  if(str != "oak") return;
  move_object(this_player(), "/wizards/kaappi/dcity/rooms/puu.c");
  tell_object(this_player(), "You manage to climb up.\n");
return 1;
}
