inherit "room/room";

reset(arg) {
  add_exit("east", "/wizards/ahma/orc/forest/for32");
  add_exit("northwest", "/wizards/ahma/orc/forest/for28");
  add_exit("southeast", "/wizards/ahma/orc/forest/for30");
  short_desc = "In an intersection";
}

init() {
  int i;
  ::init();
  i = random(5);
  if(i==0) {
    long_desc = "The path separates in three directions.\n" + 
    read_file("/wizards/ahma/orc/forest/fordesc01", 2);
  }
  if(i==1) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc02", 2);
  }
  if(i==2) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc03", 2);
  }
  if(i==3) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc04", 2);
  }
  if(i==4) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc05", 2);
  }
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}
