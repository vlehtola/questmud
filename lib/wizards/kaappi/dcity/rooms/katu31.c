inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu30.c");
  add_exit("south", "katu25.c");
  add_exit("north", "katu36.c");
  
  short_desc = "The crossing";
  long_desc = ""
"#| B |            You are standing at the crossing of the Dalvur and Bolain\n"+
"#|S W| ####       street. On the right side there is a fence between the park\n"+
"#|   | #          and road. The crossing is leading to north, south and west.\n"+
"#+-8-* # K        One huge lantern is lightening the whole street.\n"+
"#|   | #   \n"+
"#2  G| ##-#\n";

  set_light(2);
}
