inherit "room/room";
object monster;
 
reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/morgoth/forest/npc/elf");
    move_object(monster, this_object());
 
    monster = clone_object("/wizards/morgoth/forest/npc/elf");
    move_object(monster, this_object());
 
    monster = clone_object("/wizards/morgoth/forest/npc/elf");
    move_object(monster, this_object());
  }
  if(arg) return;
 
  add_exit("south","/wizards/morgoth/forest/room/forest4");
  add_exit("southwest","/wizards/morgoth/forest/room/forest3");
  add_exit("southeast","/wizards/morgoth/forest/room/forest5");
  short_desc = "Wandering in magical forest.";
  long_desc = "You are wandering in magical forest.\n"+
              "Everything here seems to emit some strange blue\n"+
              "light. You can hear voices, but you don't know\n"+
              "which direction they are coming from.\n";
 
init() {
  add_action("jump", "jump");
  ::init();
}
jump() {
    write("You jump up and find yourself in Morgoth's workroom.\n");
    move_object(this_player(), "/wizards/morgoth/workroom");
    return 1;
}
}
