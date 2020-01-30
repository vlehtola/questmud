inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("southwest", "t9.c");
  add_exit("northwest", "t14.c");
  add_exit("stairs", "luokka.c");

  short_desc = "A temple of Lloth";
  long_desc = "A small adjoining room. There are only a small\n"+
              "stairs leading to up. A quiet mumbling can be\n"+
              "heard from the temple.\n";              
  
  set_light(1);
}
