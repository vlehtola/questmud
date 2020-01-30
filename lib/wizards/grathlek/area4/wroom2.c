inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/simp.c");
    move_object(monster, this_object());
   }
  add_exit("west","/wizards/grathlek/area4/wroom3.c");
  add_exit("east","/wizards/grathlek/area4/wroom1.c");
  set_light(1);
 
  short_desc = "A shaman's cave.";
  long_desc = "This is a stinky and dusky place.\n"+
              "Rats swarm everywhere and there are bones\n"+ 
              "and some fetishes all over this place.\n"+
              "The smell of shit floats in the air.\n";
}
