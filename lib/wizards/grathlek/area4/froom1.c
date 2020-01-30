inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/eroom5.c");
  add_exit("northwest","/wizards/grathlek/area4/froom2.c");
  set_light(2);
 
  short_desc = "A gloomy red passage.";
  long_desc = "Red light glows dimly on the walls. It\n"+
              "smells like somewhere might be a rotting\n"+
              "carcass and dirty rats swarm everywhere\n";
}
