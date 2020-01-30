inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);


add_exit("north","/wizards/duncan/island/lighthouse/corridor2");
add_exit("out","/wizards/duncan/island/lighthouse/entrance");

short_desc = "A corridor on the first floor of the lighthouse";
long_desc =  "A corridor inside the lighthouse, leading to the centre of the lighthouse.\n"+
             "The lighthouse consist of corridors, which are connected together. The\n"+
             "tower-like structure of the lighthouse is based to the ancient times.\n"+
             "The lighthouse is built from square-stones, supported with thick boards\n"+
             "and strengthen with mortar. The corridor is located on the first floor\n"+
             "in the lighthouse.\n";
}
