inherit "room/room";


object mob, mob1; int rn;  reset(arg) {
  /* Applying mobs */
  if(!mob) {
    mob = clone_object("/wizards/gynter/darke/mobs/lovers");
    move_object(mob, this_object());
  }
  if (!mob1) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/lovers");
    move_object(mob1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("south","/wizards/gynter/darke/city/garden/1g6");
  add_exit("west","/wizards/gynter/darke/city/garden/1g4");
  /* setting desc */
  short_desc = "The Rose Garden";
  rn = random(3);
  if (rn == 1) {
    long_desc = "This is the rose garden. This part of the garden has\n"+
                "been cared for by the lovers. They have planted\n"+
                "this garden to symbolise the break from their\n"+
                "heritance, or their try to break with it.\n";
  } else if (rn == 2) {
    long_desc = "As you enter this room you intuitively notice that\n"+
                "something is wrong. The stunning beauti that is in the\n"+
                "other rooms exist here aswell, but something is amiss here.\n"+
                "After careful examination you spot some black roses in the midst\n"+
                "of all the other beautiful red and yellow roses. Another\n"+
                "proof that you cannot break with your inheritance\n";
  } else {
    long_desc = "This is the ultimate proof of the black souls that the\n"+
                "Dark Elfs inherit. This room is totally covered with black\n"+
                "and rotting roses. Some roses are even planted with the dark\n"+
                "magic given to the dark elfs. Something is truly amiss here.\n";
  }
}
