inherit "room/room";
object mob01, mob02, mob03, mob04, mob05;
int childnum;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/sq09");
  add_exit("west", "/wizards/ahma/orc/village/sq05");
  add_exit("enter", "/wizards/ahma/orc/village/tent03");
  short_desc = "Northeastern corner of village square";
  long_desc = read_file("/wizards/ahma/orc/village/sqdesc") + 
              "A tent with flowery coverings and lots of flowers surrounding it is\n" + 
              "standing in the border of the square. A wooden sign is hanging from\n" + 
              "the tent.\n";

  items = allocate(6);
  items[0] = "tent";
  items[1] = "A tent with calming flowery coverings is located near the moat and\n" + 
             "a wonderful scent is floating all around the tent. Dozens of different\n" + 
             "flowers surround the tent, so it is not hard to guess where the scent\n" + 
             "might come from. The wooden sign is hanging near the entrance to the\n" + 
             "tent";
  items[2] = "sign";
  items[3] = "Flower shop Nehelam's Heart.\n" + 
             "We are also selling perfumes.\n" + 
             "- Nadia, the shopkeeper and flower-lover";
  items[4] = "flowers";
  items[5] = "Most of the flowers seem to be some kind of hybrids from Orchids and\n" + 
             "roses, but some other varieties can also be seen. The flowers smell\n" + 
             "fascinating, and make your head spin a little";

  if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/customer"), this_object()); }
  if(childnum < 2) { if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(childnum < 2) { if(!mob05) { move_object(mob05 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
}

childdead() {
  childnum--;
}