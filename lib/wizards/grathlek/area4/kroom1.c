inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/king.c");
    move_object(monster, this_object());
   }
  add_exit("east","/wizards/grathlek/area4/mroom11.c");
  set_light(3);
 
  short_desc = "The end of the rocky path.";
  long_desc = "This is the room of the imp king.\n"+
              "Red light and the burning heat shines\n"+
              "very brightly from the lavastream. The\n"+
              "King's throne stands in the middle of the\n"+
              "room. The ground is covered by stones.\n";

items = allocate(4);
  items[0] = "lavastream";
  items[1] = "Lavastream shines brightly red.";

items = allocate(4);
  items[0] = "throne";
  items[1] = "King's throne.";
}
