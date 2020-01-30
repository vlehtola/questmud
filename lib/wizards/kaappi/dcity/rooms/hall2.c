inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("out", "katu26.c");
  add_exit("north", "hall5.c");
  add_exit("east", "hall3.c");
  add_exit("west", "hall1.c");
  
  short_desc = "The city hall";
  long_desc = "You have entered the city hall. This is a huge and spacious place.\n"+
              "The hallway leads to north, west and east. There are busy looking\n"+ 
              "dwarves running everywhere. Some of them are carrying papers in their\n"+
              "hands. A great and gorgeously decorated pillars are rising on both\n"+
              "sides of you. The floor is made from beautiful marble.\n";

  set_light(2);
}
