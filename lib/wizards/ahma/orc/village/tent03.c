inherit "room/room";

reset(arg) {
  if(arg) return;
  {
    if(!present("nadia", this_object())) { move_object(clone_object("/wizards/ahma/orc/mob/shopkeeper02"), this_object()); }
  }
  add_exit("out", "/wizards/ahma/orc/village/sq06");
  short_desc = "In the flower shop";
  long_desc = "Pure nature shines out from this beautiful entity which happens to be a\n" + 
              "flower shop of Nehelam. Few holes have been pierced through the ceiling,\n" + 
              "letting the sunlight shine straight inside the tent and to the flowers.\n" + 
              "The flowery alleys lead eventually to the counter, which is just about\n" + 
              "only place in the shop which is not covered with flowers. On the counter\n" +
              "seems to be also some perfumes for sale. A fascinating scent of flowers\n"+ 
              "and perfumes is floating all around the tent, making your head spin a\n" + 
              "little. On the floor has been placed a soft flowery carpet. It feels very\n" + 
              "comfortable to your feet.\n";
  
  items = allocate(6);
  items[0] = "flowers";
  items[1] = "From this tent can be found more and more fascinating looking flowers. The\n" + 
             "flowers are placed all around the tent, some of them even hang from the\n" + 
             "ceiling. Most of the flowers seem to be some kind of hybrids of orchids\n" + 
             "and roses, but some other varieties can also be seen. The flowers smell\n" + 
             "fascinating and make your head spin a little";
  items[2] = "flower";
  items[3] = "Try looking at 'flowers'";
  items[4] = "carpet";
  items[5] = "Numerous small blue, violet and yellow flowers are floating on a white\n" + 
             "background. This carpet seems to be self-made. Someone has spent a lot\n" +
             "of time making each of the flowers to match the rest. The carpet is\n" + 
             "made of soft material and it feels comfortable under your feet";
}
