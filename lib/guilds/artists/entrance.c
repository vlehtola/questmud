inherit "room/room";

/*init() {
        ::init();
        add_action("hall","hall");
}*/

reset(arg) {
  if(arg) return;
add_exit("hall","/guilds/artists/base_guild.c");
  add_exit("south","out: 45 72");
  add_exit("north","out: 45 72");
  add_exit("east","out: 45 72");
  add_exit("west","out: 45 72");
  short_desc = "An opening";
  long_desc = "A peaceful opening in the middle of a light forest.\n"+
              "There is a training hall near a big oak. Birds are singing quietly.\n";
}

hall() {
        if( this_player()->query_real_name() == "bloodstorm" ||
            this_player()->query_real_name() == "golthar" ||
            this_player()->query_real_name() == "rimber" ||
            this_player()->query_real_name() == "devil" ||
            this_player()->query_real_name() == "celes" ||
            this_player()->query_real_name() == "slat" ||
            this_player()->query_tester() ||
            this_player()->query_wiz() ) {
                return;
        } else {
                write("You are not allowed to enter.\n");
                return 1;
        }
}

