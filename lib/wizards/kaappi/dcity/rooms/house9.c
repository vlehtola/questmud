inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("north", "katu16.c");

  short_desc = "A house";
  long_desc = "This house is one of the smallest ones\n"+
              "you have ever visited. The ceiling is \n"+
              "only ten feet high and the table barely\n"+
              "reaches your waist. This place is so \n"+
              "tight that you begin to feel anxious.\n";
  set_light(2);
}
