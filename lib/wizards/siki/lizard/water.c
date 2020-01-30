inherit "room/room";
object monster;

reset(arg) {
    if(!monster) {
       if(arg) return;
       monster = clone_object("/wizards/siki/lizard/monsters/monster");
       move_object(monster, this_object());
       }



  add_exit("up","/wizards/siki/lizard/water2");


  short_desc = "In the lake";
  long_desc = "The bottom is full of fishbones and there are also some human\n"+
             "bones too. Large amount of different kinds of metal objects\n"+
             "shine in the bottom as the sunshine hits them. The water is\n"+
             "cold and muddy and it is hard to see.\n";

  set_water(10);
}

