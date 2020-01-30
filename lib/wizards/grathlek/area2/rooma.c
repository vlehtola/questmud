inherit "room/room";
object monster; 
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/grathlek/area2/monsies/graul.c");
    move_object(monster, this_object());
  }
  add_exit("west","/wizards/grathlek/area2/room8.c");
  set_light(2); 
  short_desc = "Weapon shop.";
  long_desc = "You are in the weapon shop.\n"+
              "Commands : list\n"+
              "           buy <ITEM>\n"+
              ".\n"; 
}
