inherit "room/room";
object monster;

reset(arg) { 

if(arg) return;
        if (!monster) {
                monster = clone_object("/wizards/jenny/gnael/mosut/beledor.c");
                move_object(monster, this_object());
        }

        add_exit("south","/wizards/jenny/gnael/huoneet/mansion14.c");
       
  short_desc = "The second floor of the mansion";
  long_desc = "You have arrived into a cosy room. There is a nice\n"+
              "looking bed in the corner and a wooden table with few\n"+
              "chairs placed in the middle of the room. A few paintings\n"+
              "have been placed on the wall, and there is a small statue\n"+
              "on the table. In south you can see a staircase leading\n"+
              "into the basements of the mansion.\n";

        items = allocate(12);
        items[0] = "bed";
        items[1] = "A very nice looking bed";
        items[2] = "table";
        items[3] = "A wooden table, there is a statue on it";
        items[4] = "chairs";
        items[5] = "few wooden chairs are surrounding the table";
        items[6] = "paintings";
        items[7] = "Some nice looking paintings are on the wall";
        items[8] = "statue";
        items[9] = "A statue of unicorn is on the table";
        items[10] = "staircase";
        items[11] = "You can see a staircase in south";
}
