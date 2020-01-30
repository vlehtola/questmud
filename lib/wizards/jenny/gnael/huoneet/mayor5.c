inherit "room/room";
object human,human2,human3;

reset(arg) {

           if (!present("human")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/byrokraatti.c"), this_object());
        }

         if (!present("human2")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/byrokraatti.c"), this_object());
        }

         if (!present("human3")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/byrokraatti.c"), this_object());
        }

  if(arg) return;


        add_exit("west","/wizards/jenny/gnael/huoneet/mayor4.c");
        add_exit("northwest","/wizards/jenny/gnael/huoneet/mayor9.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/mayor8.c");
        add_exit("northeast","/wizards/jenny/gnael/huoneet/mayor7.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/mayor6.c");
        add_exit("southeast","/wizards/jenny/gnael/huoneet/mayor3.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/mayor1.c");
        add_exit("southwest","/wizards/jenny/gnael/huoneet/mayor2.c");


    short_desc = "Inside the mayor's house";
    long_desc = "You have entered the mayor's house. There is a massive\n"+
              "carpet on the floor filling the whole big room. The carpet\n"+
              "has many colors on it and it is decorated with beautiful\n"+
              "pictures. There are paintings of former mayor's hung on\n"+
              "the walls and hundreads of candles are lighting the room.\n";

  set_not_out(1);
  set_light(3);

        items = allocate(6);
        items[0] = "carpet";
        items[1] = "This must be the most beautiful carpet you have ever seen";
        items[2] = "paintings";
        items[3] = "Paintings of former mayor's are hung on the walls";
        items[4] = "candles";
        items[5] = "The candles are giving light to the room";

}
