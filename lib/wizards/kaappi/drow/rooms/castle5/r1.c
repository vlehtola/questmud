inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("out", "/wizards/kaappi/drow/vmap/castle5_entrance.c");
  add_exit("north", "r3.c");

  short_desc = "A hallway";
  long_desc = "You have entered to the castle. This is a very\n"+
              "narrow hallway which is leading to the north.\n"+
              "The walls are decorated with some beautiful\n"+
              "paintings. A small spiders are running almost\n"+
              "everywhere. These evil drows really like those\n"+
              "small disgusting creatures.\n";
              
  set_light(1);
}
