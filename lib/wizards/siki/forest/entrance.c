inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","outmap: 238 149");
        add_exit("south","outmap: 238 149");
        add_exit("west","outmap: 238 149");
        add_exit("east","outmap: 238 149");
        add_exit("enter","room1");
        short_desc = "Entrance to Deformed forest";
   long_desc = "This gloomy and deformed entrance is filled with eerie sounds. The ground\n"+
               "is full of corpses where are lots of maggots crawling and eating the flesh.\n"+
               "A strange looking purple mist is covering the ground here and there and it\n"+
               "makes breathing very hard. This forest is full of twisted and deformed\n"+
               "looking trees and bushes.\n";
        items = allocate(4);
        items[0] = "ground";
        items[1] = "The ground is full of rotting corpses of different creatures.\n";
        items[2] = "mist";
        items[3] = "The mist looks quite strange and magical.\n";

}
