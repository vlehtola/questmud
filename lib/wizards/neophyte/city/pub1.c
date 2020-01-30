inherit "room/room";

reset(arg) {
if(arg) return;

set_not_out(1);
set_light(3);

short_desc = "The second floor of the pub";
long_desc =  "The stairs end in here, in the second floor of the pub. The walls are\n"+
             "painted with yellow paint and decorated with paintings. Travellers can\n"+
             "rent accommodation for the night from here. A simple wooden table is next\n"+
             "to the stairs, which are leading back to the down. The table is full of\n"+
             "empty glasses and bottles. The visitors' book is placed on the table,\n"+
             "waiting for the next inhabitants.\n";
   items = allocate(6);
   items [0] = "stairs";
   items [1] = "The stairs are leading back to the down";
   items [2] = "paintings";
   items [3] = "The paintings are portraits of some important people";
   items [4] = "book";
   items [5] = "The visitors' book is full is names";

add_exit("north","pub2");
add_exit("down","pub");
}

