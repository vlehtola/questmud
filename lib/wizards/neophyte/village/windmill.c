inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "Inside the windmill";
        long_desc = "This windmill looks quite much abandoned but it is still working.\n"+
                    "A large stones are grinding grains to flour. The stones seems to\n"+
                    "constantly moving despating the wind. This look magical mill cause\n"+
                    "outside is not wind blowing.\n";
        add_exit("out", "room11");
        }
