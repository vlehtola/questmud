inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("west", "torni2.c");
  add_exit("east", "torni3.c");

  short_desc = "The balcony";
  long_desc = "You are standing at a long balcony, which is\n"+
              "a gateway between these gorgeous looking towers.\n"+
              "From here you can see some drows and slaves walking\n"+
              "in the tunnels.\n";               
  set_light(1);
}
