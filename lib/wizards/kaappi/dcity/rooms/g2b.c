inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu27.c");
  add_exit("south", "g1b.c");
  add_exit("east", "g5b.c");
  add_exit("north", "g3b.c");

short_desc = "The guard barracks";
long_desc = "You have arrived to the barracks. This room\n"+
            "is spacious and nearly empty. Couple of\n"+
            "hallways begin here. You can hear loud\n"+
            "shouts from somewhere. The voices echo\n"+
            "here and it is hard to say where these\n"+
            "sounds exactly are coming from.\n";
  set_light(3);
}
