inherit "room/room";

reset(arg) {
  add_exit("northeast", "/wizards/ahma/orc/forest/for02");
  add_exit("forest", "outmap: 180 147");
  short_desc = "Entrance to thick forest";
  long_desc = "The forest surrounding this area gets thicker when moving northwards.\n" + 
              "In south continues the thinner forest which leads to the open plains\n" + 
              "of Deleria. The thick forest seems to be full of life. Many species\n" + 
              "of different animals seek for shelter from their enemies among the\n" + 
              "tree trunks and thick bushes growing all around this forest. The path\n" + 
              "leading to northeast is covered with fallen leaves which make it feel\n" + 
              "very comfortable under your feet.\n";
}

init() {
  ::init();
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
  if(present("walkeri", this_object())) {
  call_other(present("walkeri", this_object()), "checkroom");
  }
}
