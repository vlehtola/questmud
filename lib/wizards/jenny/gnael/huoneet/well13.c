inherit "room/room";

reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/well12.c");
        
     short_desc = "A mysterious looking room";
     long_desc = "You have arrived into a huge room. There are\n"+
              "bones and bodies everywhere. You can smell the blood\n"+
              "everywhere in here and you can sense some extremely\n"+
              "powerful creature's aura close. There is a small altar\n"+
              "in this room where Mondasa's minions bring their sacrifices.\n"+
              "You can see nearly nothing here because the walls are\n"+
              "somehow absorbing all the light in here.\n";

        set_not_out();
 
        items = allocate(4);
        items[0] = "altar";
        items[1] = "A small cruel looking altar, maybe you could lure Mondasa here if you would have the right sacrifice to drop";
        items[2] = "walls";
        items[3] = "The walls are absorbing all the light from the room";
}

heart_location() {
  return 1;

}
