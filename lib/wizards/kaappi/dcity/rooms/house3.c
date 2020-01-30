inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu10.c");

  short_desc = "A house";
  long_desc = "Dusty and messy looking house. There\n"+
              "are some broken pieces of furniture\n"+
              "laying on the floor. It seems that\n"+
              "no one has lived here for a long time.\n";
  set_light(3);
}
