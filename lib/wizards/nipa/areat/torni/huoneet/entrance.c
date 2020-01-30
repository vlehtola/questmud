inherit "room/room";

reset(arg) 
   {
        add_exit("enter","/wizards/nipa/areat/torni/huoneet/lounge.c");
        add_exit("north", "out: 269 59");
        add_exit("east", "out: 270 58");
        add_exit("south", "out: 269 57");
        add_exit("west", "out:268 58");

   short_desc = "Entrance of huge cone-shaped tower.";
   long_desc = "You have arrived at the entrance of huge blue cone-shaped tower.\n"+
               "Firstly you question why you haven't seen this humongous tower before.\n"+
               "After a while of closer inspection you notice that there isn't any\n"+
               "flaws in this towers structure. It's blue exterior shines with a\n"+
               "mystical glow colouring the surroundings purple. Some markings can\n"+
               "be seen on the surface of the tower. You feel very strong magical\n"+
               "presence from the tower but you have no clue what emits it.\n"+
               "Comparing to the size of the tower entrance looks very small sized.\n"+
               "There is no door and no one is guarding the entrance.\n";

        set_light(3);
  
        items = allocate(2);
        items[0] = "markings";
        items[1] = "Some rune-like markings move wildly under the tower's blue surface.";
}
