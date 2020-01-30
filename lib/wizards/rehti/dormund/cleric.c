inherit "room/room";
object monster;

reset(arg) {

  add_exit("east","/wizards/rehti/dormund/w");
  short_desc = "City cleric.";
  long_desc = "This is cleric's office. House is filled with shelves containing healing herbs\n" +
              "and you also see some wounded knights sleeping in beds. It seems that cleric\n" + 
              "is worrying about something. Those knights sure look massacred, maybe he\n" +
              "waits for some more massive attacks.\n";
  items = allocate(4);
  items[0] = "shelves";
  items[1] = "These shelves are filled with somekind of healing herbs. You just didn't know that pig shit can be used for healing purposes";
  if(!present("cleric")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/cleric"), this_object());
  if(arg) { return; }
}
}