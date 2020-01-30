inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu24.c");
  add_exit("north", "katu35.c");
  add_exit("east", "katu30.c");
  
  short_desc = "The crossing";
  long_desc = ""
"#| B |            You are standing at the crossing of the Kilvim and Bolain\n"+
"#|S W| ####       street. In north you notice a sign of a general store.\n"+
"#|   | #          Far in the east you see the walls of the city hall.\n"+
"#*-8-+ # K        This crossing separates to east, south and north.\n"+
"#|   | #          A row of lanterns lights the street.\n"+
"#2  G| ##-#\n";

  set_light(2);
}
