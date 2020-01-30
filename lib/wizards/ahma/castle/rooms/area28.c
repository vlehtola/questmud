inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area29");
  add_exit("south", "/wizards/ahma/castle/rooms/area27");
  short_desc = "The kitchen";
  long_desc = "In the kitchen.\n" + 
              "The shiny-white room is a beautiful sight. Though all of the knives and\n" + 
              "frying pans from the eastern wall have fell on the floor, the kitchen-\n" + 
              "ware on the western wall is perfectly arranged. Some pots are still\n" + 
              "boiling on the oven, though the fire in it has almost died. The chief\n" + 
              "cook's assistant is lying lifeless on the floor near the entrance to\n" + 
              "the wine cellar, which is located to the north from the kitchen.\n";
              
  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster01, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster01, this_object());
    }
  }  
}
