inherit "room/room";
object monster;
int i;

reset(arg) {
  add_exit("west", "/wizards/ahma/orc/village/sub11");
  add_exit("northeast", "/wizards/ahma/orc/village/sub13");
  add_exit("ladders", "/wizards/ahma/orc/village/sub17");
  short_desc = "Deeper in an underground sewer-system";
  long_desc = "The air pressure can be felt in the ears when being this deep under ground-\n" + 
              "level. The torches are lighting the way in this small circular tunnel. The\n" + 
              "water is running slowly by your feet, the water-level is reaching up to your\n" + 
              "knees. Water can be heard falling down somewhere very near. The walls of this\n" + 
              "part of the tunnel system are much cleaner than in the upper part. Though\n" + 
              "some slimy substance can be still seen on the walls. The slimy ladders are\n" +
              "leading up by the eastern wall.\n";
  
  items = allocate(6);
  items[0] = "torches";
  items[1] = "Some lit torches have been attached to the tunnel walls, which seems strange\n" + 
             "to you. There must be someone else also in the sewers. The torches seem\n" + 
             "recently lit because they are still quite long. In addon to the lighting,\n" + 
             "the torches indicate that no fatal sewer-gasses are mixed with the air you\n" + 
             "are breathing";
  items[2] = "water";
  items[3] = "In the brownish water floats various items and substances. You do not even\n" + 
             "want to think about what causes water's brown colour. The water seems to\n" + 
             "run in counterclockwise in this part of the sewer tunnel";
  items[4] = "ladders";
  items[5] = "Slimy, greenish ladders lead up from the room you are standing in. The\n" + 
             "ladders are not entirely covered in slime, some symmetrical spots with\n" + 
             "no slime can be seen in each ladder. Seems like someone would have been\n" + 
             "climbing them not too long ago";

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