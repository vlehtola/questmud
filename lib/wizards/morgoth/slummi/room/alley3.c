inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("north","/wizards/morgoth/slummi/room/alley4");
  add_exit("southeast","/wizards/morgoth/slummi/room/slum5");
  short_desc = "Another dark alley.";
  long_desc = "Yikes! Again you are in some dark alley.\n"+
              "You should avoid places like this.\n"+
              "You can sense the presence of death.\n"+
              "Maybe you should check the north exit?\n";
 }
