inherit "room/room";
int i;
object monster01, monster02;
reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area23");
  add_exit("west", "/wizards/ahma/castle/rooms/area22");
  short_desc = "In a bedroom";
  long_desc = "In one of the servants' bedrooms.\n" + 
              "The room is a typical, small bedroom for king's servants. The window on\n" + 
              "the eastern wall is giving some light to the room. The stench of blood and\n" + 
              "torn flesh is penetrating into your olfactorial nerves. The room looks like a\n" + 
              "slaughterhouse: There are four beds, two in each side of the toom. In all\n" + 
              "beds there is a massacred body of a servant, the resistance had been futile,\n" + 
              "they had been mauled to death when they were asleep. There is a wooden night-\n" + 
              "stand between two of the beds. On the nightstand there is a painting of a\n" + 
              "beautiful woman. The northern wall has collapsed letting you enter the room\n" + 
              "behind the wall.\n";
  items = allocate(2);
  items[0] = "painting";
  items[1] = "Your mind is confounded by pity and sadness as you look at this\n" + 
             "painting which is certainly made to remind the poor man laying on\n" + 
             "the bed from his beautiful and now lonely wife.\n" + 
             "You give a quick final glance at the picture as you decide to continue\n" + 
             "your journey to make the ones who are responsible for this woman's\n" + 
             "suffering repay";
  
  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob06");
      move_object(monster02, this_object());
    }  
  }
  
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob08");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob10");
      move_object(monster02, this_object());
    }  
  }  
  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
    if(!monster02) {
      monster02 = clone_object("/wizards/ahma/castle/mob/mob07");
      move_object(monster02, this_object());
    }  
  }
}
