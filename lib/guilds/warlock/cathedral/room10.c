inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("west","/guilds/warlock/warlock");
        short_desc = "A cold chamber";
        long_desc = "The center of this large chamber contains an imposing black trone, covered with bones and skulls lashed together "+
        "with razorwire and black thorny vines. The whole thing is stained with reddish brown, as if with blood. Paintings on canvas "+
        "and framed in gilt wood cover the walls here. A lush red carpet with swirling streaks of black and green cover most of the floor. "+
        "On the carpet is a lots of bones, torn bits of clothing and remnants of dead bodies. Near the north wall stands a obsidian statue "+
        "of man holding somekind of pendant. In the pedant seems to be somekind of reddish flowing of souls.\n";
        items = allocate(8);
        items[0] = "throne";
        items[1] = "The throne is made from black material, covered with bones and skulls lashed together with razorwire and black thorny vines";
        items[2] = "paintings";
        items[3] = "The paintings represent scenarios of soul hunting and sacrificing the souls to the dark gods";
        items[4] = "statue";
        items[5] = "The statue is holding a pendant of souls on his right hand. The statue is prepresenting the chaotic soul hunter, which are know for the deeds that they drain the soul of their victims";
        items[6] = "carpet";
        items[7] = "The carpet is made from red silk with swirling streaks of black and green painted on it. On the carpet is lots of remnants of dead bodies and bones";
        property = allocate(1);
        property[0] = "no_summon";
        set_not_out(1);
        set_light(0);
        move_object(clone_object("/guilds/warlock/cathedral/man"), this_object());
}
