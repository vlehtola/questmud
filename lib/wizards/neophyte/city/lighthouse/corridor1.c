inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);


add_exit("north","corridor2");
add_exit("out","entrance");

short_desc = "A corridor on the first floor of the lighthouse";
long_desc =  "A corridor inside the lighthouse is gloomy, the grey walls, rough floor and\n"+
             "ceiling full of spiderwebs, gives the lighthouse an ancient and elegant look.\n"+
             "The lighthouse consist of corridors, which are connected together like the\n"+
             "tunnel network. The tower-like structure of the lighthouse is based from time\n"+
             "immemorial, built with the same pattern as in ancient times. The lighthouse\n"+
             "is built from square-stones, supported with thick boards and strengthen with\n"+
             "mortar. The corridor is located on the first floor of the lighthouse. The\n"+
             "corridor continues towards north.\n";

  property = allocate(1);
  property[0] = "no_summon";

}
