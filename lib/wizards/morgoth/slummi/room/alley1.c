inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/slummi/npc/beggar");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("northwest","/wizards/morgoth/slummi/room/alley2");
  add_exit("southeast","/wizards/morgoth/slummi/room/slum3");
  short_desc = "A dark alley";
  long_desc = 
"This is a dark alley. There is a strong smell of rotting flesh in the\n"+
"air. You can hear screaming from the northwest. At the southwest is a\n"+
"filthy street.\n";
 
 }
