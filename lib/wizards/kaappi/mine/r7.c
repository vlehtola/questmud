inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
  monster = clone_object("/wizards/kaappi/mine/mosat/kaivurit.c");
  move_object(monster, this_object()); }

  if(arg) return;

   add_exit("south", "r6.c");
   add_exit("north", "r12.c");
short_desc = "A tunnel";
long_desc = "Older parts of these tunnels. A thin layer\n"+ 
              "of dust covers the floor and a lot of footprints can be\n"+
              "seen. There are many dwarven miners running everywhere.\n";
  set_light(1);
}
