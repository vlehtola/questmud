inherit "room/room";

reset(arg) {
  add_exit("east", "/wizards/ahma/orc/forest/for07");
  add_exit("northwest", "/wizards/ahma/orc/forest/for09");
  short_desc = "On a soft forest path";

}

init() {
  int i;
  ::init();
  i = random(5);
  if(i==0) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc01"); }
  if(i==1) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc02"); }
  if(i==2) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc03"); }
  if(i==3) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc04"); }
  if(i==4) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc05"); }
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}
