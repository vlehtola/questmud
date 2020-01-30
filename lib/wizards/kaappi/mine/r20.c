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

   add_exit("east", "r19.c");
   add_exit("southwest", "r21.c");
short_desc = "A tunnel";
   long_desc = "This part of the tunnel looks quite new. Marks of\n"+
               "mining can clearly see. Walls are full of cracks and \n"+
               "holes. Some small pieces of mithril can be seen on \n"+
               "the walls. There are many dwarven miners working and \n"+
               "running everywhere.\n";
set_light(1);
}
