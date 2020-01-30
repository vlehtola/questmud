inherit "room/outroom";

start() {
  mapfile = "/wizards/duncan/island/virtual_map";
  short_desc = "Cave";
  long_desc = "This is the highest place on the hills, beatiful horizon\n"+
              "opens in every direction ending to the blue sea far from\n"+
              "here. The hills are almost inside the white fluffy clouds.\n"+
              "The mist is gone, just few seconds ago it was floating\n"+
              "over the whole island. Someone has dug the ground recently.\n";
              
 }

search_finished() {
        if(!this_player()->query_quests("Find wolfrider den")) {
                write("You have found the wolfrider den!\n");
                        write("You find a cave entrance and quickly step in.\n");
                        say(this_player()->query_name()+ " finds something.\n");
                        move_object(this_player(), "/wizards/neophyte/city/den/entrance");
                        this_player()->set_quest("Find wolfrider den");
                return 1;
        }
        write("You find a cave entrance and quickly step in.\n");
        say(this_player()->query_name()+ " finds something.\n");
        move_object(this_player(), "/wizards/neophyte/city/den/entrance");
}
