inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu12.c");

  short_desc = "A noble house";
  long_desc = "A spacious looking apartment with a large round table in the center\n"+
              "of the room with 6 chairs evenly spreaded around it. There is a shining\n"+
              "chandelier on the ceiling just above the table with tens of candles in it.\n"+
              "Each of the four walls have two extensively decorated shields hanging,\n"+
              "carved with some sort of emblems.\n";
  set_light(3);
}
