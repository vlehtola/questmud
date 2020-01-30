inherit "room/room";
object monster,monster2;

reset(arg) {

if(!monster) {
  monster = clone_object("/wizards/kaappi/mine/mosat/kaivurit.c");
  move_object(monster, this_object()); }

if(!monster2) {
  monster2 = clone_object("/wizards/kaappi/mine/mosat/kaivurit.c");
  move_object(monster2, this_object()); }

  if(arg) return;

add_exit("leave", "entrance.c");
add_exit("northeast", "r2.c");
add_exit("northwest", "r14.c");
  short_desc = "A tunnel";
  long_desc = "A quite dark tunnel. Only one torch, burning with\n"+
               "an eternal flame is hanging on the wall, giving light.\n"+
              "The walls are smooth, no cracks or sharp edges have been left\n"+
              "when the tunnel has been dug.\n";
  set_light(1);
}
