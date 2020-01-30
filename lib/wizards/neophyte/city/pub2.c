inherit "room/room";

reset(arg) {
if(arg) return;

set_not_out(1);
set_light(3);

short_desc = "The second floor of the pub";
long_desc =  "The long hallway leads to the private rooms, where the travellers can go\n"+
             "rest. The walls are painted with yellow paint, but the paint is coming off.\n"+
             "This hallway should be re-painted soon. The paintings are hanging on the\n"+
             "walls, hiding behind that crackling paint in some places. A huge chandelier\n"+
             "made of crystals is hanging from the ceiling. The candles which are burning\n"+
             "in it are making this inn look cosy.\n";
   items = allocate(6);
   items [0] = "chandelier";
   items [1] = "The chandelier is made out of crystals. It offers light in every corner of the hallway";
   items [2] = "paintings";
   items [3] = "The paintings are portraits of some important people";
   items [4] = "walls";
   items [5] = "The yellow paint is coming off from the walls";

add_exit("west","pub3");
add_exit("east","pub4");
add_exit("south","pub1");
}

