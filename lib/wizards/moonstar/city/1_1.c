inherit "room/room";
//1_1
reset(arg) {
        if(arg) return;
        add_exit("south","1_2");
        add_exit("east","2_1");
        short_desc = "On the northern part of Diamond street";
        long_desc =
"########### You are on Diamond street running north-east. There is a small\n" +
"# WWWWWWWW# street leading to Emerald street east of here. The richest people\n" +
"# W *--+--# of Duranghom live here. The large city walls rise very high\n" +
"# W |     # over your head, as the city does not want to have any \n" +
"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
"far away in south of here. The large north wall is just next to you as is the\n" +
"west wall. All kinds of shops are scattered by the sides of this street.\n";

}