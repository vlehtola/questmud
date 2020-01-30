inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/famu.c");
    move_object(monster, this_object());
   }
  add_exit("northeast","/wizards/grathlek/area4/eroom3.c");
  add_exit("southwest","/wizards/grathlek/area4/eroom5.c");
  set_light(2);
 
  short_desc = "A bad smelling red cave.";
  long_desc = "Red light shimmers on the walls.\n"+
              "The smell is here somewhat awful.\n"+
              "A fresh wind blows from the hole\n"+
              "bringing some air to this smelly cave.\n";

  items = allocate(4);
    items[0] = "hole";
    items[1] = "This hole is maybe too tight to crawl in.";
}
