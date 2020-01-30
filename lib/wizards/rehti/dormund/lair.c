inherit "room/room";
object monster;

reset(arg) {
  add_exit("up","/wizards/rehti/dormund/tunkio");
  short_desc = "Ancient lair.";
  long_desc = "This huge lair looks almost abandoned. The walls around are burnt but not with\n"+
              "fire but acid. The air around here is hard to breath. Some bones of large\n"+
              "creatures lie massacred on the floor. If someone or something would have\n"+
              "been trapped here for a very long time, anything nasty could happen.\n";
  if(!present("shinryu")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/shinryu"), this_object());
  if(arg) { return; }
}
}