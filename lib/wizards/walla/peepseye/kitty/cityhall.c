inherit "room/room"; 
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/peepseye/monsters/judge");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("out","wizards/walla/peepseye/kitty/m5");
  short_desc = "In the yet to be finished courthouse";
  long_desc =
"The courthouse is the most important place of the city. It contains the\n" +
"cityhall and the courthouse and all the vital and important places, where\n" +
"the good people of OilOhnRock do business.\n";
}  

