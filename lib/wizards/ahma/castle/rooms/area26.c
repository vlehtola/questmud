inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area13f");
  add_exit("east", "/wizards/ahma/castle/rooms/area27");
  short_desc = "In a hallway";
  long_desc = "In a hallway leading to dining area.\n" + 
              "The red carpet leads towards the intersection of dining hall and the\n" + 
              "kitchen, in the other direction, to the throne room. There are two candles\n" + 
              "on the both walls to give some luminance to the hallway. Near the ceiling,\n" + 
              "attached to a wooden pedal which is nailed on the wall, there are two quite\n" + 
              "big and noble moose heads. The smell is here a bit better than in other\n" + 
              "parts of the castle: The stench of corpses and bowels is mixed with the\n" + 
              "soft aroma of various foods, probably made up for breakfast.\n";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster01, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster01, this_object());
    }
  }  
}
