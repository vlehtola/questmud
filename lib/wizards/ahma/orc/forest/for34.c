inherit "room/room";
object mob;
int h, alive;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/forest/for35");
  add_exit("west", "/wizards/ahma/orc/forest/for33");
  add_exit("east", "/wizards/ahma/orc/forest/for36");
  short_desc = "In the center of a flowery meadow";
  long_desc = "The flowery meadow shimmers in every colour of the whole spectrum.\n" + 
              "The soil feels soft under your feet, the weeds and the stalks of the\n" + 
              "flowers are fondling your legs when advancing forward in the opening.\n" + 
              "Some butterflies can be seen flying over the flowers. The meadow ends\n" + 
              "into a thick wall of trees in the north, but continues to all other\n" + 
              "directions.\n";
  
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
