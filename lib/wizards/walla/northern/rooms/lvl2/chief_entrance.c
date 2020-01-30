inherit "room/room";
 
object monster,monster2;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/khilar_guard");
    move_object(monster, this_object());
  }
  
  if(!monster2) {
    monster2 = clone_object("/wizards/walla/northern/mobs/khilar_guard2");
    move_object(monster2, this_object());
  }
 
  if(arg) return;
  add_exit("down","cell_10");
  add_exit("west","balcony_w");
  add_exit("east","balcony_e");
  short_desc = "On the balcony";
  long_desc =
"You are standing on a viewing balcony where the officers view the progress\n"+
"of their subordinates. It lies some 15 feet over the courtyard, in order to\n"+
"have a good view of the premises. You can clearly see the flagpole in the\n"+
"middle of the courtyard, onto which is hoisted the flag of Razinduktha.\n";
 
}
