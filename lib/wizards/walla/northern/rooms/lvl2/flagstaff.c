inherit "room/room";
 
object flagstaff,monster;
 
reset(arg) {
  if(!flagstaff) {
    flagstaff = clone_object("/wizards/walla/northern/stuph/flagpole");
    move_object(flagstaff, this_object());
  }
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/kiban");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","court_33");
  add_exit("west","court_22");
  add_exit("south","court_13");
  add_exit("east","court_24");
  short_desc = "In the courtyard";
  long_desc =
"You are standing in the middle of the castle's courtyard. At this location you can see a huge \n"+
"flagpole flying the flag of Razindukhta. The flagpole has been placed upon a pedistal, and is \n"+
"at least 50 feet high. The flag can surely be seen from outside of the castle aswell. A guard \n"+
"is slowly pacing around the pedistal, and it seems that many others have done so, since you can\n"+
"clearly see stones slightly pressed down in his path.\n";
 
}
