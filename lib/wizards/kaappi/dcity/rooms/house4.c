inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("east", "katu11.c");
  add_exit("stairs", "house4yla.c");

  short_desc = "A house";
  long_desc = "This house is bigger than the others.\n"+
              "There is a big table with six chairs\n"+
              "placed on the western side of the room.\n"+
              "Wooden stairs are leading upstairs.\n"; 
  set_light(3);
}
