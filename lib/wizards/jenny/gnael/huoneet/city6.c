inherit "room/room";
object monster;

reset(arg) {

         if (!present("glenfast")) {
         move_object("wizards/jenny/gnael/mosut/glenfast_assassin.c", this_object());
        }

        if(arg) return;


        add_exit("east","/wizards/jenny/gnael/huoneet/city5.c");

  short_desc = "A dark alley";
  long_desc = "You have arrived to a dark alley, there are not\n"+
              "many light sources here and it's very quiet. Some\n"+
              "people pass the alley walking very fast. It is said\n"+
              "that assassins and other criminals lurk in these dark\n"+
              "alleys of Gnael. Even guards are avoiding these alleys\n"+
              "and the smell of this alley is terrible.\n";

        items = allocate(2);
        items[0] = "people";
        items[1] = "Some beggars are passing the alley";
        }
