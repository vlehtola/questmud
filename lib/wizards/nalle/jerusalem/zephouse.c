inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/zephaniah");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("out","wizards/nalle/jerusalem/armb3");
  short_desc = "Zephaniah's house";
  long_desc =
"You have entered an old man's house. The man himself is\n" +
"sitting in one corner of the room, on a wooden chair.\n" +
"The man seems quite frail and not in a very good shape.\n" +
"Despite his poor physical condition he seems mentally fit.\n";
}
