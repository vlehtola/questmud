inherit "room/room";
object monster01, monster02;
int i;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area03");
  add_exit("south", "/wizards/ahma/castle/rooms/area01");
  short_desc = "On a hallway";
  long_desc = "Continuing walking onwards the hallway reveals more and more signs\n" + 
              "of a furious battle fought: In the wall there is a hole which probably\n" + 
              "became from a strike with a morningstar, near the hole there is a huge\n" + 
              "bloodstain which matches the shape of an average man's head.\n" + 
              "Still, there is no other-raced corpses in sight than humans. The attack\n" + 
              "must have struck the castle while it was still sleeping, no other way\n" + 
              "could this much damage be done to king's elite guards without any\n" + 
              "casualties to the other side.\n" + 
              "The hallway leads on.\n";

  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster02, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob04");
      move_object(monster02, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }

    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster02, this_object());
    }
  }  
}