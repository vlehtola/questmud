inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area18");
  add_exit("south", "/wizards/ahma/castle/rooms/area21");
  short_desc = "In a corridor";
  long_desc = "In a corridor.\n" + 
              "The corridor is quite spacious, the soft carpet is covering the floor\n" + 
              "and walls are painted with calming light blue.\n" + 
              "The bedroom door with number 2 on it is located on the eastern wall\n" + 
              "The door seems to be twisted in such position that opening it would be\n" + 
              "impossible. Some smoke is coming from under the door, only as much as it\n" + 
              "can just be noticed. There is a keyhole on the door's lock.\n";
  items = allocate(2);
  items[0] = "keyhole";
  items[1] = "As you take a peek in the room beyond you can see a horrible scene.\n" + 
             "A burning, horned dog-like demon is devouring a head still attached to\n" + 
             "servant's body. The demon has made its way through the hard skull and is\n" + 
             "having the jelly brains for a dinner.\n" + 
             "You move your sight to the other side of the room where you can spot a\n" + 
             "small more human-like demon doing something with a corpse. As you look\n" + 
             "more carefully you figure out that the demon is digging for the servant's\n" + 
             "bowels and loading them up into his mouth.\n" + 
             "You decide not to look for more details from that room";

  i = random(4);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob09");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster01, this_object());
    }
  }
}
