inherit "room/room";
object mob01, mob02, mob03, mob04;
int childnum;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/vil11");
  short_desc = "In a hut-like building";
  long_desc = "A precisely decorated and cozy apartment. The walls have been made by\n" +
              "stomping numerous trunks of some sturdy tree in the ground, tightly\n" + 
              "side by side. A window has been carved in the northern wall. By the\n" + 
              "western wall is located three high-chairs for babies, which indicate\n" + 
              "that there might be living few smaller children in this household.\n" +
              "The floor is covered with an ordinary-looking, green carpet. On the\n" + 
              "eastern wall is hanging a big, furry rug.\n";

  items = allocate(6);
  items[0] = "window";
  items[1] = "The window carved in the northern wall gives out to the backyard of this\n" +
             "building. Some various plants and flowers are being grown in the yard.\n" +
             "Behind a longer distance in northeast can be seen the central part of\n" + 
             "the village and the village square. In northwest can be seen the entrance\n" + 
             "to the forest surrounding this village";
  items[2] = "rug";
  items[3] = "On the rug seems to be some bold, blue symbols on yellow background. The\n" + 
             "rug does not seem to fit to the style of decoration of this house at all.\n" + 
             "It almost seems like someone was forced to hang the rug on the wall.\n" + 
             "Maybe you could take a peek behind the rug";
  items[4] = "carpet";
  items[5] = "The green, furry carpet reminds you a bit from grass. The whole village\n" + 
             "seems to be somehow very nature-friendly, and this carpet might re-\n" + 
             "present the nature in this house. The soft carpet feels comfortable\n" +
             "under your feet";

  if(childnum < 3) { if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(childnum < 3) { if(!mob02) { move_object(mob02 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(childnum < 3) { if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/woman02"), this_object()); }
}

childdead() {
  childnum--;
}

init() {
  ::init();
  add_action("hep", "move");
  add_action("hep", "peek");
}

hep(str) {
  if(str == "behind the rug" || str == "behind rug") return;
  write("You peek behind the rug by moving it a little. You discoverd that the\n" +
        "wall behind the rug has been completely ruined by non-senseless drawings.\n" +
        "They have probably been made by some small children. You place the rug\n" +
        "back to its original position.\n");
  return 1;
}