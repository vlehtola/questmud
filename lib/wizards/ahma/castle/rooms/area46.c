inherit "room/room";
object monster01, monster02;

reset(arg) {
  add_exit("south", "/wizards/ahma/castle/rooms/area45");
  add_exit("up", "/wizards/ahma/castle/rooms/area47");
  short_desc = "First floor of the tower";
  long_desc =  "On the first floor of the Demon Tower.\n" + 
               "The first floor of the tower looks hastily made and never cleaned. The floor\n" + 
               "is covered with crap and small shards of stone, which crunch under your feet.\n" + 
               "The small circular room is fully illuminated by the red glowing stones, which\n" + 
               "are either stuffed in the walls or just left lying around the floor. The light\n" + 
               "feels almost comfortable. Lots of footprints can be seen on the crappy floor\n" + 
               "leading to stairs in the northern side of this room.\n" + 
               "Near the stairs there seems to be some kind of a plaque hanging on the wall.\n";
  
  items = allocate(2);
  items[0] = "plaque";
  items[1] = "A stony plaque is hanging on the wall near the stairs. Some runes have been\n" + 
             "carved on its sturdy surface, but they are not understandable to you. Maybe\n" + 
             "this is some kind of a guild";
  
  set_not_out(1);

}