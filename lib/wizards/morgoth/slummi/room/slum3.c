inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/dog");
    move_object(monster, this_object());
 
    monster = clone_object("/wizards/morgoth/slummi/npc/dog");
    move_object(monster, this_object());
 
  }
  if(arg) return;
 
  add_exit("west","/wizards/morgoth/slummi/room/slum2");
  add_exit("east","/wizards/morgoth/slummi/room/slum4");
  add_exit("northwest","/wizards/morgoth/slummi/room/alley1");
  short_desc = "A crossing.";
  long_desc = "You are on road within the slums. To the northwest of you\n"+
              "is the murky alley. As you look a bit west and east you\n"+
              "can see the street going further. Looking north and south,\n"+
              "there is only a old buildings and trash.\n";
 
}
