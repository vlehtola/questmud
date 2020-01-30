inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/khilarbhunaz");
    move_object(monster, this_object());
  }
 
  if(arg) return;
  add_exit("west","wizards/walla/northern/rooms/lvl2/chief_entrance");
  short_desc = "The viewing balcony";
  long_desc =
"You are standing on a viewing balcony where the officers view the progress\n"+
"of their subordinates. It lies some 15 feet over the courtyard, in order to\n"+
"have a good view of the premises. You can clearly see the flagpole in the\n"+
"middle of the courtyard, onto which is hoisted the flag of Razinduktha.\n";

 
 
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_spell";
 
}
