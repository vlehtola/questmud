#define AREAPATH "wizards/nalle/rebirth/"+

inherit "room/testroom";

reset(arg) {
  if(arg) return;
  add_exit("northeast",AREAPATH"/path04");
  add_exit("southwest","wizards/nalle/jerusalem/path05");
  add_exit("south","wizards/nalle/jerusalem/path05");
  add_exit("southeast","wizards/nalle/jerusalem/path05");
  short_desc = "Northern parth of a verdant plateau";

  set_sound(5,"The girls cheer at Nalle\n");

  long_desc =
"The path continues south-west, up the hill, which seems to gradually\n"+
"become more mountainous. There are some pine trees here, but hardly\n"+ 
"any birches or oaks that were of abundance lower down the hill.\n"+
"The trail itself is getting slightly difficult to walk on, as larger\n"+
"rocks and roots obstruct your way.\n";
}

