inherit "room/room";
object mob;
int h, alive;

reset(arg) {
  add_exit("east", "/wizards/ahma/orc/forest/for34");
  add_exit("southwest", "/wizards/ahma/orc/forest/for32");
  add_exit("southeast", "/wizards/ahma/orc/forest/for35");
  short_desc = "Entrance to a small opening";
  long_desc = "The thick forest ends in a meadow full of flowers and small insects.\n" + 
              "The forest is surrounding the meadow, but all the trees are cut down\n" + 
              "from the center of it. Many different kinds of flowers have turned to\n" + 
              "live in this, presumably, nutrious soil. Among the flowers can be seen\n" + 
              "growing some common weeds like grass and hay. But still, the colourful\n" + 
              "and beautiful flowers reach the highest towards the sky. Some small\n" + 
              "animals can be heard moving in the meadow, but they cannot be seen.\n";
              
  items = allocate(6);
  items[0] = "flower";
  items[1] = "Try looking at 'flowers'";
  items[2] = "flowers";
  items[3] = "Many different varieties of flowers are living in this meadow. There must\n" + 
             "be almost a dozen different types of flowers, but seems that not too rare\n" +
             "varieties or species can be found. The flowers emit a soft, wonderful\n" + 
             "scent and some butterflies can be seen flying from flower to flower";
  items[4] = "butterflies";
  items[5] = "Common-looking butterflies live their short life here. Flying from flower\n" + 
             "to flower, getting nutrients and in the same time pollinating the flowers.\n" +
             "Butterflies are a beautiful sight in the meadow, but the flowers win even\n" + 
             "those with their fascinating and bright colours";

  h = random(5);
  if(!mob) {
  if(!alive) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/bear01"), this_object()); alive = 1; }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/eagle"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/fox"), this_object()); alive = 1; }
    if(h==3) { move_object(mob = clone_object("/wizards/ahma/orc/mob/deer"), this_object()); alive = 1; }
    if(h==4) { move_object(mob = clone_object("/wizards/ahma/orc/mob/jogger"), this_object()); alive = 1; }
  }
  }
}

init() {
  ::init();
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

mobdead() {
  alive = 0;
}
