inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("east", "katu25.c");
  add_exit("south", "g1a.c");
  add_exit("west", "g5a.c");
  add_exit("north", "g3a.c");

short_desc = "The guard barracks";
long_desc = "You have arrived to the barracks. This room\n"+
            "is spacious and nearly empty. Couple of\n"+
            "hallways begin here. You can hear loud\n"+
            "shouts from somewhere. The voices echo\n"+
            "here and it is hard to say where these\n"+
            "sounds exactly are coming from.\n";
  set_light(3);
}
