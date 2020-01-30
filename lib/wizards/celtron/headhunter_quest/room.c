inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/celtron/headhunter_quest/headhunter_mob");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("north","/wizards/morgoth/slummi/room/slum2");
  short_desc = "A filthy street.";
  long_desc = "You are on a dark street which runs from north to a dead end.\n"+
              "The darkness makes this smelly street worse. You can smell\n"+
		"the presence of death here.\n";
}
