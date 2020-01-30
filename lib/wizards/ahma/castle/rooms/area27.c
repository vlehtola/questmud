inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area28");
  add_exit("west", "/wizards/ahma/castle/rooms/area26");
  short_desc = "An intersection";
  long_desc = "In the intersection.\n" + 
              "The partly burnt red-carpeted hallway separates in three directions:\n" + 
              "To north is the kitchen room from where all the interesting aromas\n" + 
              "are floating into this room.\n" + 
              "To east is the dining hall. The hall is on heavy fire and it cannot\n" + 
              "be entered. Tables, chairs, artistic curtains hanging from the ceiling,\n" + 
              "flags and emblems on the walls: They are all in the burning-hot flames.\n" + 
              "To west is the hallway leading to the throne room.\n" + 
              "There is a sign on the southern wall.\n";
  items = allocate(2);
  items[0] = "sign";
  items[1] = ".+------------------------------------------+.\n" +
             ".| Meals are served at the following times  |.\n" +
             ".|  Breakfast:  5  AM  to  6  AM      ONLY! |.\n" +
             ".|  Lunch:     11  AM  to  12 AM      ^^^^  |.\n" +
             ".|  Dinner:     2  PM  to  4  PM            |.\n" +
             ".|  Supper:     8  PM  to  9  PM            |.\n" +
             ".+------------------------------------------+";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob05");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster02, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }  
}