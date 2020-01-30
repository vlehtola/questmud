inherit "room/room";
object monster;
 
reset(arg) {
  if (!monster) {
    monster = clone_object("/wizards/morgoth/forest/npc/witch");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("paikka","/wizards/shadow/shortban");
  short_desc = "Inside of house.";
  long_desc = "You have entered the house of witch. This place doesn't\n"+
              "appear to be very hospitable or comfortable. The place\n"+
              "is hot and there is only one exit to out.\n"+
              "The witch is usually here eating some little kids!\n";
}
