inherit "room/room";
object mob01, mob02;
int plant_touched, i;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/vil07");
  short_desc = "In a simple house";
  long_desc = "An ordinary-looking house. A basic set of furniture can be found all around\n" + 
              "the house: A wooden dining table and a soft, green carpet are just like in\n" + 
              "any other houses. A small window in the northern wall gives some light to\n" +
              "the green plants near the window. Few bigger plants are growing in clay\n" + 
              "pots, which are hanging from the ceiling. Surprisingly, the apartment smells\n" +
              "clean.\n";
  
  items = allocate(8);
  items[0] = "carpet";
  items[1] = "The green, furry carpet reminds you a bit from grass. The whole village\n" + 
             "seems to be somehow very nature-friendly, and this carpet might re-\n" + 
             "present the nature in this house. The soft carpet feels comfortable\n" +
             "under your feet";
  items[2] = "table";
  items[3] = "An ordinary wooden dining table is standing by the western vall.\n" +
             "Some dishes are set on the table, but no food is placed on them\n" +
             "yet. Though the table is made of wood, it looks sturdy enough for\n" + 
             "lasting at least half a century in use";
  items[4] = "window";
  items[5] = "The window carved in the northern wall gives out to the backyard of the\n" + 
             "building. The yard seems to be in bad condition, though there grows those\n" + 
             "same green plants which are set in the pots and hung from the ceiling\n" + 
             "inside this house. You wonder if they have some special purpose";
  items[6] = "plant";
  items[7] = "Strange-looking green plant is set in a clay pot and hung from the ceiling.\n" + 
             "As examining the plant more closely, you discover that it seems to have\n" + 
             "numerous small mouths full of small teeth in its trunk. In few mouths can\n" +
             "be seen some pieces of greenish Orc skin, like someone would have been\n" + 
             "touching the plants, or had been feed to them. Suddenly, a burst of\n" +
             "laughter rises inside you: Killer plants? Hee-hee";

  if(!mob01) { mob01 = clone_object("/wizards/ahma/orc/mob/man02"); move_object(mob01, this_object()); }
  if(!mob02) { mob02 = clone_object("/wizards/ahma/orc/mob/woman02"); move_object(mob02, this_object()); }
}

init() {
  ::init();
  add_action("hep", "touch");
}

hep(str) {
  if(str == "plant") {
  if(!plant_touched) {
    write("You start moving you hand towards the plant as it suddenly starts to act\n" + 
          "wildly. It quickly wraps itself around your hand. An extremely painful wave\n" + 
          "sweeps through your body as it starts to devour your hand with its hundreds\n" + 
          "of small teeth. You eventually react and pull your hand away as hard as you\n" + 
          "can. Eventually you get your hand off from the plants grip, but as you pull\n" + 
          "your hand, you manage to drop the plant down on the floor from the clay pot.\n\n" +
          "The plant starts furiously jumping towards you.\n");
    this_player()->hit_with_spell(300);
    say(this_player()->query_name() + " tries to touch the strange-looking plant which is hanging from\n" + 
        "the ceiling as it quickly wraps around " + this_player()->query_name() + "'s hand. With surprised\n" + 
        "look in " + this_player()->query_possessive() + " eyes " + this_player()->query_name() + " starts hysterically pull the hand away from the\n" + 
        "plant. The hand reaches the freedom, but the plant falls on the floor.\nIt attacks.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/carnplant01"), this_object());
    plant_touched = 1;
    return 1;
  }
  else {
    write("As you touch the plant, it quickly chugs a bit, but nothing else happens.\n");
    return 1;
  }
  {
    write("Touch what?\n");
    return 1;
  }
}
}

specsay() {
  if(mob01 || mob02) {
    if(!random(17)) {
      i = random(4);
      if(i==0) { tell_room(this_object(), "Orc says: 'I love to grow mysterious plants.'\n"); }
      if(i==1) { tell_room(this_object(), "Orc explains: 'These plants really give meaning for your life.'\n"); }
      if(i==2) { tell_room(this_object(), "Orc sighs: 'Growing plants is so exciting.'\n"); }
      if(i==3) { tell_room(this_object(), "Orc laughs: 'Plants are like food: Spicy is good.'\n"); }
    }
  }
  call_out("specsay", 2);
}
