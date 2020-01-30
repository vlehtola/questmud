inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "park7.c");
  add_exit("north", "park9.c");
short_desc = "A park";
long_desc = "The trees and bushes are growing straight from the rock.\n"+
            "A beautiful green grass covers the ground. Some most commonly\n"+
            "used paths can clearly be seen on the ground.\n";
  set_light(3);

items = allocate(2);
  items[0] = "bushes";
  items[1] = "There is a very small area behind of these bushes.\n";
}
init() {
  ::init();
  add_action("enter", "enter"); }

enter(str) {
  if(str != "bushes") return;
  move_object(this_player(), "/wizards/kaappi/dcity/rooms/puska.c");
  tell_object(this_player(), "You manage to flounder through the bushes.\n");
return 1;
}
