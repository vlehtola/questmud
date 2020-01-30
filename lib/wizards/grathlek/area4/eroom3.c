inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/dimp.c");
    move_object(monster, this_object());
   }
  add_exit("northeast","/wizards/grathlek/area4/eroom2.c");
  add_exit("west","/wizards/grathlek/area4/mroom1.c");
  add_exit("southwest","/wizards/grathlek/area4/eroom4.c");
  set_light(2);
 
  short_desc = "A bad smelling dirty junction.";
  long_desc = "This is the home of minor evil monsters.\n"+
              "Red light shines from the west and the smell\n"+
              "in here is horrible. Evil athmosphere is around.\n";
}
