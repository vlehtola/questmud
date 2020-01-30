inherit "room/room";
reset(arg) {
if(arg) return;
set_not_out(1);
set_light(1);

short_desc = "A nicely decorated bedroom";
long_desc =  "This is the bedroom of lowie family, where they spend their holidays\n"+
             "and spare time. A large mirror is placed on the ceiling and something\n"+
             "seems to moving directly beneath it. The ceiling is painted in red and\n"+
             "small white flowers are also painted on it. Backside of the bedroom is\n"+
             "a large bed, which looks quite tempting to sleep in. On the bed is small\n"+
             "furs taken from those hunting encampment that lowies have been. The room\n"+
             "itself looks little dark and quiet place but that is what should typical\n"+
             "bedroom look like. A small night desk is placed next to the bed, but the\n"+
             "drawer in desk looks tightly shut.\n";
  add_exit("west", "house2");
}


