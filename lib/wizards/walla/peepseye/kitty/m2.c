inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/peepseye/monsters/kid");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","/wizards/walla/peepseye/kitty/house1");
  add_exit("south","/wizards/walla/peepseye/kitty/store");
  add_exit("west","/wizards/walla/peepseye/kitty/2");
  add_exit("east","/wizards/walla/peepseye/kitty/m3");
  short_desc = "On Main Street, OilOhnRock";
  long_desc =
  "As in every town there is a Main Street. The mainstreet of OilOhnRock leads east\n" +
 "from here. To the south is a type of store and to the north is a normal looking house.\n";
 
  items = allocate(4);
  items[0] = "house";
  items[1] = "To the north is a house, where Victoria and Beavis live.";

 
}

