#include <ansi.h>

inherit "obj/weapon";

start() {
      set_class(7);
      set_sub_type("staff");
     set_alias("wrath");
     set_name("staff");
       set_short("The long ebony quarterstaff named "+RED_F+"'Wrath'"+OFF+" ");
    set_long("This masterfully crafted staff is made of ebony but it has silvered\n"+ 
             "runes all over it. You have never seen anything so beautifully made,\n"+ 
             "it almost looks too perfect. It has very detailed head of its former\n"+ 
             "owner,Hefasto, screaming in agony. If you look carefully you almost\n"+ 
             "see another set of runes beneath silvered ones, yet you cant clearly\n"+ 
             "visualize them. These dark red runes seems like they are on move all\n"+
             "the time. When you try to decipher them you start feeling sick.\n"+ 
             "The aura of wickedness and the staffs lust for power is overwhelming.\n"+
             "As you grab the staff dull pain hits you in the back of your head and\n"+ 
             "suddenly you hear a deep voice laughing in your head, 'You can call me\n"+ 
             "Wrath. We are gonna get along just fine', and with that voice fades out\n"+ 
             "leaving behind but a headache. Now all you can see are the red runes and\n"+ 
             "they clearly tell about your conquests yet to come.\n"+ 
             "You grin wickedly and have feeling that with this staff no one can stop you.\n"+ 
             "You hear a wicked laughter in your head but shake it off. The staff feels\n"+ 
             "warm and you feel like it has always been inseparable part of you.\n");
    set_stats("int", 10);
    set_stats("wis", 6);
     set_stats("con", 6);
     set_stats("dex", -10);
    set_stats("str", -10);
     set_stats("spr", 10);
}
