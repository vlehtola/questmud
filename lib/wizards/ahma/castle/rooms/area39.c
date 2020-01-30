inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("west", "/wizards/ahma/castle/rooms/area40");
  add_exit("hole", "/wizards/ahma/castle/rooms/area38");
  short_desc = "Beginning of the third floor";
  long_desc = "At the beginning of the third floor of the cavern.\n" + 
              "The third floor can be seen in whole from here. You are standing\n" + 
              "on a small hill watching an enormous, absolutely beautiful, red\n" + 
              "opening. The walls are a bit crude and they consist of glowing red\n" + 
              "stones. Same goes with the floor. In the center of the room there\n" + 
              "are two geysirs. They are making out humongous amount of bright white,\n" + 
              "sulphurous-stenching steam which is eventually coloured red by the\n" + 
              "radiating stones on the walls and floor. From the southwest corner of\n" + 
              "the room seems to start some kind of a road. It leads from the corner,\n" + 
              "between the geysirs, to the northern side of the room, where cannot be\n" + 
              "seen from here due to all the steam coming out from the geysirs. Some\n" + 
              "huge dripstones are hanging from the ceiling, which is about 30 feet high.\n" + 
              "The air feels hot and moist.\n";

  set_not_out(1);

  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster01, this_object());
      set_blocker("hunter", "west");
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob16");
      move_object(monster01, this_object());
      set_blocker("master", "west");
    }
  }
}