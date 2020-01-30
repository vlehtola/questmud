inherit "room/room";

object monster;
reset(arg) {

    if(!monster) {
       if(arg) return;
       monster = clone_object("/wizards/siki/lizard/monsters/shaman");
       move_object(monster, this_object());
       }


  add_exit("out","/wizards/siki/lizard/room12");


  short_desc = "A extremely dusty and narrow hut";
  long_desc = "The walls are colored black with coal. A symbol is drawn\n"+
              "on the western wall, it almost covers the whole wall. There is\n"+
              "a small fire in the middle of the floor and a pot on it.\n";
            
              
   items = allocate(4);
   items[0] = "symbol";
   items[1] = "A huge white symbol of the lizardman race";
   items[2] = "pot";
   items[3] = "The iron pot is full of strange liquid";
  
   set_not_out(1);
   set_light(2);
}


