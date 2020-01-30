inherit "room/room";
object monster;
int i;

reset(arg) {
  add_exit("northeast", "/wizards/ahma/orc/village/sub15");
  add_exit("southeast", "/wizards/ahma/orc/village/sub11");
  add_exit("stairs", "/wizards/ahma/orc/village/sub18");
  short_desc = "Deeper in an underground sewer-system";
  long_desc = "The air pressure can be felt in the ears when being this deep under ground-\n" + 
              "level. The torches are lighting the way in this small circular tunnel. The\n" + 
              "water is running slowly by your feet, the water-level is reaching up to your\n" + 
              "knees. Water can be heard falling down somewhere very near. The walls of this\n" + 
              "part of the tunnel system are much cleaner than in the upper part. Though\n" + 
              "some slimy substance can be still seen on the walls. In the eastern wall is a\n" +
              "hole where the water runs in. Rusty stairs are leading deeper in the tunnel\n" +
              "system.\n";
              
  items = allocate(8);
  items[0] = "torches";
  items[1] = "Some lit torches have been attached to the tunnel walls, which seems strange\n" + 
             "to you. There must be someone else also in the sewers. The torches seem\n" + 
             "recently lit because they are still quite long. In addon to the lighting,\n" + 
             "the torches indicate that no fatal sewer-gasses are mixed with the air you\n" + 
             "are breathing";
  items[2] = "water";
  items[3] = "In the brownish water floats various items and substances. You do not even\n" + 
             "want to think about what causes water's brown colour. The water runs into a\n" +
             "hole on the western wall. It can be heard falling down for a long distance";
  items[4] = "hole";
  items[5] = "A gaping hole in the eastern wall leads the water further in the tunnel\n" + 
             "system. The water entering the hole can be heard falling down for a long\n" + 
             "distance. The hole is too small for you to fit in it";
  items[6] = "stairs";
  items[7] = "Rusty metal stairs in the eastern wall lead deeper into the tunnel system";

  set_water(4);
  set_not_out(1);

  if(!monster) {
  i = random(6);
  if(i==0) { move_object(monster = clone_object("/wizards/ahma/orc/mob/alligator"), this_object()); }
  if(i==1) { move_object(monster = clone_object("/wizards/ahma/orc/mob/leech"), this_object()); }
  if(i==2) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant03"), this_object()); }
  if(i==3) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant01"), this_object()); }
  if(i==4) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant02"), this_object()); }
  if(i==5) { move_object(monster = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  }
}