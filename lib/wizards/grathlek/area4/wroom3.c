inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/ewimp.c");
    move_object(monster, this_object());
   }
  add_exit("northwest","/wizards/grathlek/area4/froom6.c");
  add_exit("east","/wizards/grathlek/area4/wroom2.c");
  set_light(1);
 
  short_desc = "A dark passage.";
  long_desc = "This is a stinky and dusky passage.\n"+
              "Rats and carrion animals swarm all over\n"+ 
              "this place and everything here makes you\n"+
              "wanna throw up.\n";
}
