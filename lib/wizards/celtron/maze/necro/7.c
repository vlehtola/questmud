inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "An underground graveyard";
  long_desc = "You are in an underground graveyard, which is carved into rock.\n"+
        "There is a rotten smell on the air. Some graves are dug open, but there are no\n"+
        "corpses in them.\n";
  add_exit("south", "/wizards/celtron/maze/necro/6");
  add_exit("northwest", "/obj/rebirth_room");
  move_object(clone_object("/wizards/celtron/maze/monsters/necro"), this_object());
  move_object(clone_object("/wizards/celtron/maze/monsters/mummy"), this_object());
}


