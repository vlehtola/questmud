inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/wwimp.c");
    move_object(monster, this_object());
   }
  add_exit("northeast","/wizards/grathlek/area4/froom2.c");
  add_exit("west","/wizards/grathlek/area4/wroom2.c");
  set_light(1);
 
  short_desc = "A dark passage.";
  long_desc = "This is a stinky and dusky passage.\n"+
              "Rats and carrion animals swarm all over\n"+ 
              "this place and everything here makes you\n"+
              "wanna throw up.\n";
}
