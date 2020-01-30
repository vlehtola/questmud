inherit "room/room";
object monster;
int i;

reset(arg) {
  add_exit("west", "/wizards/ahma/orc/village/sub15");
  add_exit("southeast", "/wizards/ahma/orc/village/sub13");
  short_desc = "Deeper in an underground sewer-system";
  long_desc = "The air pressure can be felt in the ears when this deep under ground-\n" + 
              "level. The torches are lighting the way in this small circular tunnel.\n" + 
              "There is no water in this part of the tunnel system, but some flowing\n" + 
              "water can be heard being somewhere very near. The walls of this part\n" + 
              "of the tunnel system are much cleaner than in the upper part. Though\n" + 
              "some slimy substance can be still seen on the walls.\n";
  
  items = allocate(2);
  items[0] = "torches";
  items[1] = "Some lit torches have been attached to the tunnel walls, which seems strange\n" + 
             "to you. There must be someone else also in the sewers. The torches seem\n" + 
             "recently lit because they are still quite long. In addon to the lighting,\n" + 
             "the torches indicate that no fatal sewer-gasses are mixed with the air you\n" + 
             "are breathing";

  set_not_out(1);

  if(!monster) {
  i = random(4);
  if(i==0) { move_object(monster = clone_object("/wizards/ahma/orc/mob/alligator"), this_object()); }
  if(i==1) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant01"), this_object()); }
  if(i==2) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant02"), this_object()); }
  if(i==3) { move_object(monster = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  }
}