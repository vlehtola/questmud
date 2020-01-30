inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu33.c");

  short_desc = "A house";
  long_desc = "This house is in very bad shape.\n"+
              "There are many cracks on the walls and \n"+
              "the dust covers the floor and furnitures.\n"+
              "The ceiling looks like it could collapse\n"+
              "at any time.\n";

  set_light(1);
}
