inherit "room/room";

reset(arg) {
  if(arg) return;
  if(!present("figure", this_object())) move_object(clone_object("/wizards/ahma/orc/mob/membera"), this_object());
  if(!present("figure 2", this_object())) move_object(clone_object("/wizards/ahma/orc/mob/memberb"), this_object());
  if(!present("figure 3", this_object())) move_object(clone_object("/wizards/ahma/orc/mob/membera"), this_object());
  if(!present("figure 4", this_object())) move_object(clone_object("/wizards/ahma/orc/mob/memberb"), this_object());
  if(!present("figure 5", this_object())) move_object(clone_object("/wizards/ahma/orc/mob/membera"), this_object());
  if(!present("figure 6", this_object())) move_object(clone_object("/wizards/ahma/orc/mob/memberb"), this_object());
  
  add_exit("east", "/wizards/ahma/orc/village/sub19");
  add_exit("stairs", "/wizards/ahma/orc/village/sub16");
  short_desc = "Bottom part of the tunnel system";
  long_desc = "The large, open room is full of candles and torches. From the ceiling is\n" + 
              "even hanging a cheap-looking chandelier. In the center of the room is a\n" + 
              "huge table. Around the table there seems to be placed at least ten chairs.\n" + 
              "The walls are covered with different kinds of emblems and paintings. Some\n" + 
              "candlesticks are standing by the brick-walls. The gray carpet covers the\n" + 
              "whole area of room's floor. Water can be seen falling down by the room from\n" + 
              "both, western and eastern, ends of it. The rusty metal stairs are leading\n" + 
              "up in the western wall.\n";
              
  items = allocate(22);
  items[0] = "table";
  items[1] = "A huge wooden table must have been made in this room because there is no\n" + 
             "way it could have been transferred through the small, winding tunnels.\n" + 
             "At least ten chairs have been placed around the table. It seems, that\n" + 
             "this table would be some kind of a negotiation of planning table";
  items[2] = "chairs";
  items[3] = "Ordinary chairs made of wood have been dragged down in the sewers. They\n" + 
             "are all placed nicely around the big wooden table standing in the center\n" + 
             "of the room. There seems to be ten or more chairs around the table";
  items[4] = "chair";
  items[5] = "Try looking at 'chairs'";
  items[6] = "paintings";
  items[7] = "The paintings are hanging in the height of your eyes. By most of them is\n" + 
             "placed two candles near the frames of the painting. All of the paintings\n" + 
             "seem to have one common theme: slay the Dwarves. Most of the paintings are\n" + 
             "either illustrating a dead Dwarf or a battle between an Orc and a Dwarf.\n" + 
             "Some paintings picture more abstractily the death of a Dwarf. The paintings\n" +
             "look quite harsh and brutal";
  items[8] = "painting";
  items[9] = "Try looking at 'paintings'";
 items[10] = "emblems";
 items[11] = "Many colourful emblems are hanging on the walls. The emblems are mostly\n" + 
             "hanging near the ceiling, the paintings are hanging below them. The emblems\n" + 
             "might be insignias of different Orcish communities all around the realm of\n" + 
             "Deleria. All of the emblems look patiently planned and made, none of them\n" + 
             "seem too colourful or ugly";
 items[12] = "emblem";
 items[13] = "Try looking at 'emblems'";
 items[14] = "carpet";
 items[15] = "Dull-looking gray carpet has been laid on the floor. The carpet is quite\n" + 
             "furry and comfortable, despite of its boring colouring. The carpet is big\n" + 
             "enough to cover the whole floor of this big room";
 items[16] = "stairs";
 items[17] = "Rusty metal stairs in the western wall lead upper into the tunnel system";
 items[18] = "candlesticks";
 items[19] = "Silvery candlesticks are full of lit candles. The candlesticks are set near\n" + 
             "the paintings and emblems hanging on the walls. The candlesticks have multiple\n" + 
             "places for candles on them";
 items[20] = "candlestick";
 items[21] = "Try looking at 'candlesticks'";
 
}

init() {
  ::init();
  if(present("figure 2", this_object())) call_out("saymsg", 1);
}

saymsg() {
  tell_room(this_object(), "As you arrive the room the robed figures surround you and attack.\n");
}
