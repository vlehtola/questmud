inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/dog");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("north","/wizards/morgoth/slummi/room/slum10");
  add_exit("south","/wizards/morgoth/slummi/room/slum8");
  add_exit("southwest","/wizards/morgoth/slummi/room/alley5");
  short_desc = "A crossing.";
  long_desc = "You are on road within the slums. To the southwest of you\n"+
              "is the murky alley. As you look a bit north and south you\n"+
              "can see the street going further. Looking west and east,\n"+
              "there is only a old buildings and trash.\n";
 }
