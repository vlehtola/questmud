inherit "room/room";

reset(arg) {
  add_exit("west", "/wizards/ahma/orc/forest/for29");
  add_exit("northeast", "/wizards/ahma/orc/forest/for33");
  short_desc = "On a soft forest path leading to a small opening";

}

init() {
  int i;
  ::init();
  i = random(5);
  if(i==0) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc01") + 
             "Forest can be seen ending in a meadow on northeast.\n"; }
  if(i==1) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc02") + 
             "Forest can be seen ending in a meadow on northeast.\n"; }
  if(i==2) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc03") + 
             "Forest can be seen ending in a meadow on northeast.\n"; }
  if(i==3) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc04") + 
             "Forest can be seen ending in a meadow on northeast.\n"; }
  if(i==4) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc05") + 
             "Forest can be seen ending in a meadow on northeast.\n"; }
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}
