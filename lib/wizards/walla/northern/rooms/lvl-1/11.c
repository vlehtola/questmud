inherit "room/room";
init() {
  ::init();
  add_action("pull", "pull");
}
 
pull(str) {
  if(str != "torchholder") return;
  write("You pull the torchholder, and the wall slides open.\n");
  say(""+this_player()->query_name()+" fumbles with the torchholder.\n");
  add_exit("east","pull_lever");
  command("look");
  return 1;
}
 
 
  reset(arg) {
  add_exit("north","10");
  add_exit("south","12");
   short_desc = "In a dark passage under the mountain";
  long_desc =
"The passage that you see before you, reminds you oddly of a prison. There are bars\n" +
"and chains hanging of the wall. The paraphernalia on the walls seem to have been\n" +
"abandoned for quite some time now. Still, voices can be heard from the depths of\n" +
"the mountain. Torchholders cover the walls on the east side.\n";
 
 
}
