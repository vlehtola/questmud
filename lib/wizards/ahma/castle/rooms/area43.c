inherit "room/room";
int i;
object monster01;

reset(arg) {
  add_exit("northeast", "/wizards/ahma/castle/rooms/area42");
  short_desc = "Underground dead end";
  long_desc =  "End of road.\n" + 
               "The road ends into a tunnel, which seems to be either collapsed or\n" + 
               "filled up with stones. The second option seems to be more logical,\n" + 
               "because there appears to be some kind of runes carved in few stones,\n" + 
               "like it would be a curse or a banishment spell. The biggest stone\n" + 
               "rolled in must weight close to a thousand pounds and there are runes\n" + 
               "in it, too.\n";
  items = allocate(2);
  items[0] = "runes";
  items[1] = "You do not understand anything what stands in the runes, but you still\n" + 
             "manage to figure out that these demons may have been banished from the\n" + 
             "Hell. If so, you are facing pretty nasty army when continuing forward";
               

  set_not_out(1);

i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob14");
      move_object(monster01, this_object());
    }
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob15");
      move_object(monster01, this_object());
    }  
  }
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob16");
      move_object(monster01, this_object());
    }
  }
}