inherit "room/room";

static status rod_found;
object ferryman;
reset(arg) {

if(!ferryman) {
ferryman = clone_object("/wizards/duncan/sharkisland/monsters/ferryman.c");
move_object(ferryman, this_object());
}
if(arg) return;

add_exit("north","/wizards/duncan/sharkisland/rooms/ferry/deck1.c");


short_desc = "On a half-sunken ferry";
long_desc = "You are standing in the water, on a deck of a half-sunken ferry. The\n"+
            "water level is about thirty centimeters from the deck. A safety fence\n"+
            "is built around the ferry. The deck is slippery and dangerous because\n"+
            "you can't see what's under surface of the water. The ferry isn't\n"+
            "floating, so it must be sunken all the way to the sea-bed. A life\n"+
            "buoy is attached to the ferry's hull.\n"; 

           set_light(3);

items = allocate(8);
items[0] = "water";
items[1] = "The water is cold. It's covering the ferry's deck.";
items[2] = "safety fence";
items[3] = "The safety fence is built around the ferry.";
items[4] = "deck";
items[5] = "The deck is covered with water.";
items[6] = "life buoy";
items[7] = "The life buoy is attached to the ferry's hull. It can't be loosened.";


}
int rod_found;
init() {
  ::init(); 
  add_action("open", "open"); 
}

open(str) {
  if(rod_found) {
    write("There's nothing anymore.\n");
    return 1;
  }
  rod_found = 1;
  if(str == "box") {
    if(present("ferryman", this_object())) {
    write("As you try to open the box the ferryman attacks you!\n");
return 1;
}
    write("You open the box and search it.\n"); 
    write("You grab on something hard.\n");
    write("You pull a fishing rod from the box!\n");
    say(this_player()->query_name()+" opens the box and takes a fishing rod from inside of it.\n");
    move_object(clone_object("/wizards/duncan/sharkisland/object/rod.c"), this_player()); 

     }
     return 1;
 }