#include <ansi.h>

inherit "obj/armour";

start() {

set_class(1);
set_sub_type("chain coif");
set_name("hat");
set_short("A very cool looking "+sprintf("%c",27)+"[1;1;31m"+"christmas hat"+OFF+"");
set_long("This christmas hat looks absolutely\n"+
            "cool, there is a small text 'I am\n"+
            "santa's little helper written on it\n"+
            "You feel like you could 'cdance' or\n"+
            "'csing' if you have this hat!\n"+
            "(c stands for christmas idiot)");
set_value(100);
set_weight(2);

}

init() {
  ::init();
add_action("messu","csing");
add_action("toine","cdance");
}

messu() {

if(query_worn() != this_player()) { write("Wear the hat first dummy!\n"); return 1; }
  write("You start to sing a cool christmas song\n"); 
    say(this_player()->query_name()+ " starts to sing a cool christmas song\n");

return 1;
}

toine() {

if(query_worn() != this_player()) { write("Wear the hat first dummy!\n"); return 1; }
    write("You start to dance a cool looking christmas dance\n"); 
      say(this_player()->query_name()+ " starts to dance a cool looking christmas dance\n");

return 1;
}
