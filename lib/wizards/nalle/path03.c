inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("southwest","wizards/nalle/jerusalem/path04");
  short_desc = "A path leading up the hill";
  long_desc =
"The path continues south-west, up the hill, which seems to gradually\n"+
"become more mountainous. There are some pine trees here, but hardly\n"+ 
"any birches or oaks that were of abundance lower down the hill.\n"+
"The trail itself is getting slightly difficult to walk on, as larger\n"+
"rocks and roots obstruct your way.\n";
}

