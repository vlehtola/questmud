inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/famu.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/eroom3.c");
  add_exit("west","/wizards/grathlek/area4/mroom2.c");
  set_light(2);
 
  short_desc = "A large red corridor.";
  long_desc = "This is the main corridor of this cave.\n"+
              "Red light shines from the west. Large pillars\n"+
              "support the walls which might be a sign of a\n"+
              "higher civilisation\n";
}
