inherit "room/room";
object monster,monster2,monster3;
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

   add_exit("south", "r11.c");
short_desc = "A tunnel";
long_desc = "Older parts of these tunnels. A thin layer\n"+ 
              "of dust covers the floor and a lot of footprints can be\n"+
              "seen. There are many dwarven miners running everywhere.\n";
  set_light(1);
}
