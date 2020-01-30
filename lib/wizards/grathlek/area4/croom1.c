inherit "room/room";
object monster;
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/cimp.c");
    move_object(monster, this_object());
   }
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/cimp.c");
    move_object(monster, this_object());
   }
  add_exit("northwest","/wizards/grathlek/area4/croom2.c");
  add_exit("southwest","/wizards/grathlek/area4/mroom2.c");
  set_light(2);
 
  short_desc = "A dark corner.";
  long_desc = "This is the area where whores usually.\n"+
              "serve their clients. This area has a\n"+
              "very bad reputation among the noble imps.\n";
}
