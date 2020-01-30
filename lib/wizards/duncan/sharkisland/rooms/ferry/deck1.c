inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("north","/wizards/duncan/sharkisland/rooms/ferry/deck.c");
add_exit("south","/wizards/duncan/sharkisland/rooms/ferry/deck2.c");

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
