inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("pier","/wizards/duncan/sharkisland/rooms/isentrance.c");
add_exit("south","/wizards/duncan/sharkisland/rooms/ferry/deck1.c");

short_desc = "Foredeck of a half-sunken ferry";
long_desc = "The foredeck of the half-sunken ferry is covered with cold water. The\n"+
            "water level is about thirty centimeters from the deck. A safety fence\n"+
            "is built around the ferry. The deck is slippery and dangerous because\n"+
            "you can't see what's under surface of the water. A huge iron box,\n"+
            "covered with water, is on the deck. The ferry isn't floating, so it\n"+
            "must be sunken all the way to the sea-bed.\n"; 

           set_light(3);

items = allocate(8);
items[0] = "water";
items[1] = "The water is cold. It's covering the ferry's deck.";
items[2] = "safety fence";
items[3] = "The safety fence is built around the ferry.";
items[4] = "deck";
items[5] = "The deck is covered with water.";
items[6] = "box";
items[7] = "A huge iron box is on the deck. It's almost covered with water. It's stuck.";


}
