inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("down","/wizards/duncan/sharkisland/rooms/bailiffshop/room1.c");

short_desc = "Bedroom in upstairs";
long_desc = "A bedroom is built in the upstairs. The ceiling is very low, about one\n"+
            "and a half meters from the floor. Two beds are placed next to next,\n"+
            "taking almost the whole floor-space. There are two curtains covering\n"+
            "the windows on walls. Wooden stairs are leading back to the\n"+
            "downstairs. A candle is burning on the floor.\n"; 
           
  
   set_not_out(1);
   set_light(2);

items = allocate(8);
items[0] = "bed";
items[1] = "There are two beds placed next to next.";
items[2] = "curtain";
items[3] = "Two curtains are covering the windows.";
items[4] = "stairs";
items[5] = "The stairs are leading back to the downstairs.";
items[6] = "candle";
items[7] = "A small candle is burning on the floor. It lits up the room.";

}
