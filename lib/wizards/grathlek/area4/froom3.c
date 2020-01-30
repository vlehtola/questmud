inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/froom2.c");
  add_exit("west","/wizards/grathlek/area4/froom4.c");
  set_light(2);
 
  short_desc = "A smelly red passage.";
  long_desc = "The smell of undead is horrible here.\n"+
              "Rats and carrion animals swarm all over\n"+ 
              "this place and everything here makes you\n"+
              "wanna throw up. Even shit smells better than\n"+
              "this place.\n";
}
