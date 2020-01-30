#include <ansi.h>
inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_level(27);
 set_gender(1);
 set_name("priest");
 set_short(""+BOLD+"A temple priest dressed in white."+OFF+"");
 set_long("An old man is wearing a long white cloak which is covering his body totally.\n"+
                "Priest is chanting a prayer all the time for the ancients. He has long blond hair\n"+
                "and brown eyes which are sometimes pointed at you.\n");
 set_alias("priest");
 set_al(50);
}
