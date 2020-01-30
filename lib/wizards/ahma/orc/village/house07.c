inherit "room/room";
object mob;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/vil09");
  short_desc = "In a pink-painted house";
  long_desc = "Very feminine house. The walls have been painted in light pink and the main\n" + 
              "color theme seems to be pink everywhere. Numerous flowers set in the vases\n" + 
              "and pots are emitting a wonderful scent all around the apartment. A wooden\n" + 
              "dinner table is covered with flowery cloth and a flowery carpet is covering\n" + 
              "the floor. A window is located in the eastern wall. From the outlook of the\n" + 
              "house can be concluded that whoever owns this apartment must be a real\n" + 
              "flower-addict.\n";
  
  items = allocate(8);
  items[0] = "table";
  items[1] = "An ordinary wooden dining table is standing by the northern wall.\n" +
             "A beautiful flowery cloth is covering the table and some dishes\n" + 
             "are set on the cloth. No food is placed on them yet. Though the\n" + 
             "table is made from wood, it looks sturdy enough for lasting at\n" + 
             "least half a century in use";
  items[2] = "window";
  items[3] = "The window carved in the eastern wall gives out to the backyard of the\n" + 
             "red-painted building. The yard is covered by a colourful and varying\n" + 
             "flower bed. The effort and love toward flowers can be seen in every\n" + 
             "single flower in the yard. The flowers have been categorized by colour\n" + 
             "and variety";
  items[4] = "carpet";
  items[5] = "Numerous small blue, violet and yellow flowers are floating on a white\n" + 
             "background. This carpet seems to be self-made. Someone has spent a lot\n" +
             "of time making each of the flowers to match the rest. The carpet is\n" + 
             "made of soft material and it feels comfortable under your feet";
  items[6] = "flowers";
  items[7] = "Few of the most beautiful individual flowers have been transferred from\n" + 
             "the back and front yards into the house to satisfy everyone visiting it.\n" + 
             "The flowers look like hybrids of an orchid and rose. You do not know the\n" + 
             "exact name for them, but they all look very pretty";
  if(!mob) { move_object(mob = clone_object("/wizards/ahma/orc/mob/man02"), this_object()); }
}

init() {
  ::init();
  add_action("hep", "pick");
}

hep(str) {
  if(str == "flower" || str == "flowers") {
    write("You do not want to pick flowers from inside the house.\n");
    return 1;
  }
}
