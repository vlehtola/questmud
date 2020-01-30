inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/map");
   return 1;
}
object monster,hattu;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/dlof");
    move_object(monster, this_object());
  }
 
  if(!hattu) {
     hattu = clone_object("/wizards/walla/jericho/stuph/hat");
     move_object(hattu, this_object());
  }
 
 
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/bazaar/ylaoikea");
  add_exit("west","wizards/walla/jericho/rooms/bazaar/keski");
  short_desc = "In the bazaar";
  long_desc =
"You are standing in the eastern part of the bazaar. This location\n" +
"is the source of the music, and you can see a white male singing\n" +
"various old fold melodies here. As you listen to the man, you start\n" +
"feeling relaxed. It is as if the singing almost hypnotizes you. You\n" +
"can see a hat, which is filled with small coins.\n";
 
 
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}
