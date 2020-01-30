inherit "room/room";
object mob;
int h;

reset(arg) {
  add_exit("out", "/wizards/ahma/orc/village/vil15");
  short_desc = "Inside the clumsy wagons";
  long_desc = "The light is shimmering inside the cart from numerous holes found in the\n" + 
              "sheet covering the wagons. The cart is almost empty, just some various\n" + 
              "trash can be found here and there. On the bottom is lying wrappings of\n" + 
              "many different items. Some wooden racks have been piled up by the wall\n" + 
              "nearest to the cart's drivers seat. A thin layer of dust covers the most\n" + 
              "of the cart's wooden bottom.\n";

  items = allocate(4);
  items[0] = "wrappings";
  items[1] = "Wrappings of various different items are lying on the bottom. Wrappings\n" + 
             "of clothes, beer, weapons, food and et cetera are covering the huge\n" + 
             "part of the wagons' bottom among the dust. The conclusion is that these\n" + 
             "wagons were once used to transfer trading goods from one place to another";
  items[2] = "racks";
  items[3] = "A big pile of simple wooden racks is located by the eastern wall. The racks\n" + 
             "are now empty, but they surely have once been used to carry the things\n" + 
             "which were transferred from one place to another with these wagons";

  if(!mob) {
    move_object(mob = clone_object("/wizards/ahma/orc/mob/bum02"), this_object());
    if(h) { present("bum", this_object())->task_complete(); }
  }
}

task_complete() {
  h = 1;
}
