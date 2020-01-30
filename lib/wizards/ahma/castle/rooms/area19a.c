inherit "room/room";
int i;
object monster01, monster02;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area18");
  short_desc = "In a bedroom";
  long_desc = "In one of the servants' bedrooms.\n" + 
              "The room is a typical, small bedroom for king's servants. The window on\n" + 
              "the eastern wall is giving some light to the room. The stench of blood and\n" + 
              "torn flesh is penetrating into your olfactorial nerves. The room looks like a\n" + 
              "slaughterhouse: There are four beds, two in each side of the room. In three\n" + 
              "of the beds there is a massacred body of a servant, the resistance had been\n" + 
              "futile, they had been mauled to death when they were asleep. The fourth\n" + 
              "corpse is found near the door in a huge bloodpool. This man's head is missing.\n";

  i = random(3);
  
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
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster02, this_object());
    }  
  }
}
