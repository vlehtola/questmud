inherit "room/room";
object monster;
int i;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/sub04");
  add_exit("northwest", "/wizards/ahma/orc/village/sub02");
  short_desc = "In a dark sewage tunnel";
  long_desc = "Some torches attached to the tunnel walls are lighting up the way. The\n" +
              "water runs slowly along the bottom of the tunnel. The water level is quite\n" + 
              "low, reaching only to your ankles. The walls of the tunnel are covered\n" + 
              "with green slime-like mould and the stench floating in the room is quite\n" + 
              "pungent. Small pipes are piercing the tunnel walls here and there.\n" + 
              "Miscellaneous trash is floating in the brownish water.\n";

  items = allocate(6);
  items[0] = "torches";
  items[1] = "Some lit torches have been attached to the tunnel walls, which seems strange\n" + 
             "to you. There must be someone else also in the sewers. The torches seem\n" + 
             "recently lit because they are still quite long. In addon to the lighting,\n" + 
             "the torches indicate that no fatal sewer-gasses are mixed with the air you\n" + 
             "are breathing";
  items[2] = "pipes";
  items[3] = "Some stony pipes reach the tunnel through its walls. The brownish water\n" + 
             "is flowing into the tunnel from these pipes. The pipes are too small for\n" + 
             "you to fit in them";
  items[4] = "water";
  items[5] = "In the brownish water floats various items and substances. You do not even\n" + 
             "want to think about what causes water's brown colour. The water seems to\n" + 
             "run in clockwise in this part of the sewer tunnel";

  set_water(2);
  set_not_out(1);

  if(!monster) {
  i = random(6);
  if(i==0) { move_object(monster = clone_object("/wizards/ahma/orc/mob/alligator"), this_object()); }
  if(i==1) { move_object(monster = clone_object("/wizards/ahma/orc/mob/leech"), this_object()); }
  if(i==2) { move_object(monster = clone_object("/wizards/ahma/orc/mob/sewerrat"), this_object()); }
  if(i==3) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant01"), this_object()); }
  if(i==4) { move_object(monster = clone_object("/wizards/ahma/orc/mob/mutant02"), this_object()); }
  if(i==5) { move_object(monster = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  }
}