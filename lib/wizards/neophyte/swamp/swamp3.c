inherit "room/room";
object swarm;
reset(arg) {
                if(!swarm) {
                        swarm = clone_object("/wizards/neophyte/swamp/swarm.c");
                        move_object(swarm, this_object());
                }

        add_exit("west","/guilds/witch/witch");
        add_exit("southwest","swamp2");
short_desc = "A boggy swamp";
long_desc = "You are standing in the wet swamp filled with rotting trees.\n"+
            "The ground feels dangerously wet and every where is piles of tussock's.\n"+
            "Air is full of small insects constantly buzzing. To the west is small hut.\n";

}
init() {
  ::init();
  add_action("test", "southwest");
  add_action("test", "west");
}

test() {
        if(random(3) == 0) {
                write("You get stuck in the bog.\n");
                say(this_player()->query_name()+" gets stuck in the bog.\n");
                return 1;
}
return 0;
}

