inherit "room/room";
object monster, monster2, monster3;
int lifted;
reset(arg) {

if(!monster) {
  monster = clone_object("/wizards/kaappi/mine/mosat/kaivurit.c");
  move_object(monster, this_object()); }

if(!monster2) {
  monster2 = clone_object("/wizards/kaappi/mine/mosat/kaivurit.c");
  move_object(monster2, this_object()); }

if(!monster3) {
  monster3 = clone_object("/wizards/kaappi/mine/mosat/kaivurit.c");
  move_object(monster3, this_object()); }

  if(arg) return;

   add_exit("northwest", "r23.c");
  short_desc = "Tunnel";
   long_desc = ("The end of this tunnel. There are much little pieces of rocks around\n"+
               "the floor. Couple of bigger rocks are placed in the corner.\n");
set_light(1);

items = allocate(2);
        items[0] = "rocks";
         items[1] = "As you take a closer look at the rocks, you notice\n"+
                   "some rays of light coming from somewhere under of the\n"+
                  "bigger one.\n";
}
init () {
  ::init();
  add_action("lift", "lift"); }

lift(str) {
  if(str != "rock") return;
  if(!lifted) {
  write("You manage to move the rock and find a hole under it.\n");
   add_exit("down", "ala.c");
 lifted = 1;
return 1;
}
else {
    write("You hide the hole with a rock\n");
    remove_exit("down");
 lifted = 0;
return 1;
}
}
